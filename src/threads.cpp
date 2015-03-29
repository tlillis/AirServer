#include "../include/threads.h"

#include <fstream>
#include <iostream>

void AutopilotSerialThread::run() {
    mavlink_message_t message;
    char * port = (char*)_file.c_str();

    Serial_Port serial_port(port, _baud);

    try {
        serial_port.start();

        while(true) {

            if (serial_port.status == 1) {
                serial_port.read_message(message);
            }
            else {
                break;
            }
            _lock->lock(); //acquire lock
            _collector->push(message);
            _lock->unlock();  //release lock
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
};

void WebSocketThread::run() {
    HTTPClientSession cs(_address,_port);
    HTTPRequest request(HTTPRequest::HTTP_GET, "/",HTTPMessage::HTTP_1_1);
    request.set("origin", "http://www.websocket.org");
    HTTPResponse response;

    char * message;

    WebSocket* psock = new WebSocket(cs, request, response);

    int rlen = 0;
    int len = 0;
    int flags = 0;

    while(true) {

        _lock->lock();
        if(!_tosend->empty()) {
            try {

            message = _tosend->front();

            len = psock->sendFrame(message,strlen(message)+1,WebSocket::FRAME_TEXT);

            char receiveBuff[len];

            rlen = psock->receiveFrame(receiveBuff,len,flags);

            if(rlen > 0) std::cout << receiveBuff << std::endl;

            _tosend->pop();

            } catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
                break;
            }

        } else {

        }
        _lock->unlock();
    }
    psock->close();
};

void UDPThread::run() {
    Poco::Net::SocketAddress sa(_address, _port);
    Poco::Net::DatagramSocket dgs;
    dgs.connect(sa);

    mavlink_message_t message;
    uint8_t buffer[2041];
    int len;

    while(true) {

        _lock->lock();
        if(!_tosend->empty()) {
            try {
                message = _tosend->front();

                len = mavlink_msg_to_send_buffer(buffer, &message);

                dgs.sendBytes(buffer, len);

                _tosend->pop();

            } catch (std::exception &e) {
                //std::cout << "Exception: " << e.what() << std::endl;
            }

        } else {

        }
        _lock->unlock();
    }

};

void MessageLoggingThread::run() {
    std::ofstream message_file;
    message_file.open (_address.c_str());

    char * message;

    while (true) {
        _lock->lock();
        if(!_tolog->empty()) {
            try {
                message = _tolog->front();

                if (message_file.is_open()) {
                    message_file << message << std::endl;
                }

                _tolog->pop();

            } catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
            }
        }
        _lock->unlock();
    }

    message_file.close();

};
