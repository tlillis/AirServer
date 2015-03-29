#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadPool.h"
#include "Poco/RWLock.h"
#include "Poco/Mutex.h"

#include "../include/threads.h"
#include "../include/conversions.h"
#include "../include/initialization.h"

using namespace std;

int main() {
    cout << "Starting AirServer..." << endl << endl;

    //load ini file
    Initialization ini;
    if(ini.load()) {
        cout << "Unable to load configuration file." << endl;
        return 0;
    }
    ini.print();

    //Set up sitl
    if(ini.autopilot_sitl) {
        cout << "Setting up SITL connection..." << endl;
        pid_t pid = fork();
        if (pid == 0) {
            system("xterm -e \"./sitl.sh\"");
            return 0;
        }
        if (pid > 0) {
            sleep(1); //Wait for SITL to be setup. May need to be longer
        }
        else {
            cout << "fork() failed!" << endl;
            return 0;
        }
    }

    //Create a queues for getting data between threads
    queue <mavlink_message_t> msg_queue_received;
    queue <mavlink_message_t> msg_queue_udp;
    queue <char *> msg_queue_socket;
    queue <char *> msg_queue_logging;

    Poco::Mutex lock_serial;
    Poco::Mutex lock_socket;
    Poco::Mutex lock_udp;
    Poco::Mutex lock_messagelogging;

    AutopilotSerialThread autopilot_thread(1, &lock_serial, &msg_queue_received, ini.autopilot_file, ini.autopilot_baud);
    WebSocketThread websocket_thread(2, &lock_socket, &msg_queue_socket, ini.websocket_address, ini.websocket_port);
    UDPThread udp_thread(3, &lock_udp, &msg_queue_udp,ini.udp_address, ini.udp_port);
    MessageLoggingThread messagelogging_thread(4, &lock_messagelogging, &msg_queue_logging, ini.logging_messages);

    Poco::ThreadPool pool;
    pool.start(autopilot_thread);
    pool.start(websocket_thread);
    pool.start(udp_thread);
    pool.start(messagelogging_thread);

    mavlink_message_t message_mav;
    char message_json [256];

    int previous_id = -1;

    cout << "Waiting for first data from devices..." << endl;
    while(msg_queue_received.empty()) {
    }

    cout << "Starting main loop..." << endl;
    while(true) {
        lock_serial.lock();
        if(!msg_queue_received.empty()) {
            message_mav = msg_queue_received.front();
            msg_queue_received.pop();

            lock_udp.lock();
            msg_queue_udp.push(message_mav);
            lock_udp.unlock();

            if(message_mav.msgid != previous_id) { //To remove duplicates. May not be wanted

                mav_to_json(message_mav,message_json);

                lock_messagelogging.lock();
                msg_queue_logging.push(message_json);
                lock_messagelogging.unlock();

                lock_socket.lock();
                msg_queue_socket.push(message_json);
                lock_socket.unlock();

                previous_id = message_mav.msgid;
            }
        }
        lock_serial.unlock();
    }

    pool.joinAll();
    return 0;
}
