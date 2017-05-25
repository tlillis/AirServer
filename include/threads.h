#ifndef THREADS_H
#define THREADS_H

#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/NetException.h"

#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"

#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/FileChannel.h"

#include "serial_port.h"
#include "websocket.h"

#include <queue>
#include <string>
#include <sstream>
#include <iostream>

using Poco::Net::ServerSocket;
using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::WebSocketException;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Net::WebSocket;
using Poco::SimpleFileChannel;
using Poco::Logger;
using Poco::FileChannel;

class AutopilotSerialThread : public Poco::Runnable{
private:
    int _id;
    int _debug;
    Poco::Mutex * _lock_tosend;
    Poco::Mutex * _lock_received;
    std::queue <mavlink_message_t> * _tosend;
    std::queue <mavlink_message_t> * _received;
    std::string _file;
    int _baud;
    int *_use;
public:
    AutopilotSerialThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received, 
                                                std::queue <mavlink_message_t> * tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::string file, int baud, int *use)
    : _id(id), _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend(tosend), _received(received),
                                                _file(file), _baud(baud), _use(use){}
    void run();
};

class TeensySerialThread : public Poco::Runnable{
private:
    int _id;
    int _debug;
    Poco::Mutex * _lock_tosend;
    Poco::Mutex * _lock_received;
    std::queue <mavlink_message_t> * _tosend;
    std::queue <mavlink_message_t> * _received;
    std::string _file;
    int _baud;
    int *_use;
public:
    TeensySerialThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received, 
                                                std::queue <mavlink_message_t> * tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::string file, int baud, int *use)
    : _id(id), _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend(tosend), _received(received),
                                                _file(file), _baud(baud), _use(use){}
    void run();
};

class OutputSerialThread : public Poco::Runnable{
private:
    int _id;
    int _debug;
    Poco::Mutex * _lock_tosend;
    Poco::Mutex * _lock_received;
    std::queue <mavlink_message_t> * _tosend;
    std::queue <mavlink_message_t> * _received;
    std::string _file;
    int _baud;
    int *_use;
public:
    OutputSerialThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received, 
                                                std::queue <mavlink_message_t> * tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::string file, int baud, int *use)
    : _id(id), _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend(tosend), _received(received),
                                                _file(file), _baud(baud), _use(use){}
    void run();
};

class WebSocketThread : public Poco::Runnable{
private:
    int _id;
    int _debug;
    Poco::Mutex * _lock_tosend;
    Poco::Mutex * _lock_received;
    std::queue <std::string> * _tosend;
    std::queue <mavlink_message_t> * _received;
    std::string _address;
    int _port;
    int *_use;
public:
    WebSocketThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received,
                                                std::queue <std::string> * tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::string address, int port, int *use)
    : _id(id),  _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend(tosend),_received(received),
                                                _address(address), _port(port), _use(use){}
    void run();
};

class UDPThread : public Poco::Runnable{
private:
    int _id;
    int _debug;
    Poco::Mutex * _lock_tosend;
    Poco::Mutex * _lock_received;
    std::queue <mavlink_message_t> * _tosend;
    std::queue <mavlink_message_t> * _received;
    std::string _address;
    int _port_send;
    int _port_bind;
    int _broadcast;
    int *_use;
public:
    UDPThread (int id, int debug, Poco::Mutex * lock_tosend, Poco::Mutex * lock_received,
                                                std::queue <mavlink_message_t> * tosend,
                                                std::queue <mavlink_message_t> * received,
                                                std::string address, int port_send, int port_bind, int broadcast, int *use)
    : _id(id), _debug(debug), _lock_tosend(lock_tosend), _lock_received(lock_received), _tosend(tosend), _received(received),
                                                _address(address), _port_send(port_send), _port_bind(port_bind), _broadcast(broadcast), _use(use){}
    void run();
    int pop(mavlink_message_t message);
    int push(mavlink_message_t message);
};

class MessageLoggingThread : public Poco::Runnable{
private:
    int _id;
    int _debug;
    Poco::Mutex * _lock;
    std::queue <std::string> * _tolog;
    std::string _address;
    int *_use;
public:
    MessageLoggingThread (int id, int debug, Poco::Mutex * lock, std::queue <std::string> * tolog,
                                                std::string address, int *use)
    : _id(id), _debug(debug), _lock(lock), _tolog(tolog), _address(address), _use(use){}
    void run();
};

#endif // THREADS_H