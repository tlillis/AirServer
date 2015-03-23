#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "serial_port.h"

int mav_to_json(mavlink_message_t &message);

int json_to_mav(char * json);

#endif // CONVERSIONS
