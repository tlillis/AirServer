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
    Poco::Mutex * _lock;
    std::queue <mavlink_message_t> * _collector;
    std::string _file;
    int _baud;
public:
    AutopilotSerialThread (int id, Poco::Mutex * lock, std::queue <mavlink_message_t> * collector, std::string file, int baud)
    : _id(id), _lock(lock), _collector(collector), _file(file), _baud(baud) {}
    void run();
};

class WebSocketThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock;
    std::queue <char *> * _tosend;
    std::string _address;
    int _port;
public:
    WebSocketThread (int id, Poco::Mutex * lock, std::queue <char *> * tosend, std::string address, int port)
    : _id(id), _lock(lock), _tosend(tosend), _address(address), _port(port) {}
    void run();
};

class UDPThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock;
    std::queue <mavlink_message_t> * _tosend;
    std::string _address;
    int _port;
public:
    UDPThread (int id, Poco::Mutex * lock, std::queue <mavlink_message_t> * tosend, std::string address, int port)
    : _id(id), _lock(lock), _tosend(tosend), _address(address), _port(port) {}
    void run();
};

class MessageLoggingThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock;
    std::queue <char *> * _tolog;
    std::string _address;
public:
    MessageLoggingThread (int id, Poco::Mutex * lock, std::queue <char *> * tolog, std::string address)
    : _id(id), _lock(lock), _tolog(tolog), _address(address) {}
    void run();
};

#endif // THREADS_H
