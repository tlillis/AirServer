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

class Initialization {
    private:

    public:
        Initialization();

        int load();
        void print();

        bool read;

        std::string autopilot_type;
        std::string autopilot_file;
        int autopilot_baud;
        int autopilot_sitl;

        std::string teensy_file;
        int teensy_baud;
        int teensy_imu;

        std::string websocket_address;
        int websocket_port;

        std::string udp_address;
        int udp_port;

        std::string logging_messages;
        std::string logging_errors;
};

#endif // CONFIGURATION_H
