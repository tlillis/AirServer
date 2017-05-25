#include "../include/initialization.h"
#include "../include/filter.h"
#include <sstream>

Initialization::Initialization() {
    read = false; //mark values as not read
}


int Initialization::load() {
    
    AbstractConfiguration *cfg = new XMLConfiguration("config.xml");

    try {
        debug = cfg->getInt("debug");
        //Autopilot
        autopilot_use = cfg->getInt("autopilot.use");
        autopilot_debug = cfg->getInt("autopilot.debug");
        autopilot_file = cfg->getString("autopilot.file");
        autopilot_baud = cfg->getInt("autopilot.baud");
        autopilot_sitl = cfg->getInt("autopilot.sitl");
        msg_all = cfg->getInt("autopilot.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("autopilot.msg_set");

        for(int i = 0; i < msg_set; i++) {
            stream << "autopilot.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");
            stream.str("");
            stream.clear();
        }
        cout << "Got autopilot configuration..." << endl;

        //Teensy
        teensy_use = cfg->getInt("teensy.use");
        teensy_debug = cfg->getInt("teensy.debug");
        teensy_file = cfg->getString("teensy.file");
        teensy_baud = cfg->getInt("teensy.baud");
        msg_all = cfg->getInt("teensy.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("teensy.msg_set");

        for(int i = 0; i < msg_set; i++) {
            stream << "teensy.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");;
            stream.str("");
            stream.clear();
        }
        cout << "Got teensy configuration..." << endl;

        //Serial_out
        serial_out_use = cfg->getInt("serial_out.use");
        serial_out_debug = cfg->getInt("serial_out.debug");
        serial_out_file = cfg->getString("serial_out.file");
        serial_out_baud = cfg->getInt("serial_out.baud");
        msg_all = cfg->getInt("serial_out.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("serial_out.msg_set");

        serial_out_filter.set_all(msg_all);

        for(int i = 0; i < msg_set; i++) {
            stream << "serial_out.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");
            serial_out_filter.set(msg_id, rate);
            stream.str("");
            stream.clear();
        }
        cout << "Got serial_out configuration..." << endl;


        //Websocket
        websocket_0_use = cfg->getInt("websocket_0.use");
        websocket_0_debug = cfg->getInt("websocket_0.debug");
        websocket_0_address = cfg->getString("websocket_0.address");
        websocket_0_port = cfg->getInt("websocket_0.port");
        msg_all = cfg->getInt("websocket_0.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("websocket_0.msg_set");

        websocket_0_filter.set_all(msg_all);

        for(int i = 0; i < msg_set; i++) {
            stream << "websocket_0.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");
            websocket_0_filter.set(msg_id, rate);
            stream.str("");
            stream.clear();
        }

        websocket_1_use = cfg->getInt("websocket_1.use");
        websocket_1_debug = cfg->getInt("websocket_1.debug");
        websocket_1_address = cfg->getString("websocket_1.address");
        websocket_1_port = cfg->getInt("websocket_1.port");
        msg_all = cfg->getInt("websocket_1.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("websocket_1.msg_set");

        websocket_1_filter.set_all(msg_all);

        for(int i = 0; i < msg_set; i++) {
            stream << "websocket_1.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");
            websocket_1_filter.set(msg_id, rate);
            stream.str("");
            stream.clear();
        }

        websocket_2_use = cfg->getInt("websocket_2.use");
        websocket_2_debug = cfg->getInt("websocket_2.debug");
        websocket_2_address = cfg->getString("websocket_2.address");
        websocket_2_port = cfg->getInt("websocket_2.port");
        msg_all = cfg->getInt("websocket_2.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("websocket_2.msg_set");

        websocket_2_filter.set_all(msg_all);

        for(int i = 0; i < msg_set; i++) {
            stream << "websocket_2.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");
            websocket_2_filter.set(msg_id, rate);
            stream.str("");
            stream.clear();
        }
        cout << "Got websocket configuration..." << endl;

        //UDP
        udp_0_use = cfg->getInt("udp_0.use");
        udp_0_debug = cfg->getInt("udp_0.debug");
        udp_0_broadcast = cfg->getInt("udp_0.broadcast");
        udp_0_address = cfg->getString("udp_0.address");
        udp_0_port_send = cfg->getInt("udp_0.send_port");
        udp_0_port_bind = cfg->getInt("udp_0.bind_port");
        msg_all = cfg->getInt("udp_0.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("udp_0.msg_set");

        udp_0_filter.set_all(msg_all);

        for(int i = 0; i < msg_set; i++) {
            stream << "udp_0.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");
            udp_0_filter.set(msg_id, rate);
            stream.str("");
            stream.clear();
        }

        udp_1_use = cfg->getInt("udp_1.use");
        udp_1_debug = cfg->getInt("udp_1.debug");
        udp_1_broadcast = cfg->getInt("udp_1.broadcast");
        udp_1_address = cfg->getString("udp_1.address");
        udp_1_port_send = cfg->getInt("udp_1.send_port");
        udp_1_port_bind = cfg->getInt("udp_1.bind_port");
        msg_all = cfg->getInt("udp_1.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("udp_1.msg_set");

        udp_1_filter.set_all(msg_all);

        for(int i = 0; i < msg_set; i++) {
            stream << "udp_1.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");
            udp_1_filter.set(msg_id, rate);
            stream.str("");
            stream.clear();
        }

        udp_2_use = cfg->getInt("udp_2.use");
        udp_2_debug = cfg->getInt("udp_2.debug");
        udp_2_broadcast = cfg->getInt("udp_2.broadcast");
        udp_2_address = cfg->getString("udp_2.address");
        udp_2_port_send = cfg->getInt("udp_2.send_port");
        udp_2_port_bind = cfg->getInt("udp_2.bind_port");
        msg_all = cfg->getInt("udp_2.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("udp_2.msg_set");

        udp_2_filter.set_all(msg_all);

        for(int i = 0; i < msg_set; i++) {
            stream << "udp_2.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");
            udp_2_filter.set(msg_id, rate);
            stream.str("");
            stream.clear();
        }

        cout << "Got UDP configuration..." << endl;

        //Logging
        logging_0_use = cfg->getInt("logging_0.use");
        logging_0_debug = cfg->getInt("logging_0.debug");
        logging_0_messages = cfg->getString("logging_0.msg");
        logging_0_errors = cfg->getString("logging_0.errors");
        msg_all = cfg->getInt("logging_0.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("logging_0.msg_set");

        logging_0_filter.set_all(msg_all);

        for(int i = 0; i < msg_set; i++) {
            stream << "logging_0.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");
            logging_0_filter.set(msg_id, rate);
            stream.str("");
            stream.clear();
        }
        logging_0_filter.print_rate_all();

        logging_1_use = cfg->getInt("logging_1.use");
        logging_1_debug = cfg->getInt("logging_1.debug");
        logging_1_messages = cfg->getString("logging_1.msg");
        logging_1_errors = cfg->getString("logging_1.errors");
        msg_all = cfg->getInt("logging_1.msg_all");
        msg_set = 0;
        msg_set = cfg->getInt("logging_1.msg_set");

        logging_1_filter.set_all(msg_all);

        for(int i = 0; i < msg_set; i++) {
            stream << "logging_1.filter[" << i << "]";
            msg_id = cfg->getInt(stream.str() + ".id");
            rate = cfg->getInt(stream.str() + ".rate");
            logging_1_filter.set(msg_id, rate);
            stream.str("");
            stream.clear();
        }

        cout << "Got logging configuration..." << endl;
        //logging_filter.print_rate_all();
        cout << endl;

    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return -1;
    }
    
    read = true;
    return 0;
};

void Initialization::print() {

    if(read) {
        cout << "~~CONFIGURATION~~" << endl << endl;

        cout << "AUTOPILOT:" << endl;
        cout << "AutoPilot Port: " << autopilot_file << endl;
        cout << "AutoPilot Baud: " << autopilot_baud << endl;
        cout << "SITL: " << autopilot_sitl << endl << endl;

        cout << "TEENSY:" << endl;
        cout << "Teensy Port: " << teensy_file << endl;
        cout << "Teensy Baud Rate: " << teensy_baud << endl;

        cout << "Web Socket_0:" << endl;
        cout << "Address: " << websocket_0_address << endl;
        cout << "Port: " << websocket_0_port << endl << endl;

        cout << "Web Socket_1:" << endl;
        cout << "Address: " << websocket_1_address << endl;
        cout << "Port: " << websocket_1_port << endl << endl;

        cout << "Web Socket_2:" << endl;
        cout << "Address: " << websocket_2_address << endl;
        cout << "Port: " << websocket_2_port << endl << endl;

        cout << "UDP_0:" << endl;
        cout << "Address: " << udp_0_address << endl;
        cout << "Send Port: " << udp_0_port_send << endl;
        cout << "Bind Port: " << udp_0_port_bind << endl << endl;

        cout << "UDP_1:" << endl;
        cout << "Address: " << udp_1_address << endl;
        cout << "Send Port: " << udp_1_port_send << endl;
        cout << "Bind Port: " << udp_1_port_bind << endl << endl;

        cout << "UDP_2:" << endl;
        cout << "Address: " << udp_2_address << endl;
        cout << "Send Port: " << udp_2_port_send << endl;
        cout << "Bind Port: " << udp_2_port_bind << endl << endl;

        cout << "Logging_0:" << endl;
        cout << "Message File: " << logging_0_messages << endl;
        cout << "Error Log: " << logging_0_errors << endl << endl;

        cout << "Logging_1:" << endl;
        cout << "Message File: " << logging_0_messages << endl;
        cout << "Error Log: " << logging_0_errors << endl << endl;
    }
    return;
};

void Initialization::end() {
    websocket_0_use = 0;
    websocket_1_use = 0;
    websocket_2_use = 0;
    serial_out_use = 0;
    teensy_use = 0;
    autopilot_use = 0;
    udp_0_use = 0;
    udp_1_use = 0;
    udp_2_use = 0;
    logging_0_use = 0;
    logging_1_use = 0;
}