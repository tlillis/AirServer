#ifndef THREADS_H
#define THREADS_H

#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/HTTPClientSession.h"

#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"

#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/FileChannel.h"

#include "serial_port.h"

#include <queue>
#include <string>
#include <sstream>
#include <iostream>

using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::Net::WebSocket;
using Poco::SimpleFileChannel;
using Poco::Logger;
using Poco::FileChannel;

class AutopilotSerialThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock_received;
    Poco::Mutex * _lock_tosend;
    std::queue <mavlink_message_t> * _received;
    std::queue <mavlink_message_t> * _tosend;
    std::string _file;
    int _baud;
    int *_use;
public:
    AutopilotSerialThread (int id, Poco::Mutex * lock_received, Poco::Mutex * lock_tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::queue <mavlink_message_t> * tosend,
                                                std::string file, int baud, int *use)
    : _id(id),_lock_received(lock_received), _lock_tosend(lock_tosend), _received(received), _tosend(tosend),
                                                _file(file), _baud(baud), _use(use){}
    void run();
};

class TeensySerialThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock_received;
    Poco::Mutex * _lock_tosend;
    std::queue <mavlink_message_t> * _received;
    std::queue <mavlink_message_t> * _tosend;
    std::string _file;
    int _baud;
    int *_use;
public:
    TeensySerialThread (int id, Poco::Mutex * lock_received, Poco::Mutex * lock_tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::queue <mavlink_message_t> * tosend,
                                                std::string file, int baud, int *use)
    : _id(id), _lock_received(lock_received), _lock_tosend(lock_tosend), _received(received), _tosend(tosend),
                                                _file(file), _baud(baud), _use(use){}
    void run();
};

class WebSocketThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock_tosend;
    Poco::Mutex * _lock_received;
    std::queue <char *> * _tosend;
    std::queue <mavlink_message_t> * _received;
    std::string _address;
    int _port;
    int *_use;
public:
    WebSocketThread (int id, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received,
                                                std::queue <char *> * tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::string address, int port, int *use)
    : _id(id), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend(tosend),_received(received),
                                                _address(address), _port(port), _use(use){}
    void run();
};

class UDPThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock_tosend;
    Poco::Mutex * _lock_received;
    std::queue <mavlink_message_t> * _tosend;
    std::queue <mavlink_message_t> * _received;
    std::string _address;
    int _port;
    int *_use;
public:
    UDPThread (int id, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received,
                                                std::queue <mavlink_message_t> * tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::string address, int port, int *use)
    : _id(id), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend(tosend), _received(received),
                                                _address(address), _port(port), _use(use){}
    void run();
};

class MessageLoggingThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock;
    std::queue <char *> * _tolog;
    std::string _address;
    int *_use;
public:
    MessageLoggingThread (int id, Poco::Mutex * lock, std::queue <char *> * tolog,
                                                std::string address, int *use)
    : _id(id), _lock(lock), _tolog(tolog), _address(address), _use(use){}
    void run();
};

#endif // THREADS_H