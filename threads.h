#ifndef THREADS_H
#define THREADS_H

#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/HTTPClientSession.h"

#include "serial_port.h"

#include <queue>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::Net::WebSocket;

class AutopilotSerialThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock;
    std::queue <mavlink_message_t> * _collector;
public:
    AutopilotSerialThread (int id, Poco::Mutex * lock, std::queue <mavlink_message_t> * collector) : _id(id), _lock(lock), _collector(collector) {}
    void run();
};

class WebSocketThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock;
    std::queue <mavlink_message_t> * _tosend;
public:
    WebSocketThread (int id, Poco::Mutex * lock, std::queue <mavlink_message_t> * tosend) : _id(id), _lock(lock), _tosend(tosend) {}
    void run();
};

#endif // THREADS_H
