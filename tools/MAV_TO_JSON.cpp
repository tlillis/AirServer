// This file was created using AirServer tool "con_gen.py"
// Generated cpp code for converting mavlink to json
// This code was generated on 08/07/2015 at 12:22:21

#include "../include/conversions.h"
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
                << "\",\"type\":\"" << heartbeat.type
                << "\",\"autopilot\":\"" << heartbeat.autopilot
                << "\",\"base_mode\":\"" << heartbeat.base_mode
                << "\",\"custom_mode\":\"" << heartbeat.custom_mode
                << "\",\"system_status\":\"" << heartbeat.system_status
                << "\",\"mavlink_version\":\"" << heartbeat.mavlink_version
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SYS_STATUS: 
            // msgid = 1
            // 
            mavlink_sys_status_t sys_status;
            mavlink_msg_sys_status_decode(&message, &(sys_status));
            stream << "{\"type\":\"SYS_STATUS"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SYSTEM_TIME: 
            // msgid = 2
            // 
            mavlink_system_time_t system_time;
            mavlink_msg_system_time_decode(&message, &(system_time));
            stream << "{\"type\":\"SYSTEM_TIME"
                << "\",\"time_unix_usec\":\"" << system_time.time_unix_usec
                << "\",\"time_boot_ms\":\"" << system_time.time_boot_ms
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PING: 
            // msgid = 4
            // 
            mavlink_ping_t ping;
            mavlink_msg_ping_decode(&message, &(ping));
            stream << "{\"type\":\"PING"
                << "\",\"time_usec\":\"" << ping.time_usec
                << "\",\"seq\":\"" << ping.seq
                << "\",\"target_system\":\"" << ping.target_system
                << "\",\"target_component\":\"" << ping.target_component
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL: 
            // msgid = 5
            // 
            mavlink_change_operator_control_t change_operator_control;
            mavlink_msg_change_operator_control_decode(&message, &(change_operator_control));
            stream << "{\"type\":\"CHANGE_OPERATOR_CONTROL"
                << "\",\"target_system\":\"" << change_operator_control.target_system
                << "\",\"control_request\":\"" << change_operator_control.control_request
                << "\",\"version\":\"" << change_operator_control.version
                << "\",\"passkey\":\"" << change_operator_control.passkey
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK: 
            // msgid = 6
            // 
            mavlink_change_operator_control_ack_t change_operator_control_ack;
            mavlink_msg_change_operator_control_ack_decode(&message, &(change_operator_control_ack));
            stream << "{\"type\":\"CHANGE_OPERATOR_CONTROL_ACK"
                << "\",\"gcs_system_id\":\"" << change_operator_control_ack.gcs_system_id
                << "\",\"control_request\":\"" << change_operator_control_ack.control_request
                << "\",\"ack\":\"" << change_operator_control_ack.ack
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AUTH_KEY: 
            // msgid = 7
            // 
            mavlink_auth_key_t auth_key;
            mavlink_msg_auth_key_decode(&message, &(auth_key));
            stream << "{\"type\":\"AUTH_KEY"
                << "\",\"key\":\"" << auth_key.key
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_MODE: 
            // msgid = 11
            // 
            mavlink_set_mode_t set_mode;
            mavlink_msg_set_mode_decode(&message, &(set_mode));
            stream << "{\"type\":\"SET_MODE"
                << "\",\"target_system\":\"" << set_mode.target_system
                << "\",\"base_mode\":\"" << set_mode.base_mode
                << "\",\"custom_mode\":\"" << set_mode.custom_mode
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PARAM_REQUEST_READ: 
            // msgid = 20
            // 
            mavlink_param_request_read_t param_request_read;
            mavlink_msg_param_request_read_decode(&message, &(param_request_read));
            stream << "{\"type\":\"PARAM_REQUEST_READ"
                << "\",\"target_system\":\"" << param_request_read.target_system
                << "\",\"target_component\":\"" << param_request_read.target_component
                << "\",\"param_id\":\"" << param_request_read.param_id
                << "\",\"param_index\":\"" << param_request_read.param_index
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PARAM_REQUEST_LIST: 
            // msgid = 21
            // 
            mavlink_param_request_list_t param_request_list;
            mavlink_msg_param_request_list_decode(&message, &(param_request_list));
            stream << "{\"type\":\"PARAM_REQUEST_LIST"
                << "\",\"target_system\":\"" << param_request_list.target_system
                << "\",\"target_component\":\"" << param_request_list.target_component
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PARAM_VALUE: 
            // msgid = 22
            // 
            mavlink_param_value_t param_value;
            mavlink_msg_param_value_decode(&message, &(param_value));
            stream << "{\"type\":\"PARAM_VALUE"
                << "\",\"param_id\":\"" << param_value.param_id
                << "\",\"param_value\":\"" << param_value.param_value
                << "\",\"param_type\":\"" << param_value.param_type
                << "\",\"param_count\":\"" << param_value.param_count
                << "\",\"param_index\":\"" << param_value.param_index
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PARAM_SET: 
            // msgid = 23
            // 
            mavlink_param_set_t param_set;
            mavlink_msg_param_set_decode(&message, &(param_set));
            stream << "{\"type\":\"PARAM_SET"
                << "\",\"target_system\":\"" << param_set.target_system
                << "\",\"target_component\":\"" << param_set.target_component
                << "\",\"param_id\":\"" << param_set.param_id
                << "\",\"param_value\":\"" << param_set.param_value
                << "\",\"param_type\":\"" << param_set.param_type
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS_RAW_INT: 
            // msgid = 24
            // 
            mavlink_gps_raw_int_t gps_raw_int;
            mavlink_msg_gps_raw_int_decode(&message, &(gps_raw_int));
            stream << "{\"type\":\"GPS_RAW_INT"
                << "\",\"time_usec\":\"" << gps_raw_int.time_usec
                << "\",\"fix_type\":\"" << gps_raw_int.fix_type
                << "\",\"lat\":\"" << gps_raw_int.lat
                << "\",\"lon\":\"" << gps_raw_int.lon
                << "\",\"alt\":\"" << gps_raw_int.alt
                << "\",\"eph\":\"" << gps_raw_int.eph
                << "\",\"epv\":\"" << gps_raw_int.epv
                << "\",\"vel\":\"" << gps_raw_int.vel
                << "\",\"cog\":\"" << gps_raw_int.cog
                << "\",\"satellites_visible\":\"" << gps_raw_int.satellites_visible
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS_STATUS: 
            // msgid = 25
            // 
            mavlink_gps_status_t gps_status;
            mavlink_msg_gps_status_decode(&message, &(gps_status));
            stream << "{\"type\":\"GPS_STATUS"
                << "\",\"satellites_visible\":\"" << gps_status.satellites_visible
                << "\",\"satellite_prn\":\"" << gps_status.satellite_prn
                << "\",\"satellite_used\":\"" << gps_status.satellite_used
                << "\",\"satellite_elevation\":\"" << gps_status.satellite_elevation
                << "\",\"satellite_azimuth\":\"" << gps_status.satellite_azimuth
                << "\",\"satellite_snr\":\"" << gps_status.satellite_snr
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SCALED_IMU: 
            // msgid = 26
            // 
            mavlink_scaled_imu_t scaled_imu;
            mavlink_msg_scaled_imu_decode(&message, &(scaled_imu));
            stream << "{\"type\":\"SCALED_IMU"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RAW_IMU: 
            // msgid = 27
            // 
            mavlink_raw_imu_t raw_imu;
            mavlink_msg_raw_imu_decode(&message, &(raw_imu));
            stream << "{\"type\":\"RAW_IMU"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RAW_PRESSURE: 
            // msgid = 28
            // 
            mavlink_raw_pressure_t raw_pressure;
            mavlink_msg_raw_pressure_decode(&message, &(raw_pressure));
            stream << "{\"type\":\"RAW_PRESSURE"
                << "\",\"time_usec\":\"" << raw_pressure.time_usec
                << "\",\"press_abs\":\"" << raw_pressure.press_abs
                << "\",\"press_diff1\":\"" << raw_pressure.press_diff1
                << "\",\"press_diff2\":\"" << raw_pressure.press_diff2
                << "\",\"temperature\":\"" << raw_pressure.temperature
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SCALED_PRESSURE: 
            // msgid = 29
            // 
            mavlink_scaled_pressure_t scaled_pressure;
            mavlink_msg_scaled_pressure_decode(&message, &(scaled_pressure));
            stream << "{\"type\":\"SCALED_PRESSURE"
                << "\",\"time_boot_ms\":\"" << scaled_pressure.time_boot_ms
                << "\",\"press_abs\":\"" << scaled_pressure.press_abs
                << "\",\"press_diff\":\"" << scaled_pressure.press_diff
                << "\",\"temperature\":\"" << scaled_pressure.temperature
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ATTITUDE: 
            // msgid = 30
            // 
            mavlink_attitude_t attitude;
            mavlink_msg_attitude_decode(&message, &(attitude));
            stream << "{\"type\":\"ATTITUDE"
                << "\",\"time_boot_ms\":\"" << attitude.time_boot_ms
                << "\",\"roll\":\"" << attitude.roll
                << "\",\"pitch\":\"" << attitude.pitch
                << "\",\"yaw\":\"" << attitude.yaw
                << "\",\"rollspeed\":\"" << attitude.rollspeed
                << "\",\"pitchspeed\":\"" << attitude.pitchspeed
                << "\",\"yawspeed\":\"" << attitude.yawspeed
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ATTITUDE_QUATERNION: 
            // msgid = 31
            // 
            mavlink_attitude_quaternion_t attitude_quaternion;
            mavlink_msg_attitude_quaternion_decode(&message, &(attitude_quaternion));
            stream << "{\"type\":\"ATTITUDE_QUATERNION"
                << "\",\"time_boot_ms\":\"" << attitude_quaternion.time_boot_ms
                << "\",\"q1\":\"" << attitude_quaternion.q1
                << "\",\"q2\":\"" << attitude_quaternion.q2
                << "\",\"q3\":\"" << attitude_quaternion.q3
                << "\",\"q4\":\"" << attitude_quaternion.q4
                << "\",\"rollspeed\":\"" << attitude_quaternion.rollspeed
                << "\",\"pitchspeed\":\"" << attitude_quaternion.pitchspeed
                << "\",\"yawspeed\":\"" << attitude_quaternion.yawspeed
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOCAL_POSITION_NED: 
            // msgid = 32
            // 
            mavlink_local_position_ned_t local_position_ned;
            mavlink_msg_local_position_ned_decode(&message, &(local_position_ned));
            stream << "{\"type\":\"LOCAL_POSITION_NED"
                << "\",\"time_boot_ms\":\"" << local_position_ned.time_boot_ms
                << "\",\"x\":\"" << local_position_ned.x
                << "\",\"y\":\"" << local_position_ned.y
                << "\",\"z\":\"" << local_position_ned.z
                << "\",\"vx\":\"" << local_position_ned.vx
                << "\",\"vy\":\"" << local_position_ned.vy
                << "\",\"vz\":\"" << local_position_ned.vz
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT: 
            // msgid = 33
            // 
            mavlink_global_position_int_t global_position_int;
            mavlink_msg_global_position_int_decode(&message, &(global_position_int));
            stream << "{\"type\":\"GLOBAL_POSITION_INT"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RC_CHANNELS_SCALED: 
            // msgid = 34
            // 
            mavlink_rc_channels_scaled_t rc_channels_scaled;
            mavlink_msg_rc_channels_scaled_decode(&message, &(rc_channels_scaled));
            stream << "{\"type\":\"RC_CHANNELS_SCALED"
                << "\",\"time_boot_ms\":\"" << rc_channels_scaled.time_boot_ms
                << "\",\"port\":\"" << rc_channels_scaled.port
                << "\",\"chan1_scaled\":\"" << rc_channels_scaled.chan1_scaled
                << "\",\"chan2_scaled\":\"" << rc_channels_scaled.chan2_scaled
                << "\",\"chan3_scaled\":\"" << rc_channels_scaled.chan3_scaled
                << "\",\"chan4_scaled\":\"" << rc_channels_scaled.chan4_scaled
                << "\",\"chan5_scaled\":\"" << rc_channels_scaled.chan5_scaled
                << "\",\"chan6_scaled\":\"" << rc_channels_scaled.chan6_scaled
                << "\",\"chan7_scaled\":\"" << rc_channels_scaled.chan7_scaled
                << "\",\"chan8_scaled\":\"" << rc_channels_scaled.chan8_scaled
                << "\",\"rssi\":\"" << rc_channels_scaled.rssi
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RC_CHANNELS_RAW: 
            // msgid = 35
            // 
            mavlink_rc_channels_raw_t rc_channels_raw;
            mavlink_msg_rc_channels_raw_decode(&message, &(rc_channels_raw));
            stream << "{\"type\":\"RC_CHANNELS_RAW"
                << "\",\"time_boot_ms\":\"" << rc_channels_raw.time_boot_ms
                << "\",\"port\":\"" << rc_channels_raw.port
                << "\",\"chan1_raw\":\"" << rc_channels_raw.chan1_raw
                << "\",\"chan2_raw\":\"" << rc_channels_raw.chan2_raw
                << "\",\"chan3_raw\":\"" << rc_channels_raw.chan3_raw
                << "\",\"chan4_raw\":\"" << rc_channels_raw.chan4_raw
                << "\",\"chan5_raw\":\"" << rc_channels_raw.chan5_raw
                << "\",\"chan6_raw\":\"" << rc_channels_raw.chan6_raw
                << "\",\"chan7_raw\":\"" << rc_channels_raw.chan7_raw
                << "\",\"chan8_raw\":\"" << rc_channels_raw.chan8_raw
                << "\",\"rssi\":\"" << rc_channels_raw.rssi
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW: 
            // msgid = 36
            // 
            mavlink_servo_output_raw_t servo_output_raw;
            mavlink_msg_servo_output_raw_decode(&message, &(servo_output_raw));
            stream << "{\"type\":\"SERVO_OUTPUT_RAW"
                << "\",\"time_usec\":\"" << servo_output_raw.time_usec
                << "\",\"port\":\"" << servo_output_raw.port
                << "\",\"servo1_raw\":\"" << servo_output_raw.servo1_raw
                << "\",\"servo2_raw\":\"" << servo_output_raw.servo2_raw
                << "\",\"servo3_raw\":\"" << servo_output_raw.servo3_raw
                << "\",\"servo4_raw\":\"" << servo_output_raw.servo4_raw
                << "\",\"servo5_raw\":\"" << servo_output_raw.servo5_raw
                << "\",\"servo6_raw\":\"" << servo_output_raw.servo6_raw
                << "\",\"servo7_raw\":\"" << servo_output_raw.servo7_raw
                << "\",\"servo8_raw\":\"" << servo_output_raw.servo8_raw
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST: 
            // msgid = 37
            // 
            mavlink_mission_request_partial_list_t mission_request_partial_list;
            mavlink_msg_mission_request_partial_list_decode(&message, &(mission_request_partial_list));
            stream << "{\"type\":\"MISSION_REQUEST_PARTIAL_LIST"
                << "\",\"target_system\":\"" << mission_request_partial_list.target_system
                << "\",\"target_component\":\"" << mission_request_partial_list.target_component
                << "\",\"start_index\":\"" << mission_request_partial_list.start_index
                << "\",\"end_index\":\"" << mission_request_partial_list.end_index
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST: 
            // msgid = 38
            // 
            mavlink_mission_write_partial_list_t mission_write_partial_list;
            mavlink_msg_mission_write_partial_list_decode(&message, &(mission_write_partial_list));
            stream << "{\"type\":\"MISSION_WRITE_PARTIAL_LIST"
                << "\",\"target_system\":\"" << mission_write_partial_list.target_system
                << "\",\"target_component\":\"" << mission_write_partial_list.target_component
                << "\",\"start_index\":\"" << mission_write_partial_list.start_index
                << "\",\"end_index\":\"" << mission_write_partial_list.end_index
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_ITEM: 
            // msgid = 39
            // 
            mavlink_mission_item_t mission_item;
            mavlink_msg_mission_item_decode(&message, &(mission_item));
            stream << "{\"type\":\"MISSION_ITEM"
                << "\",\"target_system\":\"" << mission_item.target_system
                << "\",\"target_component\":\"" << mission_item.target_component
                << "\",\"seq\":\"" << mission_item.seq
                << "\",\"frame\":\"" << mission_item.frame
                << "\",\"command\":\"" << mission_item.command
                << "\",\"current\":\"" << mission_item.current
                << "\",\"autocontinue\":\"" << mission_item.autocontinue
                << "\",\"param1\":\"" << mission_item.param1
                << "\",\"param2\":\"" << mission_item.param2
                << "\",\"param3\":\"" << mission_item.param3
                << "\",\"param4\":\"" << mission_item.param4
                << "\",\"x\":\"" << mission_item.x
                << "\",\"y\":\"" << mission_item.y
                << "\",\"z\":\"" << mission_item.z
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_REQUEST: 
            // msgid = 40
            // 
            mavlink_mission_request_t mission_request;
            mavlink_msg_mission_request_decode(&message, &(mission_request));
            stream << "{\"type\":\"MISSION_REQUEST"
                << "\",\"target_system\":\"" << mission_request.target_system
                << "\",\"target_component\":\"" << mission_request.target_component
                << "\",\"seq\":\"" << mission_request.seq
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_SET_CURRENT: 
            // msgid = 41
            // 
            mavlink_mission_set_current_t mission_set_current;
            mavlink_msg_mission_set_current_decode(&message, &(mission_set_current));
            stream << "{\"type\":\"MISSION_SET_CURRENT"
                << "\",\"target_system\":\"" << mission_set_current.target_system
                << "\",\"target_component\":\"" << mission_set_current.target_component
                << "\",\"seq\":\"" << mission_set_current.seq
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_CURRENT: 
            // msgid = 42
            // 
            mavlink_mission_current_t mission_current;
            mavlink_msg_mission_current_decode(&message, &(mission_current));
            stream << "{\"type\":\"MISSION_CURRENT"
                << "\",\"seq\":\"" << mission_current.seq
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_REQUEST_LIST: 
            // msgid = 43
            // 
            mavlink_mission_request_list_t mission_request_list;
            mavlink_msg_mission_request_list_decode(&message, &(mission_request_list));
            stream << "{\"type\":\"MISSION_REQUEST_LIST"
                << "\",\"target_system\":\"" << mission_request_list.target_system
                << "\",\"target_component\":\"" << mission_request_list.target_component
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_COUNT: 
            // msgid = 44
            // 
            mavlink_mission_count_t mission_count;
            mavlink_msg_mission_count_decode(&message, &(mission_count));
            stream << "{\"type\":\"MISSION_COUNT"
                << "\",\"target_system\":\"" << mission_count.target_system
                << "\",\"target_component\":\"" << mission_count.target_component
                << "\",\"count\":\"" << mission_count.count
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_CLEAR_ALL: 
            // msgid = 45
            // 
            mavlink_mission_clear_all_t mission_clear_all;
            mavlink_msg_mission_clear_all_decode(&message, &(mission_clear_all));
            stream << "{\"type\":\"MISSION_CLEAR_ALL"
                << "\",\"target_system\":\"" << mission_clear_all.target_system
                << "\",\"target_component\":\"" << mission_clear_all.target_component
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_ITEM_REACHED: 
            // msgid = 46
            // 
            mavlink_mission_item_reached_t mission_item_reached;
            mavlink_msg_mission_item_reached_decode(&message, &(mission_item_reached));
            stream << "{\"type\":\"MISSION_ITEM_REACHED"
                << "\",\"seq\":\"" << mission_item_reached.seq
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_ACK: 
            // msgid = 47
            // 
            mavlink_mission_ack_t mission_ack;
            mavlink_msg_mission_ack_decode(&message, &(mission_ack));
            stream << "{\"type\":\"MISSION_ACK"
                << "\",\"target_system\":\"" << mission_ack.target_system
                << "\",\"target_component\":\"" << mission_ack.target_component
                << "\",\"type\":\"" << mission_ack.type
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN: 
            // msgid = 48
            // 
            mavlink_set_gps_global_origin_t set_gps_global_origin;
            mavlink_msg_set_gps_global_origin_decode(&message, &(set_gps_global_origin));
            stream << "{\"type\":\"SET_GPS_GLOBAL_ORIGIN"
                << "\",\"target_system\":\"" << set_gps_global_origin.target_system
                << "\",\"latitude\":\"" << set_gps_global_origin.latitude
                << "\",\"longitude\":\"" << set_gps_global_origin.longitude
                << "\",\"altitude\":\"" << set_gps_global_origin.altitude
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN: 
            // msgid = 49
            // 
            mavlink_gps_global_origin_t gps_global_origin;
            mavlink_msg_gps_global_origin_decode(&message, &(gps_global_origin));
            stream << "{\"type\":\"GPS_GLOBAL_ORIGIN"
                << "\",\"latitude\":\"" << gps_global_origin.latitude
                << "\",\"longitude\":\"" << gps_global_origin.longitude
                << "\",\"altitude\":\"" << gps_global_origin.altitude
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_PARAM_MAP_RC: 
            // msgid = 50
            // 
            mavlink_param_map_rc_t param_map_rc;
            mavlink_msg_param_map_rc_decode(&message, &(param_map_rc));
            stream << "{\"type\":\"PARAM_MAP_RC"
                << "\",\"target_system\":\"" << param_map_rc.target_system
                << "\",\"target_component\":\"" << param_map_rc.target_component
                << "\",\"param_id\":\"" << param_map_rc.param_id
                << "\",\"param_index\":\"" << param_map_rc.param_index
                << "\",\"parameter_rc_channel_index\":\"" << param_map_rc.parameter_rc_channel_index
                << "\",\"param_value0\":\"" << param_map_rc.param_value0
                << "\",\"scale\":\"" << param_map_rc.scale
                << "\",\"param_value_min\":\"" << param_map_rc.param_value_min
                << "\",\"param_value_max\":\"" << param_map_rc.param_value_max
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA: 
            // msgid = 54
            // 
            mavlink_safety_set_allowed_area_t safety_set_allowed_area;
            mavlink_msg_safety_set_allowed_area_decode(&message, &(safety_set_allowed_area));
            stream << "{\"type\":\"SAFETY_SET_ALLOWED_AREA"
                << "\",\"target_system\":\"" << safety_set_allowed_area.target_system
                << "\",\"target_component\":\"" << safety_set_allowed_area.target_component
                << "\",\"frame\":\"" << safety_set_allowed_area.frame
                << "\",\"p1x\":\"" << safety_set_allowed_area.p1x
                << "\",\"p1y\":\"" << safety_set_allowed_area.p1y
                << "\",\"p1z\":\"" << safety_set_allowed_area.p1z
                << "\",\"p2x\":\"" << safety_set_allowed_area.p2x
                << "\",\"p2y\":\"" << safety_set_allowed_area.p2y
                << "\",\"p2z\":\"" << safety_set_allowed_area.p2z
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA: 
            // msgid = 55
            // 
            mavlink_safety_allowed_area_t safety_allowed_area;
            mavlink_msg_safety_allowed_area_decode(&message, &(safety_allowed_area));
            stream << "{\"type\":\"SAFETY_ALLOWED_AREA"
                << "\",\"frame\":\"" << safety_allowed_area.frame
                << "\",\"p1x\":\"" << safety_allowed_area.p1x
                << "\",\"p1y\":\"" << safety_allowed_area.p1y
                << "\",\"p1z\":\"" << safety_allowed_area.p1z
                << "\",\"p2x\":\"" << safety_allowed_area.p2x
                << "\",\"p2y\":\"" << safety_allowed_area.p2y
                << "\",\"p2z\":\"" << safety_allowed_area.p2z
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ATTITUDE_QUATERNION_COV: 
            // msgid = 61
            // 
            mavlink_attitude_quaternion_cov_t attitude_quaternion_cov;
            mavlink_msg_attitude_quaternion_cov_decode(&message, &(attitude_quaternion_cov));
            stream << "{\"type\":\"ATTITUDE_QUATERNION_COV"
                << "\",\"time_boot_ms\":\"" << attitude_quaternion_cov.time_boot_ms
                << "\",\"q\":\"" << attitude_quaternion_cov.q
                << "\",\"rollspeed\":\"" << attitude_quaternion_cov.rollspeed
                << "\",\"pitchspeed\":\"" << attitude_quaternion_cov.pitchspeed
                << "\",\"yawspeed\":\"" << attitude_quaternion_cov.yawspeed
                << "\",\"covariance\":\"" << attitude_quaternion_cov.covariance
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT: 
            // msgid = 62
            // 
            mavlink_nav_controller_output_t nav_controller_output;
            mavlink_msg_nav_controller_output_decode(&message, &(nav_controller_output));
            stream << "{\"type\":\"NAV_CONTROLLER_OUTPUT"
                << "\",\"nav_roll\":\"" << nav_controller_output.nav_roll
                << "\",\"nav_pitch\":\"" << nav_controller_output.nav_pitch
                << "\",\"nav_bearing\":\"" << nav_controller_output.nav_bearing
                << "\",\"target_bearing\":\"" << nav_controller_output.target_bearing
                << "\",\"wp_dist\":\"" << nav_controller_output.wp_dist
                << "\",\"alt_error\":\"" << nav_controller_output.alt_error
                << "\",\"aspd_error\":\"" << nav_controller_output.aspd_error
                << "\",\"xtrack_error\":\"" << nav_controller_output.xtrack_error
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT_COV: 
            // msgid = 63
            // 
            mavlink_global_position_int_cov_t global_position_int_cov;
            mavlink_msg_global_position_int_cov_decode(&message, &(global_position_int_cov));
            stream << "{\"type\":\"GLOBAL_POSITION_INT_COV"
                << "\",\"time_boot_ms\":\"" << global_position_int_cov.time_boot_ms
                << "\",\"time_utc\":\"" << global_position_int_cov.time_utc
                << "\",\"estimator_type\":\"" << global_position_int_cov.estimator_type
                << "\",\"lat\":\"" << global_position_int_cov.lat
                << "\",\"lon\":\"" << global_position_int_cov.lon
                << "\",\"alt\":\"" << global_position_int_cov.alt
                << "\",\"relative_alt\":\"" << global_position_int_cov.relative_alt
                << "\",\"vx\":\"" << global_position_int_cov.vx
                << "\",\"vy\":\"" << global_position_int_cov.vy
                << "\",\"vz\":\"" << global_position_int_cov.vz
                << "\",\"covariance\":\"" << global_position_int_cov.covariance
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOCAL_POSITION_NED_COV: 
            // msgid = 64
            // 
            mavlink_local_position_ned_cov_t local_position_ned_cov;
            mavlink_msg_local_position_ned_cov_decode(&message, &(local_position_ned_cov));
            stream << "{\"type\":\"LOCAL_POSITION_NED_COV"
                << "\",\"time_boot_ms\":\"" << local_position_ned_cov.time_boot_ms
                << "\",\"time_utc\":\"" << local_position_ned_cov.time_utc
                << "\",\"estimator_type\":\"" << local_position_ned_cov.estimator_type
                << "\",\"x\":\"" << local_position_ned_cov.x
                << "\",\"y\":\"" << local_position_ned_cov.y
                << "\",\"z\":\"" << local_position_ned_cov.z
                << "\",\"vx\":\"" << local_position_ned_cov.vx
                << "\",\"vy\":\"" << local_position_ned_cov.vy
                << "\",\"vz\":\"" << local_position_ned_cov.vz
                << "\",\"covariance\":\"" << local_position_ned_cov.covariance
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RC_CHANNELS: 
            // msgid = 65
            // 
            mavlink_rc_channels_t rc_channels;
            mavlink_msg_rc_channels_decode(&message, &(rc_channels));
            stream << "{\"type\":\"RC_CHANNELS"
                << "\",\"time_boot_ms\":\"" << rc_channels.time_boot_ms
                << "\",\"chancount\":\"" << rc_channels.chancount
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
                << "\",\"rssi\":\"" << rc_channels.rssi
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_REQUEST_DATA_STREAM: 
            // msgid = 66
            // 
            mavlink_request_data_stream_t request_data_stream;
            mavlink_msg_request_data_stream_decode(&message, &(request_data_stream));
            stream << "{\"type\":\"REQUEST_DATA_STREAM"
                << "\",\"target_system\":\"" << request_data_stream.target_system
                << "\",\"target_component\":\"" << request_data_stream.target_component
                << "\",\"req_stream_id\":\"" << request_data_stream.req_stream_id
                << "\",\"req_message_rate\":\"" << request_data_stream.req_message_rate
                << "\",\"start_stop\":\"" << request_data_stream.start_stop
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DATA_STREAM: 
            // msgid = 67
            // 
            mavlink_data_stream_t data_stream;
            mavlink_msg_data_stream_decode(&message, &(data_stream));
            stream << "{\"type\":\"DATA_STREAM"
                << "\",\"stream_id\":\"" << data_stream.stream_id
                << "\",\"message_rate\":\"" << data_stream.message_rate
                << "\",\"on_off\":\"" << data_stream.on_off
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MANUAL_CONTROL: 
            // msgid = 69
            // 
            mavlink_manual_control_t manual_control;
            mavlink_msg_manual_control_decode(&message, &(manual_control));
            stream << "{\"type\":\"MANUAL_CONTROL"
                << "\",\"target\":\"" << manual_control.target
                << "\",\"x\":\"" << manual_control.x
                << "\",\"y\":\"" << manual_control.y
                << "\",\"z\":\"" << manual_control.z
                << "\",\"r\":\"" << manual_control.r
                << "\",\"buttons\":\"" << manual_control.buttons
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE: 
            // msgid = 70
            // 
            mavlink_rc_channels_override_t rc_channels_override;
            mavlink_msg_rc_channels_override_decode(&message, &(rc_channels_override));
            stream << "{\"type\":\"RC_CHANNELS_OVERRIDE"
                << "\",\"target_system\":\"" << rc_channels_override.target_system
                << "\",\"target_component\":\"" << rc_channels_override.target_component
                << "\",\"chan1_raw\":\"" << rc_channels_override.chan1_raw
                << "\",\"chan2_raw\":\"" << rc_channels_override.chan2_raw
                << "\",\"chan3_raw\":\"" << rc_channels_override.chan3_raw
                << "\",\"chan4_raw\":\"" << rc_channels_override.chan4_raw
                << "\",\"chan5_raw\":\"" << rc_channels_override.chan5_raw
                << "\",\"chan6_raw\":\"" << rc_channels_override.chan6_raw
                << "\",\"chan7_raw\":\"" << rc_channels_override.chan7_raw
                << "\",\"chan8_raw\":\"" << rc_channels_override.chan8_raw
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MISSION_ITEM_INT: 
            // msgid = 73
            // 
            mavlink_mission_item_int_t mission_item_int;
            mavlink_msg_mission_item_int_decode(&message, &(mission_item_int));
            stream << "{\"type\":\"MISSION_ITEM_INT"
                << "\",\"target_system\":\"" << mission_item_int.target_system
                << "\",\"target_component\":\"" << mission_item_int.target_component
                << "\",\"seq\":\"" << mission_item_int.seq
                << "\",\"frame\":\"" << mission_item_int.frame
                << "\",\"command\":\"" << mission_item_int.command
                << "\",\"current\":\"" << mission_item_int.current
                << "\",\"autocontinue\":\"" << mission_item_int.autocontinue
                << "\",\"param1\":\"" << mission_item_int.param1
                << "\",\"param2\":\"" << mission_item_int.param2
                << "\",\"param3\":\"" << mission_item_int.param3
                << "\",\"param4\":\"" << mission_item_int.param4
                << "\",\"x\":\"" << mission_item_int.x
                << "\",\"y\":\"" << mission_item_int.y
                << "\",\"z\":\"" << mission_item_int.z
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_VFR_HUD: 
            // msgid = 74
            // 
            mavlink_vfr_hud_t vfr_hud;
            mavlink_msg_vfr_hud_decode(&message, &(vfr_hud));
            stream << "{\"type\":\"VFR_HUD"
                << "\",\"airspeed\":\"" << vfr_hud.airspeed
                << "\",\"groundspeed\":\"" << vfr_hud.groundspeed
                << "\",\"heading\":\"" << vfr_hud.heading
                << "\",\"throttle\":\"" << vfr_hud.throttle
                << "\",\"alt\":\"" << vfr_hud.alt
                << "\",\"climb\":\"" << vfr_hud.climb
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_COMMAND_INT: 
            // msgid = 75
            // 
            mavlink_command_int_t command_int;
            mavlink_msg_command_int_decode(&message, &(command_int));
            stream << "{\"type\":\"COMMAND_INT"
                << "\",\"target_system\":\"" << command_int.target_system
                << "\",\"target_component\":\"" << command_int.target_component
                << "\",\"frame\":\"" << command_int.frame
                << "\",\"command\":\"" << command_int.command
                << "\",\"current\":\"" << command_int.current
                << "\",\"autocontinue\":\"" << command_int.autocontinue
                << "\",\"param1\":\"" << command_int.param1
                << "\",\"param2\":\"" << command_int.param2
                << "\",\"param3\":\"" << command_int.param3
                << "\",\"param4\":\"" << command_int.param4
                << "\",\"x\":\"" << command_int.x
                << "\",\"y\":\"" << command_int.y
                << "\",\"z\":\"" << command_int.z
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_COMMAND_LONG: 
            // msgid = 76
            // 
            mavlink_command_long_t command_long;
            mavlink_msg_command_long_decode(&message, &(command_long));
            stream << "{\"type\":\"COMMAND_LONG"
                << "\",\"target_system\":\"" << command_long.target_system
                << "\",\"target_component\":\"" << command_long.target_component
                << "\",\"command\":\"" << command_long.command
                << "\",\"confirmation\":\"" << command_long.confirmation
                << "\",\"param1\":\"" << command_long.param1
                << "\",\"param2\":\"" << command_long.param2
                << "\",\"param3\":\"" << command_long.param3
                << "\",\"param4\":\"" << command_long.param4
                << "\",\"param5\":\"" << command_long.param5
                << "\",\"param6\":\"" << command_long.param6
                << "\",\"param7\":\"" << command_long.param7
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_COMMAND_ACK: 
            // msgid = 77
            // 
            mavlink_command_ack_t command_ack;
            mavlink_msg_command_ack_decode(&message, &(command_ack));
            stream << "{\"type\":\"COMMAND_ACK"
                << "\",\"command\":\"" << command_ack.command
                << "\",\"result\":\"" << command_ack.result
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MANUAL_SETPOINT: 
            // msgid = 81
            // 
            mavlink_manual_setpoint_t manual_setpoint;
            mavlink_msg_manual_setpoint_decode(&message, &(manual_setpoint));
            stream << "{\"type\":\"MANUAL_SETPOINT"
                << "\",\"time_boot_ms\":\"" << manual_setpoint.time_boot_ms
                << "\",\"roll\":\"" << manual_setpoint.roll
                << "\",\"pitch\":\"" << manual_setpoint.pitch
                << "\",\"yaw\":\"" << manual_setpoint.yaw
                << "\",\"thrust\":\"" << manual_setpoint.thrust
                << "\",\"mode_switch\":\"" << manual_setpoint.mode_switch
                << "\",\"manual_override_switch\":\"" << manual_setpoint.manual_override_switch
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_ATTITUDE_TARGET: 
            // msgid = 82
            // 
            mavlink_set_attitude_target_t set_attitude_target;
            mavlink_msg_set_attitude_target_decode(&message, &(set_attitude_target));
            stream << "{\"type\":\"SET_ATTITUDE_TARGET"
                << "\",\"time_boot_ms\":\"" << set_attitude_target.time_boot_ms
                << "\",\"target_system\":\"" << set_attitude_target.target_system
                << "\",\"target_component\":\"" << set_attitude_target.target_component
                << "\",\"type_mask\":\"" << set_attitude_target.type_mask
                << "\",\"q\":\"" << set_attitude_target.q
                << "\",\"body_roll_rate\":\"" << set_attitude_target.body_roll_rate
                << "\",\"body_pitch_rate\":\"" << set_attitude_target.body_pitch_rate
                << "\",\"body_yaw_rate\":\"" << set_attitude_target.body_yaw_rate
                << "\",\"thrust\":\"" << set_attitude_target.thrust
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ATTITUDE_TARGET: 
            // msgid = 83
            // 
            mavlink_attitude_target_t attitude_target;
            mavlink_msg_attitude_target_decode(&message, &(attitude_target));
            stream << "{\"type\":\"ATTITUDE_TARGET"
                << "\",\"time_boot_ms\":\"" << attitude_target.time_boot_ms
                << "\",\"type_mask\":\"" << attitude_target.type_mask
                << "\",\"q\":\"" << attitude_target.q
                << "\",\"body_roll_rate\":\"" << attitude_target.body_roll_rate
                << "\",\"body_pitch_rate\":\"" << attitude_target.body_pitch_rate
                << "\",\"body_yaw_rate\":\"" << attitude_target.body_yaw_rate
                << "\",\"thrust\":\"" << attitude_target.thrust
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED: 
            // msgid = 84
            // 
            mavlink_set_position_target_local_ned_t set_position_target_local_ned;
            mavlink_msg_set_position_target_local_ned_decode(&message, &(set_position_target_local_ned));
            stream << "{\"type\":\"SET_POSITION_TARGET_LOCAL_NED"
                << "\",\"time_boot_ms\":\"" << set_position_target_local_ned.time_boot_ms
                << "\",\"target_system\":\"" << set_position_target_local_ned.target_system
                << "\",\"target_component\":\"" << set_position_target_local_ned.target_component
                << "\",\"coordinate_frame\":\"" << set_position_target_local_ned.coordinate_frame
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED: 
            // msgid = 85
            // 
            mavlink_position_target_local_ned_t position_target_local_ned;
            mavlink_msg_position_target_local_ned_decode(&message, &(position_target_local_ned));
            stream << "{\"type\":\"POSITION_TARGET_LOCAL_NED"
                << "\",\"time_boot_ms\":\"" << position_target_local_ned.time_boot_ms
                << "\",\"coordinate_frame\":\"" << position_target_local_ned.coordinate_frame
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_POSITION_TARGET_GLOBAL_INT: 
            // msgid = 86
            // 
            mavlink_set_position_target_global_int_t set_position_target_global_int;
            mavlink_msg_set_position_target_global_int_decode(&message, &(set_position_target_global_int));
            stream << "{\"type\":\"SET_POSITION_TARGET_GLOBAL_INT"
                << "\",\"time_boot_ms\":\"" << set_position_target_global_int.time_boot_ms
                << "\",\"target_system\":\"" << set_position_target_global_int.target_system
                << "\",\"target_component\":\"" << set_position_target_global_int.target_component
                << "\",\"coordinate_frame\":\"" << set_position_target_global_int.coordinate_frame
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT: 
            // msgid = 87
            // 
            mavlink_position_target_global_int_t position_target_global_int;
            mavlink_msg_position_target_global_int_decode(&message, &(position_target_global_int));
            stream << "{\"type\":\"POSITION_TARGET_GLOBAL_INT"
                << "\",\"time_boot_ms\":\"" << position_target_global_int.time_boot_ms
                << "\",\"coordinate_frame\":\"" << position_target_global_int.coordinate_frame
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET: 
            // msgid = 89
            // 
            mavlink_local_position_ned_system_global_offset_t local_position_ned_system_global_offset;
            mavlink_msg_local_position_ned_system_global_offset_decode(&message, &(local_position_ned_system_global_offset));
            stream << "{\"type\":\"LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET"
                << "\",\"time_boot_ms\":\"" << local_position_ned_system_global_offset.time_boot_ms
                << "\",\"x\":\"" << local_position_ned_system_global_offset.x
                << "\",\"y\":\"" << local_position_ned_system_global_offset.y
                << "\",\"z\":\"" << local_position_ned_system_global_offset.z
                << "\",\"roll\":\"" << local_position_ned_system_global_offset.roll
                << "\",\"pitch\":\"" << local_position_ned_system_global_offset.pitch
                << "\",\"yaw\":\"" << local_position_ned_system_global_offset.yaw
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_STATE: 
            // msgid = 90
            // 
            mavlink_hil_state_t hil_state;
            mavlink_msg_hil_state_decode(&message, &(hil_state));
            stream << "{\"type\":\"HIL_STATE"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_CONTROLS: 
            // msgid = 91
            // 
            mavlink_hil_controls_t hil_controls;
            mavlink_msg_hil_controls_decode(&message, &(hil_controls));
            stream << "{\"type\":\"HIL_CONTROLS"
                << "\",\"time_usec\":\"" << hil_controls.time_usec
                << "\",\"roll_ailerons\":\"" << hil_controls.roll_ailerons
                << "\",\"pitch_elevator\":\"" << hil_controls.pitch_elevator
                << "\",\"yaw_rudder\":\"" << hil_controls.yaw_rudder
                << "\",\"throttle\":\"" << hil_controls.throttle
                << "\",\"aux1\":\"" << hil_controls.aux1
                << "\",\"aux2\":\"" << hil_controls.aux2
                << "\",\"aux3\":\"" << hil_controls.aux3
                << "\",\"aux4\":\"" << hil_controls.aux4
                << "\",\"mode\":\"" << hil_controls.mode
                << "\",\"nav_mode\":\"" << hil_controls.nav_mode
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW: 
            // msgid = 92
            // 
            mavlink_hil_rc_inputs_raw_t hil_rc_inputs_raw;
            mavlink_msg_hil_rc_inputs_raw_decode(&message, &(hil_rc_inputs_raw));
            stream << "{\"type\":\"HIL_RC_INPUTS_RAW"
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
                << "\",\"rssi\":\"" << hil_rc_inputs_raw.rssi
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_OPTICAL_FLOW: 
            // msgid = 100
            // 
            mavlink_optical_flow_t optical_flow;
            mavlink_msg_optical_flow_decode(&message, &(optical_flow));
            stream << "{\"type\":\"OPTICAL_FLOW"
                << "\",\"time_usec\":\"" << optical_flow.time_usec
                << "\",\"sensor_id\":\"" << optical_flow.sensor_id
                << "\",\"flow_x\":\"" << optical_flow.flow_x
                << "\",\"flow_y\":\"" << optical_flow.flow_y
                << "\",\"flow_comp_m_x\":\"" << optical_flow.flow_comp_m_x
                << "\",\"flow_comp_m_y\":\"" << optical_flow.flow_comp_m_y
                << "\",\"quality\":\"" << optical_flow.quality
                << "\",\"ground_distance\":\"" << optical_flow.ground_distance
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GLOBAL_VISION_POSITION_ESTIMATE: 
            // msgid = 101
            // 
            mavlink_global_vision_position_estimate_t global_vision_position_estimate;
            mavlink_msg_global_vision_position_estimate_decode(&message, &(global_vision_position_estimate));
            stream << "{\"type\":\"GLOBAL_VISION_POSITION_ESTIMATE"
                << "\",\"usec\":\"" << global_vision_position_estimate.usec
                << "\",\"x\":\"" << global_vision_position_estimate.x
                << "\",\"y\":\"" << global_vision_position_estimate.y
                << "\",\"z\":\"" << global_vision_position_estimate.z
                << "\",\"roll\":\"" << global_vision_position_estimate.roll
                << "\",\"pitch\":\"" << global_vision_position_estimate.pitch
                << "\",\"yaw\":\"" << global_vision_position_estimate.yaw
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE: 
            // msgid = 102
            // 
            mavlink_vision_position_estimate_t vision_position_estimate;
            mavlink_msg_vision_position_estimate_decode(&message, &(vision_position_estimate));
            stream << "{\"type\":\"VISION_POSITION_ESTIMATE"
                << "\",\"usec\":\"" << vision_position_estimate.usec
                << "\",\"x\":\"" << vision_position_estimate.x
                << "\",\"y\":\"" << vision_position_estimate.y
                << "\",\"z\":\"" << vision_position_estimate.z
                << "\",\"roll\":\"" << vision_position_estimate.roll
                << "\",\"pitch\":\"" << vision_position_estimate.pitch
                << "\",\"yaw\":\"" << vision_position_estimate.yaw
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE: 
            // msgid = 103
            // 
            mavlink_vision_speed_estimate_t vision_speed_estimate;
            mavlink_msg_vision_speed_estimate_decode(&message, &(vision_speed_estimate));
            stream << "{\"type\":\"VISION_SPEED_ESTIMATE"
                << "\",\"usec\":\"" << vision_speed_estimate.usec
                << "\",\"x\":\"" << vision_speed_estimate.x
                << "\",\"y\":\"" << vision_speed_estimate.y
                << "\",\"z\":\"" << vision_speed_estimate.z
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE: 
            // msgid = 104
            // 
            mavlink_vicon_position_estimate_t vicon_position_estimate;
            mavlink_msg_vicon_position_estimate_decode(&message, &(vicon_position_estimate));
            stream << "{\"type\":\"VICON_POSITION_ESTIMATE"
                << "\",\"usec\":\"" << vicon_position_estimate.usec
                << "\",\"x\":\"" << vicon_position_estimate.x
                << "\",\"y\":\"" << vicon_position_estimate.y
                << "\",\"z\":\"" << vicon_position_estimate.z
                << "\",\"roll\":\"" << vicon_position_estimate.roll
                << "\",\"pitch\":\"" << vicon_position_estimate.pitch
                << "\",\"yaw\":\"" << vicon_position_estimate.yaw
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIGHRES_IMU: 
            // msgid = 105
            // 
            mavlink_highres_imu_t highres_imu;
            mavlink_msg_highres_imu_decode(&message, &(highres_imu));
            stream << "{\"type\":\"HIGHRES_IMU"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_OPTICAL_FLOW_RAD: 
            // msgid = 106
            // 
            mavlink_optical_flow_rad_t optical_flow_rad;
            mavlink_msg_optical_flow_rad_decode(&message, &(optical_flow_rad));
            stream << "{\"type\":\"OPTICAL_FLOW_RAD"
                << "\",\"time_usec\":\"" << optical_flow_rad.time_usec
                << "\",\"sensor_id\":\"" << optical_flow_rad.sensor_id
                << "\",\"integration_time_us\":\"" << optical_flow_rad.integration_time_us
                << "\",\"integrated_x\":\"" << optical_flow_rad.integrated_x
                << "\",\"integrated_y\":\"" << optical_flow_rad.integrated_y
                << "\",\"integrated_xgyro\":\"" << optical_flow_rad.integrated_xgyro
                << "\",\"integrated_ygyro\":\"" << optical_flow_rad.integrated_ygyro
                << "\",\"integrated_zgyro\":\"" << optical_flow_rad.integrated_zgyro
                << "\",\"temperature\":\"" << optical_flow_rad.temperature
                << "\",\"quality\":\"" << optical_flow_rad.quality
                << "\",\"time_delta_distance_us\":\"" << optical_flow_rad.time_delta_distance_us
                << "\",\"distance\":\"" << optical_flow_rad.distance
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_SENSOR: 
            // msgid = 107
            // 
            mavlink_hil_sensor_t hil_sensor;
            mavlink_msg_hil_sensor_decode(&message, &(hil_sensor));
            stream << "{\"type\":\"HIL_SENSOR"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SIM_STATE: 
            // msgid = 108
            // 
            mavlink_sim_state_t sim_state;
            mavlink_msg_sim_state_decode(&message, &(sim_state));
            stream << "{\"type\":\"SIM_STATE"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_RADIO_STATUS: 
            // msgid = 109
            // 
            mavlink_radio_status_t radio_status;
            mavlink_msg_radio_status_decode(&message, &(radio_status));
            stream << "{\"type\":\"RADIO_STATUS"
                << "\",\"rssi\":\"" << radio_status.rssi
                << "\",\"remrssi\":\"" << radio_status.remrssi
                << "\",\"txbuf\":\"" << radio_status.txbuf
                << "\",\"noise\":\"" << radio_status.noise
                << "\",\"remnoise\":\"" << radio_status.remnoise
                << "\",\"rxerrors\":\"" << radio_status.rxerrors
                << "\",\"fixed\":\"" << radio_status.fixed
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL: 
            // msgid = 110
            // 
            mavlink_file_transfer_protocol_t file_transfer_protocol;
            mavlink_msg_file_transfer_protocol_decode(&message, &(file_transfer_protocol));
            stream << "{\"type\":\"FILE_TRANSFER_PROTOCOL"
                << "\",\"target_network\":\"" << file_transfer_protocol.target_network
                << "\",\"target_system\":\"" << file_transfer_protocol.target_system
                << "\",\"target_component\":\"" << file_transfer_protocol.target_component
                << "\",\"payload\":\"" << file_transfer_protocol.payload
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_TIMESYNC: 
            // msgid = 111
            // 
            mavlink_timesync_t timesync;
            mavlink_msg_timesync_decode(&message, &(timesync));
            stream << "{\"type\":\"TIMESYNC"
                << "\",\"tc1\":\"" << timesync.tc1
                << "\",\"ts1\":\"" << timesync.ts1
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_GPS: 
            // msgid = 113
            // 
            mavlink_hil_gps_t hil_gps;
            mavlink_msg_hil_gps_decode(&message, &(hil_gps));
            stream << "{\"type\":\"HIL_GPS"
                << "\",\"time_usec\":\"" << hil_gps.time_usec
                << "\",\"fix_type\":\"" << hil_gps.fix_type
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
                << "\",\"satellites_visible\":\"" << hil_gps.satellites_visible
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_OPTICAL_FLOW: 
            // msgid = 114
            // 
            mavlink_hil_optical_flow_t hil_optical_flow;
            mavlink_msg_hil_optical_flow_decode(&message, &(hil_optical_flow));
            stream << "{\"type\":\"HIL_OPTICAL_FLOW"
                << "\",\"time_usec\":\"" << hil_optical_flow.time_usec
                << "\",\"sensor_id\":\"" << hil_optical_flow.sensor_id
                << "\",\"integration_time_us\":\"" << hil_optical_flow.integration_time_us
                << "\",\"integrated_x\":\"" << hil_optical_flow.integrated_x
                << "\",\"integrated_y\":\"" << hil_optical_flow.integrated_y
                << "\",\"integrated_xgyro\":\"" << hil_optical_flow.integrated_xgyro
                << "\",\"integrated_ygyro\":\"" << hil_optical_flow.integrated_ygyro
                << "\",\"integrated_zgyro\":\"" << hil_optical_flow.integrated_zgyro
                << "\",\"temperature\":\"" << hil_optical_flow.temperature
                << "\",\"quality\":\"" << hil_optical_flow.quality
                << "\",\"time_delta_distance_us\":\"" << hil_optical_flow.time_delta_distance_us
                << "\",\"distance\":\"" << hil_optical_flow.distance
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_HIL_STATE_QUATERNION: 
            // msgid = 115
            // 
            mavlink_hil_state_quaternion_t hil_state_quaternion;
            mavlink_msg_hil_state_quaternion_decode(&message, &(hil_state_quaternion));
            stream << "{\"type\":\"HIL_STATE_QUATERNION"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SCALED_IMU2: 
            // msgid = 116
            // 
            mavlink_scaled_imu2_t scaled_imu2;
            mavlink_msg_scaled_imu2_decode(&message, &(scaled_imu2));
            stream << "{\"type\":\"SCALED_IMU2"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_REQUEST_LIST: 
            // msgid = 117
            // 
            mavlink_log_request_list_t log_request_list;
            mavlink_msg_log_request_list_decode(&message, &(log_request_list));
            stream << "{\"type\":\"LOG_REQUEST_LIST"
                << "\",\"target_system\":\"" << log_request_list.target_system
                << "\",\"target_component\":\"" << log_request_list.target_component
                << "\",\"start\":\"" << log_request_list.start
                << "\",\"end\":\"" << log_request_list.end
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_ENTRY: 
            // msgid = 118
            // 
            mavlink_log_entry_t log_entry;
            mavlink_msg_log_entry_decode(&message, &(log_entry));
            stream << "{\"type\":\"LOG_ENTRY"
                << "\",\"id\":\"" << log_entry.id
                << "\",\"num_logs\":\"" << log_entry.num_logs
                << "\",\"last_log_num\":\"" << log_entry.last_log_num
                << "\",\"time_utc\":\"" << log_entry.time_utc
                << "\",\"size\":\"" << log_entry.size
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_REQUEST_DATA: 
            // msgid = 119
            // 
            mavlink_log_request_data_t log_request_data;
            mavlink_msg_log_request_data_decode(&message, &(log_request_data));
            stream << "{\"type\":\"LOG_REQUEST_DATA"
                << "\",\"target_system\":\"" << log_request_data.target_system
                << "\",\"target_component\":\"" << log_request_data.target_component
                << "\",\"id\":\"" << log_request_data.id
                << "\",\"ofs\":\"" << log_request_data.ofs
                << "\",\"count\":\"" << log_request_data.count
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_DATA: 
            // msgid = 120
            // 
            mavlink_log_data_t log_data;
            mavlink_msg_log_data_decode(&message, &(log_data));
            stream << "{\"type\":\"LOG_DATA"
                << "\",\"id\":\"" << log_data.id
                << "\",\"ofs\":\"" << log_data.ofs
                << "\",\"count\":\"" << log_data.count
                << "\",\"data\":\"" << log_data.data
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_ERASE: 
            // msgid = 121
            // 
            mavlink_log_erase_t log_erase;
            mavlink_msg_log_erase_decode(&message, &(log_erase));
            stream << "{\"type\":\"LOG_ERASE"
                << "\",\"target_system\":\"" << log_erase.target_system
                << "\",\"target_component\":\"" << log_erase.target_component
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_LOG_REQUEST_END: 
            // msgid = 122
            // 
            mavlink_log_request_end_t log_request_end;
            mavlink_msg_log_request_end_decode(&message, &(log_request_end));
            stream << "{\"type\":\"LOG_REQUEST_END"
                << "\",\"target_system\":\"" << log_request_end.target_system
                << "\",\"target_component\":\"" << log_request_end.target_component
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS_INJECT_DATA: 
            // msgid = 123
            // 
            mavlink_gps_inject_data_t gps_inject_data;
            mavlink_msg_gps_inject_data_decode(&message, &(gps_inject_data));
            stream << "{\"type\":\"GPS_INJECT_DATA"
                << "\",\"target_system\":\"" << gps_inject_data.target_system
                << "\",\"target_component\":\"" << gps_inject_data.target_component
                << "\",\"len\":\"" << gps_inject_data.len
                << "\",\"data\":\"" << gps_inject_data.data
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS2_RAW: 
            // msgid = 124
            // 
            mavlink_gps2_raw_t gps2_raw;
            mavlink_msg_gps2_raw_decode(&message, &(gps2_raw));
            stream << "{\"type\":\"GPS2_RAW"
                << "\",\"time_usec\":\"" << gps2_raw.time_usec
                << "\",\"fix_type\":\"" << gps2_raw.fix_type
                << "\",\"lat\":\"" << gps2_raw.lat
                << "\",\"lon\":\"" << gps2_raw.lon
                << "\",\"alt\":\"" << gps2_raw.alt
                << "\",\"eph\":\"" << gps2_raw.eph
                << "\",\"epv\":\"" << gps2_raw.epv
                << "\",\"vel\":\"" << gps2_raw.vel
                << "\",\"cog\":\"" << gps2_raw.cog
                << "\",\"satellites_visible\":\"" << gps2_raw.satellites_visible
                << "\",\"dgps_numch\":\"" << gps2_raw.dgps_numch
                << "\",\"dgps_age\":\"" << gps2_raw.dgps_age
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_POWER_STATUS: 
            // msgid = 125
            // 
            mavlink_power_status_t power_status;
            mavlink_msg_power_status_decode(&message, &(power_status));
            stream << "{\"type\":\"POWER_STATUS"
                << "\",\"Vcc\":\"" << power_status.Vcc
                << "\",\"Vservo\":\"" << power_status.Vservo
                << "\",\"flags\":\"" << power_status.flags
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SERIAL_CONTROL: 
            // msgid = 126
            // 
            mavlink_serial_control_t serial_control;
            mavlink_msg_serial_control_decode(&message, &(serial_control));
            stream << "{\"type\":\"SERIAL_CONTROL"
                << "\",\"device\":\"" << serial_control.device
                << "\",\"flags\":\"" << serial_control.flags
                << "\",\"timeout\":\"" << serial_control.timeout
                << "\",\"baudrate\":\"" << serial_control.baudrate
                << "\",\"count\":\"" << serial_control.count
                << "\",\"data\":\"" << serial_control.data
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS_RTK: 
            // msgid = 127
            // 
            mavlink_gps_rtk_t gps_rtk;
            mavlink_msg_gps_rtk_decode(&message, &(gps_rtk));
            stream << "{\"type\":\"GPS_RTK"
                << "\",\"time_last_baseline_ms\":\"" << gps_rtk.time_last_baseline_ms
                << "\",\"rtk_receiver_id\":\"" << gps_rtk.rtk_receiver_id
                << "\",\"wn\":\"" << gps_rtk.wn
                << "\",\"tow\":\"" << gps_rtk.tow
                << "\",\"rtk_health\":\"" << gps_rtk.rtk_health
                << "\",\"rtk_rate\":\"" << gps_rtk.rtk_rate
                << "\",\"nsats\":\"" << gps_rtk.nsats
                << "\",\"baseline_coords_type\":\"" << gps_rtk.baseline_coords_type
                << "\",\"baseline_a_mm\":\"" << gps_rtk.baseline_a_mm
                << "\",\"baseline_b_mm\":\"" << gps_rtk.baseline_b_mm
                << "\",\"baseline_c_mm\":\"" << gps_rtk.baseline_c_mm
                << "\",\"accuracy\":\"" << gps_rtk.accuracy
                << "\",\"iar_num_hypotheses\":\"" << gps_rtk.iar_num_hypotheses
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_GPS2_RTK: 
            // msgid = 128
            // 
            mavlink_gps2_rtk_t gps2_rtk;
            mavlink_msg_gps2_rtk_decode(&message, &(gps2_rtk));
            stream << "{\"type\":\"GPS2_RTK"
                << "\",\"time_last_baseline_ms\":\"" << gps2_rtk.time_last_baseline_ms
                << "\",\"rtk_receiver_id\":\"" << gps2_rtk.rtk_receiver_id
                << "\",\"wn\":\"" << gps2_rtk.wn
                << "\",\"tow\":\"" << gps2_rtk.tow
                << "\",\"rtk_health\":\"" << gps2_rtk.rtk_health
                << "\",\"rtk_rate\":\"" << gps2_rtk.rtk_rate
                << "\",\"nsats\":\"" << gps2_rtk.nsats
                << "\",\"baseline_coords_type\":\"" << gps2_rtk.baseline_coords_type
                << "\",\"baseline_a_mm\":\"" << gps2_rtk.baseline_a_mm
                << "\",\"baseline_b_mm\":\"" << gps2_rtk.baseline_b_mm
                << "\",\"baseline_c_mm\":\"" << gps2_rtk.baseline_c_mm
                << "\",\"accuracy\":\"" << gps2_rtk.accuracy
                << "\",\"iar_num_hypotheses\":\"" << gps2_rtk.iar_num_hypotheses
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SCALED_IMU3: 
            // msgid = 129
            // 
            mavlink_scaled_imu3_t scaled_imu3;
            mavlink_msg_scaled_imu3_decode(&message, &(scaled_imu3));
            stream << "{\"type\":\"SCALED_IMU3"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE: 
            // msgid = 130
            // 
            mavlink_data_transmission_handshake_t data_transmission_handshake;
            mavlink_msg_data_transmission_handshake_decode(&message, &(data_transmission_handshake));
            stream << "{\"type\":\"DATA_TRANSMISSION_HANDSHAKE"
                << "\",\"type\":\"" << data_transmission_handshake.type
                << "\",\"size\":\"" << data_transmission_handshake.size
                << "\",\"width\":\"" << data_transmission_handshake.width
                << "\",\"height\":\"" << data_transmission_handshake.height
                << "\",\"packets\":\"" << data_transmission_handshake.packets
                << "\",\"payload\":\"" << data_transmission_handshake.payload
                << "\",\"jpg_quality\":\"" << data_transmission_handshake.jpg_quality
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ENCAPSULATED_DATA: 
            // msgid = 131
            // 
            mavlink_encapsulated_data_t encapsulated_data;
            mavlink_msg_encapsulated_data_decode(&message, &(encapsulated_data));
            stream << "{\"type\":\"ENCAPSULATED_DATA"
                << "\",\"seqnr\":\"" << encapsulated_data.seqnr
                << "\",\"data\":\"" << encapsulated_data.data
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DISTANCE_SENSOR: 
            // msgid = 132
            // 
            mavlink_distance_sensor_t distance_sensor;
            mavlink_msg_distance_sensor_decode(&message, &(distance_sensor));
            stream << "{\"type\":\"DISTANCE_SENSOR"
                << "\",\"time_boot_ms\":\"" << distance_sensor.time_boot_ms
                << "\",\"min_distance\":\"" << distance_sensor.min_distance
                << "\",\"max_distance\":\"" << distance_sensor.max_distance
                << "\",\"current_distance\":\"" << distance_sensor.current_distance
                << "\",\"type\":\"" << distance_sensor.type
                << "\",\"id\":\"" << distance_sensor.id
                << "\",\"orientation\":\"" << distance_sensor.orientation
                << "\",\"covariance\":\"" << distance_sensor.covariance
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_TERRAIN_REQUEST: 
            // msgid = 133
            // 
            mavlink_terrain_request_t terrain_request;
            mavlink_msg_terrain_request_decode(&message, &(terrain_request));
            stream << "{\"type\":\"TERRAIN_REQUEST"
                << "\",\"lat\":\"" << terrain_request.lat
                << "\",\"lon\":\"" << terrain_request.lon
                << "\",\"grid_spacing\":\"" << terrain_request.grid_spacing
                << "\",\"mask\":\"" << terrain_request.mask
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_TERRAIN_DATA: 
            // msgid = 134
            // 
            mavlink_terrain_data_t terrain_data;
            mavlink_msg_terrain_data_decode(&message, &(terrain_data));
            stream << "{\"type\":\"TERRAIN_DATA"
                << "\",\"lat\":\"" << terrain_data.lat
                << "\",\"lon\":\"" << terrain_data.lon
                << "\",\"grid_spacing\":\"" << terrain_data.grid_spacing
                << "\",\"gridbit\":\"" << terrain_data.gridbit
                << "\",\"data\":\"" << terrain_data.data
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_TERRAIN_CHECK: 
            // msgid = 135
            // 
            mavlink_terrain_check_t terrain_check;
            mavlink_msg_terrain_check_decode(&message, &(terrain_check));
            stream << "{\"type\":\"TERRAIN_CHECK"
                << "\",\"lat\":\"" << terrain_check.lat
                << "\",\"lon\":\"" << terrain_check.lon
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_TERRAIN_REPORT: 
            // msgid = 136
            // 
            mavlink_terrain_report_t terrain_report;
            mavlink_msg_terrain_report_decode(&message, &(terrain_report));
            stream << "{\"type\":\"TERRAIN_REPORT"
                << "\",\"lat\":\"" << terrain_report.lat
                << "\",\"lon\":\"" << terrain_report.lon
                << "\",\"spacing\":\"" << terrain_report.spacing
                << "\",\"terrain_height\":\"" << terrain_report.terrain_height
                << "\",\"current_height\":\"" << terrain_report.current_height
                << "\",\"pending\":\"" << terrain_report.pending
                << "\",\"loaded\":\"" << terrain_report.loaded
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SCALED_PRESSURE2: 
            // msgid = 137
            // 
            mavlink_scaled_pressure2_t scaled_pressure2;
            mavlink_msg_scaled_pressure2_decode(&message, &(scaled_pressure2));
            stream << "{\"type\":\"SCALED_PRESSURE2"
                << "\",\"time_boot_ms\":\"" << scaled_pressure2.time_boot_ms
                << "\",\"press_abs\":\"" << scaled_pressure2.press_abs
                << "\",\"press_diff\":\"" << scaled_pressure2.press_diff
                << "\",\"temperature\":\"" << scaled_pressure2.temperature
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ATT_POS_MOCAP: 
            // msgid = 138
            // 
            mavlink_att_pos_mocap_t att_pos_mocap;
            mavlink_msg_att_pos_mocap_decode(&message, &(att_pos_mocap));
            stream << "{\"type\":\"ATT_POS_MOCAP"
                << "\",\"time_usec\":\"" << att_pos_mocap.time_usec
                << "\",\"q\":\"" << att_pos_mocap.q
                << "\",\"x\":\"" << att_pos_mocap.x
                << "\",\"y\":\"" << att_pos_mocap.y
                << "\",\"z\":\"" << att_pos_mocap.z
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET: 
            // msgid = 139
            // 
            mavlink_set_actuator_control_target_t set_actuator_control_target;
            mavlink_msg_set_actuator_control_target_decode(&message, &(set_actuator_control_target));
            stream << "{\"type\":\"SET_ACTUATOR_CONTROL_TARGET"
                << "\",\"time_usec\":\"" << set_actuator_control_target.time_usec
                << "\",\"group_mlx\":\"" << set_actuator_control_target.group_mlx
                << "\",\"target_system\":\"" << set_actuator_control_target.target_system
                << "\",\"target_component\":\"" << set_actuator_control_target.target_component
                << "\",\"controls\":\"" << set_actuator_control_target.controls
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET: 
            // msgid = 140
            // 
            mavlink_actuator_control_target_t actuator_control_target;
            mavlink_msg_actuator_control_target_decode(&message, &(actuator_control_target));
            stream << "{\"type\":\"ACTUATOR_CONTROL_TARGET"
                << "\",\"time_usec\":\"" << actuator_control_target.time_usec
                << "\",\"group_mlx\":\"" << actuator_control_target.group_mlx
                << "\",\"controls\":\"" << actuator_control_target.controls
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_BATTERY_STATUS: 
            // msgid = 147
            // 
            mavlink_battery_status_t battery_status;
            mavlink_msg_battery_status_decode(&message, &(battery_status));
            stream << "{\"type\":\"BATTERY_STATUS"
                << "\",\"id\":\"" << battery_status.id
                << "\",\"battery_function\":\"" << battery_status.battery_function
                << "\",\"type\":\"" << battery_status.type
                << "\",\"temperature\":\"" << battery_status.temperature
                << "\",\"voltages\":\"" << battery_status.voltages
                << "\",\"current_battery\":\"" << battery_status.current_battery
                << "\",\"current_consumed\":\"" << battery_status.current_consumed
                << "\",\"energy_consumed\":\"" << battery_status.energy_consumed
                << "\",\"battery_remaining\":\"" << battery_status.battery_remaining
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_AUTOPILOT_VERSION: 
            // msgid = 148
            // 
            mavlink_autopilot_version_t autopilot_version;
            mavlink_msg_autopilot_version_decode(&message, &(autopilot_version));
            stream << "{\"type\":\"AUTOPILOT_VERSION"
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

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_V2_EXTENSION: 
            // msgid = 248
            // 
            mavlink_v2_extension_t v2_extension;
            mavlink_msg_v2_extension_decode(&message, &(v2_extension));
            stream << "{\"type\":\"V2_EXTENSION"
                << "\",\"target_network\":\"" << v2_extension.target_network
                << "\",\"target_system\":\"" << v2_extension.target_system
                << "\",\"target_component\":\"" << v2_extension.target_component
                << "\",\"message_type\":\"" << v2_extension.message_type
                << "\",\"payload\":\"" << v2_extension.payload
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_MEMORY_VECT: 
            // msgid = 249
            // 
            mavlink_memory_vect_t memory_vect;
            mavlink_msg_memory_vect_decode(&message, &(memory_vect));
            stream << "{\"type\":\"MEMORY_VECT"
                << "\",\"address\":\"" << memory_vect.address
                << "\",\"ver\":\"" << memory_vect.ver
                << "\",\"type\":\"" << memory_vect.type
                << "\",\"value\":\"" << memory_vect.value
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DEBUG_VECT: 
            // msgid = 250
            // 
            mavlink_debug_vect_t debug_vect;
            mavlink_msg_debug_vect_decode(&message, &(debug_vect));
            stream << "{\"type\":\"DEBUG_VECT"
                << "\",\"name\":\"" << debug_vect.name
                << "\",\"time_usec\":\"" << debug_vect.time_usec
                << "\",\"x\":\"" << debug_vect.x
                << "\",\"y\":\"" << debug_vect.y
                << "\",\"z\":\"" << debug_vect.z
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_NAMED_VALUE_FLOAT: 
            // msgid = 251
            // 
            mavlink_named_value_float_t named_value_float;
            mavlink_msg_named_value_float_decode(&message, &(named_value_float));
            stream << "{\"type\":\"NAMED_VALUE_FLOAT"
                << "\",\"time_boot_ms\":\"" << named_value_float.time_boot_ms
                << "\",\"name\":\"" << named_value_float.name
                << "\",\"value\":\"" << named_value_float.value
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_NAMED_VALUE_INT: 
            // msgid = 252
            // 
            mavlink_named_value_int_t named_value_int;
            mavlink_msg_named_value_int_decode(&message, &(named_value_int));
            stream << "{\"type\":\"NAMED_VALUE_INT"
                << "\",\"time_boot_ms\":\"" << named_value_int.time_boot_ms
                << "\",\"name\":\"" << named_value_int.name
                << "\",\"value\":\"" << named_value_int.value
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_STATUSTEXT: 
            // msgid = 253
            // 
            mavlink_statustext_t statustext;
            mavlink_msg_statustext_decode(&message, &(statustext));
            stream << "{\"type\":\"STATUSTEXT"
                << "\",\"severity\":\"" << statustext.severity
                << "\",\"text\":\"" << statustext.text
                << "\"}";

            josn_message = stream.str();
            return 0;

        case MAVLINK_MSG_ID_DEBUG: 
            // msgid = 254
            // 
            mavlink_debug_t debug;
            mavlink_msg_debug_decode(&message, &(debug));
            stream << "{\"type\":\"DEBUG"
                << "\",\"time_boot_ms\":\"" << debug.time_boot_ms
                << "\",\"ind\":\"" << debug.ind
                << "\",\"value\":\"" << debug.value
                << "\"}";

            josn_message = stream.str();
            return 0;

        default:
            // msgid = None
            //
            stream << "{\"type\":\"CONVERSION_ERROR\"}";

            josn_message = stream.str();
            return 0;

    }
    return -1;
}
