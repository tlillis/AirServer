#include <iostream>
#include <queue>
#include <string>
#include <sstream>

#include "Poco/Util/IniFileConfiguration.h"
#include "Poco/AutoPtr.h"
#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadPool.h"
#include "Poco/RWLock.h"

#include "serialdata.h"
#include "serial_port.h"

using namespace std;
using Poco::AutoPtr;
using Poco::Util::IniFileConfiguration;
using Poco::SimpleFileChannel;
using Poco::Logger;
using Poco::FileChannel;

class AutopilotSerialThread : public Poco::Runnable{
private:
    int _id;
    Poco::RWLock * _lock;
    queue <mavlink_message_t> * _collector;
public:
    AutopilotSerialThread (int id, Poco::RWLock * lock, queue <mavlink_message_t> * collector) : _id(id), _lock(lock), _collector(collector) {}
    void run(){
        cout << "This is a test" << endl;
        mavlink_message_t message;
        char * port = "/dev/ttyAMC1";
        int baud = 115200;
        Serial_Port serial_port(port,baud);
        serial_port.start();
        sleep(1);
        while(true){

           _lock->writeLock(); //acquire lock
           serial_port.read_message(message);
           _collector->push(message);
           _lock->unlock();  //release lock
        }
    }
};

class AutopilotSITLThread : public Poco::Runnable{
private:
    int _id;
    Poco::RWLock * _lock;
    queue <mavlink_message_t> * _collector;
public:
    AutopilotSITLThread (int id, Poco::RWLock * lock, queue <mavlink_message_t> * collector) : _id(id), _lock(lock), _collector(collector) {}
    void run(){
        mavlink_message_t message;
        char * port = "127.0.0.1:14551";
        int baud = 115200;
        Serial_Port serial_port(port,baud);
        serial_port.start();
        while(true){
           _lock->writeLock(); //acquire lock
           serial_port.read_message(message);
           _collector->push(message);
           _lock->unlock();  //release lock
        }
    }
};

int main()
{
    cout << "Starting AirServer..." << endl << endl;

    //Get data from configuration file
    AutoPtr<IniFileConfiguration> pConf(new IniFileConfiguration("airserver.ini"));

    std::string autopilot_type = pConf->getString("autopilot.type");
    std::string autopilot_file = pConf->getString("autopilot.file");
    int autopilot_sitl = pConf->getInt("autopilot.sitl");

    std::string teensy_file = pConf->getString("teensy.file");
    int teensy_baud = pConf->getInt("teensy.baud");
    int teensy_imu = pConf->getInt("teensy.imu");

    cout << "~~CONFIGURATION~~" << endl << endl;

    cout << "AUTOPILOT:" << endl;
    cout << "AutoPilot Type: " << autopilot_type << endl;
    cout << "AutoPilot Port: " << autopilot_file << endl;
    cout << "SITL: " << autopilot_sitl << endl << endl;

    cout << "TEENSY:" << endl;
    cout << "Teensy Port: " << teensy_file << endl;
    cout << "Teensy Baud Rate: " << teensy_baud << endl;
    cout << "Teensy IMU: " << teensy_imu << endl << endl;


    //Create a queue for getting data between threads
    queue <mavlink_message_t> msg_queue_send;
    Poco::RWLock lock;

    Poco::ThreadPool pool;

    if (autopilot_sitl == 1)
    {
        cout << "Starting autopilot serial connection..." << endl;
        AutopilotSerialThread autopilot_thread(1, &lock, &msg_queue_send);
        pool.start(autopilot_thread);

    }



    /**
    else if (autopilot_sitl == 0)
    {
        cout << "Starting autopilot SITL connection..." << endl;
        AutopilotSITLThread autopilot_thread(1, &lock, &msg_queue_send);
        pool.start(autopilot_thread);
    }
    **/
    //else{
   //     cout << "Not connecting to an autopilot..." << endl;
  //  }

    mavlink_message_t message;

    while(!msg_queue_send.empty())
    {
        message = msg_queue_send.front();
        cout << message.sysid << endl;
        cout << message.compid << endl << endl;
        //std::cout << item;
        msg_queue_send.pop();
    }

    pool.joinAll();

    return 0;
}
