#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "../include/filter.h"

#include "Poco/Util/IniFileConfiguration.h"
#include "Poco/AutoPtr.h"

#include <Poco/Util/AbstractConfiguration.h>
#include <Poco/Util/XMLConfiguration.h>

#include <queue>
#include <string>
#include <sstream>
#include <iostream>

using namespace Poco::Util;
using namespace std;

using Poco::AutoPtr;
using Poco::Util::IniFileConfiguration;

struct Initialization {

    Initialization();

    int load();
    void print();
        void end();

    bool read;
    std::ostringstream stream;
    int msg_id;
    int rate;
    int msg_set;
    int msg_all;

    int debug;

    int autopilot_use;
    int autopilot_debug;
    std::string autopilot_type;
    std::string autopilot_file;
    int autopilot_baud;
    int autopilot_sitl;

    int teensy_use;
    int teensy_debug;
    std::string teensy_file;
    int teensy_baud;

    int serial_out_use;
    int serial_out_debug;
    std::string serial_out_file;
    int serial_out_baud;

    int websocket_0_use;
    int websocket_0_debug;
    std::string websocket_0_address;
    int websocket_0_port;

    int websocket_1_use;
    int websocket_1_debug;
    std::string websocket_1_address;
    int websocket_1_port;

    int websocket_2_use;
    int websocket_2_debug;
    std::string websocket_2_address;
    int websocket_2_port;

    int udp_0_use;
    int udp_0_debug;
    int udp_0_broadcast;
    std::string udp_0_address;
    int udp_0_port_send;
    int udp_0_port_bind;

    int udp_1_use;
    int udp_1_debug;
    int udp_1_broadcast;
    std::string udp_1_address;
    int udp_1_port_send;
    int udp_1_port_bind;

    int udp_2_use;
    int udp_2_debug;
    int udp_2_broadcast;
    std::string udp_2_address;
    int udp_2_port_send;
    int udp_2_port_bind;

    int logging_0_use;
    int logging_0_debug;
    std::string logging_0_messages;
    std::string logging_0_errors;

    int logging_1_use;
    int logging_1_debug;
    std::string logging_1_messages;
    std::string logging_1_errors;

    Filter serial_out_filter;
    Filter udp_0_filter;
    Filter udp_1_filter;
    Filter udp_2_filter;
    Filter websocket_0_filter;
    Filter websocket_1_filter;
    Filter websocket_2_filter;
    Filter logging_0_filter;
    Filter logging_1_filter;
};

#endif // CONFIGURATION_H
