#include "../include/threads.h"
#include "../include/initialization.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include <stdio.h>

void AutopilotSerialThread::run() {
    if (!*_use) return;
    mavlink_message_t message;
    char * port = (char*)_file.c_str();

    Serial_Port serial_port(port, _baud);

    int len = 0;
    int count = 0;

    int gotData = 0;
    char tmp;

    try {
        serial_port.start();
        while(!gotData) {
            if(count > 15) {
                cout << "GOT NO DATA FROM " << port << ", RESTARTING PORT..." << endl;
                serial_port.stop();
                count = 0;
                serial_port.start();
            }
            
            do {
                gotData = serial_port.read_message_raw(tmp);
            }
            while (serial_port.status != 1);

            usleep(100000);
            count++;

            
        }
        
        std::cout << port << " GOT DATA" << std::endl;
        while(*_use) {
            len = 0;
            if (serial_port.status == 1) {
                len = serial_port.read_message_mavlink(message,0);
                if(len) {
                    if((int)message.msgid == 40) {
                    //std::cout << "GOT ID: " << (int)message.msgid << std::endl;
                        //count++;
                        //std::cout << "COUNT: " << count << std::endl;
                    }
                }
            }
            else {
                break;
            }
            if (len) {
                if(_lock_received->tryLock()){ //acquire lock
                    _received->push(message);
                    _lock_received->unlock(); 
                } //release lock
            }
            
            usleep(100);

            if(_lock_tosend->tryLock()) {            
                if(!_tosend->empty()) {
                    if(serial_port.write_message_mavlink(_tosend->front())) {
                        std::cout << "Sent ID: " << (int)_tosend->front().msgid << std::endl;
                        _tosend->pop();
                    }  
                }
                _lock_tosend->unlock();
            }
        }
    }
    catch (std::exception& e) {
        //std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "AutopilotSerialThread: CLOSED" << std::endl;
};

void TeensySerialThread::run() {
    if (!*_use) return;
    mavlink_message_t message;
    char * port = (char*)_file.c_str();

    Serial_Port serial_port(port, _baud);

    int len = 0;

    int gotData = 0;
    char tmp;
    int count = 0;

    try {
        serial_port.start();
        while(!gotData) {
            if(count > 15) {
                cout << "GOT NO DATA FROM " << port << ", RESTARTING PORT..." << endl;
                serial_port.stop();
                count = 0;
                serial_port.start();
            }
            
            do {
                gotData = serial_port.read_message_raw(tmp);
            }
            while (serial_port.status != 1);

            usleep(100000);
            count++;

            
        }
        
        std::cout << port << " GOT DATA" << std::endl;

        while(*_use) {

            if (serial_port.status == 1) {
                len = serial_port.read_message_mavlink(message,1);
            }
            else {
                break;
            }
            if (len) {
                if(_lock_received->tryLock()){ //acquire lock
                    _received->push(message);
                    _lock_received->unlock(); 
                } //release lock
            }
            usleep(100);
        }
    }
    catch (std::exception& e) {
        //std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "TeensySerialThread: CLOSED" << std::endl;
};

void OutputSerialThread::run() {
    if (!*_use) return;
    mavlink_message_t message;
    char * port = (char*)_file.c_str();
    int count_r = 0;
    int count_s = 0;

    Serial_Port serial_port(port, _baud);

    int len = 0;

    //int gotData = 0;

    try {
        serial_port.start();
        /**
        while(!gotData) {
            serial_port.start();
            gotData = serial_port.read_message_mavlink(message,2);
            if(!gotData) {
                serial_port.stop();
            }
        
        }
        **/
        std::cout << port << " GOT MAVLINK DATA" << std::endl;

        while(*_use) {

            if (serial_port.status == 1) {
                len = serial_port.read_message_mavlink(message,2);
                
            }
            else {
                break;
            }
            if (len) {
                if(_lock_received->tryLock()) { //acquire lock
                    _received->push(message);
                    if(_debug) std::cout << "Got " << count_r << " messages" << std::endl;
                    count_r++;
                    _lock_received->unlock();  //release lock
                }
            }
            
            usleep(100);

            if(_lock_tosend->tryLock()) {            
                if(!_tosend->empty()) {
                    if(serial_port.write_message_mavlink(_tosend->front())) {
                        if(_debug) std::cout << "Sent ID: " << _tosend->front().msgid << std::endl;
                        _tosend->pop();
                        //if(_debug) std::cout << "Sent " << count_s << " messages" << std::endl;


                        count_s++;
                    }  
                }
                _lock_tosend->unlock();
            }
        }
    }
    catch (std::exception& e) {
        if(_debug) std::cout << "Exception: " << e.what() << std::endl;
    }
    if(_debug) std::cout << "OutputSerialThread: CLOSED" << std::endl;
};

void WebSocketThread::run() {
    if (!*_use) return;

    ServerSocket svs(_port);
    // set-up a HTTPServer instance
    RequestHandlerFactory *requestHandler = new RequestHandlerFactory;
    HTTPServerParams *serverParams = new HTTPServerParams;
    requestHandler->setParams(_lock_tosend, 
                        _lock_received, 
                        _tosend, 
                        _received,
                        _address,
                        _port,
                        _use);

    HTTPServer srv(requestHandler, svs, serverParams);
    // start the HTTPServer
    srv.start();
    // wait for CTRL-C or kill
    while(*_use) {
        if(_lock_tosend->tryLock()) {    
            while(_tosend->size() > 300) {
                    _tosend->pop(); //Keep queue from getting too big
                }
            _lock_tosend->unlock();
        }
        usleep(1000);
    }
    // Stop the HTTPServer
    srv.stop();
    std::cout << "WebSocketThread: CLOSED" << std::endl;
};

void UDPThread::run() {
    if (!*_use) return;
    Poco::Net::SocketAddress sa(_address, _port_send);
    Poco::Net::SocketAddress bsa("0.0.0.0", _port_bind);
    Poco::Net::DatagramSocket dgs;
    dgs.bind(bsa);

    dgs.setBroadcast(_broadcast);
    dgs.setBlocking(false);
    cout << "UDP: Bound to " << _address << ":" <<_port_bind << ", Broadcast: " << _broadcast <<endl;
    cout << "UDP: Sending to " << _address << ":" <<_port_send <<endl;
    cout << "DEBUG: " << _debug << endl;

    mavlink_message_t message;
    mavlink_status_t status;
    
    uint8_t sendBuffer[100000];
    uint8_t receivedBuffer[100000];
    int len = 0;

    while(*_use) {
        //send udp
        if(_lock_tosend->tryLock()) {        
            if(!_tosend->empty()) {
                try {
                    message = _tosend->front();
                    len = mavlink_msg_to_send_buffer(sendBuffer, &message);
                    dgs.sendTo(sendBuffer, len, sa);
                    if(_debug) std::cout << "Sent: " << sendBuffer << std::endl;

                    _tosend->pop();
                    while(_tosend->size() > 300) _tosend->pop(); //Keep queue from getting too big
                    _lock_tosend->unlock();

                } catch (std::exception &e) {
                    _lock_tosend->tryLock();
                    _lock_tosend->unlock();
                    if(_debug) std::cout << "Exception: " << e.what() << std::endl;
                }

            } else {
                _lock_tosend->unlock();
                
            }
        }

        usleep(1000);
        
        //receive udp
        if(_lock_received->tryLock()) {        
            try {
                len = dgs.receiveBytes(&receivedBuffer, 100000);
                if(len > 0) {
                    for(int i = 0; i <= len; i++) {
                        if(mavlink_parse_char(4, receivedBuffer[i], &message, &status) > 0) {
                            _received->push(message);
                             if(_debug) std::cout << "GOT MESSAGE: " << message.msgid << std::endl;
                        }
                        if(status.packet_rx_drop_count > 0) {
                             if(_debug) std::cout << "ERROR: DROPPED: " << status.packet_rx_drop_count << std::endl;
                        }
                    }
                } else {
                }
            } catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
                _lock_received->tryLock();
                _lock_received->unlock();
            }
            _lock_received->unlock();
        }
        
        
    }
    std::cout << "UDPThread: CLOSED" << std::endl;
};

void MessageLoggingThread::run() {
    if (!*_use) return;
    //Check to make new file
    unsigned int file_tag = 0;
    std::ostringstream oss;

    oss << _address << file_tag << ".txt";
    while (std::ifstream(oss.str().c_str())) { //Check if file already exists
        file_tag++;
        oss.str("");
        oss.clear();
        oss << _address << file_tag << ".txt";
    }

    std::string message;

    int count = 0;

    FILE* pFile;
    pFile = fopen(oss.str().c_str(), "wb");

    while (*_use) {
        if(_lock->tryLock()) {
            if(!_tolog->empty()) {
                try {
                    message = _tolog->front();
                    if (pFile!=NULL) {
                        if(fwrite(message.c_str(), 1, strlen(message.c_str()), pFile)) {
                            fwrite("\n", sizeof(char), 1, pFile);
                            fflush(pFile);
                             if(_debug) std::cout << "WRITTEN TO FILE: " << count << " : " << message <<std::endl;
                             //std::cout << message << std::endl;
                            count++;
                            _tolog->pop();
                        } else {
                            //std::cout << message << std::endl;
                        }
                        
                    }
                    

                } catch (std::exception &e) {
                     if(_debug) std::cout << "Exception: " << e.what() << std::endl;
                }
            }
            while(_tolog->size() > 500) _tolog->pop(); //Keep queue from getting too big
            _lock->unlock();
        }
        usleep(5000);
    }
    fclose(pFile);
    //message_file.close();
     if(_debug) std::cout << "MessageLoggingThread: CLOSED" << std::endl;
};
