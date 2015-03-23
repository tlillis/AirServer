#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/FileChannel.h"

#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadPool.h"
#include "Poco/RWLock.h"
#include "Poco/Mutex.h"

#include "threads.h"
#include "conversions.h"
#include "initialization.h"

using namespace std;

using Poco::SimpleFileChannel;
using Poco::Logger;
using Poco::FileChannel;

int main() {
    cout << "Starting AirServer..." << endl << endl;

    //load ini file
    Initialization config;
    if(config.load()) {
        cout << "Unable to load configuration file." << endl;
        return 0;
    }
    config.print();

    //Create a queue for getting data between threads
    queue <mavlink_message_t> msg_queue_send;
    queue <char *> msg_queue_socket;

    Poco::Mutex lock;
    Poco::Mutex lock_socket;

    AutopilotSerialThread autopilot_thread(1, &lock, &msg_queue_send);
    WebSocketThread websocket_thread(1, &lock_socket, &msg_queue_socket);

    Poco::ThreadPool pool;
    pool.start(autopilot_thread);
    pool.start(websocket_thread);

    mavlink_message_t message;

    char json[256];

    printf("Waiting for first data from devices...");
    while(msg_queue_send.empty()) {
    }

    int previous_id = -1;
    while(!msg_queue_send.empty()) {
        lock.lock();
        message = msg_queue_send.front();
        msg_queue_send.pop();
        lock.unlock();

        if(message.msgid != previous_id) {
            mav_to_json(message,json);
            //lock_socket.lock();
            msg_queue_socket.push(json);
            //lock_socket.unlock();

            previous_id = message.msgid;
            sleep(1);
        }
    }
    printf("Reached end of loop...");
    pool.joinAll();
    return 0;
}
