#include "../include/threads.h"
#include "../include/initialization.h"

#include <fstream>
#include <iostream>

void AutopilotSerialThread::run() {
    mavlink_message_t message;
    char * port = (char*)_file.c_str();

    Serial_Port serial_port(port, _baud);

    int len = 0;

    try {
        serial_port.start();

        while(*_use) {

            if (serial_port.status == 1) {
                len = serial_port.read_message(message);
            }
            else {
                break;
            }
            if (len) {
                _lock_received->lock(); //acquire lock
                _received->push(message);
                _lock_received->unlock();  //release lock
            }
            usleep(100);
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "AutopilotSerialThread: CLOSED" << std::endl;
};

void TeensySerialThread::run() {
    mavlink_message_t message;
    char * port = (char*)_file.c_str();

    Serial_Port serial_port(port, _baud);

    int len = 0;

    try {
        serial_port.start();

        while(*_use) {

            if (serial_port.status == 1) {
                len = serial_port.read_message(message);
            }
            else {
                break;
            }
            if (len) {
                _lock_received->lock(); //acquire lock
                _received->push(message);
                _lock_received->unlock();  //release lock
            }
            usleep(100);
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "TeensySerialThread: CLOSED" << std::endl;
};

void WebSocketThread::run() {
    HTTPClientSession cs(_address,_port);
    HTTPRequest request(HTTPRequest::HTTP_GET, "/",HTTPMessage::HTTP_1_1);
    request.set("origin", "http://www.websocket.org");
    HTTPResponse response;

    char * message;

    WebSocket* psock = new WebSocket(cs, request, response);

    //psock->setReceiveTimeout(50);
    //psock->setSendTimeout(50);

    int rlen = 0;
    int len = 0;
    int flags = 0;

    while(*_use) {

        _lock_tosend->lock();
        if(!_tosend->empty()) {
            try {

            message = _tosend->front();

            len = psock->sendFrame(message,strlen(message)+1,WebSocket::FRAME_TEXT);

            char receiveBuff[len];

            rlen = psock->receiveFrame(receiveBuff,len,flags);

           // if(rlen > 0) std::cout << "Got WebSocket message: " << receiveBuff << std::endl;

            _tosend->pop();

            } catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
                break;
            }

        } else {

        }
        _lock_tosend->unlock();
        usleep(5000);
    }
    psock->close();
    std::cout << "WebSocketThread: CLOSED" << std::endl;
};

void UDPThread::run() {
    Poco::Net::SocketAddress sa(_address, _port);
    Poco::Net::DatagramSocket dgs;
    dgs.connect(sa);

    mavlink_message_t message;
    uint8_t buffer[2041];
    int len;

    while(*_use) {

        _lock_tosend->lock();
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
        _lock_tosend->unlock();
        usleep(5000);
    }
    std::cout << "UDPThread: CLOSED" << std::endl;
};

void MessageLoggingThread::run() {
    std::ofstream message_file;
    message_file.open (_address.c_str(), std::ios::out);

    char * message;

    int count = 0;

    while (*_use) {
        _lock->lock();
        if(!_tolog->empty()) {
            try {
                message = _tolog->front();

                if (message_file.is_open()) {
                    message_file << message << std::endl;
                    //std::cout << "WRITTEN TO FILE: " << count << " : " << message <<std::endl;
                    //std::cout << "size: " << _tolog->size() <<std::endl;
                    message_file.flush();
                    count++;
                }

                _tolog->pop();

            } catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
            }
        }
        _lock->unlock();
        usleep(5000);
    }
    message_file.close();
    std::cout << "MessageLoggingThread: CLOSED" << std::endl;
};
