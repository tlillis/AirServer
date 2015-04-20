#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Poco/Util/IniFileConfiguration.h"
#include "Poco/AutoPtr.h"

#include <queue>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

using Poco::AutoPtr;
using Poco::Util::IniFileConfiguration;

struct Initialization {

    Initialization();

    int load();
    void print();
        void end();

    bool read;

    int autopilot_use;
    std::string autopilot_type;
    std::string autopilot_file;
    int autopilot_baud;
    int autopilot_sitl;

    int teensy_use;
    std::string teensy_file;
    int teensy_baud;
    int teensy_imu;

    int websocket_use;
    std::string websocket_address;
    int websocket_port;

    int udp_use;
    std::string udp_address;
    int udp_port;

    int logging_use;
    std::string logging_messages;
    std::string logging_errors;
};

#endif // CONFIGURATION_H
