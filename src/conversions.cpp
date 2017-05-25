// This file was created using AirServer tool "con_gen.py"
// Generated cpp code for converting mavlink to json
// This code was generated on 27/07/2015 at 01:43:25

#include "../include/conversions.h"
#include <string>
#include <sstream>

int mav_to_json(mavlink_message_t &message, std::string &json_message) {

    int msgid = message.msgid;
    int sysid = message.sysid;
    json_message.clear();

    std::ostringstream stream;

    switch (msgid) {
        case MAVLINK_MSG_ID_HEARTBEAT: 
            // msgid = 0
            // 
            mavlink_heartbeat_t heartbeat;
            mavlink_msg_heartbeat_decode(&message, &(heartbeat));
            stream << "{\"type\":\"HEARTBEAT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"type\":\"" << unsigned(heartbeat.type)
                << "\",\"autopilot\":\"" << unsigned(heartbeat.autopilot)
                << "\",\"base_mode\":\"" << unsigned(heartbeat.base_mode)
                << "\",\"custom_mode\":\"" << heartbeat.custom_mode
                << "\",\"system_status\":\"" << unsigned(heartbeat.system_status)
                << "\",\"mavlink_version\":\""                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SYS_STATUS: 
            // msgid = 1
            // 
            mavlink_sys_status_t sys_status;
            mavlink_msg_sys_status_decode(&message, &(sys_status));
            stream << "{\"type\":\"SYS_STATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"onboard_control_sensors_present\":\"" << sys_status.onboard_control_sensors_present
                << "\",\"onboard_control_sensors_enabled\":\"" << sys_status.onboard_control_sensors_enabled
                << "\",\"onboard_control_sensors_health\":\"" << sys_status.onboard_control_sensors_health
                << "\",\"load\":\"" << sys_status.load
                << "\",\"voltage_battery\":\"" << sys_status.voltage_battery
                << "\",\"current_battery\":\"" << sys_status.current_battery
                << "\",\"battery_remaining\":\"" << sys_status.battery_remaining
                << "\",\"drop_rate_comm\":\"" << sys_status.drop_rate_comm
                << "\",\"errors_comm\":\"" << sys_status.errors_comm
                << "\",\"errors_count1\":\"" << sys_status.errors_count1
                << "\",\"errors_count2\":\"" << sys_status.errors_count2
                << "\",\"errors_count3\":\"" << sys_status.errors_count3
                << "\",\"errors_count4\":\"" << sys_status.errors_count4
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SYSTEM_TIME: 
            // msgid = 2
            // 
            mavlink_system_time_t system_time;
            mavlink_msg_system_time_decode(&message, &(system_time));
            stream << "{\"type\":\"SYSTEM_TIME"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_unix_usec\":\"" << system_time.time_unix_usec
                << "\",\"time_boot_ms\":\"" << system_time.time_boot_ms
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PING: 
            // msgid = 4
            // 
            mavlink_ping_t ping;
            mavlink_msg_ping_decode(&message, &(ping));
            stream << "{\"type\":\"PING"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << ping.time_usec
                << "\",\"seq\":\"" << ping.seq
                << "\",\"target_system\":\"" << unsigned(ping.target_system)
                << "\",\"target_component\":\"" << unsigned(ping.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL: 
            // msgid = 5
            // 
            mavlink_change_operator_control_t change_operator_control;
            mavlink_msg_change_operator_control_decode(&message, &(change_operator_control));
            stream << "{\"type\":\"CHANGE_OPERATOR_CONTROL"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(change_operator_control.target_system)
                << "\",\"control_request\":\"" << unsigned(change_operator_control.control_request)
                << "\",\"version\":\"" << unsigned(change_operator_control.version)
                << "\",\"passkey\":\"" << change_operator_control.passkey
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK: 
            // msgid = 6
            // 
            mavlink_change_operator_control_ack_t change_operator_control_ack;
            mavlink_msg_change_operator_control_ack_decode(&message, &(change_operator_control_ack));
            stream << "{\"type\":\"CHANGE_OPERATOR_CONTROL_ACK"
                << "\",\"system_id\":\"" << sysid
                << "\",\"gcs_system_id\":\"" << unsigned(change_operator_control_ack.gcs_system_id)
                << "\",\"control_request\":\"" << unsigned(change_operator_control_ack.control_request)
                << "\",\"ack\":\"" << unsigned(change_operator_control_ack.ack)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AUTH_KEY: 
            // msgid = 7
            // 
            mavlink_auth_key_t auth_key;
            mavlink_msg_auth_key_decode(&message, &(auth_key));
            stream << "{\"type\":\"AUTH_KEY"
                << "\",\"system_id\":\"" << sysid
                << "\",\"key\":\"" << auth_key.key
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_MODE: 
            // msgid = 11
            // 
            mavlink_set_mode_t set_mode;
            mavlink_msg_set_mode_decode(&message, &(set_mode));
            stream << "{\"type\":\"SET_MODE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(set_mode.target_system)
                << "\",\"base_mode\":\"" << unsigned(set_mode.base_mode)
                << "\",\"custom_mode\":\"" << set_mode.custom_mode
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PARAM_REQUEST_READ: 
            // msgid = 20
            // 
            mavlink_param_request_read_t param_request_read;
            mavlink_msg_param_request_read_decode(&message, &(param_request_read));
            stream << "{\"type\":\"PARAM_REQUEST_READ"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(param_request_read.target_system)
                << "\",\"target_component\":\"" << unsigned(param_request_read.target_component)
                << "\",\"param_id\":\"" << param_request_read.param_id
                << "\",\"param_index\":\"" << param_request_read.param_index
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PARAM_REQUEST_LIST: 
            // msgid = 21
            // 
            mavlink_param_request_list_t param_request_list;
            mavlink_msg_param_request_list_decode(&message, &(param_request_list));
            stream << "{\"type\":\"PARAM_REQUEST_LIST"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(param_request_list.target_system)
                << "\",\"target_component\":\"" << unsigned(param_request_list.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PARAM_VALUE: 
            // msgid = 22
            // 
            mavlink_param_value_t param_value;
            mavlink_msg_param_value_decode(&message, &(param_value));
            stream << "{\"type\":\"PARAM_VALUE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"param_id\":\"" << param_value.param_id
                << "\",\"param_value\":\"" << param_value.param_value
                << "\",\"param_type\":\"" << unsigned(param_value.param_type)
                << "\",\"param_count\":\"" << param_value.param_count
                << "\",\"param_index\":\"" << param_value.param_index
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PARAM_SET: 
            // msgid = 23
            // 
            mavlink_param_set_t param_set;
            mavlink_msg_param_set_decode(&message, &(param_set));
            stream << "{\"type\":\"PARAM_SET"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(param_set.target_system)
                << "\",\"target_component\":\"" << unsigned(param_set.target_component)
                << "\",\"param_id\":\"" << param_set.param_id
                << "\",\"param_value\":\"" << param_set.param_value
                << "\",\"param_type\":\"" << unsigned(param_set.param_type)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS_RAW_INT: 
            // msgid = 24
            // 
            mavlink_gps_raw_int_t gps_raw_int;
            mavlink_msg_gps_raw_int_decode(&message, &(gps_raw_int));
            stream << "{\"type\":\"GPS_RAW_INT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << gps_raw_int.time_usec
                << "\",\"fix_type\":\"" << unsigned(gps_raw_int.fix_type)
                << "\",\"lat\":\"" << gps_raw_int.lat
                << "\",\"lon\":\"" << gps_raw_int.lon
                << "\",\"alt\":\"" << gps_raw_int.alt
                << "\",\"eph\":\"" << gps_raw_int.eph
                << "\",\"epv\":\"" << gps_raw_int.epv
                << "\",\"vel\":\"" << gps_raw_int.vel
                << "\",\"cog\":\"" << gps_raw_int.cog
                << "\",\"satellites_visible\":\"" << unsigned(gps_raw_int.satellites_visible)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS_STATUS: 
            // msgid = 25
            // 
            mavlink_gps_status_t gps_status;
            mavlink_msg_gps_status_decode(&message, &(gps_status));
            stream << "{\"type\":\"GPS_STATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"satellites_visible\":\"" << unsigned(gps_status.satellites_visible)
                << "\",\"satellite_prn\":\"" << gps_status.satellite_prn
                << "\",\"satellite_used\":\"" << gps_status.satellite_used
                << "\",\"satellite_elevation\":\"" << gps_status.satellite_elevation
                << "\",\"satellite_azimuth\":\"" << gps_status.satellite_azimuth
                << "\",\"satellite_snr\":\"" << gps_status.satellite_snr
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SCALED_IMU: 
            // msgid = 26
            // 
            mavlink_scaled_imu_t scaled_imu;
            mavlink_msg_scaled_imu_decode(&message, &(scaled_imu));
            stream << "{\"type\":\"SCALED_IMU"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << scaled_imu.time_boot_ms
                << "\",\"xacc\":\"" << scaled_imu.xacc
                << "\",\"yacc\":\"" << scaled_imu.yacc
                << "\",\"zacc\":\"" << scaled_imu.zacc
                << "\",\"xgyro\":\"" << scaled_imu.xgyro
                << "\",\"ygyro\":\"" << scaled_imu.ygyro
                << "\",\"zgyro\":\"" << scaled_imu.zgyro
                << "\",\"xmag\":\"" << scaled_imu.xmag
                << "\",\"ymag\":\"" << scaled_imu.ymag
                << "\",\"zmag\":\"" << scaled_imu.zmag
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RAW_IMU: 
            // msgid = 27
            // 
            mavlink_raw_imu_t raw_imu;
            mavlink_msg_raw_imu_decode(&message, &(raw_imu));
            stream << "{\"type\":\"RAW_IMU"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << raw_imu.time_usec
                << "\",\"xacc\":\"" << raw_imu.xacc
                << "\",\"yacc\":\"" << raw_imu.yacc
                << "\",\"zacc\":\"" << raw_imu.zacc
                << "\",\"xgyro\":\"" << raw_imu.xgyro
                << "\",\"ygyro\":\"" << raw_imu.ygyro
                << "\",\"zgyro\":\"" << raw_imu.zgyro
                << "\",\"xmag\":\"" << raw_imu.xmag
                << "\",\"ymag\":\"" << raw_imu.ymag
                << "\",\"zmag\":\"" << raw_imu.zmag
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RAW_PRESSURE: 
            // msgid = 28
            // 
            mavlink_raw_pressure_t raw_pressure;
            mavlink_msg_raw_pressure_decode(&message, &(raw_pressure));
            stream << "{\"type\":\"RAW_PRESSURE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << raw_pressure.time_usec
                << "\",\"press_abs\":\"" << raw_pressure.press_abs
                << "\",\"press_diff1\":\"" << raw_pressure.press_diff1
                << "\",\"press_diff2\":\"" << raw_pressure.press_diff2
                << "\",\"temperature\":\"" << raw_pressure.temperature
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SCALED_PRESSURE: 
            // msgid = 29
            // 
            mavlink_scaled_pressure_t scaled_pressure;
            mavlink_msg_scaled_pressure_decode(&message, &(scaled_pressure));
            stream << "{\"type\":\"SCALED_PRESSURE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << scaled_pressure.time_boot_ms
                << "\",\"press_abs\":\"" << scaled_pressure.press_abs
                << "\",\"press_diff\":\"" << scaled_pressure.press_diff
                << "\",\"temperature\":\"" << scaled_pressure.temperature
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ATTITUDE: 
            // msgid = 30
            // 
            mavlink_attitude_t attitude;
            mavlink_msg_attitude_decode(&message, &(attitude));
            stream << "{\"type\":\"ATTITUDE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << attitude.time_boot_ms
                << "\",\"roll\":\"" << attitude.roll
                << "\",\"pitch\":\"" << attitude.pitch
                << "\",\"yaw\":\"" << attitude.yaw
                << "\",\"rollspeed\":\"" << attitude.rollspeed
                << "\",\"pitchspeed\":\"" << attitude.pitchspeed
                << "\",\"yawspeed\":\"" << attitude.yawspeed
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ATTITUDE_QUATERNION: 
            // msgid = 31
            // 
            mavlink_attitude_quaternion_t attitude_quaternion;
            mavlink_msg_attitude_quaternion_decode(&message, &(attitude_quaternion));
            stream << "{\"type\":\"ATTITUDE_QUATERNION"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << attitude_quaternion.time_boot_ms
                << "\",\"q1\":\"" << attitude_quaternion.q1
                << "\",\"q2\":\"" << attitude_quaternion.q2
                << "\",\"q3\":\"" << attitude_quaternion.q3
                << "\",\"q4\":\"" << attitude_quaternion.q4
                << "\",\"rollspeed\":\"" << attitude_quaternion.rollspeed
                << "\",\"pitchspeed\":\"" << attitude_quaternion.pitchspeed
                << "\",\"yawspeed\":\"" << attitude_quaternion.yawspeed
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOCAL_POSITION_NED: 
            // msgid = 32
            // 
            mavlink_local_position_ned_t local_position_ned;
            mavlink_msg_local_position_ned_decode(&message, &(local_position_ned));
            stream << "{\"type\":\"LOCAL_POSITION_NED"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << local_position_ned.time_boot_ms
                << "\",\"x\":\"" << local_position_ned.x
                << "\",\"y\":\"" << local_position_ned.y
                << "\",\"z\":\"" << local_position_ned.z
                << "\",\"vx\":\"" << local_position_ned.vx
                << "\",\"vy\":\"" << local_position_ned.vy
                << "\",\"vz\":\"" << local_position_ned.vz
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT: 
            // msgid = 33
            // 
            mavlink_global_position_int_t global_position_int;
            mavlink_msg_global_position_int_decode(&message, &(global_position_int));
            stream << "{\"type\":\"GLOBAL_POSITION_INT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << global_position_int.time_boot_ms
                << "\",\"lat\":\"" << global_position_int.lat
                << "\",\"lon\":\"" << global_position_int.lon
                << "\",\"alt\":\"" << global_position_int.alt
                << "\",\"relative_alt\":\"" << global_position_int.relative_alt
                << "\",\"vx\":\"" << global_position_int.vx
                << "\",\"vy\":\"" << global_position_int.vy
                << "\",\"vz\":\"" << global_position_int.vz
                << "\",\"hdg\":\"" << global_position_int.hdg
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RC_CHANNELS_SCALED: 
            // msgid = 34
            // 
            mavlink_rc_channels_scaled_t rc_channels_scaled;
            mavlink_msg_rc_channels_scaled_decode(&message, &(rc_channels_scaled));
            stream << "{\"type\":\"RC_CHANNELS_SCALED"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << rc_channels_scaled.time_boot_ms
                << "\",\"port\":\"" << unsigned(rc_channels_scaled.port)
                << "\",\"chan1_scaled\":\"" << rc_channels_scaled.chan1_scaled
                << "\",\"chan2_scaled\":\"" << rc_channels_scaled.chan2_scaled
                << "\",\"chan3_scaled\":\"" << rc_channels_scaled.chan3_scaled
                << "\",\"chan4_scaled\":\"" << rc_channels_scaled.chan4_scaled
                << "\",\"chan5_scaled\":\"" << rc_channels_scaled.chan5_scaled
                << "\",\"chan6_scaled\":\"" << rc_channels_scaled.chan6_scaled
                << "\",\"chan7_scaled\":\"" << rc_channels_scaled.chan7_scaled
                << "\",\"chan8_scaled\":\"" << rc_channels_scaled.chan8_scaled
                << "\",\"rssi\":\"" << unsigned(rc_channels_scaled.rssi)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RC_CHANNELS_RAW: 
            // msgid = 35
            // 
            mavlink_rc_channels_raw_t rc_channels_raw;
            mavlink_msg_rc_channels_raw_decode(&message, &(rc_channels_raw));
            stream << "{\"type\":\"RC_CHANNELS_RAW"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << rc_channels_raw.time_boot_ms
                << "\",\"port\":\"" << unsigned(rc_channels_raw.port)
                << "\",\"chan1_raw\":\"" << rc_channels_raw.chan1_raw
                << "\",\"chan2_raw\":\"" << rc_channels_raw.chan2_raw
                << "\",\"chan3_raw\":\"" << rc_channels_raw.chan3_raw
                << "\",\"chan4_raw\":\"" << rc_channels_raw.chan4_raw
                << "\",\"chan5_raw\":\"" << rc_channels_raw.chan5_raw
                << "\",\"chan6_raw\":\"" << rc_channels_raw.chan6_raw
                << "\",\"chan7_raw\":\"" << rc_channels_raw.chan7_raw
                << "\",\"chan8_raw\":\"" << rc_channels_raw.chan8_raw
                << "\",\"rssi\":\"" << unsigned(rc_channels_raw.rssi)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW: 
            // msgid = 36
            // 
            mavlink_servo_output_raw_t servo_output_raw;
            mavlink_msg_servo_output_raw_decode(&message, &(servo_output_raw));
            stream << "{\"type\":\"SERVO_OUTPUT_RAW"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << servo_output_raw.time_usec
                << "\",\"port\":\"" << unsigned(servo_output_raw.port)
                << "\",\"servo1_raw\":\"" << servo_output_raw.servo1_raw
                << "\",\"servo2_raw\":\"" << servo_output_raw.servo2_raw
                << "\",\"servo3_raw\":\"" << servo_output_raw.servo3_raw
                << "\",\"servo4_raw\":\"" << servo_output_raw.servo4_raw
                << "\",\"servo5_raw\":\"" << servo_output_raw.servo5_raw
                << "\",\"servo6_raw\":\"" << servo_output_raw.servo6_raw
                << "\",\"servo7_raw\":\"" << servo_output_raw.servo7_raw
                << "\",\"servo8_raw\":\"" << servo_output_raw.servo8_raw
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST: 
            // msgid = 37
            // 
            mavlink_mission_request_partial_list_t mission_request_partial_list;
            mavlink_msg_mission_request_partial_list_decode(&message, &(mission_request_partial_list));
            stream << "{\"type\":\"MISSION_REQUEST_PARTIAL_LIST"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mission_request_partial_list.target_system)
                << "\",\"target_component\":\"" << unsigned(mission_request_partial_list.target_component)
                << "\",\"start_index\":\"" << mission_request_partial_list.start_index
                << "\",\"end_index\":\"" << mission_request_partial_list.end_index
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST: 
            // msgid = 38
            // 
            mavlink_mission_write_partial_list_t mission_write_partial_list;
            mavlink_msg_mission_write_partial_list_decode(&message, &(mission_write_partial_list));
            stream << "{\"type\":\"MISSION_WRITE_PARTIAL_LIST"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mission_write_partial_list.target_system)
                << "\",\"target_component\":\"" << unsigned(mission_write_partial_list.target_component)
                << "\",\"start_index\":\"" << mission_write_partial_list.start_index
                << "\",\"end_index\":\"" << mission_write_partial_list.end_index
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_ITEM: 
            // msgid = 39
            // 
            mavlink_mission_item_t mission_item;
            mavlink_msg_mission_item_decode(&message, &(mission_item));
            stream << "{\"type\":\"MISSION_ITEM"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mission_item.target_system)
                << "\",\"target_component\":\"" << unsigned(mission_item.target_component)
                << "\",\"seq\":\"" << mission_item.seq
                << "\",\"frame\":\"" << unsigned(mission_item.frame)
                << "\",\"command\":\"" << mission_item.command
                << "\",\"current\":\"" << unsigned(mission_item.current)
                << "\",\"autocontinue\":\"" << unsigned(mission_item.autocontinue)
                << "\",\"param1\":\"" << mission_item.param1
                << "\",\"param2\":\"" << mission_item.param2
                << "\",\"param3\":\"" << mission_item.param3
                << "\",\"param4\":\"" << mission_item.param4
                << "\",\"x\":\"" << mission_item.x
                << "\",\"y\":\"" << mission_item.y
                << "\",\"z\":\"" << mission_item.z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_REQUEST: 
            // msgid = 40
            // 
            mavlink_mission_request_t mission_request;
            mavlink_msg_mission_request_decode(&message, &(mission_request));
            stream << "{\"type\":\"MISSION_REQUEST"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mission_request.target_system)
                << "\",\"target_component\":\"" << unsigned(mission_request.target_component)
                << "\",\"seq\":\"" << mission_request.seq
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_SET_CURRENT: 
            // msgid = 41
            // 
            mavlink_mission_set_current_t mission_set_current;
            mavlink_msg_mission_set_current_decode(&message, &(mission_set_current));
            stream << "{\"type\":\"MISSION_SET_CURRENT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mission_set_current.target_system)
                << "\",\"target_component\":\"" << unsigned(mission_set_current.target_component)
                << "\",\"seq\":\"" << mission_set_current.seq
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_CURRENT: 
            // msgid = 42
            // 
            mavlink_mission_current_t mission_current;
            mavlink_msg_mission_current_decode(&message, &(mission_current));
            stream << "{\"type\":\"MISSION_CURRENT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"seq\":\"" << mission_current.seq
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_REQUEST_LIST: 
            // msgid = 43
            // 
            mavlink_mission_request_list_t mission_request_list;
            mavlink_msg_mission_request_list_decode(&message, &(mission_request_list));
            stream << "{\"type\":\"MISSION_REQUEST_LIST"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mission_request_list.target_system)
                << "\",\"target_component\":\"" << unsigned(mission_request_list.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_COUNT: 
            // msgid = 44
            // 
            mavlink_mission_count_t mission_count;
            mavlink_msg_mission_count_decode(&message, &(mission_count));
            stream << "{\"type\":\"MISSION_COUNT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mission_count.target_system)
                << "\",\"target_component\":\"" << unsigned(mission_count.target_component)
                << "\",\"count\":\"" << mission_count.count
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_CLEAR_ALL: 
            // msgid = 45
            // 
            mavlink_mission_clear_all_t mission_clear_all;
            mavlink_msg_mission_clear_all_decode(&message, &(mission_clear_all));
            stream << "{\"type\":\"MISSION_CLEAR_ALL"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mission_clear_all.target_system)
                << "\",\"target_component\":\"" << unsigned(mission_clear_all.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_ITEM_REACHED: 
            // msgid = 46
            // 
            mavlink_mission_item_reached_t mission_item_reached;
            mavlink_msg_mission_item_reached_decode(&message, &(mission_item_reached));
            stream << "{\"type\":\"MISSION_ITEM_REACHED"
                << "\",\"system_id\":\"" << sysid
                << "\",\"seq\":\"" << mission_item_reached.seq
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_ACK: 
            // msgid = 47
            // 
            mavlink_mission_ack_t mission_ack;
            mavlink_msg_mission_ack_decode(&message, &(mission_ack));
            stream << "{\"type\":\"MISSION_ACK"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mission_ack.target_system)
                << "\",\"target_component\":\"" << unsigned(mission_ack.target_component)
                << "\",\"type\":\"" << unsigned(mission_ack.type)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN: 
            // msgid = 48
            // 
            mavlink_set_gps_global_origin_t set_gps_global_origin;
            mavlink_msg_set_gps_global_origin_decode(&message, &(set_gps_global_origin));
            stream << "{\"type\":\"SET_GPS_GLOBAL_ORIGIN"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(set_gps_global_origin.target_system)
                << "\",\"latitude\":\"" << set_gps_global_origin.latitude
                << "\",\"longitude\":\"" << set_gps_global_origin.longitude
                << "\",\"altitude\":\"" << set_gps_global_origin.altitude
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN: 
            // msgid = 49
            // 
            mavlink_gps_global_origin_t gps_global_origin;
            mavlink_msg_gps_global_origin_decode(&message, &(gps_global_origin));
            stream << "{\"type\":\"GPS_GLOBAL_ORIGIN"
                << "\",\"system_id\":\"" << sysid
                << "\",\"latitude\":\"" << gps_global_origin.latitude
                << "\",\"longitude\":\"" << gps_global_origin.longitude
                << "\",\"altitude\":\"" << gps_global_origin.altitude
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PARAM_MAP_RC: 
            // msgid = 50
            // 
            mavlink_param_map_rc_t param_map_rc;
            mavlink_msg_param_map_rc_decode(&message, &(param_map_rc));
            stream << "{\"type\":\"PARAM_MAP_RC"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(param_map_rc.target_system)
                << "\",\"target_component\":\"" << unsigned(param_map_rc.target_component)
                << "\",\"param_id\":\"" << param_map_rc.param_id
                << "\",\"param_index\":\"" << param_map_rc.param_index
                << "\",\"parameter_rc_channel_index\":\"" << unsigned(param_map_rc.parameter_rc_channel_index)
                << "\",\"param_value0\":\"" << param_map_rc.param_value0
                << "\",\"scale\":\"" << param_map_rc.scale
                << "\",\"param_value_min\":\"" << param_map_rc.param_value_min
                << "\",\"param_value_max\":\"" << param_map_rc.param_value_max
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA: 
            // msgid = 54
            // 
            mavlink_safety_set_allowed_area_t safety_set_allowed_area;
            mavlink_msg_safety_set_allowed_area_decode(&message, &(safety_set_allowed_area));
            stream << "{\"type\":\"SAFETY_SET_ALLOWED_AREA"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(safety_set_allowed_area.target_system)
                << "\",\"target_component\":\"" << unsigned(safety_set_allowed_area.target_component)
                << "\",\"frame\":\"" << unsigned(safety_set_allowed_area.frame)
                << "\",\"p1x\":\"" << safety_set_allowed_area.p1x
                << "\",\"p1y\":\"" << safety_set_allowed_area.p1y
                << "\",\"p1z\":\"" << safety_set_allowed_area.p1z
                << "\",\"p2x\":\"" << safety_set_allowed_area.p2x
                << "\",\"p2y\":\"" << safety_set_allowed_area.p2y
                << "\",\"p2z\":\"" << safety_set_allowed_area.p2z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA: 
            // msgid = 55
            // 
            mavlink_safety_allowed_area_t safety_allowed_area;
            mavlink_msg_safety_allowed_area_decode(&message, &(safety_allowed_area));
            stream << "{\"type\":\"SAFETY_ALLOWED_AREA"
                << "\",\"system_id\":\"" << sysid
                << "\",\"frame\":\"" << unsigned(safety_allowed_area.frame)
                << "\",\"p1x\":\"" << safety_allowed_area.p1x
                << "\",\"p1y\":\"" << safety_allowed_area.p1y
                << "\",\"p1z\":\"" << safety_allowed_area.p1z
                << "\",\"p2x\":\"" << safety_allowed_area.p2x
                << "\",\"p2y\":\"" << safety_allowed_area.p2y
                << "\",\"p2z\":\"" << safety_allowed_area.p2z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ATTITUDE_QUATERNION_COV: 
            // msgid = 61
            // 
            mavlink_attitude_quaternion_cov_t attitude_quaternion_cov;
            mavlink_msg_attitude_quaternion_cov_decode(&message, &(attitude_quaternion_cov));
            stream << "{\"type\":\"ATTITUDE_QUATERNION_COV"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << attitude_quaternion_cov.time_boot_ms
                << "\",\"q\":\"" << attitude_quaternion_cov.q
                << "\",\"rollspeed\":\"" << attitude_quaternion_cov.rollspeed
                << "\",\"pitchspeed\":\"" << attitude_quaternion_cov.pitchspeed
                << "\",\"yawspeed\":\"" << attitude_quaternion_cov.yawspeed
                << "\",\"covariance\":\"" << attitude_quaternion_cov.covariance
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT: 
            // msgid = 62
            // 
            mavlink_nav_controller_output_t nav_controller_output;
            mavlink_msg_nav_controller_output_decode(&message, &(nav_controller_output));
            stream << "{\"type\":\"NAV_CONTROLLER_OUTPUT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"nav_roll\":\"" << nav_controller_output.nav_roll
                << "\",\"nav_pitch\":\"" << nav_controller_output.nav_pitch
                << "\",\"nav_bearing\":\"" << nav_controller_output.nav_bearing
                << "\",\"target_bearing\":\"" << nav_controller_output.target_bearing
                << "\",\"wp_dist\":\"" << nav_controller_output.wp_dist
                << "\",\"alt_error\":\"" << nav_controller_output.alt_error
                << "\",\"aspd_error\":\"" << nav_controller_output.aspd_error
                << "\",\"xtrack_error\":\"" << nav_controller_output.xtrack_error
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT_COV: 
            // msgid = 63
            // 
            mavlink_global_position_int_cov_t global_position_int_cov;
            mavlink_msg_global_position_int_cov_decode(&message, &(global_position_int_cov));
            stream << "{\"type\":\"GLOBAL_POSITION_INT_COV"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << global_position_int_cov.time_boot_ms
                << "\",\"time_utc\":\"" << global_position_int_cov.time_utc
                << "\",\"estimator_type\":\"" << unsigned(global_position_int_cov.estimator_type)
                << "\",\"lat\":\"" << global_position_int_cov.lat
                << "\",\"lon\":\"" << global_position_int_cov.lon
                << "\",\"alt\":\"" << global_position_int_cov.alt
                << "\",\"relative_alt\":\"" << global_position_int_cov.relative_alt
                << "\",\"vx\":\"" << global_position_int_cov.vx
                << "\",\"vy\":\"" << global_position_int_cov.vy
                << "\",\"vz\":\"" << global_position_int_cov.vz
                << "\",\"covariance\":\"" << global_position_int_cov.covariance
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOCAL_POSITION_NED_COV: 
            // msgid = 64
            // 
            mavlink_local_position_ned_cov_t local_position_ned_cov;
            mavlink_msg_local_position_ned_cov_decode(&message, &(local_position_ned_cov));
            stream << "{\"type\":\"LOCAL_POSITION_NED_COV"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << local_position_ned_cov.time_boot_ms
                << "\",\"time_utc\":\"" << local_position_ned_cov.time_utc
                << "\",\"estimator_type\":\"" << unsigned(local_position_ned_cov.estimator_type)
                << "\",\"x\":\"" << local_position_ned_cov.x
                << "\",\"y\":\"" << local_position_ned_cov.y
                << "\",\"z\":\"" << local_position_ned_cov.z
                << "\",\"vx\":\"" << local_position_ned_cov.vx
                << "\",\"vy\":\"" << local_position_ned_cov.vy
                << "\",\"vz\":\"" << local_position_ned_cov.vz
                << "\",\"covariance\":\"" << local_position_ned_cov.covariance
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RC_CHANNELS: 
            // msgid = 65
            // 
            mavlink_rc_channels_t rc_channels;
            mavlink_msg_rc_channels_decode(&message, &(rc_channels));
            stream << "{\"type\":\"RC_CHANNELS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << rc_channels.time_boot_ms
                << "\",\"chancount\":\"" << unsigned(rc_channels.chancount)
                << "\",\"chan1_raw\":\"" << rc_channels.chan1_raw
                << "\",\"chan2_raw\":\"" << rc_channels.chan2_raw
                << "\",\"chan3_raw\":\"" << rc_channels.chan3_raw
                << "\",\"chan4_raw\":\"" << rc_channels.chan4_raw
                << "\",\"chan5_raw\":\"" << rc_channels.chan5_raw
                << "\",\"chan6_raw\":\"" << rc_channels.chan6_raw
                << "\",\"chan7_raw\":\"" << rc_channels.chan7_raw
                << "\",\"chan8_raw\":\"" << rc_channels.chan8_raw
                << "\",\"chan9_raw\":\"" << rc_channels.chan9_raw
                << "\",\"chan10_raw\":\"" << rc_channels.chan10_raw
                << "\",\"chan11_raw\":\"" << rc_channels.chan11_raw
                << "\",\"chan12_raw\":\"" << rc_channels.chan12_raw
                << "\",\"chan13_raw\":\"" << rc_channels.chan13_raw
                << "\",\"chan14_raw\":\"" << rc_channels.chan14_raw
                << "\",\"chan15_raw\":\"" << rc_channels.chan15_raw
                << "\",\"chan16_raw\":\"" << rc_channels.chan16_raw
                << "\",\"chan17_raw\":\"" << rc_channels.chan17_raw
                << "\",\"chan18_raw\":\"" << rc_channels.chan18_raw
                << "\",\"rssi\":\"" << unsigned(rc_channels.rssi)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_REQUEST_DATA_STREAM: 
            // msgid = 66
            // 
            mavlink_request_data_stream_t request_data_stream;
            mavlink_msg_request_data_stream_decode(&message, &(request_data_stream));
            stream << "{\"type\":\"REQUEST_DATA_STREAM"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(request_data_stream.target_system)
                << "\",\"target_component\":\"" << unsigned(request_data_stream.target_component)
                << "\",\"req_stream_id\":\"" << unsigned(request_data_stream.req_stream_id)
                << "\",\"req_message_rate\":\"" << request_data_stream.req_message_rate
                << "\",\"start_stop\":\"" << unsigned(request_data_stream.start_stop)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DATA_STREAM: 
            // msgid = 67
            // 
            mavlink_data_stream_t data_stream;
            mavlink_msg_data_stream_decode(&message, &(data_stream));
            stream << "{\"type\":\"DATA_STREAM"
                << "\",\"system_id\":\"" << sysid
                << "\",\"stream_id\":\"" << unsigned(data_stream.stream_id)
                << "\",\"message_rate\":\"" << data_stream.message_rate
                << "\",\"on_off\":\"" << unsigned(data_stream.on_off)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MANUAL_CONTROL: 
            // msgid = 69
            // 
            mavlink_manual_control_t manual_control;
            mavlink_msg_manual_control_decode(&message, &(manual_control));
            stream << "{\"type\":\"MANUAL_CONTROL"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target\":\"" << unsigned(manual_control.target)
                << "\",\"x\":\"" << manual_control.x
                << "\",\"y\":\"" << manual_control.y
                << "\",\"z\":\"" << manual_control.z
                << "\",\"r\":\"" << manual_control.r
                << "\",\"buttons\":\"" << manual_control.buttons
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE: 
            // msgid = 70
            // 
            mavlink_rc_channels_override_t rc_channels_override;
            mavlink_msg_rc_channels_override_decode(&message, &(rc_channels_override));
            stream << "{\"type\":\"RC_CHANNELS_OVERRIDE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(rc_channels_override.target_system)
                << "\",\"target_component\":\"" << unsigned(rc_channels_override.target_component)
                << "\",\"chan1_raw\":\"" << rc_channels_override.chan1_raw
                << "\",\"chan2_raw\":\"" << rc_channels_override.chan2_raw
                << "\",\"chan3_raw\":\"" << rc_channels_override.chan3_raw
                << "\",\"chan4_raw\":\"" << rc_channels_override.chan4_raw
                << "\",\"chan5_raw\":\"" << rc_channels_override.chan5_raw
                << "\",\"chan6_raw\":\"" << rc_channels_override.chan6_raw
                << "\",\"chan7_raw\":\"" << rc_channels_override.chan7_raw
                << "\",\"chan8_raw\":\"" << rc_channels_override.chan8_raw
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_ITEM_INT: 
            // msgid = 73
            // 
            mavlink_mission_item_int_t mission_item_int;
            mavlink_msg_mission_item_int_decode(&message, &(mission_item_int));
            stream << "{\"type\":\"MISSION_ITEM_INT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mission_item_int.target_system)
                << "\",\"target_component\":\"" << unsigned(mission_item_int.target_component)
                << "\",\"seq\":\"" << mission_item_int.seq
                << "\",\"frame\":\"" << unsigned(mission_item_int.frame)
                << "\",\"command\":\"" << mission_item_int.command
                << "\",\"current\":\"" << unsigned(mission_item_int.current)
                << "\",\"autocontinue\":\"" << unsigned(mission_item_int.autocontinue)
                << "\",\"param1\":\"" << mission_item_int.param1
                << "\",\"param2\":\"" << mission_item_int.param2
                << "\",\"param3\":\"" << mission_item_int.param3
                << "\",\"param4\":\"" << mission_item_int.param4
                << "\",\"x\":\"" << mission_item_int.x
                << "\",\"y\":\"" << mission_item_int.y
                << "\",\"z\":\"" << mission_item_int.z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_VFR_HUD: 
            // msgid = 74
            // 
            mavlink_vfr_hud_t vfr_hud;
            mavlink_msg_vfr_hud_decode(&message, &(vfr_hud));
            stream << "{\"type\":\"VFR_HUD"
                << "\",\"system_id\":\"" << sysid
                << "\",\"airspeed\":\"" << vfr_hud.airspeed
                << "\",\"groundspeed\":\"" << vfr_hud.groundspeed
                << "\",\"heading\":\"" << vfr_hud.heading
                << "\",\"throttle\":\"" << vfr_hud.throttle
                << "\",\"alt\":\"" << vfr_hud.alt
                << "\",\"climb\":\"" << vfr_hud.climb
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_COMMAND_INT: 
            // msgid = 75
            // 
            mavlink_command_int_t command_int;
            mavlink_msg_command_int_decode(&message, &(command_int));
            stream << "{\"type\":\"COMMAND_INT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(command_int.target_system)
                << "\",\"target_component\":\"" << unsigned(command_int.target_component)
                << "\",\"frame\":\"" << unsigned(command_int.frame)
                << "\",\"command\":\"" << command_int.command
                << "\",\"current\":\"" << unsigned(command_int.current)
                << "\",\"autocontinue\":\"" << unsigned(command_int.autocontinue)
                << "\",\"param1\":\"" << command_int.param1
                << "\",\"param2\":\"" << command_int.param2
                << "\",\"param3\":\"" << command_int.param3
                << "\",\"param4\":\"" << command_int.param4
                << "\",\"x\":\"" << command_int.x
                << "\",\"y\":\"" << command_int.y
                << "\",\"z\":\"" << command_int.z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_COMMAND_LONG: 
            // msgid = 76
            // 
            mavlink_command_long_t command_long;
            mavlink_msg_command_long_decode(&message, &(command_long));
            stream << "{\"type\":\"COMMAND_LONG"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(command_long.target_system)
                << "\",\"target_component\":\"" << unsigned(command_long.target_component)
                << "\",\"command\":\"" << command_long.command
                << "\",\"confirmation\":\"" << unsigned(command_long.confirmation)
                << "\",\"param1\":\"" << command_long.param1
                << "\",\"param2\":\"" << command_long.param2
                << "\",\"param3\":\"" << command_long.param3
                << "\",\"param4\":\"" << command_long.param4
                << "\",\"param5\":\"" << command_long.param5
                << "\",\"param6\":\"" << command_long.param6
                << "\",\"param7\":\"" << command_long.param7
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_COMMAND_ACK: 
            // msgid = 77
            // 
            mavlink_command_ack_t command_ack;
            mavlink_msg_command_ack_decode(&message, &(command_ack));
            stream << "{\"type\":\"COMMAND_ACK"
                << "\",\"system_id\":\"" << sysid
                << "\",\"command\":\"" << command_ack.command
                << "\",\"result\":\"" << unsigned(command_ack.result)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MANUAL_SETPOINT: 
            // msgid = 81
            // 
            mavlink_manual_setpoint_t manual_setpoint;
            mavlink_msg_manual_setpoint_decode(&message, &(manual_setpoint));
            stream << "{\"type\":\"MANUAL_SETPOINT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << manual_setpoint.time_boot_ms
                << "\",\"roll\":\"" << manual_setpoint.roll
                << "\",\"pitch\":\"" << manual_setpoint.pitch
                << "\",\"yaw\":\"" << manual_setpoint.yaw
                << "\",\"thrust\":\"" << manual_setpoint.thrust
                << "\",\"mode_switch\":\"" << unsigned(manual_setpoint.mode_switch)
                << "\",\"manual_override_switch\":\"" << unsigned(manual_setpoint.manual_override_switch)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_ATTITUDE_TARGET: 
            // msgid = 82
            // 
            mavlink_set_attitude_target_t set_attitude_target;
            mavlink_msg_set_attitude_target_decode(&message, &(set_attitude_target));
            stream << "{\"type\":\"SET_ATTITUDE_TARGET"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << set_attitude_target.time_boot_ms
                << "\",\"target_system\":\"" << unsigned(set_attitude_target.target_system)
                << "\",\"target_component\":\"" << unsigned(set_attitude_target.target_component)
                << "\",\"type_mask\":\"" << unsigned(set_attitude_target.type_mask)
                << "\",\"q\":\"" << set_attitude_target.q
                << "\",\"body_roll_rate\":\"" << set_attitude_target.body_roll_rate
                << "\",\"body_pitch_rate\":\"" << set_attitude_target.body_pitch_rate
                << "\",\"body_yaw_rate\":\"" << set_attitude_target.body_yaw_rate
                << "\",\"thrust\":\"" << set_attitude_target.thrust
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ATTITUDE_TARGET: 
            // msgid = 83
            // 
            mavlink_attitude_target_t attitude_target;
            mavlink_msg_attitude_target_decode(&message, &(attitude_target));
            stream << "{\"type\":\"ATTITUDE_TARGET"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << attitude_target.time_boot_ms
                << "\",\"type_mask\":\"" << unsigned(attitude_target.type_mask)
                << "\",\"q\":\"" << attitude_target.q
                << "\",\"body_roll_rate\":\"" << attitude_target.body_roll_rate
                << "\",\"body_pitch_rate\":\"" << attitude_target.body_pitch_rate
                << "\",\"body_yaw_rate\":\"" << attitude_target.body_yaw_rate
                << "\",\"thrust\":\"" << attitude_target.thrust
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED: 
            // msgid = 84
            // 
            mavlink_set_position_target_local_ned_t set_position_target_local_ned;
            mavlink_msg_set_position_target_local_ned_decode(&message, &(set_position_target_local_ned));
            stream << "{\"type\":\"SET_POSITION_TARGET_LOCAL_NED"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << set_position_target_local_ned.time_boot_ms
                << "\",\"target_system\":\"" << unsigned(set_position_target_local_ned.target_system)
                << "\",\"target_component\":\"" << unsigned(set_position_target_local_ned.target_component)
                << "\",\"coordinate_frame\":\"" << unsigned(set_position_target_local_ned.coordinate_frame)
                << "\",\"type_mask\":\"" << set_position_target_local_ned.type_mask
                << "\",\"x\":\"" << set_position_target_local_ned.x
                << "\",\"y\":\"" << set_position_target_local_ned.y
                << "\",\"z\":\"" << set_position_target_local_ned.z
                << "\",\"vx\":\"" << set_position_target_local_ned.vx
                << "\",\"vy\":\"" << set_position_target_local_ned.vy
                << "\",\"vz\":\"" << set_position_target_local_ned.vz
                << "\",\"afx\":\"" << set_position_target_local_ned.afx
                << "\",\"afy\":\"" << set_position_target_local_ned.afy
                << "\",\"afz\":\"" << set_position_target_local_ned.afz
                << "\",\"yaw\":\"" << set_position_target_local_ned.yaw
                << "\",\"yaw_rate\":\"" << set_position_target_local_ned.yaw_rate
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED: 
            // msgid = 85
            // 
            mavlink_position_target_local_ned_t position_target_local_ned;
            mavlink_msg_position_target_local_ned_decode(&message, &(position_target_local_ned));
            stream << "{\"type\":\"POSITION_TARGET_LOCAL_NED"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << position_target_local_ned.time_boot_ms
                << "\",\"coordinate_frame\":\"" << unsigned(position_target_local_ned.coordinate_frame)
                << "\",\"type_mask\":\"" << position_target_local_ned.type_mask
                << "\",\"x\":\"" << position_target_local_ned.x
                << "\",\"y\":\"" << position_target_local_ned.y
                << "\",\"z\":\"" << position_target_local_ned.z
                << "\",\"vx\":\"" << position_target_local_ned.vx
                << "\",\"vy\":\"" << position_target_local_ned.vy
                << "\",\"vz\":\"" << position_target_local_ned.vz
                << "\",\"afx\":\"" << position_target_local_ned.afx
                << "\",\"afy\":\"" << position_target_local_ned.afy
                << "\",\"afz\":\"" << position_target_local_ned.afz
                << "\",\"yaw\":\"" << position_target_local_ned.yaw
                << "\",\"yaw_rate\":\"" << position_target_local_ned.yaw_rate
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_POSITION_TARGET_GLOBAL_INT: 
            // msgid = 86
            // 
            mavlink_set_position_target_global_int_t set_position_target_global_int;
            mavlink_msg_set_position_target_global_int_decode(&message, &(set_position_target_global_int));
            stream << "{\"type\":\"SET_POSITION_TARGET_GLOBAL_INT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << set_position_target_global_int.time_boot_ms
                << "\",\"target_system\":\"" << unsigned(set_position_target_global_int.target_system)
                << "\",\"target_component\":\"" << unsigned(set_position_target_global_int.target_component)
                << "\",\"coordinate_frame\":\"" << unsigned(set_position_target_global_int.coordinate_frame)
                << "\",\"type_mask\":\"" << set_position_target_global_int.type_mask
                << "\",\"lat_int\":\"" << set_position_target_global_int.lat_int
                << "\",\"lon_int\":\"" << set_position_target_global_int.lon_int
                << "\",\"alt\":\"" << set_position_target_global_int.alt
                << "\",\"vx\":\"" << set_position_target_global_int.vx
                << "\",\"vy\":\"" << set_position_target_global_int.vy
                << "\",\"vz\":\"" << set_position_target_global_int.vz
                << "\",\"afx\":\"" << set_position_target_global_int.afx
                << "\",\"afy\":\"" << set_position_target_global_int.afy
                << "\",\"afz\":\"" << set_position_target_global_int.afz
                << "\",\"yaw\":\"" << set_position_target_global_int.yaw
                << "\",\"yaw_rate\":\"" << set_position_target_global_int.yaw_rate
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT: 
            // msgid = 87
            // 
            mavlink_position_target_global_int_t position_target_global_int;
            mavlink_msg_position_target_global_int_decode(&message, &(position_target_global_int));
            stream << "{\"type\":\"POSITION_TARGET_GLOBAL_INT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << position_target_global_int.time_boot_ms
                << "\",\"coordinate_frame\":\"" << unsigned(position_target_global_int.coordinate_frame)
                << "\",\"type_mask\":\"" << position_target_global_int.type_mask
                << "\",\"lat_int\":\"" << position_target_global_int.lat_int
                << "\",\"lon_int\":\"" << position_target_global_int.lon_int
                << "\",\"alt\":\"" << position_target_global_int.alt
                << "\",\"vx\":\"" << position_target_global_int.vx
                << "\",\"vy\":\"" << position_target_global_int.vy
                << "\",\"vz\":\"" << position_target_global_int.vz
                << "\",\"afx\":\"" << position_target_global_int.afx
                << "\",\"afy\":\"" << position_target_global_int.afy
                << "\",\"afz\":\"" << position_target_global_int.afz
                << "\",\"yaw\":\"" << position_target_global_int.yaw
                << "\",\"yaw_rate\":\"" << position_target_global_int.yaw_rate
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET: 
            // msgid = 89
            // 
            mavlink_local_position_ned_system_global_offset_t local_position_ned_system_global_offset;
            mavlink_msg_local_position_ned_system_global_offset_decode(&message, &(local_position_ned_system_global_offset));
            stream << "{\"type\":\"LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << local_position_ned_system_global_offset.time_boot_ms
                << "\",\"x\":\"" << local_position_ned_system_global_offset.x
                << "\",\"y\":\"" << local_position_ned_system_global_offset.y
                << "\",\"z\":\"" << local_position_ned_system_global_offset.z
                << "\",\"roll\":\"" << local_position_ned_system_global_offset.roll
                << "\",\"pitch\":\"" << local_position_ned_system_global_offset.pitch
                << "\",\"yaw\":\"" << local_position_ned_system_global_offset.yaw
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_STATE: 
            // msgid = 90
            // 
            mavlink_hil_state_t hil_state;
            mavlink_msg_hil_state_decode(&message, &(hil_state));
            stream << "{\"type\":\"HIL_STATE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << hil_state.time_usec
                << "\",\"roll\":\"" << hil_state.roll
                << "\",\"pitch\":\"" << hil_state.pitch
                << "\",\"yaw\":\"" << hil_state.yaw
                << "\",\"rollspeed\":\"" << hil_state.rollspeed
                << "\",\"pitchspeed\":\"" << hil_state.pitchspeed
                << "\",\"yawspeed\":\"" << hil_state.yawspeed
                << "\",\"lat\":\"" << hil_state.lat
                << "\",\"lon\":\"" << hil_state.lon
                << "\",\"alt\":\"" << hil_state.alt
                << "\",\"vx\":\"" << hil_state.vx
                << "\",\"vy\":\"" << hil_state.vy
                << "\",\"vz\":\"" << hil_state.vz
                << "\",\"xacc\":\"" << hil_state.xacc
                << "\",\"yacc\":\"" << hil_state.yacc
                << "\",\"zacc\":\"" << hil_state.zacc
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_CONTROLS: 
            // msgid = 91
            // 
            mavlink_hil_controls_t hil_controls;
            mavlink_msg_hil_controls_decode(&message, &(hil_controls));
            stream << "{\"type\":\"HIL_CONTROLS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << hil_controls.time_usec
                << "\",\"roll_ailerons\":\"" << hil_controls.roll_ailerons
                << "\",\"pitch_elevator\":\"" << hil_controls.pitch_elevator
                << "\",\"yaw_rudder\":\"" << hil_controls.yaw_rudder
                << "\",\"throttle\":\"" << hil_controls.throttle
                << "\",\"aux1\":\"" << hil_controls.aux1
                << "\",\"aux2\":\"" << hil_controls.aux2
                << "\",\"aux3\":\"" << hil_controls.aux3
                << "\",\"aux4\":\"" << hil_controls.aux4
                << "\",\"mode\":\"" << unsigned(hil_controls.mode)
                << "\",\"nav_mode\":\"" << unsigned(hil_controls.nav_mode)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW: 
            // msgid = 92
            // 
            mavlink_hil_rc_inputs_raw_t hil_rc_inputs_raw;
            mavlink_msg_hil_rc_inputs_raw_decode(&message, &(hil_rc_inputs_raw));
            stream << "{\"type\":\"HIL_RC_INPUTS_RAW"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << hil_rc_inputs_raw.time_usec
                << "\",\"chan1_raw\":\"" << hil_rc_inputs_raw.chan1_raw
                << "\",\"chan2_raw\":\"" << hil_rc_inputs_raw.chan2_raw
                << "\",\"chan3_raw\":\"" << hil_rc_inputs_raw.chan3_raw
                << "\",\"chan4_raw\":\"" << hil_rc_inputs_raw.chan4_raw
                << "\",\"chan5_raw\":\"" << hil_rc_inputs_raw.chan5_raw
                << "\",\"chan6_raw\":\"" << hil_rc_inputs_raw.chan6_raw
                << "\",\"chan7_raw\":\"" << hil_rc_inputs_raw.chan7_raw
                << "\",\"chan8_raw\":\"" << hil_rc_inputs_raw.chan8_raw
                << "\",\"chan9_raw\":\"" << hil_rc_inputs_raw.chan9_raw
                << "\",\"chan10_raw\":\"" << hil_rc_inputs_raw.chan10_raw
                << "\",\"chan11_raw\":\"" << hil_rc_inputs_raw.chan11_raw
                << "\",\"chan12_raw\":\"" << hil_rc_inputs_raw.chan12_raw
                << "\",\"rssi\":\"" << unsigned(hil_rc_inputs_raw.rssi)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_OPTICAL_FLOW: 
            // msgid = 100
            // 
            mavlink_optical_flow_t optical_flow;
            mavlink_msg_optical_flow_decode(&message, &(optical_flow));
            stream << "{\"type\":\"OPTICAL_FLOW"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << optical_flow.time_usec
                << "\",\"sensor_id\":\"" << unsigned(optical_flow.sensor_id)
                << "\",\"flow_x\":\"" << optical_flow.flow_x
                << "\",\"flow_y\":\"" << optical_flow.flow_y
                << "\",\"flow_comp_m_x\":\"" << optical_flow.flow_comp_m_x
                << "\",\"flow_comp_m_y\":\"" << optical_flow.flow_comp_m_y
                << "\",\"quality\":\"" << unsigned(optical_flow.quality)
                << "\",\"ground_distance\":\"" << optical_flow.ground_distance
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GLOBAL_VISION_POSITION_ESTIMATE: 
            // msgid = 101
            // 
            mavlink_global_vision_position_estimate_t global_vision_position_estimate;
            mavlink_msg_global_vision_position_estimate_decode(&message, &(global_vision_position_estimate));
            stream << "{\"type\":\"GLOBAL_VISION_POSITION_ESTIMATE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"usec\":\"" << global_vision_position_estimate.usec
                << "\",\"x\":\"" << global_vision_position_estimate.x
                << "\",\"y\":\"" << global_vision_position_estimate.y
                << "\",\"z\":\"" << global_vision_position_estimate.z
                << "\",\"roll\":\"" << global_vision_position_estimate.roll
                << "\",\"pitch\":\"" << global_vision_position_estimate.pitch
                << "\",\"yaw\":\"" << global_vision_position_estimate.yaw
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE: 
            // msgid = 102
            // 
            mavlink_vision_position_estimate_t vision_position_estimate;
            mavlink_msg_vision_position_estimate_decode(&message, &(vision_position_estimate));
            stream << "{\"type\":\"VISION_POSITION_ESTIMATE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"usec\":\"" << vision_position_estimate.usec
                << "\",\"x\":\"" << vision_position_estimate.x
                << "\",\"y\":\"" << vision_position_estimate.y
                << "\",\"z\":\"" << vision_position_estimate.z
                << "\",\"roll\":\"" << vision_position_estimate.roll
                << "\",\"pitch\":\"" << vision_position_estimate.pitch
                << "\",\"yaw\":\"" << vision_position_estimate.yaw
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE: 
            // msgid = 103
            // 
            mavlink_vision_speed_estimate_t vision_speed_estimate;
            mavlink_msg_vision_speed_estimate_decode(&message, &(vision_speed_estimate));
            stream << "{\"type\":\"VISION_SPEED_ESTIMATE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"usec\":\"" << vision_speed_estimate.usec
                << "\",\"x\":\"" << vision_speed_estimate.x
                << "\",\"y\":\"" << vision_speed_estimate.y
                << "\",\"z\":\"" << vision_speed_estimate.z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE: 
            // msgid = 104
            // 
            mavlink_vicon_position_estimate_t vicon_position_estimate;
            mavlink_msg_vicon_position_estimate_decode(&message, &(vicon_position_estimate));
            stream << "{\"type\":\"VICON_POSITION_ESTIMATE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"usec\":\"" << vicon_position_estimate.usec
                << "\",\"x\":\"" << vicon_position_estimate.x
                << "\",\"y\":\"" << vicon_position_estimate.y
                << "\",\"z\":\"" << vicon_position_estimate.z
                << "\",\"roll\":\"" << vicon_position_estimate.roll
                << "\",\"pitch\":\"" << vicon_position_estimate.pitch
                << "\",\"yaw\":\"" << vicon_position_estimate.yaw
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIGHRES_IMU: 
            // msgid = 105
            // 
            mavlink_highres_imu_t highres_imu;
            mavlink_msg_highres_imu_decode(&message, &(highres_imu));
            stream << "{\"type\":\"HIGHRES_IMU"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << highres_imu.time_usec
                << "\",\"xacc\":\"" << highres_imu.xacc
                << "\",\"yacc\":\"" << highres_imu.yacc
                << "\",\"zacc\":\"" << highres_imu.zacc
                << "\",\"xgyro\":\"" << highres_imu.xgyro
                << "\",\"ygyro\":\"" << highres_imu.ygyro
                << "\",\"zgyro\":\"" << highres_imu.zgyro
                << "\",\"xmag\":\"" << highres_imu.xmag
                << "\",\"ymag\":\"" << highres_imu.ymag
                << "\",\"zmag\":\"" << highres_imu.zmag
                << "\",\"abs_pressure\":\"" << highres_imu.abs_pressure
                << "\",\"diff_pressure\":\"" << highres_imu.diff_pressure
                << "\",\"pressure_alt\":\"" << highres_imu.pressure_alt
                << "\",\"temperature\":\"" << highres_imu.temperature
                << "\",\"fields_updated\":\"" << highres_imu.fields_updated
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_OPTICAL_FLOW_RAD: 
            // msgid = 106
            // 
            mavlink_optical_flow_rad_t optical_flow_rad;
            mavlink_msg_optical_flow_rad_decode(&message, &(optical_flow_rad));
            stream << "{\"type\":\"OPTICAL_FLOW_RAD"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << optical_flow_rad.time_usec
                << "\",\"sensor_id\":\"" << unsigned(optical_flow_rad.sensor_id)
                << "\",\"integration_time_us\":\"" << optical_flow_rad.integration_time_us
                << "\",\"integrated_x\":\"" << optical_flow_rad.integrated_x
                << "\",\"integrated_y\":\"" << optical_flow_rad.integrated_y
                << "\",\"integrated_xgyro\":\"" << optical_flow_rad.integrated_xgyro
                << "\",\"integrated_ygyro\":\"" << optical_flow_rad.integrated_ygyro
                << "\",\"integrated_zgyro\":\"" << optical_flow_rad.integrated_zgyro
                << "\",\"temperature\":\"" << optical_flow_rad.temperature
                << "\",\"quality\":\"" << unsigned(optical_flow_rad.quality)
                << "\",\"time_delta_distance_us\":\"" << optical_flow_rad.time_delta_distance_us
                << "\",\"distance\":\"" << optical_flow_rad.distance
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_SENSOR: 
            // msgid = 107
            // 
            mavlink_hil_sensor_t hil_sensor;
            mavlink_msg_hil_sensor_decode(&message, &(hil_sensor));
            stream << "{\"type\":\"HIL_SENSOR"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << hil_sensor.time_usec
                << "\",\"xacc\":\"" << hil_sensor.xacc
                << "\",\"yacc\":\"" << hil_sensor.yacc
                << "\",\"zacc\":\"" << hil_sensor.zacc
                << "\",\"xgyro\":\"" << hil_sensor.xgyro
                << "\",\"ygyro\":\"" << hil_sensor.ygyro
                << "\",\"zgyro\":\"" << hil_sensor.zgyro
                << "\",\"xmag\":\"" << hil_sensor.xmag
                << "\",\"ymag\":\"" << hil_sensor.ymag
                << "\",\"zmag\":\"" << hil_sensor.zmag
                << "\",\"abs_pressure\":\"" << hil_sensor.abs_pressure
                << "\",\"diff_pressure\":\"" << hil_sensor.diff_pressure
                << "\",\"pressure_alt\":\"" << hil_sensor.pressure_alt
                << "\",\"temperature\":\"" << hil_sensor.temperature
                << "\",\"fields_updated\":\"" << hil_sensor.fields_updated
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SIM_STATE: 
            // msgid = 108
            // 
            mavlink_sim_state_t sim_state;
            mavlink_msg_sim_state_decode(&message, &(sim_state));
            stream << "{\"type\":\"SIM_STATE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"q1\":\"" << sim_state.q1
                << "\",\"q2\":\"" << sim_state.q2
                << "\",\"q3\":\"" << sim_state.q3
                << "\",\"q4\":\"" << sim_state.q4
                << "\",\"roll\":\"" << sim_state.roll
                << "\",\"pitch\":\"" << sim_state.pitch
                << "\",\"yaw\":\"" << sim_state.yaw
                << "\",\"xacc\":\"" << sim_state.xacc
                << "\",\"yacc\":\"" << sim_state.yacc
                << "\",\"zacc\":\"" << sim_state.zacc
                << "\",\"xgyro\":\"" << sim_state.xgyro
                << "\",\"ygyro\":\"" << sim_state.ygyro
                << "\",\"zgyro\":\"" << sim_state.zgyro
                << "\",\"lat\":\"" << sim_state.lat
                << "\",\"lon\":\"" << sim_state.lon
                << "\",\"alt\":\"" << sim_state.alt
                << "\",\"std_dev_horz\":\"" << sim_state.std_dev_horz
                << "\",\"std_dev_vert\":\"" << sim_state.std_dev_vert
                << "\",\"vn\":\"" << sim_state.vn
                << "\",\"ve\":\"" << sim_state.ve
                << "\",\"vd\":\"" << sim_state.vd
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RADIO_STATUS: 
            // msgid = 109
            // 
            mavlink_radio_status_t radio_status;
            mavlink_msg_radio_status_decode(&message, &(radio_status));
            stream << "{\"type\":\"RADIO_STATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"rssi\":\"" << unsigned(radio_status.rssi)
                << "\",\"remrssi\":\"" << unsigned(radio_status.remrssi)
                << "\",\"txbuf\":\"" << unsigned(radio_status.txbuf)
                << "\",\"noise\":\"" << unsigned(radio_status.noise)
                << "\",\"remnoise\":\"" << unsigned(radio_status.remnoise)
                << "\",\"rxerrors\":\"" << radio_status.rxerrors
                << "\",\"fixed\":\"" << radio_status.fixed
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL: 
            // msgid = 110
            // 
            mavlink_file_transfer_protocol_t file_transfer_protocol;
            mavlink_msg_file_transfer_protocol_decode(&message, &(file_transfer_protocol));
            stream << "{\"type\":\"FILE_TRANSFER_PROTOCOL"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_network\":\"" << unsigned(file_transfer_protocol.target_network)
                << "\",\"target_system\":\"" << unsigned(file_transfer_protocol.target_system)
                << "\",\"target_component\":\"" << unsigned(file_transfer_protocol.target_component)
                << "\",\"payload\":\"" << file_transfer_protocol.payload
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_TIMESYNC: 
            // msgid = 111
            // 
            mavlink_timesync_t timesync;
            mavlink_msg_timesync_decode(&message, &(timesync));
            stream << "{\"type\":\"TIMESYNC"
                << "\",\"system_id\":\"" << sysid
                << "\",\"tc1\":\"" << timesync.tc1
                << "\",\"ts1\":\"" << timesync.ts1
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_GPS: 
            // msgid = 113
            // 
            mavlink_hil_gps_t hil_gps;
            mavlink_msg_hil_gps_decode(&message, &(hil_gps));
            stream << "{\"type\":\"HIL_GPS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << hil_gps.time_usec
                << "\",\"fix_type\":\"" << unsigned(hil_gps.fix_type)
                << "\",\"lat\":\"" << hil_gps.lat
                << "\",\"lon\":\"" << hil_gps.lon
                << "\",\"alt\":\"" << hil_gps.alt
                << "\",\"eph\":\"" << hil_gps.eph
                << "\",\"epv\":\"" << hil_gps.epv
                << "\",\"vel\":\"" << hil_gps.vel
                << "\",\"vn\":\"" << hil_gps.vn
                << "\",\"ve\":\"" << hil_gps.ve
                << "\",\"vd\":\"" << hil_gps.vd
                << "\",\"cog\":\"" << hil_gps.cog
                << "\",\"satellites_visible\":\"" << unsigned(hil_gps.satellites_visible)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_OPTICAL_FLOW: 
            // msgid = 114
            // 
            mavlink_hil_optical_flow_t hil_optical_flow;
            mavlink_msg_hil_optical_flow_decode(&message, &(hil_optical_flow));
            stream << "{\"type\":\"HIL_OPTICAL_FLOW"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << hil_optical_flow.time_usec
                << "\",\"sensor_id\":\"" << unsigned(hil_optical_flow.sensor_id)
                << "\",\"integration_time_us\":\"" << hil_optical_flow.integration_time_us
                << "\",\"integrated_x\":\"" << hil_optical_flow.integrated_x
                << "\",\"integrated_y\":\"" << hil_optical_flow.integrated_y
                << "\",\"integrated_xgyro\":\"" << hil_optical_flow.integrated_xgyro
                << "\",\"integrated_ygyro\":\"" << hil_optical_flow.integrated_ygyro
                << "\",\"integrated_zgyro\":\"" << hil_optical_flow.integrated_zgyro
                << "\",\"temperature\":\"" << hil_optical_flow.temperature
                << "\",\"quality\":\"" << unsigned(hil_optical_flow.quality)
                << "\",\"time_delta_distance_us\":\"" << hil_optical_flow.time_delta_distance_us
                << "\",\"distance\":\"" << hil_optical_flow.distance
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_STATE_QUATERNION: 
            // msgid = 115
            // 
            mavlink_hil_state_quaternion_t hil_state_quaternion;
            mavlink_msg_hil_state_quaternion_decode(&message, &(hil_state_quaternion));
            stream << "{\"type\":\"HIL_STATE_QUATERNION"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << hil_state_quaternion.time_usec
                << "\",\"attitude_quaternion\":\"" << hil_state_quaternion.attitude_quaternion
                << "\",\"rollspeed\":\"" << hil_state_quaternion.rollspeed
                << "\",\"pitchspeed\":\"" << hil_state_quaternion.pitchspeed
                << "\",\"yawspeed\":\"" << hil_state_quaternion.yawspeed
                << "\",\"lat\":\"" << hil_state_quaternion.lat
                << "\",\"lon\":\"" << hil_state_quaternion.lon
                << "\",\"alt\":\"" << hil_state_quaternion.alt
                << "\",\"vx\":\"" << hil_state_quaternion.vx
                << "\",\"vy\":\"" << hil_state_quaternion.vy
                << "\",\"vz\":\"" << hil_state_quaternion.vz
                << "\",\"ind_airspeed\":\"" << hil_state_quaternion.ind_airspeed
                << "\",\"true_airspeed\":\"" << hil_state_quaternion.true_airspeed
                << "\",\"xacc\":\"" << hil_state_quaternion.xacc
                << "\",\"yacc\":\"" << hil_state_quaternion.yacc
                << "\",\"zacc\":\"" << hil_state_quaternion.zacc
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SCALED_IMU2: 
            // msgid = 116
            // 
            mavlink_scaled_imu2_t scaled_imu2;
            mavlink_msg_scaled_imu2_decode(&message, &(scaled_imu2));
            stream << "{\"type\":\"SCALED_IMU2"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << scaled_imu2.time_boot_ms
                << "\",\"xacc\":\"" << scaled_imu2.xacc
                << "\",\"yacc\":\"" << scaled_imu2.yacc
                << "\",\"zacc\":\"" << scaled_imu2.zacc
                << "\",\"xgyro\":\"" << scaled_imu2.xgyro
                << "\",\"ygyro\":\"" << scaled_imu2.ygyro
                << "\",\"zgyro\":\"" << scaled_imu2.zgyro
                << "\",\"xmag\":\"" << scaled_imu2.xmag
                << "\",\"ymag\":\"" << scaled_imu2.ymag
                << "\",\"zmag\":\"" << scaled_imu2.zmag
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_REQUEST_LIST: 
            // msgid = 117
            // 
            mavlink_log_request_list_t log_request_list;
            mavlink_msg_log_request_list_decode(&message, &(log_request_list));
            stream << "{\"type\":\"LOG_REQUEST_LIST"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(log_request_list.target_system)
                << "\",\"target_component\":\"" << unsigned(log_request_list.target_component)
                << "\",\"start\":\"" << log_request_list.start
                << "\",\"end\":\"" << log_request_list.end
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_ENTRY: 
            // msgid = 118
            // 
            mavlink_log_entry_t log_entry;
            mavlink_msg_log_entry_decode(&message, &(log_entry));
            stream << "{\"type\":\"LOG_ENTRY"
                << "\",\"system_id\":\"" << sysid
                << "\",\"id\":\"" << log_entry.id
                << "\",\"num_logs\":\"" << log_entry.num_logs
                << "\",\"last_log_num\":\"" << log_entry.last_log_num
                << "\",\"time_utc\":\"" << log_entry.time_utc
                << "\",\"size\":\"" << log_entry.size
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_REQUEST_DATA: 
            // msgid = 119
            // 
            mavlink_log_request_data_t log_request_data;
            mavlink_msg_log_request_data_decode(&message, &(log_request_data));
            stream << "{\"type\":\"LOG_REQUEST_DATA"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(log_request_data.target_system)
                << "\",\"target_component\":\"" << unsigned(log_request_data.target_component)
                << "\",\"id\":\"" << log_request_data.id
                << "\",\"ofs\":\"" << log_request_data.ofs
                << "\",\"count\":\"" << log_request_data.count
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_DATA: 
            // msgid = 120
            // 
            mavlink_log_data_t log_data;
            mavlink_msg_log_data_decode(&message, &(log_data));
            stream << "{\"type\":\"LOG_DATA"
                << "\",\"system_id\":\"" << sysid
                << "\",\"id\":\"" << log_data.id
                << "\",\"ofs\":\"" << log_data.ofs
                << "\",\"count\":\"" << unsigned(log_data.count)
                << "\",\"data\":\"" << log_data.data
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_ERASE: 
            // msgid = 121
            // 
            mavlink_log_erase_t log_erase;
            mavlink_msg_log_erase_decode(&message, &(log_erase));
            stream << "{\"type\":\"LOG_ERASE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(log_erase.target_system)
                << "\",\"target_component\":\"" << unsigned(log_erase.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_REQUEST_END: 
            // msgid = 122
            // 
            mavlink_log_request_end_t log_request_end;
            mavlink_msg_log_request_end_decode(&message, &(log_request_end));
            stream << "{\"type\":\"LOG_REQUEST_END"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(log_request_end.target_system)
                << "\",\"target_component\":\"" << unsigned(log_request_end.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS_INJECT_DATA: 
            // msgid = 123
            // 
            mavlink_gps_inject_data_t gps_inject_data;
            mavlink_msg_gps_inject_data_decode(&message, &(gps_inject_data));
            stream << "{\"type\":\"GPS_INJECT_DATA"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gps_inject_data.target_system)
                << "\",\"target_component\":\"" << unsigned(gps_inject_data.target_component)
                << "\",\"len\":\"" << unsigned(gps_inject_data.len)
                << "\",\"data\":\"" << gps_inject_data.data
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS2_RAW: 
            // msgid = 124
            // 
            mavlink_gps2_raw_t gps2_raw;
            mavlink_msg_gps2_raw_decode(&message, &(gps2_raw));
            stream << "{\"type\":\"GPS2_RAW"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << gps2_raw.time_usec
                << "\",\"fix_type\":\"" << unsigned(gps2_raw.fix_type)
                << "\",\"lat\":\"" << gps2_raw.lat
                << "\",\"lon\":\"" << gps2_raw.lon
                << "\",\"alt\":\"" << gps2_raw.alt
                << "\",\"eph\":\"" << gps2_raw.eph
                << "\",\"epv\":\"" << gps2_raw.epv
                << "\",\"vel\":\"" << gps2_raw.vel
                << "\",\"cog\":\"" << gps2_raw.cog
                << "\",\"satellites_visible\":\"" << unsigned(gps2_raw.satellites_visible)
                << "\",\"dgps_numch\":\"" << unsigned(gps2_raw.dgps_numch)
                << "\",\"dgps_age\":\"" << gps2_raw.dgps_age
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_POWER_STATUS: 
            // msgid = 125
            // 
            mavlink_power_status_t power_status;
            mavlink_msg_power_status_decode(&message, &(power_status));
            stream << "{\"type\":\"POWER_STATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"Vcc\":\"" << power_status.Vcc
                << "\",\"Vservo\":\"" << power_status.Vservo
                << "\",\"flags\":\"" << power_status.flags
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SERIAL_CONTROL: 
            // msgid = 126
            // 
            mavlink_serial_control_t serial_control;
            mavlink_msg_serial_control_decode(&message, &(serial_control));
            stream << "{\"type\":\"SERIAL_CONTROL"
                << "\",\"system_id\":\"" << sysid
                << "\",\"device\":\"" << unsigned(serial_control.device)
                << "\",\"flags\":\"" << unsigned(serial_control.flags)
                << "\",\"timeout\":\"" << serial_control.timeout
                << "\",\"baudrate\":\"" << serial_control.baudrate
                << "\",\"count\":\"" << unsigned(serial_control.count)
                << "\",\"data\":\"" << serial_control.data
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS_RTK: 
            // msgid = 127
            // 
            mavlink_gps_rtk_t gps_rtk;
            mavlink_msg_gps_rtk_decode(&message, &(gps_rtk));
            stream << "{\"type\":\"GPS_RTK"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_last_baseline_ms\":\"" << gps_rtk.time_last_baseline_ms
                << "\",\"rtk_receiver_id\":\"" << unsigned(gps_rtk.rtk_receiver_id)
                << "\",\"wn\":\"" << gps_rtk.wn
                << "\",\"tow\":\"" << gps_rtk.tow
                << "\",\"rtk_health\":\"" << unsigned(gps_rtk.rtk_health)
                << "\",\"rtk_rate\":\"" << unsigned(gps_rtk.rtk_rate)
                << "\",\"nsats\":\"" << unsigned(gps_rtk.nsats)
                << "\",\"baseline_coords_type\":\"" << unsigned(gps_rtk.baseline_coords_type)
                << "\",\"baseline_a_mm\":\"" << gps_rtk.baseline_a_mm
                << "\",\"baseline_b_mm\":\"" << gps_rtk.baseline_b_mm
                << "\",\"baseline_c_mm\":\"" << gps_rtk.baseline_c_mm
                << "\",\"accuracy\":\"" << gps_rtk.accuracy
                << "\",\"iar_num_hypotheses\":\"" << gps_rtk.iar_num_hypotheses
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS2_RTK: 
            // msgid = 128
            // 
            mavlink_gps2_rtk_t gps2_rtk;
            mavlink_msg_gps2_rtk_decode(&message, &(gps2_rtk));
            stream << "{\"type\":\"GPS2_RTK"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_last_baseline_ms\":\"" << gps2_rtk.time_last_baseline_ms
                << "\",\"rtk_receiver_id\":\"" << unsigned(gps2_rtk.rtk_receiver_id)
                << "\",\"wn\":\"" << gps2_rtk.wn
                << "\",\"tow\":\"" << gps2_rtk.tow
                << "\",\"rtk_health\":\"" << unsigned(gps2_rtk.rtk_health)
                << "\",\"rtk_rate\":\"" << unsigned(gps2_rtk.rtk_rate)
                << "\",\"nsats\":\"" << unsigned(gps2_rtk.nsats)
                << "\",\"baseline_coords_type\":\"" << unsigned(gps2_rtk.baseline_coords_type)
                << "\",\"baseline_a_mm\":\"" << gps2_rtk.baseline_a_mm
                << "\",\"baseline_b_mm\":\"" << gps2_rtk.baseline_b_mm
                << "\",\"baseline_c_mm\":\"" << gps2_rtk.baseline_c_mm
                << "\",\"accuracy\":\"" << gps2_rtk.accuracy
                << "\",\"iar_num_hypotheses\":\"" << gps2_rtk.iar_num_hypotheses
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SCALED_IMU3: 
            // msgid = 129
            // 
            mavlink_scaled_imu3_t scaled_imu3;
            mavlink_msg_scaled_imu3_decode(&message, &(scaled_imu3));
            stream << "{\"type\":\"SCALED_IMU3"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << scaled_imu3.time_boot_ms
                << "\",\"xacc\":\"" << scaled_imu3.xacc
                << "\",\"yacc\":\"" << scaled_imu3.yacc
                << "\",\"zacc\":\"" << scaled_imu3.zacc
                << "\",\"xgyro\":\"" << scaled_imu3.xgyro
                << "\",\"ygyro\":\"" << scaled_imu3.ygyro
                << "\",\"zgyro\":\"" << scaled_imu3.zgyro
                << "\",\"xmag\":\"" << scaled_imu3.xmag
                << "\",\"ymag\":\"" << scaled_imu3.ymag
                << "\",\"zmag\":\"" << scaled_imu3.zmag
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE: 
            // msgid = 130
            // 
            mavlink_data_transmission_handshake_t data_transmission_handshake;
            mavlink_msg_data_transmission_handshake_decode(&message, &(data_transmission_handshake));
            stream << "{\"type\":\"DATA_TRANSMISSION_HANDSHAKE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"type\":\"" << unsigned(data_transmission_handshake.type)
                << "\",\"size\":\"" << data_transmission_handshake.size
                << "\",\"width\":\"" << data_transmission_handshake.width
                << "\",\"height\":\"" << data_transmission_handshake.height
                << "\",\"packets\":\"" << data_transmission_handshake.packets
                << "\",\"payload\":\"" << unsigned(data_transmission_handshake.payload)
                << "\",\"jpg_quality\":\"" << unsigned(data_transmission_handshake.jpg_quality)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ENCAPSULATED_DATA: 
            // msgid = 131
            // 
            mavlink_encapsulated_data_t encapsulated_data;
            mavlink_msg_encapsulated_data_decode(&message, &(encapsulated_data));
            stream << "{\"type\":\"ENCAPSULATED_DATA"
                << "\",\"system_id\":\"" << sysid
                << "\",\"seqnr\":\"" << encapsulated_data.seqnr
                << "\",\"data\":\"" << encapsulated_data.data
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DISTANCE_SENSOR: 
            // msgid = 132
            // 
            mavlink_distance_sensor_t distance_sensor;
            mavlink_msg_distance_sensor_decode(&message, &(distance_sensor));
            stream << "{\"type\":\"DISTANCE_SENSOR"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << distance_sensor.time_boot_ms
                << "\",\"min_distance\":\"" << distance_sensor.min_distance
                << "\",\"max_distance\":\"" << distance_sensor.max_distance
                << "\",\"current_distance\":\"" << distance_sensor.current_distance
                << "\",\"type\":\"" << unsigned(distance_sensor.type)
                << "\",\"id\":\"" << unsigned(distance_sensor.id)
                << "\",\"orientation\":\"" << unsigned(distance_sensor.orientation)
                << "\",\"covariance\":\"" << unsigned(distance_sensor.covariance)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_TERRAIN_REQUEST: 
            // msgid = 133
            // 
            mavlink_terrain_request_t terrain_request;
            mavlink_msg_terrain_request_decode(&message, &(terrain_request));
            stream << "{\"type\":\"TERRAIN_REQUEST"
                << "\",\"system_id\":\"" << sysid
                << "\",\"lat\":\"" << terrain_request.lat
                << "\",\"lon\":\"" << terrain_request.lon
                << "\",\"grid_spacing\":\"" << terrain_request.grid_spacing
                << "\",\"mask\":\"" << terrain_request.mask
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_TERRAIN_DATA: 
            // msgid = 134
            // 
            mavlink_terrain_data_t terrain_data;
            mavlink_msg_terrain_data_decode(&message, &(terrain_data));
            stream << "{\"type\":\"TERRAIN_DATA"
                << "\",\"system_id\":\"" << sysid
                << "\",\"lat\":\"" << terrain_data.lat
                << "\",\"lon\":\"" << terrain_data.lon
                << "\",\"grid_spacing\":\"" << terrain_data.grid_spacing
                << "\",\"gridbit\":\"" << unsigned(terrain_data.gridbit)
                << "\",\"data\":\"" << terrain_data.data
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_TERRAIN_CHECK: 
            // msgid = 135
            // 
            mavlink_terrain_check_t terrain_check;
            mavlink_msg_terrain_check_decode(&message, &(terrain_check));
            stream << "{\"type\":\"TERRAIN_CHECK"
                << "\",\"system_id\":\"" << sysid
                << "\",\"lat\":\"" << terrain_check.lat
                << "\",\"lon\":\"" << terrain_check.lon
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_TERRAIN_REPORT: 
            // msgid = 136
            // 
            mavlink_terrain_report_t terrain_report;
            mavlink_msg_terrain_report_decode(&message, &(terrain_report));
            stream << "{\"type\":\"TERRAIN_REPORT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"lat\":\"" << terrain_report.lat
                << "\",\"lon\":\"" << terrain_report.lon
                << "\",\"spacing\":\"" << terrain_report.spacing
                << "\",\"terrain_height\":\"" << terrain_report.terrain_height
                << "\",\"current_height\":\"" << terrain_report.current_height
                << "\",\"pending\":\"" << terrain_report.pending
                << "\",\"loaded\":\"" << terrain_report.loaded
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SCALED_PRESSURE2: 
            // msgid = 137
            // 
            mavlink_scaled_pressure2_t scaled_pressure2;
            mavlink_msg_scaled_pressure2_decode(&message, &(scaled_pressure2));
            stream << "{\"type\":\"SCALED_PRESSURE2"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << scaled_pressure2.time_boot_ms
                << "\",\"press_abs\":\"" << scaled_pressure2.press_abs
                << "\",\"press_diff\":\"" << scaled_pressure2.press_diff
                << "\",\"temperature\":\"" << scaled_pressure2.temperature
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ATT_POS_MOCAP: 
            // msgid = 138
            // 
            mavlink_att_pos_mocap_t att_pos_mocap;
            mavlink_msg_att_pos_mocap_decode(&message, &(att_pos_mocap));
            stream << "{\"type\":\"ATT_POS_MOCAP"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << att_pos_mocap.time_usec
                << "\",\"q\":\"" << att_pos_mocap.q
                << "\",\"x\":\"" << att_pos_mocap.x
                << "\",\"y\":\"" << att_pos_mocap.y
                << "\",\"z\":\"" << att_pos_mocap.z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET: 
            // msgid = 139
            // 
            mavlink_set_actuator_control_target_t set_actuator_control_target;
            mavlink_msg_set_actuator_control_target_decode(&message, &(set_actuator_control_target));
            stream << "{\"type\":\"SET_ACTUATOR_CONTROL_TARGET"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << set_actuator_control_target.time_usec
                << "\",\"group_mlx\":\"" << unsigned(set_actuator_control_target.group_mlx)
                << "\",\"target_system\":\"" << unsigned(set_actuator_control_target.target_system)
                << "\",\"target_component\":\"" << unsigned(set_actuator_control_target.target_component)
                << "\",\"controls\":\"" << set_actuator_control_target.controls
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET: 
            // msgid = 140
            // 
            mavlink_actuator_control_target_t actuator_control_target;
            mavlink_msg_actuator_control_target_decode(&message, &(actuator_control_target));
            stream << "{\"type\":\"ACTUATOR_CONTROL_TARGET"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << actuator_control_target.time_usec
                << "\",\"group_mlx\":\"" << unsigned(actuator_control_target.group_mlx)
                << "\",\"controls\":\"" << actuator_control_target.controls
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_BATTERY_STATUS: 
            // msgid = 147
            // 
            mavlink_battery_status_t battery_status;
            mavlink_msg_battery_status_decode(&message, &(battery_status));
            stream << "{\"type\":\"BATTERY_STATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"id\":\"" << unsigned(battery_status.id)
                << "\",\"battery_function\":\"" << unsigned(battery_status.battery_function)
                << "\",\"type\":\"" << unsigned(battery_status.type)
                << "\",\"temperature\":\"" << battery_status.temperature
                << "\",\"voltages\":\"" << battery_status.voltages
                << "\",\"current_battery\":\"" << battery_status.current_battery
                << "\",\"current_consumed\":\"" << battery_status.current_consumed
                << "\",\"energy_consumed\":\"" << battery_status.energy_consumed
                << "\",\"battery_remaining\":\"" << battery_status.battery_remaining
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AUTOPILOT_VERSION: 
            // msgid = 148
            // 
            mavlink_autopilot_version_t autopilot_version;
            mavlink_msg_autopilot_version_decode(&message, &(autopilot_version));
            stream << "{\"type\":\"AUTOPILOT_VERSION"
                << "\",\"system_id\":\"" << sysid
                << "\",\"capabilities\":\"" << autopilot_version.capabilities
                << "\",\"flight_sw_version\":\"" << autopilot_version.flight_sw_version
                << "\",\"middleware_sw_version\":\"" << autopilot_version.middleware_sw_version
                << "\",\"os_sw_version\":\"" << autopilot_version.os_sw_version
                << "\",\"board_version\":\"" << autopilot_version.board_version
                << "\",\"flight_custom_version\":\"" << autopilot_version.flight_custom_version
                << "\",\"middleware_custom_version\":\"" << autopilot_version.middleware_custom_version
                << "\",\"os_custom_version\":\"" << autopilot_version.os_custom_version
                << "\",\"vendor_id\":\"" << autopilot_version.vendor_id
                << "\",\"product_id\":\"" << autopilot_version.product_id
                << "\",\"uid\":\"" << autopilot_version.uid
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_V2_EXTENSION: 
            // msgid = 248
            // 
            mavlink_v2_extension_t v2_extension;
            mavlink_msg_v2_extension_decode(&message, &(v2_extension));
            stream << "{\"type\":\"V2_EXTENSION"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_network\":\"" << unsigned(v2_extension.target_network)
                << "\",\"target_system\":\"" << unsigned(v2_extension.target_system)
                << "\",\"target_component\":\"" << unsigned(v2_extension.target_component)
                << "\",\"message_type\":\"" << v2_extension.message_type
                << "\",\"payload\":\"" << v2_extension.payload
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MEMORY_VECT: 
            // msgid = 249
            // 
            mavlink_memory_vect_t memory_vect;
            mavlink_msg_memory_vect_decode(&message, &(memory_vect));
            stream << "{\"type\":\"MEMORY_VECT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"address\":\"" << memory_vect.address
                << "\",\"ver\":\"" << unsigned(memory_vect.ver)
                << "\",\"type\":\"" << unsigned(memory_vect.type)
                << "\",\"value\":\"" << memory_vect.value
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DEBUG_VECT: 
            // msgid = 250
            // 
            mavlink_debug_vect_t debug_vect;
            mavlink_msg_debug_vect_decode(&message, &(debug_vect));
            stream << "{\"type\":\"DEBUG_VECT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"name\":\"" << debug_vect.name
                << "\",\"time_usec\":\"" << debug_vect.time_usec
                << "\",\"x\":\"" << debug_vect.x
                << "\",\"y\":\"" << debug_vect.y
                << "\",\"z\":\"" << debug_vect.z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_NAMED_VALUE_FLOAT: 
            // msgid = 251
            // 
            mavlink_named_value_float_t named_value_float;
            mavlink_msg_named_value_float_decode(&message, &(named_value_float));
            stream << "{\"type\":\"NAMED_VALUE_FLOAT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << named_value_float.time_boot_ms
                << "\",\"name\":\"" << named_value_float.name
                << "\",\"value\":\"" << named_value_float.value
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_NAMED_VALUE_INT: 
            // msgid = 252
            // 
            mavlink_named_value_int_t named_value_int;
            mavlink_msg_named_value_int_decode(&message, &(named_value_int));
            stream << "{\"type\":\"NAMED_VALUE_INT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << named_value_int.time_boot_ms
                << "\",\"name\":\"" << named_value_int.name
                << "\",\"value\":\"" << named_value_int.value
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_STATUSTEXT: 
            // msgid = 253
            // 
            mavlink_statustext_t statustext;
            mavlink_msg_statustext_decode(&message, &(statustext));
            stream << "{\"type\":\"STATUSTEXT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"severity\":\"" << unsigned(statustext.severity)
                << "\",\"text\":\"" << statustext.text
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DEBUG: 
            // msgid = 254
            // 
            mavlink_debug_t debug;
            mavlink_msg_debug_decode(&message, &(debug));
            stream << "{\"type\":\"DEBUG"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_boot_ms\":\"" << debug.time_boot_ms
                << "\",\"ind\":\"" << unsigned(debug.ind)
                << "\",\"value\":\"" << debug.value
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SENSOR_OFFSETS: 
            // msgid = 150
            // 
            mavlink_sensor_offsets_t sensor_offsets;
            mavlink_msg_sensor_offsets_decode(&message, &(sensor_offsets));
            stream << "{\"type\":\"SENSOR_OFFSETS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"mag_ofs_x\":\"" << sensor_offsets.mag_ofs_x
                << "\",\"mag_ofs_y\":\"" << sensor_offsets.mag_ofs_y
                << "\",\"mag_ofs_z\":\"" << sensor_offsets.mag_ofs_z
                << "\",\"mag_declination\":\"" << sensor_offsets.mag_declination
                << "\",\"raw_press\":\"" << sensor_offsets.raw_press
                << "\",\"raw_temp\":\"" << sensor_offsets.raw_temp
                << "\",\"gyro_cal_x\":\"" << sensor_offsets.gyro_cal_x
                << "\",\"gyro_cal_y\":\"" << sensor_offsets.gyro_cal_y
                << "\",\"gyro_cal_z\":\"" << sensor_offsets.gyro_cal_z
                << "\",\"accel_cal_x\":\"" << sensor_offsets.accel_cal_x
                << "\",\"accel_cal_y\":\"" << sensor_offsets.accel_cal_y
                << "\",\"accel_cal_z\":\"" << sensor_offsets.accel_cal_z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_MAG_OFFSETS: 
            // msgid = 151
            // 
            mavlink_set_mag_offsets_t set_mag_offsets;
            mavlink_msg_set_mag_offsets_decode(&message, &(set_mag_offsets));
            stream << "{\"type\":\"SET_MAG_OFFSETS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(set_mag_offsets.target_system)
                << "\",\"target_component\":\"" << unsigned(set_mag_offsets.target_component)
                << "\",\"mag_ofs_x\":\"" << set_mag_offsets.mag_ofs_x
                << "\",\"mag_ofs_y\":\"" << set_mag_offsets.mag_ofs_y
                << "\",\"mag_ofs_z\":\"" << set_mag_offsets.mag_ofs_z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MEMINFO: 
            // msgid = 152
            // 
            mavlink_meminfo_t meminfo;
            mavlink_msg_meminfo_decode(&message, &(meminfo));
            stream << "{\"type\":\"MEMINFO"
                << "\",\"system_id\":\"" << sysid
                << "\",\"brkval\":\"" << meminfo.brkval
                << "\",\"freemem\":\"" << meminfo.freemem
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AP_ADC: 
            // msgid = 153
            // 
            mavlink_ap_adc_t ap_adc;
            mavlink_msg_ap_adc_decode(&message, &(ap_adc));
            stream << "{\"type\":\"AP_ADC"
                << "\",\"system_id\":\"" << sysid
                << "\",\"adc1\":\"" << ap_adc.adc1
                << "\",\"adc2\":\"" << ap_adc.adc2
                << "\",\"adc3\":\"" << ap_adc.adc3
                << "\",\"adc4\":\"" << ap_adc.adc4
                << "\",\"adc5\":\"" << ap_adc.adc5
                << "\",\"adc6\":\"" << ap_adc.adc6
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DIGICAM_CONFIGURE: 
            // msgid = 154
            // 
            mavlink_digicam_configure_t digicam_configure;
            mavlink_msg_digicam_configure_decode(&message, &(digicam_configure));
            stream << "{\"type\":\"DIGICAM_CONFIGURE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(digicam_configure.target_system)
                << "\",\"target_component\":\"" << unsigned(digicam_configure.target_component)
                << "\",\"mode\":\"" << unsigned(digicam_configure.mode)
                << "\",\"shutter_speed\":\"" << digicam_configure.shutter_speed
                << "\",\"aperture\":\"" << unsigned(digicam_configure.aperture)
                << "\",\"iso\":\"" << unsigned(digicam_configure.iso)
                << "\",\"exposure_type\":\"" << unsigned(digicam_configure.exposure_type)
                << "\",\"command_id\":\"" << unsigned(digicam_configure.command_id)
                << "\",\"engine_cut_off\":\"" << unsigned(digicam_configure.engine_cut_off)
                << "\",\"extra_param\":\"" << unsigned(digicam_configure.extra_param)
                << "\",\"extra_value\":\"" << digicam_configure.extra_value
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DIGICAM_CONTROL: 
            // msgid = 155
            // 
            mavlink_digicam_control_t digicam_control;
            mavlink_msg_digicam_control_decode(&message, &(digicam_control));
            stream << "{\"type\":\"DIGICAM_CONTROL"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(digicam_control.target_system)
                << "\",\"target_component\":\"" << unsigned(digicam_control.target_component)
                << "\",\"session\":\"" << unsigned(digicam_control.session)
                << "\",\"zoom_pos\":\"" << unsigned(digicam_control.zoom_pos)
                << "\",\"zoom_step\":\"" << digicam_control.zoom_step
                << "\",\"focus_lock\":\"" << unsigned(digicam_control.focus_lock)
                << "\",\"shot\":\"" << unsigned(digicam_control.shot)
                << "\",\"command_id\":\"" << unsigned(digicam_control.command_id)
                << "\",\"extra_param\":\"" << unsigned(digicam_control.extra_param)
                << "\",\"extra_value\":\"" << digicam_control.extra_value
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MOUNT_CONFIGURE: 
            // msgid = 156
            // 
            mavlink_mount_configure_t mount_configure;
            mavlink_msg_mount_configure_decode(&message, &(mount_configure));
            stream << "{\"type\":\"MOUNT_CONFIGURE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mount_configure.target_system)
                << "\",\"target_component\":\"" << unsigned(mount_configure.target_component)
                << "\",\"mount_mode\":\"" << unsigned(mount_configure.mount_mode)
                << "\",\"stab_roll\":\"" << unsigned(mount_configure.stab_roll)
                << "\",\"stab_pitch\":\"" << unsigned(mount_configure.stab_pitch)
                << "\",\"stab_yaw\":\"" << unsigned(mount_configure.stab_yaw)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MOUNT_CONTROL: 
            // msgid = 157
            // 
            mavlink_mount_control_t mount_control;
            mavlink_msg_mount_control_decode(&message, &(mount_control));
            stream << "{\"type\":\"MOUNT_CONTROL"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mount_control.target_system)
                << "\",\"target_component\":\"" << unsigned(mount_control.target_component)
                << "\",\"input_a\":\"" << mount_control.input_a
                << "\",\"input_b\":\"" << mount_control.input_b
                << "\",\"input_c\":\"" << mount_control.input_c
                << "\",\"save_position\":\"" << unsigned(mount_control.save_position)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MOUNT_STATUS: 
            // msgid = 158
            // 
            mavlink_mount_status_t mount_status;
            mavlink_msg_mount_status_decode(&message, &(mount_status));
            stream << "{\"type\":\"MOUNT_STATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(mount_status.target_system)
                << "\",\"target_component\":\"" << unsigned(mount_status.target_component)
                << "\",\"pointing_a\":\"" << mount_status.pointing_a
                << "\",\"pointing_b\":\"" << mount_status.pointing_b
                << "\",\"pointing_c\":\"" << mount_status.pointing_c
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_FENCE_POINT: 
            // msgid = 160
            // 
            mavlink_fence_point_t fence_point;
            mavlink_msg_fence_point_decode(&message, &(fence_point));
            stream << "{\"type\":\"FENCE_POINT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(fence_point.target_system)
                << "\",\"target_component\":\"" << unsigned(fence_point.target_component)
                << "\",\"idx\":\"" << unsigned(fence_point.idx)
                << "\",\"count\":\"" << unsigned(fence_point.count)
                << "\",\"lat\":\"" << fence_point.lat
                << "\",\"lng\":\"" << fence_point.lng
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_FENCE_FETCH_POINT: 
            // msgid = 161
            // 
            mavlink_fence_fetch_point_t fence_fetch_point;
            mavlink_msg_fence_fetch_point_decode(&message, &(fence_fetch_point));
            stream << "{\"type\":\"FENCE_FETCH_POINT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(fence_fetch_point.target_system)
                << "\",\"target_component\":\"" << unsigned(fence_fetch_point.target_component)
                << "\",\"idx\":\"" << unsigned(fence_fetch_point.idx)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_FENCE_STATUS: 
            // msgid = 162
            // 
            mavlink_fence_status_t fence_status;
            mavlink_msg_fence_status_decode(&message, &(fence_status));
            stream << "{\"type\":\"FENCE_STATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"breach_status\":\"" << unsigned(fence_status.breach_status)
                << "\",\"breach_count\":\"" << fence_status.breach_count
                << "\",\"breach_type\":\"" << unsigned(fence_status.breach_type)
                << "\",\"breach_time\":\"" << fence_status.breach_time
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AHRS: 
            // msgid = 163
            // 
            mavlink_ahrs_t ahrs;
            mavlink_msg_ahrs_decode(&message, &(ahrs));
            stream << "{\"type\":\"AHRS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"omegaIx\":\"" << ahrs.omegaIx
                << "\",\"omegaIy\":\"" << ahrs.omegaIy
                << "\",\"omegaIz\":\"" << ahrs.omegaIz
                << "\",\"accel_weight\":\"" << ahrs.accel_weight
                << "\",\"renorm_val\":\"" << ahrs.renorm_val
                << "\",\"error_rp\":\"" << ahrs.error_rp
                << "\",\"error_yaw\":\"" << ahrs.error_yaw
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SIMSTATE: 
            // msgid = 164
            // 
            mavlink_simstate_t simstate;
            mavlink_msg_simstate_decode(&message, &(simstate));
            stream << "{\"type\":\"SIMSTATE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"roll\":\"" << simstate.roll
                << "\",\"pitch\":\"" << simstate.pitch
                << "\",\"yaw\":\"" << simstate.yaw
                << "\",\"xacc\":\"" << simstate.xacc
                << "\",\"yacc\":\"" << simstate.yacc
                << "\",\"zacc\":\"" << simstate.zacc
                << "\",\"xgyro\":\"" << simstate.xgyro
                << "\",\"ygyro\":\"" << simstate.ygyro
                << "\",\"zgyro\":\"" << simstate.zgyro
                << "\",\"lat\":\"" << simstate.lat
                << "\",\"lng\":\"" << simstate.lng
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HWSTATUS: 
            // msgid = 165
            // 
            mavlink_hwstatus_t hwstatus;
            mavlink_msg_hwstatus_decode(&message, &(hwstatus));
            stream << "{\"type\":\"HWSTATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"Vcc\":\"" << hwstatus.Vcc
                << "\",\"I2Cerr\":\"" << unsigned(hwstatus.I2Cerr)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RADIO: 
            // msgid = 166
            // 
            mavlink_radio_t radio;
            mavlink_msg_radio_decode(&message, &(radio));
            stream << "{\"type\":\"RADIO"
                << "\",\"system_id\":\"" << sysid
                << "\",\"rssi\":\"" << unsigned(radio.rssi)
                << "\",\"remrssi\":\"" << unsigned(radio.remrssi)
                << "\",\"txbuf\":\"" << unsigned(radio.txbuf)
                << "\",\"noise\":\"" << unsigned(radio.noise)
                << "\",\"remnoise\":\"" << unsigned(radio.remnoise)
                << "\",\"rxerrors\":\"" << radio.rxerrors
                << "\",\"fixed\":\"" << radio.fixed
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LIMITS_STATUS: 
            // msgid = 167
            // 
            mavlink_limits_status_t limits_status;
            mavlink_msg_limits_status_decode(&message, &(limits_status));
            stream << "{\"type\":\"LIMITS_STATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"limits_state\":\"" << unsigned(limits_status.limits_state)
                << "\",\"last_trigger\":\"" << limits_status.last_trigger
                << "\",\"last_action\":\"" << limits_status.last_action
                << "\",\"last_recovery\":\"" << limits_status.last_recovery
                << "\",\"last_clear\":\"" << limits_status.last_clear
                << "\",\"breach_count\":\"" << limits_status.breach_count
                << "\",\"mods_enabled\":\"" << unsigned(limits_status.mods_enabled)
                << "\",\"mods_required\":\"" << unsigned(limits_status.mods_required)
                << "\",\"mods_triggered\":\"" << unsigned(limits_status.mods_triggered)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_WIND: 
            // msgid = 168
            // 
            mavlink_wind_t wind;
            mavlink_msg_wind_decode(&message, &(wind));
            stream << "{\"type\":\"WIND"
                << "\",\"system_id\":\"" << sysid
                << "\",\"direction\":\"" << wind.direction
                << "\",\"speed\":\"" << wind.speed
                << "\",\"speed_z\":\"" << wind.speed_z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DATA16: 
            // msgid = 169
            // 
            mavlink_data16_t data16;
            mavlink_msg_data16_decode(&message, &(data16));
            stream << "{\"type\":\"DATA16"
                << "\",\"system_id\":\"" << sysid
                << "\",\"type\":\"" << unsigned(data16.type)
                << "\",\"len\":\"" << unsigned(data16.len)
                << "\",\"data\":\"" << data16.data
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DATA32: 
            // msgid = 170
            // 
            mavlink_data32_t data32;
            mavlink_msg_data32_decode(&message, &(data32));
            stream << "{\"type\":\"DATA32"
                << "\",\"system_id\":\"" << sysid
                << "\",\"type\":\"" << unsigned(data32.type)
                << "\",\"len\":\"" << unsigned(data32.len)
                << "\",\"data\":\"" << data32.data
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DATA64: 
            // msgid = 171
            // 
            mavlink_data64_t data64;
            mavlink_msg_data64_decode(&message, &(data64));
            stream << "{\"type\":\"DATA64"
                << "\",\"system_id\":\"" << sysid
                << "\",\"type\":\"" << unsigned(data64.type)
                << "\",\"len\":\"" << unsigned(data64.len)
                << "\",\"data\":\"" << data64.data
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DATA96: 
            // msgid = 172
            // 
            mavlink_data96_t data96;
            mavlink_msg_data96_decode(&message, &(data96));
            stream << "{\"type\":\"DATA96"
                << "\",\"system_id\":\"" << sysid
                << "\",\"type\":\"" << unsigned(data96.type)
                << "\",\"len\":\"" << unsigned(data96.len)
                << "\",\"data\":\"" << data96.data
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RANGEFINDER: 
            // msgid = 173
            // 
            mavlink_rangefinder_t rangefinder;
            mavlink_msg_rangefinder_decode(&message, &(rangefinder));
            stream << "{\"type\":\"RANGEFINDER"
                << "\",\"system_id\":\"" << sysid
                << "\",\"distance\":\"" << rangefinder.distance
                << "\",\"voltage\":\"" << rangefinder.voltage
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AIRSPEED_AUTOCAL: 
            // msgid = 174
            // 
            mavlink_airspeed_autocal_t airspeed_autocal;
            mavlink_msg_airspeed_autocal_decode(&message, &(airspeed_autocal));
            stream << "{\"type\":\"AIRSPEED_AUTOCAL"
                << "\",\"system_id\":\"" << sysid
                << "\",\"vx\":\"" << airspeed_autocal.vx
                << "\",\"vy\":\"" << airspeed_autocal.vy
                << "\",\"vz\":\"" << airspeed_autocal.vz
                << "\",\"diff_pressure\":\"" << airspeed_autocal.diff_pressure
                << "\",\"EAS2TAS\":\"" << airspeed_autocal.EAS2TAS
                << "\",\"ratio\":\"" << airspeed_autocal.ratio
                << "\",\"state_x\":\"" << airspeed_autocal.state_x
                << "\",\"state_y\":\"" << airspeed_autocal.state_y
                << "\",\"state_z\":\"" << airspeed_autocal.state_z
                << "\",\"Pax\":\"" << airspeed_autocal.Pax
                << "\",\"Pby\":\"" << airspeed_autocal.Pby
                << "\",\"Pcz\":\"" << airspeed_autocal.Pcz
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RALLY_POINT: 
            // msgid = 175
            // 
            mavlink_rally_point_t rally_point;
            mavlink_msg_rally_point_decode(&message, &(rally_point));
            stream << "{\"type\":\"RALLY_POINT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(rally_point.target_system)
                << "\",\"target_component\":\"" << unsigned(rally_point.target_component)
                << "\",\"idx\":\"" << unsigned(rally_point.idx)
                << "\",\"count\":\"" << unsigned(rally_point.count)
                << "\",\"lat\":\"" << rally_point.lat
                << "\",\"lng\":\"" << rally_point.lng
                << "\",\"alt\":\"" << rally_point.alt
                << "\",\"break_alt\":\"" << rally_point.break_alt
                << "\",\"land_dir\":\"" << rally_point.land_dir
                << "\",\"flags\":\"" << unsigned(rally_point.flags)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RALLY_FETCH_POINT: 
            // msgid = 176
            // 
            mavlink_rally_fetch_point_t rally_fetch_point;
            mavlink_msg_rally_fetch_point_decode(&message, &(rally_fetch_point));
            stream << "{\"type\":\"RALLY_FETCH_POINT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(rally_fetch_point.target_system)
                << "\",\"target_component\":\"" << unsigned(rally_fetch_point.target_component)
                << "\",\"idx\":\"" << unsigned(rally_fetch_point.idx)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_COMPASSMOT_STATUS: 
            // msgid = 177
            // 
            mavlink_compassmot_status_t compassmot_status;
            mavlink_msg_compassmot_status_decode(&message, &(compassmot_status));
            stream << "{\"type\":\"COMPASSMOT_STATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"throttle\":\"" << compassmot_status.throttle
                << "\",\"current\":\"" << compassmot_status.current
                << "\",\"interference\":\"" << compassmot_status.interference
                << "\",\"CompensationX\":\"" << compassmot_status.CompensationX
                << "\",\"CompensationY\":\"" << compassmot_status.CompensationY
                << "\",\"CompensationZ\":\"" << compassmot_status.CompensationZ
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AHRS2: 
            // msgid = 178
            // 
            mavlink_ahrs2_t ahrs2;
            mavlink_msg_ahrs2_decode(&message, &(ahrs2));
            stream << "{\"type\":\"AHRS2"
                << "\",\"system_id\":\"" << sysid
                << "\",\"roll\":\"" << ahrs2.roll
                << "\",\"pitch\":\"" << ahrs2.pitch
                << "\",\"yaw\":\"" << ahrs2.yaw
                << "\",\"altitude\":\"" << ahrs2.altitude
                << "\",\"lat\":\"" << ahrs2.lat
                << "\",\"lng\":\"" << ahrs2.lng
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_CAMERA_STATUS: 
            // msgid = 179
            // 
            mavlink_camera_status_t camera_status;
            mavlink_msg_camera_status_decode(&message, &(camera_status));
            stream << "{\"type\":\"CAMERA_STATUS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << camera_status.time_usec
                << "\",\"target_system\":\"" << unsigned(camera_status.target_system)
                << "\",\"cam_idx\":\"" << unsigned(camera_status.cam_idx)
                << "\",\"img_idx\":\"" << camera_status.img_idx
                << "\",\"event_id\":\"" << unsigned(camera_status.event_id)
                << "\",\"p1\":\"" << camera_status.p1
                << "\",\"p2\":\"" << camera_status.p2
                << "\",\"p3\":\"" << camera_status.p3
                << "\",\"p4\":\"" << camera_status.p4
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_CAMERA_FEEDBACK: 
            // msgid = 180
            // 
            mavlink_camera_feedback_t camera_feedback;
            mavlink_msg_camera_feedback_decode(&message, &(camera_feedback));
            stream << "{\"type\":\"CAMERA_FEEDBACK"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << camera_feedback.time_usec
                << "\",\"target_system\":\"" << unsigned(camera_feedback.target_system)
                << "\",\"cam_idx\":\"" << unsigned(camera_feedback.cam_idx)
                << "\",\"img_idx\":\"" << camera_feedback.img_idx
                << "\",\"lat\":\"" << camera_feedback.lat
                << "\",\"lng\":\"" << camera_feedback.lng
                << "\",\"alt_msl\":\"" << camera_feedback.alt_msl
                << "\",\"alt_rel\":\"" << camera_feedback.alt_rel
                << "\",\"roll\":\"" << camera_feedback.roll
                << "\",\"pitch\":\"" << camera_feedback.pitch
                << "\",\"yaw\":\"" << camera_feedback.yaw
                << "\",\"foc_len\":\"" << camera_feedback.foc_len
                << "\",\"flags\":\"" << unsigned(camera_feedback.flags)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_BATTERY2: 
            // msgid = 181
            // 
            mavlink_battery2_t battery2;
            mavlink_msg_battery2_decode(&message, &(battery2));
            stream << "{\"type\":\"BATTERY2"
                << "\",\"system_id\":\"" << sysid
                << "\",\"voltage\":\"" << battery2.voltage
                << "\",\"current_battery\":\"" << battery2.current_battery
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AHRS3: 
            // msgid = 182
            // 
            mavlink_ahrs3_t ahrs3;
            mavlink_msg_ahrs3_decode(&message, &(ahrs3));
            stream << "{\"type\":\"AHRS3"
                << "\",\"system_id\":\"" << sysid
                << "\",\"roll\":\"" << ahrs3.roll
                << "\",\"pitch\":\"" << ahrs3.pitch
                << "\",\"yaw\":\"" << ahrs3.yaw
                << "\",\"altitude\":\"" << ahrs3.altitude
                << "\",\"lat\":\"" << ahrs3.lat
                << "\",\"lng\":\"" << ahrs3.lng
                << "\",\"v1\":\"" << ahrs3.v1
                << "\",\"v2\":\"" << ahrs3.v2
                << "\",\"v3\":\"" << ahrs3.v3
                << "\",\"v4\":\"" << ahrs3.v4
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AUTOPILOT_VERSION_REQUEST: 
            // msgid = 183
            // 
            mavlink_autopilot_version_request_t autopilot_version_request;
            mavlink_msg_autopilot_version_request_decode(&message, &(autopilot_version_request));
            stream << "{\"type\":\"AUTOPILOT_VERSION_REQUEST"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(autopilot_version_request.target_system)
                << "\",\"target_component\":\"" << unsigned(autopilot_version_request.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LED_CONTROL: 
            // msgid = 186
            // 
            mavlink_led_control_t led_control;
            mavlink_msg_led_control_decode(&message, &(led_control));
            stream << "{\"type\":\"LED_CONTROL"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(led_control.target_system)
                << "\",\"target_component\":\"" << unsigned(led_control.target_component)
                << "\",\"instance\":\"" << unsigned(led_control.instance)
                << "\",\"pattern\":\"" << unsigned(led_control.pattern)
                << "\",\"custom_len\":\"" << unsigned(led_control.custom_len)
                << "\",\"custom_bytes\":\"" << led_control.custom_bytes
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MAG_CAL_PROGRESS: 
            // msgid = 191
            // 
            mavlink_mag_cal_progress_t mag_cal_progress;
            mavlink_msg_mag_cal_progress_decode(&message, &(mag_cal_progress));
            stream << "{\"type\":\"MAG_CAL_PROGRESS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"compass_id\":\"" << unsigned(mag_cal_progress.compass_id)
                << "\",\"cal_mask\":\"" << unsigned(mag_cal_progress.cal_mask)
                << "\",\"cal_status\":\"" << unsigned(mag_cal_progress.cal_status)
                << "\",\"attempt\":\"" << unsigned(mag_cal_progress.attempt)
                << "\",\"completion_pct\":\"" << unsigned(mag_cal_progress.completion_pct)
                << "\",\"completion_mask\":\"" << mag_cal_progress.completion_mask
                << "\",\"direction_x\":\"" << mag_cal_progress.direction_x
                << "\",\"direction_y\":\"" << mag_cal_progress.direction_y
                << "\",\"direction_z\":\"" << mag_cal_progress.direction_z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MAG_CAL_REPORT: 
            // msgid = 192
            // 
            mavlink_mag_cal_report_t mag_cal_report;
            mavlink_msg_mag_cal_report_decode(&message, &(mag_cal_report));
            stream << "{\"type\":\"MAG_CAL_REPORT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"compass_id\":\"" << unsigned(mag_cal_report.compass_id)
                << "\",\"cal_mask\":\"" << unsigned(mag_cal_report.cal_mask)
                << "\",\"cal_status\":\"" << unsigned(mag_cal_report.cal_status)
                << "\",\"autosaved\":\"" << unsigned(mag_cal_report.autosaved)
                << "\",\"fitness\":\"" << mag_cal_report.fitness
                << "\",\"ofs_x\":\"" << mag_cal_report.ofs_x
                << "\",\"ofs_y\":\"" << mag_cal_report.ofs_y
                << "\",\"ofs_z\":\"" << mag_cal_report.ofs_z
                << "\",\"diag_x\":\"" << mag_cal_report.diag_x
                << "\",\"diag_y\":\"" << mag_cal_report.diag_y
                << "\",\"diag_z\":\"" << mag_cal_report.diag_z
                << "\",\"offdiag_x\":\"" << mag_cal_report.offdiag_x
                << "\",\"offdiag_y\":\"" << mag_cal_report.offdiag_y
                << "\",\"offdiag_z\":\"" << mag_cal_report.offdiag_z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_EKF_STATUS_REPORT: 
            // msgid = 193
            // 
            mavlink_ekf_status_report_t ekf_status_report;
            mavlink_msg_ekf_status_report_decode(&message, &(ekf_status_report));
            stream << "{\"type\":\"EKF_STATUS_REPORT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"flags\":\"" << ekf_status_report.flags
                << "\",\"velocity_variance\":\"" << ekf_status_report.velocity_variance
                << "\",\"pos_horiz_variance\":\"" << ekf_status_report.pos_horiz_variance
                << "\",\"pos_vert_variance\":\"" << ekf_status_report.pos_vert_variance
                << "\",\"compass_variance\":\"" << ekf_status_report.compass_variance
                << "\",\"terrain_alt_variance\":\"" << ekf_status_report.terrain_alt_variance
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PID_TUNING: 
            // msgid = 194
            // 
            mavlink_pid_tuning_t pid_tuning;
            mavlink_msg_pid_tuning_decode(&message, &(pid_tuning));
            stream << "{\"type\":\"PID_TUNING"
                << "\",\"system_id\":\"" << sysid
                << "\",\"axis\":\"" << unsigned(pid_tuning.axis)
                << "\",\"desired\":\"" << pid_tuning.desired
                << "\",\"achieved\":\"" << pid_tuning.achieved
                << "\",\"FF\":\"" << pid_tuning.FF
                << "\",\"P\":\"" << pid_tuning.P
                << "\",\"I\":\"" << pid_tuning.I
                << "\",\"D\":\"" << pid_tuning.D
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_REPORT: 
            // msgid = 200
            // 
            mavlink_gimbal_report_t gimbal_report;
            mavlink_msg_gimbal_report_decode(&message, &(gimbal_report));
            stream << "{\"type\":\"GIMBAL_REPORT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gimbal_report.target_system)
                << "\",\"target_component\":\"" << unsigned(gimbal_report.target_component)
                << "\",\"delta_time\":\"" << gimbal_report.delta_time
                << "\",\"delta_angle_x\":\"" << gimbal_report.delta_angle_x
                << "\",\"delta_angle_y\":\"" << gimbal_report.delta_angle_y
                << "\",\"delta_angle_z\":\"" << gimbal_report.delta_angle_z
                << "\",\"delta_velocity_x\":\"" << gimbal_report.delta_velocity_x
                << "\",\"delta_velocity_y\":\"" << gimbal_report.delta_velocity_y
                << "\",\"delta_velocity_z\":\"" << gimbal_report.delta_velocity_z
                << "\",\"joint_roll\":\"" << gimbal_report.joint_roll
                << "\",\"joint_el\":\"" << gimbal_report.joint_el
                << "\",\"joint_az\":\"" << gimbal_report.joint_az
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_CONTROL: 
            // msgid = 201
            // 
            mavlink_gimbal_control_t gimbal_control;
            mavlink_msg_gimbal_control_decode(&message, &(gimbal_control));
            stream << "{\"type\":\"GIMBAL_CONTROL"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gimbal_control.target_system)
                << "\",\"target_component\":\"" << unsigned(gimbal_control.target_component)
                << "\",\"demanded_rate_x\":\"" << gimbal_control.demanded_rate_x
                << "\",\"demanded_rate_y\":\"" << gimbal_control.demanded_rate_y
                << "\",\"demanded_rate_z\":\"" << gimbal_control.demanded_rate_z
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_RESET: 
            // msgid = 202
            // 
            mavlink_gimbal_reset_t gimbal_reset;
            mavlink_msg_gimbal_reset_decode(&message, &(gimbal_reset));
            stream << "{\"type\":\"GIMBAL_RESET"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gimbal_reset.target_system)
                << "\",\"target_component\":\"" << unsigned(gimbal_reset.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_AXIS_CALIBRATION_PROGRESS: 
            // msgid = 203
            // 
            mavlink_gimbal_axis_calibration_progress_t gimbal_axis_calibration_progress;
            mavlink_msg_gimbal_axis_calibration_progress_decode(&message, &(gimbal_axis_calibration_progress));
            stream << "{\"type\":\"GIMBAL_AXIS_CALIBRATION_PROGRESS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"calibration_axis\":\"" << unsigned(gimbal_axis_calibration_progress.calibration_axis)
                << "\",\"calibration_progress\":\"" << unsigned(gimbal_axis_calibration_progress.calibration_progress)
                << "\",\"calibration_status\":\"" << unsigned(gimbal_axis_calibration_progress.calibration_status)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_SET_HOME_OFFSETS: 
            // msgid = 204
            // 
            mavlink_gimbal_set_home_offsets_t gimbal_set_home_offsets;
            mavlink_msg_gimbal_set_home_offsets_decode(&message, &(gimbal_set_home_offsets));
            stream << "{\"type\":\"GIMBAL_SET_HOME_OFFSETS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gimbal_set_home_offsets.target_system)
                << "\",\"target_component\":\"" << unsigned(gimbal_set_home_offsets.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_HOME_OFFSET_CALIBRATION_RESULT: 
            // msgid = 205
            // 
            mavlink_gimbal_home_offset_calibration_result_t gimbal_home_offset_calibration_result;
            mavlink_msg_gimbal_home_offset_calibration_result_decode(&message, &(gimbal_home_offset_calibration_result));
            stream << "{\"type\":\"GIMBAL_HOME_OFFSET_CALIBRATION_RESULT"
                << "\",\"system_id\":\"" << sysid
                << "\",\"calibration_result\":\"" << unsigned(gimbal_home_offset_calibration_result.calibration_result)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_SET_FACTORY_PARAMETERS: 
            // msgid = 206
            // 
            mavlink_gimbal_set_factory_parameters_t gimbal_set_factory_parameters;
            mavlink_msg_gimbal_set_factory_parameters_decode(&message, &(gimbal_set_factory_parameters));
            stream << "{\"type\":\"GIMBAL_SET_FACTORY_PARAMETERS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gimbal_set_factory_parameters.target_system)
                << "\",\"target_component\":\"" << unsigned(gimbal_set_factory_parameters.target_component)
                << "\",\"magic_1\":\"" << gimbal_set_factory_parameters.magic_1
                << "\",\"magic_2\":\"" << gimbal_set_factory_parameters.magic_2
                << "\",\"magic_3\":\"" << gimbal_set_factory_parameters.magic_3
                << "\",\"assembly_year\":\"" << gimbal_set_factory_parameters.assembly_year
                << "\",\"assembly_month\":\"" << unsigned(gimbal_set_factory_parameters.assembly_month)
                << "\",\"assembly_day\":\"" << unsigned(gimbal_set_factory_parameters.assembly_day)
                << "\",\"assembly_hour\":\"" << unsigned(gimbal_set_factory_parameters.assembly_hour)
                << "\",\"assembly_minute\":\"" << unsigned(gimbal_set_factory_parameters.assembly_minute)
                << "\",\"assembly_second\":\"" << unsigned(gimbal_set_factory_parameters.assembly_second)
                << "\",\"serial_number_pt_1\":\"" << gimbal_set_factory_parameters.serial_number_pt_1
                << "\",\"serial_number_pt_2\":\"" << gimbal_set_factory_parameters.serial_number_pt_2
                << "\",\"serial_number_pt_3\":\"" << gimbal_set_factory_parameters.serial_number_pt_3
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_FACTORY_PARAMETERS_LOADED: 
            // msgid = 207
            // 
            mavlink_gimbal_factory_parameters_loaded_t gimbal_factory_parameters_loaded;
            mavlink_msg_gimbal_factory_parameters_loaded_decode(&message, &(gimbal_factory_parameters_loaded));
            stream << "{\"type\":\"GIMBAL_FACTORY_PARAMETERS_LOADED"
                << "\",\"system_id\":\"" << sysid
                << "\",\"dummy\":\"" << unsigned(gimbal_factory_parameters_loaded.dummy)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_ERASE_FIRMWARE_AND_CONFIG: 
            // msgid = 208
            // 
            mavlink_gimbal_erase_firmware_and_config_t gimbal_erase_firmware_and_config;
            mavlink_msg_gimbal_erase_firmware_and_config_decode(&message, &(gimbal_erase_firmware_and_config));
            stream << "{\"type\":\"GIMBAL_ERASE_FIRMWARE_AND_CONFIG"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gimbal_erase_firmware_and_config.target_system)
                << "\",\"target_component\":\"" << unsigned(gimbal_erase_firmware_and_config.target_component)
                << "\",\"knock\":\"" << gimbal_erase_firmware_and_config.knock
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_PERFORM_FACTORY_TESTS: 
            // msgid = 209
            // 
            mavlink_gimbal_perform_factory_tests_t gimbal_perform_factory_tests;
            mavlink_msg_gimbal_perform_factory_tests_decode(&message, &(gimbal_perform_factory_tests));
            stream << "{\"type\":\"GIMBAL_PERFORM_FACTORY_TESTS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gimbal_perform_factory_tests.target_system)
                << "\",\"target_component\":\"" << unsigned(gimbal_perform_factory_tests.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GIMBAL_REPORT_FACTORY_TESTS_PROGRESS: 
            // msgid = 210
            // 
            mavlink_gimbal_report_factory_tests_progress_t gimbal_report_factory_tests_progress;
            mavlink_msg_gimbal_report_factory_tests_progress_decode(&message, &(gimbal_report_factory_tests_progress));
            stream << "{\"type\":\"GIMBAL_REPORT_FACTORY_TESTS_PROGRESS"
                << "\",\"system_id\":\"" << sysid
                << "\",\"test\":\"" << unsigned(gimbal_report_factory_tests_progress.test)
                << "\",\"test_section\":\"" << unsigned(gimbal_report_factory_tests_progress.test_section)
                << "\",\"test_section_progress\":\"" << unsigned(gimbal_report_factory_tests_progress.test_section_progress)
                << "\",\"test_status\":\"" << unsigned(gimbal_report_factory_tests_progress.test_status)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GOPRO_POWER_ON: 
            // msgid = 215
            // 
            mavlink_gopro_power_on_t gopro_power_on;
            mavlink_msg_gopro_power_on_decode(&message, &(gopro_power_on));
            stream << "{\"type\":\"GOPRO_POWER_ON"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gopro_power_on.target_system)
                << "\",\"target_component\":\"" << unsigned(gopro_power_on.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GOPRO_POWER_OFF: 
            // msgid = 216
            // 
            mavlink_gopro_power_off_t gopro_power_off;
            mavlink_msg_gopro_power_off_decode(&message, &(gopro_power_off));
            stream << "{\"type\":\"GOPRO_POWER_OFF"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gopro_power_off.target_system)
                << "\",\"target_component\":\"" << unsigned(gopro_power_off.target_component)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GOPRO_COMMAND: 
            // msgid = 217
            // 
            mavlink_gopro_command_t gopro_command;
            mavlink_msg_gopro_command_decode(&message, &(gopro_command));
            stream << "{\"type\":\"GOPRO_COMMAND"
                << "\",\"system_id\":\"" << sysid
                << "\",\"target_system\":\"" << unsigned(gopro_command.target_system)
                << "\",\"target_component\":\"" << unsigned(gopro_command.target_component)
                << "\",\"gp_cmd_name_1\":\"" << unsigned(gopro_command.gp_cmd_name_1)
                << "\",\"gp_cmd_name_2\":\"" << unsigned(gopro_command.gp_cmd_name_2)
                << "\",\"gp_cmd_parm\":\"" << unsigned(gopro_command.gp_cmd_parm)
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GOPRO_RESPONSE: 
            // msgid = 218
            // 
            mavlink_gopro_response_t gopro_response;
            mavlink_msg_gopro_response_decode(&message, &(gopro_response));
            stream << "{\"type\":\"GOPRO_RESPONSE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"gp_cmd_name_1\":\"" << unsigned(gopro_response.gp_cmd_name_1)
                << "\",\"gp_cmd_name_2\":\"" << unsigned(gopro_response.gp_cmd_name_2)
                << "\",\"gp_cmd_response_status\":\"" << unsigned(gopro_response.gp_cmd_response_status)
                << "\",\"gp_cmd_response_argument\":\"" << unsigned(gopro_response.gp_cmd_response_argument)
                << "\",\"gp_cmd_result\":\"" << gopro_response.gp_cmd_result
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_NCAR_PTH: 
            // msgid = 240
            // 
            mavlink_ncar_pth_t ncar_pth;
            mavlink_msg_ncar_pth_decode(&message, &(ncar_pth));
            stream << "{\"type\":\"NCAR_PTH"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << ncar_pth.time_usec
                << "\",\"sample_num\":\"" << unsigned(ncar_pth.sample_num)
                << "\",\"pressure\":\"" << ncar_pth.pressure
                << "\",\"external_temp\":\"" << ncar_pth.external_temp
                << "\",\"rh1\":\"" << ncar_pth.rh1
                << "\",\"rh2\":\"" << ncar_pth.rh2
                << "\",\"internal_temp\":\"" << ncar_pth.internal_temp
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_VECTOR_NAV: 
            // msgid = 241
            // 
            mavlink_vector_nav_t vector_nav;
            mavlink_msg_vector_nav_decode(&message, &(vector_nav));
            stream << "{\"type\":\"VECTOR_NAV"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << vector_nav.time_usec
                << "\",\"time_startup\":\"" << vector_nav.time_startup
                << "\",\"time_gps\":\"" << vector_nav.time_gps
                << "\",\"time_syncln\":\"" << vector_nav.time_syncln
                << "\",\"yaw\":\"" << vector_nav.yaw
                << "\",\"pitch\":\"" << vector_nav.pitch
                << "\",\"roll\":\"" << vector_nav.roll
                << "\",\"qtn_0\":\"" << vector_nav.qtn_0
                << "\",\"qtn_1\":\"" << vector_nav.qtn_1
                << "\",\"qtn_2\":\"" << vector_nav.qtn_2
                << "\",\"qtn_3\":\"" << vector_nav.qtn_3
                << "\",\"rate_0\":\"" << vector_nav.rate_0
                << "\",\"rate_1\":\"" << vector_nav.rate_1
                << "\",\"rate_2\":\"" << vector_nav.rate_2
                << "\",\"lat\":\"" << vector_nav.lat
                << "\",\"lon\":\"" << vector_nav.lon
                << "\",\"alt\":\"" << vector_nav.alt
                << "\",\"vel_0\":\"" << vector_nav.vel_0
                << "\",\"vel_1\":\"" << vector_nav.vel_1
                << "\",\"vel_2\":\"" << vector_nav.vel_2
                << "\",\"accel_0\":\"" << vector_nav.accel_0
                << "\",\"accel_1\":\"" << vector_nav.accel_1
                << "\",\"accel_2\":\"" << vector_nav.accel_2
                << "\",\"imu_0\":\"" << vector_nav.imu_0
                << "\",\"imu_1\":\"" << vector_nav.imu_1
                << "\",\"imu_2\":\"" << vector_nav.imu_2
                << "\",\"imu_3\":\"" << vector_nav.imu_3
                << "\",\"imu_4\":\"" << vector_nav.imu_4
                << "\",\"imu_5\":\"" << vector_nav.imu_5
                << "\",\"mag_pres_0\":\"" << vector_nav.mag_pres_0
                << "\",\"mag_pres_1\":\"" << vector_nav.mag_pres_1
                << "\",\"mag_pres_2\":\"" << vector_nav.mag_pres_2
                << "\",\"mag_pres_3\":\"" << vector_nav.mag_pres_3
                << "\",\"mag_pres_4\":\"" << vector_nav.mag_pres_4
                << "\",\"delta_theta_0\":\"" << vector_nav.delta_theta_0
                << "\",\"delta_theta_1\":\"" << vector_nav.delta_theta_1
                << "\",\"delta_theta_2\":\"" << vector_nav.delta_theta_2
                << "\",\"delta_theta_3\":\"" << vector_nav.delta_theta_3
                << "\",\"delta_theta_4\":\"" << vector_nav.delta_theta_4
                << "\",\"delta_theta_5\":\"" << vector_nav.delta_theta_5
                << "\",\"delta_theta_6\":\"" << vector_nav.delta_theta_6
                << "\",\"ins_status\":\"" << vector_nav.ins_status
                << "\",\"syncln_cnt\":\"" << vector_nav.syncln_cnt
                << "\",\"gps_pps\":\"" << vector_nav.gps_pps
                << "\"}";

            json_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AEROPROBE: 
            // msgid = 242
            // 
            mavlink_aeroprobe_t aeroprobe;
            mavlink_msg_aeroprobe_decode(&message, &(aeroprobe));
            stream << "{\"type\":\"AEROPROBE"
                << "\",\"system_id\":\"" << sysid
                << "\",\"time_usec\":\"" << aeroprobe.time_usec
                << "\",\"time_device\":\"" << aeroprobe.time_device
                << "\",\"date\":\"" << aeroprobe.date
                << "\",\"velocity\":\"" << aeroprobe.velocity
                << "\",\"aoa\":\"" << aeroprobe.aoa
                << "\",\"aos\":\"" << aeroprobe.aos
                << "\",\"pa\":\"" << aeroprobe.pa
                << "\",\"ps\":\"" << aeroprobe.ps
                << "\",\"pt\":\"" << aeroprobe.pt
                << "\",\"tc\":\"" << aeroprobe.tc
                << "\"}";

            json_message = stream.str();
            return 0;

        default:
            // msgid = None
            //
            stream << "{\"type\":\"CONVERSION_ERROR\"}";

            json_message = stream.str();
            return 0;

    }
    return -1;
}
