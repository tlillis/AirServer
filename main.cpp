#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/FileChannel.h"

#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadPool.h"
#include "Poco/RWLock.h"
#include "Poco/Mutex.h"

#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"

#include "threads.h"
#include "conversions.h"
#include "initialization.h"

using namespace std;

using Poco::SimpleFileChannel;
using Poco::Logger;
using Poco::FileChannel;

int main()
{
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

    cout << "Starting autopilot serial connection..." << endl;

    Poco::Mutex lock;
    AutopilotSerialThread autopilot_thread(1, &lock, &msg_queue_send);

    Poco::ThreadPool pool;
    pool.start(autopilot_thread);

    mavlink_message_t message;

    Poco::Net::SocketAddress sa("localhost", 514);
    Poco::Net::DatagramSocket dgs;
    dgs.connect(sa);
 /**
    HTTPClientSession cs("localhost",9000);
    HTTPRequest request(HTTPRequest::HTTP_GET, "/",HTTPMessage::HTTP_1_1);
    request.set("origin", "http://www.websocket.org");
    HTTPResponse response;

    try {
        WebSocket* m_psock = new WebSocket(cs, request, response);
        char *testStr="Hello echo websocket!";
        char receiveBuff[strlen(testStr)];

        int len=m_psock->sendFrame(testStr,strlen(testStr),WebSocket::FRAME_TEXT);
        std::cout << "Sent bytes " << len << std::endl;
        int flags=0;

        int rlen=m_psock->receiveFrame(receiveBuff,strlen(testStr),flags);
        std::cout << "Received bytes " << rlen << std::endl;
        std::cout << receiveBuff << std::endl ;

        m_psock->close();

    } catch (std::exception &e) {
        std::cout << "Exception " << e.what();
    }
**/
    printf("Waiting for first data from devices...");
    while(msg_queue_send.empty())
    {
    }

    int previous_id = -1;
    while(!msg_queue_send.empty())
    {
        lock.lock();
        message = msg_queue_send.front();
        msg_queue_send.pop();
        lock.unlock();

        if(message.msgid != previous_id)
        {


            mav_to_json(message);

            previous_id = message.msgid;
            sleep(1);
        }

    }
    printf("Reached end of loop...");
    pool.joinAll();
    return 0;
}
