#include "../include/websocket.h"

void WebSocketRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    try
    {
        WebSocket ws(request, response);
        //int len = 0;
        //int rlen = 0;
        std::string message;
        while(*_use) {

            if(_lock_tosend->tryLock()) {
                if(!_tosend->empty()) {
                    try {
                        message = _tosend->front();

                        ws.sendFrame(message.c_str(),strlen(message.c_str()),WebSocket::FRAME_TEXT);

                        //char receiveBuff[len];

                        //rlen = ws.receiveFrame(receiveBuff,len,flags);

                        //if(rlen > 0) std::cout << "Got WebSocket message: " << receiveBuff << std::endl;

                        _tosend->pop();

                    } catch (std::exception &e) {
                        std::cout << "Exception: " << e.what() << std::endl;
                        _lock_tosend->unlock();
                        break;
                    }

                } else {

                }
                _lock_tosend->unlock();
                
            }
            usleep(5000);
        }
    } catch (WebSocketException& exc) {
        _lock_tosend->unlock();
        std::cout << "Exception: " << exc.what() << std::endl;
        switch (exc.code())
        {
            case WebSocket::WS_ERR_HANDSHAKE_UNSUPPORTED_VERSION:
                response.set("Sec-WebSocket-Version", WebSocket::WEBSOCKET_VERSION);
                // fallthrough
            case WebSocket::WS_ERR_NO_HANDSHAKE:
                 std::cout << "WEBSOCKET: No handshake" << std::endl;
            case WebSocket::WS_ERR_HANDSHAKE_NO_VERSION:
                std::cout << "WEBSOCKET: No version" << std::endl;
            case WebSocket::WS_ERR_HANDSHAKE_NO_KEY:
                std::cout << "WEBSOCKET: No key" << std::endl;
                response.setStatusAndReason(HTTPResponse::HTTP_BAD_REQUEST);
                response.setContentLength(0);
                response.send();
                break;
        }
    }
};

void WebSocketRequestHandler::setParams(Poco::Mutex * lock_tosend, 
                        Poco::Mutex * lock_received, 
                        std::queue <std::string> * tosend, 
                        std::queue <mavlink_message_t> * received,
                        std::string address,
                        int port,
                        int *use)
{
    _lock_tosend = lock_tosend;
    _lock_received = lock_received;
    _tosend = tosend;
    _received = received;
    _address = address;
    _port = port;
    _use = use;
    return;
}

HTTPRequestHandler *RequestHandlerFactory::createRequestHandler(const HTTPServerRequest& request)
{   
    if(request.find("Upgrade") != request.end() && Poco::icompare(request["Upgrade"], "websocket") == 0) {
        WebSocketRequestHandler *wsrh = new WebSocketRequestHandler;
        wsrh->setParams(_lock_tosend, 
                        _lock_received, 
                        _tosend, 
                        _received,
                        _address,
                        _port,
                        _use);
        return wsrh;
    }else {
           std::cout << "Not able to handle request" << std::endl;
    }
    return NULL; //check this!!
};

void RequestHandlerFactory::setParams(Poco::Mutex * lock_tosend, 
                        Poco::Mutex * lock_received, 
                        std::queue <std::string> * tosend, 
                        std::queue <mavlink_message_t> * received,
                        std::string address,
                        int port,
                        int *use)
{
    _lock_tosend = lock_tosend;
    _lock_received = lock_received;
    _tosend = tosend;
    _received = received;
    _address = address;
    _port = port;
    _use = use;
    return;
}
