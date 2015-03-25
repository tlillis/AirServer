#include "conversions.h"

int mav_to_json(mavlink_message_t &message,char *json_buffer)
{
    int msgid = message.msgid;

    sprintf(json_buffer,"SYSTEM ID: %i",msgid);

    // Handle Message ID
    switch (msgid)
    {

        case MAVLINK_MSG_ID_HEARTBEAT:
        {
            // Heart Beat
            mavlink_heartbeat_t heartbeat;

            //printf("MAVLINK_MSG_ID_HEARTBEAT\n");
            mavlink_msg_heartbeat_decode(&message, &(heartbeat));

            if(sprintf(json_buffer,"{\"HRT\":{\"type\":%i,\"autoPilot\":%i,\"baseMode\":%i}}",
                                    heartbeat.type,heartbeat.autopilot,heartbeat.base_mode) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_SYS_STATUS:
        {
            // System Status
            mavlink_sys_status_t sys_status;

            //printf("MAVLINK_MSG_ID_SYS_STATUS\n");
            mavlink_msg_sys_status_decode(&message, &(sys_status));

            if(sprintf(json_buffer,"{\"STA\":{\"controlSensors\":%i,\"enabled\":%i,\"health\":%i,"
                            "\"load\":%i,\"voltage\":%i,\"current\":%i,\"remaining\":%i,"
                            "\"comDrops\":%i,\"comErrors\":%i}}",
                            sys_status.onboard_control_sensors_present,
                            sys_status.onboard_control_sensors_enabled,
                            sys_status.onboard_control_sensors_health,
                            sys_status.load,
                            sys_status.voltage_battery,sys_status.current_battery,
                            sys_status.battery_remaining,sys_status.drop_rate_comm,
                            sys_status.errors_comm) < 0) return -1;

            return 0;
        }

        case MAVLINK_MSG_ID_BATTERY_STATUS:
        {
            // Battery Status
            mavlink_battery_status_t battery_status;

            //printf("MAVLINK_MSG_ID_BATTERY_STATUS\n");
            mavlink_msg_battery_status_decode(&message, &(battery_status));
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_RADIO_STATUS:
        {
            // Radio Status
            mavlink_radio_status_t radio_status;

            //printf("MAVLINK_MSG_ID_RADIO_STATUS\n");
            mavlink_msg_radio_status_decode(&message, &(radio_status));
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_LOCAL_POSITION_NED:
        {
            // Local Position
            mavlink_local_position_ned_t local_position_ned;

            //printf("MAVLINK_MSG_ID_LOCAL_POSITION_NED\n");
            mavlink_msg_local_position_ned_decode(&message, &(local_position_ned));

            if(sprintf(json_buffer,"{\"NED\":{\"nedX\":%f,\"nedY\":%f,\"nedZ\":%f}}",
                                        local_position_ned.x, local_position_ned.y,
                                        local_position_ned.z ) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
        {
            // Global Position
            mavlink_global_position_int_t global_position_int;

            //printf("MAVLINK_MSG_ID_GLOBAL_POSITION_INT\n");
            mavlink_msg_global_position_int_decode(&message, &(global_position_int));

            if(sprintf(json_buffer,"{\"GPS\":{\"time\":%i,\"lat\":%i,\"lon\":%i,\"alt\":%i,\"relAlt\":%i,"
                                        "\"velX\":%i,\"velY\":%i,\"velZ\":%i}}",
                                        global_position_int.time_boot_ms,global_position_int.lat,
                                        global_position_int.lon, global_position_int.alt,
                                        global_position_int.relative_alt,global_position_int.vx,
                                        global_position_int.vy,global_position_int.vz) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED:
        {
            // Local Position Target
            mavlink_position_target_local_ned_t position_target_local_ned;

            //printf("MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED\n");
            mavlink_msg_position_target_local_ned_decode(&message, &(position_target_local_ned));
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT:
        {
            // Global Position Target
            mavlink_position_target_global_int_t position_target_global_int;

            //printf("MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT\n");
            mavlink_msg_position_target_global_int_decode(&message, &(position_target_global_int));
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_HIGHRES_IMU:
        {
            // HiRes IMU
            mavlink_highres_imu_t imu;

            //printf("MAVLINK_MSG_ID_HIGHRES_IMU\n");
            mavlink_msg_highres_imu_decode(&message, &(imu));

            if(sprintf(json_buffer,"{\"IMH\":{\"time\":%lu,\"accX\":%f,\"accY\":%f,\"accZ\":%f,"
                                        "\"gyroX\":%f,\"gyroY\":%f,\"gyrcoZ\":%f,"
                                        "\"magX\":%f,\"magY\":%f,\"magZ\":%f,"
                                        "\"baro\":%f,\"alt\":%f,\"temp\":%f}}",
                                        imu.time_usec,imu.xacc,imu.yacc,imu.zacc,
                                        imu.xgyro,imu.ygyro,imu.zgyro,
                                        imu.xmag,imu.ymag,imu.zmag,
                                        imu.abs_pressure,imu.pressure_alt,
                                        imu.temperature) < 0) return -1;

            return 0;
        }

        case MAVLINK_MSG_ID_ATTITUDE:
        {
             // Attitude
            mavlink_attitude_t attitude;

            //printf("MAVLINK_MSG_ID_ATTITUDE\n");
            mavlink_msg_attitude_decode(&message, &(attitude));

            if(sprintf(json_buffer,"{\"ATT\":{\"time\":%i,\"roll\":%f,\"pitch\":%f,\"yaw\":%f,"
                                        "\"rollSpeed\":%f,\"pitchSpeed\":%f,\"yawSpeed\":%f}}",
                                        attitude.time_boot_ms,attitude.roll,attitude.pitch,attitude.yaw,
                                        attitude.rollspeed,attitude.pitchspeed,
                                        attitude.yawspeed) < 0) return -1;

            return 0;
        }

        case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
        {
            // Raw RC Channels
            mavlink_rc_channels_raw_t channels;

            //printf("MAVLINK_MSG_ID_RC_CHANNELS_RAW\n");
            mavlink_msg_rc_channels_raw_decode(&message, &(channels));

            if(sprintf(json_buffer,"{\"RCR\":{\"time\":%i,\"port\":%i,\"chan1\":%i,\"chan2\":%i,"
                                        "\"chan3\":%i,\"chan4\":%i,\"chan5\":%i,\"chan6\":%i,"
                                        "\"chan7\":%i,\"chan8\":%i}}",
                                        channels.time_boot_ms,channels.port,channels.chan1_raw,
                                        channels.chan2_raw,channels.chan3_raw,channels.chan4_raw,
                                        channels.chan5_raw,channels.chan6_raw,channels.chan7_raw,
                                        channels.chan8_raw) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_TERRAIN_REPORT:
        {
            // Terrain Report (136)
            mavlink_terrain_report_t terrain;

            //printf("MAVLINK_MSG_ID_TERRAIN_REPORT\n");
            mavlink_msg_terrain_report_decode(&message, &(terrain));

            if(sprintf(json_buffer,"{\"TER\":{\"lat\":%i,\"lon\":%i,"
                                        "\"spacing\":%i,\"terrainHeight\":%f,\"currentHeight\":%f,"
                                        "\"pending\":%i,\"loaded\":%i}}",
                                        terrain.lat,terrain.lon,terrain.spacing,terrain.terrain_height,
                                        terrain.current_height,terrain.pending,
                                        terrain.loaded) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW:
        {
            // Servo Output Raw (36)
            mavlink_servo_output_raw_t servo;

            //printf("MAVLINK_MSG_ID_SERVO_OUTPUT_RAW\n");
            mavlink_msg_servo_output_raw_decode(&message, &(servo));

            if(sprintf(json_buffer,"{\"SOR\":{\"time\":%i,\"port\":%i,"
                                        "\"servo1\":%i,\"servo2\":%i,\"servo3\":%i,\"servo4\":%i,"
                                        "\"servo5\":%i,\"servo6\":%i,\"servo7\":%i,\"servo8\":%i}}",
                                        servo.time_usec,servo.port,servo.servo1_raw,servo.servo2_raw,
                                        servo.servo3_raw,servo.servo4_raw,servo.servo5_raw,
                                        servo.servo6_raw,servo.servo7_raw,servo.servo8_raw) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_MISSION_CURRENT:
        {
            // Mission Current (42)
            mavlink_mission_current_t mission_current;

            //printf("MAVLINK_MSG_ID_MISSION_CURRENT\n");
            mavlink_msg_mission_current_decode(&message, &(mission_current));

            if(sprintf(json_buffer,"{\"MIC\":{\"seq\":%i}}",mission_current.seq) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_SYSTEM_TIME:
        {
            // System Time (2)
            mavlink_system_time_t time;

            //printf("MAVLINK_MSG_ID_SYSTEM_TIME\n");
            mavlink_msg_system_time_decode(&message, &(time));

            if(sprintf(json_buffer,"{\"TIM\":{\"master\":%lld,\"component\":%i}}",
                                        (long long)time.time_unix_usec,time.time_boot_ms) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_SCALED_PRESSURE:
        {
            // Scaled Pressure (29)
            mavlink_scaled_pressure_t pressure;

            //printf("MAVLINK_MSG_ID_SCALED_PRESSURE\n");
            mavlink_msg_scaled_pressure_decode(&message, &(pressure));

            if(sprintf(json_buffer,"{\"PRE\":{\"time\":%i,\"absolute\":%f,"
                                        "\"differential\":%f,\"temperature\":%i}}",
                                       pressure.time_boot_ms,pressure.press_abs,pressure.press_diff,
                                       pressure.temperature) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_SCALED_IMU2:
        {
            // Scaled IMU2 (116)
            mavlink_scaled_imu2_t imu2;

            //printf("MAVLINK_MSG_ID_SCALED_IMU2\n");
            mavlink_msg_scaled_imu2_decode(&message, &(imu2));

            if(sprintf(json_buffer,"{\"IM2\":{\"time\":%i,\"accX\":%i,\"accY\":%i,\"accZ\":%i,"
                                        "\"gyroX\":%i,\"gyroY\":%i,\"gyroZ\":%i,"
                                        "\"magX\":%i,\"magY\":%i,\"magZ\":%i}}",
                                        imu2.time_boot_ms,imu2.xacc,imu2.yacc,imu2.zacc,
                                        imu2.xgyro,imu2.ygyro,imu2.zgyro,
                                        imu2.xmag,imu2.ymag,imu2.zmag) < 0) return -1;

            return 0;
        }

        case MAVLINK_MSG_ID_GPS_RAW_INT:
        {
            // GPS RAW INT (24)
            mavlink_gps_raw_int_t gps_raw;

            //printf("MAVLINK_MSG_ID_GPS_RAW_INT\n");
            mavlink_msg_gps_raw_int_decode(&message, &(gps_raw));

            if(sprintf(json_buffer,"{\"GPR\":{\"time\":%lld,\"fixType\":%i,"
                                        "\"lat\":%i,\"lon\":%i,\"alt\":%i,"
                                        "\"ehp\":%i,\"epv\":%i,\"velocity\":%i,\"cog\":%i,"
                                        "\"satellites\":%i}}",
                                        (long long)gps_raw.time_usec,gps_raw.fix_type,
                                        gps_raw.lat,gps_raw.lon,gps_raw.alt,
                                        gps_raw.eph,gps_raw.epv,gps_raw.vel,gps_raw.cog,
                                        gps_raw.satellites_visible) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_RAW_IMU:
        {
            // RAW IMU (27)
            mavlink_raw_imu_t imu_raw;

            //printf("MAVLINK_MSG_ID_RAW_IMU\n");
            mavlink_msg_raw_imu_decode(&message, &(imu_raw));

            if(sprintf(json_buffer,"{\"IMU\":{\"time\":%lld,\"accX\":%i,\"accY\":%i,\"accZ\":%i,"
                                        "\"gyroX\":%i,\"gyroY\":%i,\"gyroZ\":%i,"
                                        "\"magX\":%i,\"magY\":%i,\"magZ\":%i}}",
                                        (long long)imu_raw.time_usec,imu_raw.xacc,imu_raw.yacc,imu_raw.zacc,
                                        imu_raw.xgyro,imu_raw.ygyro,imu_raw.zgyro,
                                        imu_raw.xmag,imu_raw.ymag,imu_raw.zmag) < 0) return -1;
            return 0;
        }

        case MAVLINK_MSG_ID_VFR_HUD:
        {
            // VFW_HUD (74)
            mavlink_vfr_hud_t vfr;

            //printf("MAVLINK_MSG_ID_VFR_HUD\n");
            mavlink_msg_vfr_hud_decode(&message, &(vfr));

            if(sprintf(json_buffer,"{\"VFR\":{\"airspeed\":%f,\"groundspeed\":%f,\"heading\":%i,"
                                        "\"throttle\":%i,\"alt\":%f,\"climb\":%f,}}",
                                        vfr.airspeed,vfr.groundspeed,vfr.heading,vfr.throttle,
                                        vfr.alt,vfr.climb) < 0) return -1;
            return 0;
        }

        default:
        {
            printf("Warning, did not handle message id %i\n\n",msgid);
            return -1;
        }
    }
    return -1;
}
