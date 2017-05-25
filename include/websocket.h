#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/NetException.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Format.h"

#include "airserver/mavlink.h"

#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using Poco::Net::ServerSocket;
using Poco::Net::WebSocket;
using Poco::Net::WebSocketException;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Timestamp;
using Poco::ThreadPool;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;

class WebSocketRequestHandler: public HTTPRequestHandler
{
	public:
		Poco::Mutex * _lock_tosend;
	    Poco::Mutex * _lock_received;
	    std::queue <std::string> * _tosend;
	    std::queue <mavlink_message_t> * _received;
	    std::string _address;
	    int _port;
	    int *_use;
	    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
	    void setParams(Poco::Mutex * lock_tosend, 
						Poco::Mutex * lock_received, 
						std::queue <std::string> * tosend, 
						std::queue <mavlink_message_t> * received,
	    				std::string address,
	    				int port,
	   					int *use);
};

class RequestHandlerFactory: public HTTPRequestHandlerFactory
{
	public:
		Poco::Mutex * _lock_tosend;
	    Poco::Mutex * _lock_received;
	    std::queue <std::string> * _tosend;
	    std::queue <mavlink_message_t> * _received;
	    std::string _address;
	    int _port;
	    int *_use;
	    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request);
		void setParams(Poco::Mutex * lock_tosend, 
						Poco::Mutex * lock_received, 
						std::queue <std::string> * tosend, 
						std::queue <mavlink_message_t> * received,
	    				std::string address,
	    				int _port,
	   					int *_use);
};
#endif // WEBSOCKET