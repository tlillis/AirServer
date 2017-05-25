#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "serial_port.h"
#include <string>
//#include <sstream>


int mav_to_json(mavlink_message_t &message, std::string &json_message);

int json_to_mav(char * json_message);

#endif // CONVERSIONS
