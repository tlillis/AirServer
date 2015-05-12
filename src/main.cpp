#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadPool.h"
#include "Poco/RWLock.h"
#include "Poco/Mutex.h"

#include "../include/threads.h"
#include "../include/conversions.h"
#include "../include/initialization.h"

#include <ctime>
#include <signal.h>

using namespace std;

Initialization ini;

Poco::ThreadPool pool;

int counter = 0;

pid_t pid = 0;

void intHandler(int dummy) {
    if(pid == 0) {
        sleep(1);
    }
    if(pid > 0) {
        ini.end(); //Ends all threads
        sleep(1);
    }
    //pool.joinAll();
    cout << "Total Messages Handled:" << counter << endl;
    exit(0);
}

int main() {
    cout << "Starting AirServer..." << endl << endl;

    signal(SIGINT, intHandler);

    // Load ini file
    //Initialization ini;
    if(ini.load()) {
        cout << "Unable to load configuration file." << endl;
        return 0;
    }
    ini.print();

    // Set up sitl
    if(ini.autopilot_sitl) {
        cout << "Setting up SITL connection..." << endl;
        pid = fork();
        if (pid == 0) {
            //Not calling to system() because system() forks a process and won't quit with SIGINT
            execl("/bin/sh"
                , "sh"
                ,"-c"
                , "xterm -e \"socat -d -d UDP-LISTEN:14550 pty,raw,echo=0,link=/tmp/ttyV0\""
                ,(char *) 0);
            return 0;
        }
        if (pid > 0) {
            sleep(1); // Wait for SITL to be setup. May need to be longer
        }
        else {
            cout << "fork() failed!" << endl;
            return 0;
        }
    }

    // Create a queues for getting data between threads
    queue <mavlink_message_t> msg_queue_main_tosend; // Main queue of msgs to send out
    queue <mavlink_message_t> msg_queue_udp_tosend; // Queue of udp messages to send out
    queue <char *> msg_queue_websocket_tosend; // Queue of udp messages to send out
    queue <char *> msg_queue_logging; // Queue of messages to be saved to file

    queue <mavlink_message_t> msg_queue_received; // Queue of msgs received

    Poco::Mutex lock_main_tosend;
    Poco::Mutex lock_websocket_tosend;
    Poco::Mutex lock_udp_tosend;
    Poco::Mutex lock_teensy_tosend;
    Poco::Mutex lock_messagelogging;

    Poco::Mutex lock_main_received;

    AutopilotSerialThread autopilot_thread(1, &lock_main_tosend, &lock_main_received, &msg_queue_main_tosend, &msg_queue_received,
                                                ini.autopilot_file, ini.autopilot_baud, &ini.autopilot_use);
    TeensySerialThread teensy_thread(1, &lock_main_tosend,&lock_teensy_tosend, &msg_queue_main_tosend, &msg_queue_received,
                                                ini.teensy_file, ini.teensy_baud, &ini.teensy_use);
    WebSocketThread websocket_thread(3, &lock_websocket_tosend, &lock_main_received, &msg_queue_websocket_tosend, &msg_queue_received,
                                                ini.websocket_address, ini.websocket_port, &ini.websocket_use);
    UDPThread udp_thread(4, &lock_udp_tosend, &lock_main_received, &msg_queue_udp_tosend, &msg_queue_received,
                                                ini.udp_address, ini.udp_port, &ini.udp_use);
    MessageLoggingThread messagelogging_thread(5, &lock_messagelogging, &msg_queue_logging,
                                                ini.logging_messages, &ini.logging_use);

    pool.start(autopilot_thread);
    pool.start(teensy_thread);
    pool.start(websocket_thread);
    pool.start(udp_thread);
    pool.start(messagelogging_thread);

    //pool.collect();
    //cout << "Allocated Threads: " << pool.allocated() << endl;
    //cout << "Used Threads: " << pool.used() << endl;

    mavlink_message_t message_mav;
    char message_json [256];

    cout << "Waiting for first data from devices..." << endl;
    while(msg_queue_main_tosend.empty()) {
    }

    cout << "Starting main loop..." << endl << endl;
    while(true) {
        lock_main_tosend.lock();
        if(!msg_queue_main_tosend.empty()) {
            message_mav = msg_queue_main_tosend.front();
            msg_queue_main_tosend.pop();

            if(ini.udp_use) {
                lock_udp_tosend.lock();
                msg_queue_udp_tosend.push(message_mav);
                std::cout << "size udp: " << msg_queue_udp_tosend.size() <<std::endl;
                lock_udp_tosend.unlock();
            }

            if(ini.websocket_use || ini.websocket_use) {

                mav_to_json(message_mav,message_json);

                if(ini.logging_use) {
                    lock_messagelogging.lock();
                    msg_queue_logging.push(message_json);
                    std::cout << "size logging: " << msg_queue_logging.size() <<std::endl;
                    lock_messagelogging.unlock();
                }

                if(ini.websocket_use) {
                    lock_websocket_tosend.lock();
                    msg_queue_websocket_tosend.push(message_json);
                    std::cout << "size websocket: " << msg_queue_websocket_tosend.size() <<std::endl;
                    lock_websocket_tosend.unlock();
                }
            }

            std::cout << "size main: " << msg_queue_main_tosend.size() <<std::endl;

            counter++;
            
        }
        lock_main_tosend.unlock();
        usleep(5000);
    }

    pool.joinAll();
    return 0;
}
