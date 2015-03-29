#include "../include/initialization.h"

Initialization::Initialization() {
    read = false; //mark values as not read
}


int Initialization::load() {
    try {
        AutoPtr<IniFileConfiguration> pConf(new IniFileConfiguration("airserver.ini"));

        autopilot_type = pConf->getString("autopilot.type");
        autopilot_file = pConf->getString("autopilot.file");
        autopilot_baud = pConf->getInt("autopilot.baud");
        autopilot_sitl = pConf->getInt("autopilot.sitl");

        teensy_file = pConf->getString("teensy.file");
        teensy_baud = pConf->getInt("teensy.baud");
        teensy_imu = pConf->getInt("teensy.imu");

        websocket_address = pConf->getString("websocket.address");
        websocket_port = pConf->getInt("websocket.port");

        udp_address = pConf->getString("udp.address");
        udp_port = pConf->getInt("udp.port");

        logging_messages = pConf->getString("logging.messages");
        logging_errors = pConf->getString("logging.errors");
    }
    catch (...) {
        return -1;
    }
    read = true;
    return 0;
};

void Initialization::print() {

    if(read) {
        cout << "~~CONFIGURATION~~" << endl << endl;

        cout << "AUTOPILOT:" << endl;
        cout << "AutoPilot Type: " << autopilot_type << endl;
        cout << "AutoPilot Port: " << autopilot_file << endl;
        cout << "AutoPilot Baud: " << autopilot_baud << endl;
        cout << "SITL: " << autopilot_sitl << endl << endl;

        cout << "TEENSY:" << endl;
        cout << "Teensy Port: " << teensy_file << endl;
        cout << "Teensy Baud Rate: " << teensy_baud << endl;
        cout << "Teensy IMU: " << teensy_imu << endl << endl;

        cout << "Web Socket:" << endl;
        cout << "Address: " << websocket_address << endl;
        cout << "Port: " << websocket_port << endl << endl;

        cout << "UDP:" << endl;
        cout << "Address: " << udp_address << endl;
        cout << "Port: " << udp_port << endl << endl;

        cout << "Logging:" << endl;
        cout << "Message File: " << logging_messages << endl;
        cout << "Error Log: " << logging_errors << endl << endl;
    }
    return;
};

