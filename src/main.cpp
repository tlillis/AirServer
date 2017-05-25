#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadPool.h"
#include "Poco/RWLock.h"
#include "Poco/Mutex.h"

#include "../include/threads.h"
#include "../include/conversions.h"
#include "../include/initialization.h"
#include "../include/filter.h"

#include <ctime>
#include <signal.h>

using namespace std;

Initialization config;

Poco::ThreadPool pool;

int counter = 0;

pid_t pid = 0;

void intHandler(int dummy) {
    
    if(pid > 0) {
        //config.end(); //Ends all threads
        //sleep(1);
        //cout << "Total Messages Handled:" << counter << endl;
        exit(0);
    }
    if(pid == 0) {
        //sleep(1);
        cout << "Total Messages Handled:" << counter << endl;
        exit(0);
    }
    
    
    //pool.joinAll();
    cout << "Total Messages Handled:" << counter << endl;
    exit(0);
}

int main() {
    cout << "Starting AirServer..." << endl << endl;

    signal(SIGINT, intHandler);

    // Load config file
    //Initialization config;
    if(config.load()) {
        cout << "Unable to load configuration file." << endl;
        return 0;
    }
    config.print();

    // Set up sitl
    if(config.autopilot_sitl) {
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
    queue <mavlink_message_t> msg_queue_tosend; // Main queue of msgs to send out

    queue <mavlink_message_t> msg_queue_autopilot_tosend; //Queue of autopilot messages to send to autopilot
    queue <mavlink_message_t> msg_queue_teensy_tosend; //Queue of teensy messages to send to teensy
    queue <mavlink_message_t> msg_queue_serial_out_tosend; //Queue of serial_out messages to send to teensy
    queue <mavlink_message_t> msg_queue_udp_0_tosend; // Queue of udp messages to send out
    queue <mavlink_message_t> msg_queue_udp_1_tosend; // Queue of udp messages to send out
    queue <mavlink_message_t> msg_queue_udp_2_tosend; // Queue of udp messages to send out
    queue <std::string> msg_queue_websocket_0_tosend; // Queue of websocket messages to send out
    queue <std::string> msg_queue_websocket_1_tosend; // Queue of websocket messages to send out
    queue <std::string> msg_queue_websocket_2_tosend; // Queue of websocket messages to send out
    queue <std::string> msg_queue_logging_0; // Queue of messages to be saved to file
    queue <std::string> msg_queue_logging_1; // Queue of messages to be saved to file

    queue <mavlink_message_t> msg_queue_received; // Queue of msgs received

    queue <mavlink_message_t> msg_queue_autopilot_received;
    queue <mavlink_message_t> msg_queue_teensy_received;
    queue <mavlink_message_t> msg_queue_serial_out_received;
    queue <mavlink_message_t> msg_queue_udp_0_received;
    queue <mavlink_message_t> msg_queue_udp_1_received;
    queue <mavlink_message_t> msg_queue_udp_2_received;
    queue <mavlink_message_t> msg_queue_websocket_0_received;
    queue <mavlink_message_t> msg_queue_websocket_1_received;
    queue <mavlink_message_t> msg_queue_websocket_2_received;

    
    //Locks for outgoing messages queues
    Poco::Mutex lock_autopilot_tosend;
    Poco::Mutex lock_teensy_tosend;
    Poco::Mutex lock_serial_out_tosend;
    Poco::Mutex lock_websocket_0_tosend;
    Poco::Mutex lock_websocket_1_tosend;
    Poco::Mutex lock_websocket_2_tosend;
    Poco::Mutex lock_udp_0_tosend;
    Poco::Mutex lock_udp_1_tosend;
    Poco::Mutex lock_udp_2_tosend;
    Poco::Mutex lock_messagelogging_0;
    Poco::Mutex lock_messagelogging_1;

    //Locks for incoming messages queues
    Poco::Mutex lock_autopilot_received;
    Poco::Mutex lock_teensy_received;
    Poco::Mutex lock_serial_out_received;
    Poco::Mutex lock_udp_0_received;
    Poco::Mutex lock_udp_1_received;
    Poco::Mutex lock_udp_2_received;
    Poco::Mutex lock_websocket_0_received;
    Poco::Mutex lock_websocket_1_received;
    Poco::Mutex lock_websocket_2_received;

    AutopilotSerialThread autopilot_thread(1, config.autopilot_debug, &lock_autopilot_tosend, &lock_autopilot_received, &msg_queue_autopilot_tosend, &msg_queue_autopilot_received,
                                                config.autopilot_file, config.autopilot_baud, &config.autopilot_use);
    TeensySerialThread teensy_thread(1, config.teensy_debug, &lock_teensy_tosend,&lock_teensy_received, &msg_queue_teensy_tosend, &msg_queue_teensy_received,
                                                config.teensy_file, config.teensy_baud, &config.teensy_use);
    OutputSerialThread serial_out_thread(1, config.serial_out_debug, &lock_serial_out_tosend,&lock_serial_out_received, &msg_queue_serial_out_tosend, &msg_queue_serial_out_received,
                                                config.serial_out_file, config.serial_out_baud, &config.serial_out_use);
    WebSocketThread websocket_thread_0(3, config.websocket_0_debug, &lock_websocket_0_tosend, &lock_websocket_0_received, &msg_queue_websocket_0_tosend, &msg_queue_websocket_0_received,
                                                config.websocket_0_address, config.websocket_0_port, &config.websocket_0_use);
    WebSocketThread websocket_thread_1(3, config.websocket_1_debug, &lock_websocket_1_tosend, &lock_websocket_1_received, &msg_queue_websocket_1_tosend, &msg_queue_websocket_1_received,
                                                config.websocket_1_address, config.websocket_1_port, &config.websocket_1_use);
    WebSocketThread websocket_thread_2(3, config.websocket_2_debug, &lock_websocket_2_tosend, &lock_websocket_2_received, &msg_queue_websocket_2_tosend, &msg_queue_websocket_2_received,
                                                config.websocket_2_address, config.websocket_2_port, &config.websocket_2_use);
    UDPThread udp_thread_0(4, config.udp_0_debug, &lock_udp_0_tosend, &lock_udp_0_received, &msg_queue_udp_0_tosend, &msg_queue_udp_0_received,
                                                config.udp_0_address, config.udp_0_port_send, config.udp_0_port_bind, config.udp_0_broadcast, &config.udp_0_use);
    UDPThread udp_thread_1(4, config.udp_1_debug, &lock_udp_1_tosend, &lock_udp_1_received, &msg_queue_udp_1_tosend, &msg_queue_udp_1_received,
                                                config.udp_1_address, config.udp_1_port_send, config.udp_1_port_bind, config.udp_1_broadcast, &config.udp_1_use);
    UDPThread udp_thread_2(4, config.udp_2_debug, &lock_udp_2_tosend, &lock_udp_2_received, &msg_queue_udp_2_tosend, &msg_queue_udp_2_received,
                                                config.udp_2_address, config.udp_2_port_send, config.udp_2_port_bind, config.udp_2_broadcast, &config.udp_2_use);
    MessageLoggingThread messagelogging_thread_0(5, config.logging_0_debug, &lock_messagelogging_0, &msg_queue_logging_0,
                                                config.logging_0_messages, &config.logging_0_use);
    MessageLoggingThread messagelogging_thread_1(5, config.logging_1_debug, &lock_messagelogging_1, &msg_queue_logging_1,
                                                config.logging_1_messages, &config.logging_1_use);

    pool.start(autopilot_thread);
    pool.start(teensy_thread);
    pool.start(serial_out_thread);
    pool.start(websocket_thread_0);
    pool.start(websocket_thread_1);
    pool.start(websocket_thread_2);
    pool.start(udp_thread_0);
    pool.start(udp_thread_1);
    pool.start(udp_thread_2);
    pool.start(messagelogging_thread_0);
    pool.start(messagelogging_thread_1);

    //pool.collect();
    //cout << "Allocated Threads: " << pool.allocated() << endl;
    //cout << "Used Threads: " << pool.used() << endl;

    mavlink_message_t message_mav;
    int msgid;
    //char message_json[MAVLINK_MAX_PACKET_LEN];
    std::string message_json;

    cout << "Waiting for first data from devices..." << endl;
    while(msg_queue_autopilot_received.empty() && msg_queue_teensy_received.empty()) {
        //cout << msg_queue_autopilot_received.empty() << endl;
        //cout << msg_queue_teensy_received.empty() << endl;
        usleep(5000);
    }
    
    cout << endl << "Starting main loop..." << endl << endl;
    while(true) {
        //Get messages from autopilot and teensy
        if(lock_autopilot_received.tryLock()) {
            if(!msg_queue_autopilot_received.empty()) {
                msg_queue_tosend.push(msg_queue_autopilot_received.front());
                msg_queue_autopilot_received.pop();
            }
            lock_autopilot_received.unlock();
        }
        if(lock_teensy_received.tryLock()) {
            if(!msg_queue_teensy_received.empty()) {
                msg_queue_tosend.push(msg_queue_teensy_received.front());
                msg_queue_teensy_received.pop();
            }
            lock_teensy_received.unlock();
        }

        //Send messages from autopilot/teensy to other interfaces
        if(!msg_queue_tosend.empty()) {
            message_mav = msg_queue_tosend.front();
            msg_queue_tosend.pop();
            msgid = message_mav.msgid;
            
            if(config.serial_out_use && config.serial_out_filter.check(msgid)) {
                if(lock_serial_out_tosend.tryLock()) {
                    msg_queue_serial_out_tosend.push(message_mav);
                    //std::cout << "size serial_out: " << msg_queue_udp_tosend.size() <<std::endl;
                    lock_serial_out_tosend.unlock();
                }
            }
            
            //Send messages over udp
            if(config.udp_0_use && config.udp_0_filter.check(msgid)) {
                if(lock_udp_0_tosend.tryLock()) {
                    //cout << "LALA" << endl;
                    msg_queue_udp_0_tosend.push(message_mav);
                    //std::cout << "size udp: " << msg_queue_udp_tosend.size() <<std::endl;
                    lock_udp_0_tosend.unlock();
                }
            }

            if(config.udp_1_use && config.udp_1_filter.check(msgid)) {
                if(lock_udp_1_tosend.tryLock()) {
                    msg_queue_udp_1_tosend.push(message_mav);
                    //std::cout << "size udp: " << msg_queue_udp_tosend.size() <<std::endl;
                    lock_udp_1_tosend.unlock();
                }
            }

            if(config.udp_2_use && config.udp_2_filter.check(msgid)) {
                if(lock_udp_2_tosend.tryLock()) {
                    msg_queue_udp_2_tosend.push(message_mav);
                    //std::cout << "size udp: " << msg_queue_udp_tosend.size() <<std::endl;
                    lock_udp_2_tosend.unlock();
                }
            }
            
            mav_to_json(message_mav,message_json);

            //Log messages
            if(config.logging_0_use && config.logging_0_filter.check(msgid)) {
                if(lock_messagelogging_0.tryLock()) {
                    msg_queue_logging_0.push(message_json);
                    //std::cout << "size logging: " << msg_queue_logging.size() <<std::endl;
                    lock_messagelogging_0.unlock();
                }
            }

            if(config.logging_1_use && config.logging_1_filter.check(msgid)) {
                if(lock_messagelogging_1.tryLock()) {
                    msg_queue_logging_1.push(message_json);
                    //std::cout << "size logging: " << msg_queue_logging.size() <<std::endl;
                    lock_messagelogging_1.unlock();
                }
            }

            //Send messages over websockets
            if(config.websocket_0_use && config.websocket_0_filter.check(msgid)) {
                if(lock_websocket_0_tosend.tryLock()) {
                    msg_queue_websocket_0_tosend.push(message_json);
                    //std::cout << "size websocket: " << msg_queue_websocket_tosend.size() <<std::endl;
                    lock_websocket_0_tosend.unlock();
                }
            }

            if(config.websocket_1_use && config.websocket_1_filter.check(msgid)) {
                if(lock_websocket_1_tosend.tryLock()) {
                    msg_queue_websocket_1_tosend.push(message_json);
                    //std::cout << "size websocket: " << msg_queue_websocket_tosend.size() <<std::endl;
                    lock_websocket_1_tosend.unlock();
                }
            }

            if(config.websocket_2_use && config.websocket_2_filter.check(msgid)) {
                if(lock_websocket_2_tosend.tryLock()) {
                    msg_queue_websocket_2_tosend.push(message_json);
                    //std::cout << "size websocket: " << msg_queue_websocket_tosend.size() <<std::endl;
                    lock_websocket_2_tosend.unlock();
                }
            }
            
            //std::cout << "size main: " << msg_queue_main_tosend.size() <<std::endl;
            counter++;   
        } else {
            usleep(1000);
        }

        //Get messages from udp, websocket, serial_out
        if(lock_serial_out_received.tryLock()) {
            if(!msg_queue_serial_out_received.empty()) {
                msg_queue_received.push(msg_queue_serial_out_received.front());
                msg_queue_serial_out_received.pop();
            }
            lock_serial_out_received.unlock();
        }

        if(lock_udp_0_received.tryLock()) {
            if(!msg_queue_udp_0_received.empty()) {
                msg_queue_received.push(msg_queue_udp_0_received.front());
                msg_queue_udp_0_received.pop();
            }
            lock_udp_0_received.unlock();
        }

        if(lock_udp_1_received.tryLock()) {
            if(!msg_queue_udp_1_received.empty()) {
                msg_queue_received.push(msg_queue_udp_1_received.front());
                msg_queue_udp_1_received.pop();
            }
            lock_udp_1_received.unlock();
        }
        if(lock_udp_2_received.tryLock()) {
            if(!msg_queue_udp_2_received.empty()) {
                msg_queue_received.push(msg_queue_udp_2_received.front());
                msg_queue_udp_2_received.pop();
            }
            lock_udp_2_received.unlock();
        }
        if(lock_websocket_0_received.tryLock()) {
            if(!msg_queue_websocket_0_received.empty()) {
                msg_queue_received.push(msg_queue_websocket_0_received.front());
                msg_queue_websocket_0_received.pop();
            }
            lock_websocket_0_received.unlock();
        }
        if(lock_websocket_1_received.tryLock()) {
            if(!msg_queue_websocket_1_received.empty()) {
                msg_queue_received.push(msg_queue_websocket_1_received.front());
                msg_queue_websocket_1_received.pop();
            }
            lock_websocket_1_received.unlock();
        }

        if(lock_websocket_2_received.tryLock()) {
            if(!msg_queue_websocket_2_received.empty()) {
                msg_queue_received.push(msg_queue_websocket_2_received.front());
                msg_queue_websocket_2_received.pop();
            }
            lock_websocket_2_received.unlock();
        }

        //Send messages to autopilot
        if(!msg_queue_received.empty()) {
            if(lock_autopilot_tosend.tryLock()) {
                msg_queue_autopilot_tosend.push(msg_queue_received.front());
                msg_queue_received.pop();
                lock_autopilot_tosend.unlock();
            }
        }

        // Print for debugging
        if(config.debug) {
            std::cout << "tosend: " << msg_queue_tosend.size() << "-" << msg_queue_serial_out_tosend.size() << "-" << msg_queue_udp_0_tosend.size() << "-" << msg_queue_udp_1_tosend.size()
            << "-" << msg_queue_udp_2_tosend.size() << "-" << msg_queue_websocket_0_tosend.size() << "-" << msg_queue_websocket_1_tosend.size()
            << "-" << msg_queue_websocket_2_tosend.size() << "-" << msg_queue_logging_0.size() << "-" << msg_queue_logging_1.size()
            << "-" << msg_queue_autopilot_tosend.size() << "-" << msg_queue_teensy_tosend.size();
            std::cout << " ~~ received: " << msg_queue_received.size() << "-" << msg_queue_serial_out_received.size() << "-" << msg_queue_udp_0_received.size() << "-" << msg_queue_udp_1_received.size()
            << "-" << msg_queue_udp_2_received.size() << "-" << msg_queue_websocket_0_received.size() << "-" << msg_queue_websocket_1_received.size()
            << "-" << msg_queue_websocket_2_received.size() << "-" << msg_queue_autopilot_received.size() << "-" << msg_queue_teensy_received.size() << std::endl;
        }
        
    }

    pool.joinAll();
    return 0;
}
