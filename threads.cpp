#include "threads.h"

void AutopilotSerialThread::run() {
    mavlink_message_t message;
    //char * port = "/dev/ttyACM0";
    //int baud = 38400;
    char * port = "/dev/pts/8";
    int baud = 9600;
    Serial_Port serial_port(port,baud);
    try {
        serial_port.start();

        while(true) {

            _lock->lock(); //acquire lock
            if (serial_port.status == 1) {
                serial_port.read_message(message);
            }
            else {
                break;
            }

            _collector->push(message);
            _lock->unlock();  //release lock
        }
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }
    catch (int exit_failure) {
        cout << exit_failure << endl;
    }
};

void WebSocketThread::run() {
    HTTPClientSession cs("localhost",9000);
    HTTPRequest request(HTTPRequest::HTTP_GET, "/",HTTPMessage::HTTP_1_1);
    request.set("origin", "http://www.websocket.org");
    HTTPResponse response;

    char * message;

    while(true) {

        _lock->lock();
        if(!_tosend->empty()) {
            try {
            WebSocket* m_psock = new WebSocket(cs, request, response);

            message = _tosend->front();
            _tosend->pop();

            char receiveBuff[strlen(message)];

            int len=m_psock->sendFrame(message,strlen(message),WebSocket::FRAME_TEXT);
            std::cout << "Sent bytes " << len << std::endl;
            int flags=0;

            int rlen=m_psock->receiveFrame(receiveBuff,strlen(message),flags);
            std::cout << "Received bytes " << rlen << std::endl;
            std::cout << receiveBuff << std::endl ;

            m_psock->close();

            } catch (std::exception &e) {
                std::cout << "Exception " << e.what() << endl;
            }

        } else {
            sleep(.1);
        }
        _lock->unlock();
        sleep(.5);
    }
};

void UDPThread::run() {
    Poco::Net::SocketAddress sa("localhost", 514);
    Poco::Net::DatagramSocket dgs;
    dgs.connect(sa);
};

void MessageLoggingThread::run() {


};
