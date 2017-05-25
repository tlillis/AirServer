/** @file
 *	@brief MAVLink comm protocol testsuite generated from airserver.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef AIRSERVER_TESTSUITE_H
#define AIRSERVER_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_airserver(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_ardupilotmega(system_id, component_id, last_msg);
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_airserver(system_id, component_id, last_msg);
}
#endif

#include "../ardupilotmega/testsuite.h"
#include "../common/testsuite.h"


static void mavlink_test_ncar_pth(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ncar_pth_t packet_in = {
		93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,89
    };
	mavlink_ncar_pth_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time_usec = packet_in.time_usec;
        	packet1.pressure = packet_in.pressure;
        	packet1.external_temp = packet_in.external_temp;
        	packet1.rh1 = packet_in.rh1;
        	packet1.rh2 = packet_in.rh2;
        	packet1.internal_temp = packet_in.internal_temp;
        	packet1.sample_num = packet_in.sample_num;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ncar_pth_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ncar_pth_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ncar_pth_pack(system_id, component_id, &msg , packet1.time_usec , packet1.sample_num , packet1.pressure , packet1.external_temp , packet1.rh1 , packet1.rh2 , packet1.internal_temp );
	mavlink_msg_ncar_pth_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ncar_pth_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.sample_num , packet1.pressure , packet1.external_temp , packet1.rh1 , packet1.rh2 , packet1.internal_temp );
	mavlink_msg_ncar_pth_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ncar_pth_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ncar_pth_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.sample_num , packet1.pressure , packet1.external_temp , packet1.rh1 , packet1.rh2 , packet1.internal_temp );
	mavlink_msg_ncar_pth_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_vector_nav(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_vector_nav_t packet_in = {
		93372036854775807ULL,93372036854776311ULL,93372036854776815ULL,93372036854777319ULL,347.0,403.0,459.0,93372036854779335ULL,465.0,493.0,521.0,549.0,577.0,605.0,633.0,661.0,689.0,717.0,745.0,773.0,801.0,829.0,857.0,885.0,913.0,941.0,969.0,997.0,1025.0,1053.0,1081.0,1109.0,1137.0,1165.0,1193.0,1221.0,1249.0,1277.0,1305.0,1333.0,1361.0,1389.0,963507864,27843
    };
	mavlink_vector_nav_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time_usec = packet_in.time_usec;
        	packet1.time_startup = packet_in.time_startup;
        	packet1.time_gps = packet_in.time_gps;
        	packet1.time_syncln = packet_in.time_syncln;
        	packet1.lat = packet_in.lat;
        	packet1.lon = packet_in.lon;
        	packet1.alt = packet_in.alt;
        	packet1.gps_pps = packet_in.gps_pps;
        	packet1.yaw = packet_in.yaw;
        	packet1.pitch = packet_in.pitch;
        	packet1.roll = packet_in.roll;
        	packet1.qtn_0 = packet_in.qtn_0;
        	packet1.qtn_1 = packet_in.qtn_1;
        	packet1.qtn_2 = packet_in.qtn_2;
        	packet1.qtn_3 = packet_in.qtn_3;
        	packet1.rate_0 = packet_in.rate_0;
        	packet1.rate_1 = packet_in.rate_1;
        	packet1.rate_2 = packet_in.rate_2;
        	packet1.vel_0 = packet_in.vel_0;
        	packet1.vel_1 = packet_in.vel_1;
        	packet1.vel_2 = packet_in.vel_2;
        	packet1.accel_0 = packet_in.accel_0;
        	packet1.accel_1 = packet_in.accel_1;
        	packet1.accel_2 = packet_in.accel_2;
        	packet1.imu_0 = packet_in.imu_0;
        	packet1.imu_1 = packet_in.imu_1;
        	packet1.imu_2 = packet_in.imu_2;
        	packet1.imu_3 = packet_in.imu_3;
        	packet1.imu_4 = packet_in.imu_4;
        	packet1.imu_5 = packet_in.imu_5;
        	packet1.mag_pres_0 = packet_in.mag_pres_0;
        	packet1.mag_pres_1 = packet_in.mag_pres_1;
        	packet1.mag_pres_2 = packet_in.mag_pres_2;
        	packet1.mag_pres_3 = packet_in.mag_pres_3;
        	packet1.mag_pres_4 = packet_in.mag_pres_4;
        	packet1.delta_theta_0 = packet_in.delta_theta_0;
        	packet1.delta_theta_1 = packet_in.delta_theta_1;
        	packet1.delta_theta_2 = packet_in.delta_theta_2;
        	packet1.delta_theta_3 = packet_in.delta_theta_3;
        	packet1.delta_theta_4 = packet_in.delta_theta_4;
        	packet1.delta_theta_5 = packet_in.delta_theta_5;
        	packet1.delta_theta_6 = packet_in.delta_theta_6;
        	packet1.syncln_cnt = packet_in.syncln_cnt;
        	packet1.ins_status = packet_in.ins_status;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vector_nav_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_vector_nav_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vector_nav_pack(system_id, component_id, &msg , packet1.time_usec , packet1.time_startup , packet1.time_gps , packet1.time_syncln , packet1.yaw , packet1.pitch , packet1.roll , packet1.qtn_0 , packet1.qtn_1 , packet1.qtn_2 , packet1.qtn_3 , packet1.rate_0 , packet1.rate_1 , packet1.rate_2 , packet1.lat , packet1.lon , packet1.alt , packet1.vel_0 , packet1.vel_1 , packet1.vel_2 , packet1.accel_0 , packet1.accel_1 , packet1.accel_2 , packet1.imu_0 , packet1.imu_1 , packet1.imu_2 , packet1.imu_3 , packet1.imu_4 , packet1.imu_5 , packet1.mag_pres_0 , packet1.mag_pres_1 , packet1.mag_pres_2 , packet1.mag_pres_3 , packet1.mag_pres_4 , packet1.delta_theta_0 , packet1.delta_theta_1 , packet1.delta_theta_2 , packet1.delta_theta_3 , packet1.delta_theta_4 , packet1.delta_theta_5 , packet1.delta_theta_6 , packet1.ins_status , packet1.syncln_cnt , packet1.gps_pps );
	mavlink_msg_vector_nav_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vector_nav_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.time_startup , packet1.time_gps , packet1.time_syncln , packet1.yaw , packet1.pitch , packet1.roll , packet1.qtn_0 , packet1.qtn_1 , packet1.qtn_2 , packet1.qtn_3 , packet1.rate_0 , packet1.rate_1 , packet1.rate_2 , packet1.lat , packet1.lon , packet1.alt , packet1.vel_0 , packet1.vel_1 , packet1.vel_2 , packet1.accel_0 , packet1.accel_1 , packet1.accel_2 , packet1.imu_0 , packet1.imu_1 , packet1.imu_2 , packet1.imu_3 , packet1.imu_4 , packet1.imu_5 , packet1.mag_pres_0 , packet1.mag_pres_1 , packet1.mag_pres_2 , packet1.mag_pres_3 , packet1.mag_pres_4 , packet1.delta_theta_0 , packet1.delta_theta_1 , packet1.delta_theta_2 , packet1.delta_theta_3 , packet1.delta_theta_4 , packet1.delta_theta_5 , packet1.delta_theta_6 , packet1.ins_status , packet1.syncln_cnt , packet1.gps_pps );
	mavlink_msg_vector_nav_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_vector_nav_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vector_nav_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.time_startup , packet1.time_gps , packet1.time_syncln , packet1.yaw , packet1.pitch , packet1.roll , packet1.qtn_0 , packet1.qtn_1 , packet1.qtn_2 , packet1.qtn_3 , packet1.rate_0 , packet1.rate_1 , packet1.rate_2 , packet1.lat , packet1.lon , packet1.alt , packet1.vel_0 , packet1.vel_1 , packet1.vel_2 , packet1.accel_0 , packet1.accel_1 , packet1.accel_2 , packet1.imu_0 , packet1.imu_1 , packet1.imu_2 , packet1.imu_3 , packet1.imu_4 , packet1.imu_5 , packet1.mag_pres_0 , packet1.mag_pres_1 , packet1.mag_pres_2 , packet1.mag_pres_3 , packet1.mag_pres_4 , packet1.delta_theta_0 , packet1.delta_theta_1 , packet1.delta_theta_2 , packet1.delta_theta_3 , packet1.delta_theta_4 , packet1.delta_theta_5 , packet1.delta_theta_6 , packet1.ins_status , packet1.syncln_cnt , packet1.gps_pps );
	mavlink_msg_vector_nav_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_aeroprobe(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_aeroprobe_t packet_in = {
		93372036854775807ULL,963497880,963498088,129.0,157.0,185.0,213.0,241.0,269.0,297.0
    };
	mavlink_aeroprobe_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time_usec = packet_in.time_usec;
        	packet1.time_device = packet_in.time_device;
        	packet1.date = packet_in.date;
        	packet1.velocity = packet_in.velocity;
        	packet1.aoa = packet_in.aoa;
        	packet1.aos = packet_in.aos;
        	packet1.pa = packet_in.pa;
        	packet1.ps = packet_in.ps;
        	packet1.pt = packet_in.pt;
        	packet1.tc = packet_in.tc;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_aeroprobe_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_aeroprobe_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_aeroprobe_pack(system_id, component_id, &msg , packet1.time_usec , packet1.time_device , packet1.date , packet1.velocity , packet1.aoa , packet1.aos , packet1.pa , packet1.ps , packet1.pt , packet1.tc );
	mavlink_msg_aeroprobe_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_aeroprobe_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.time_device , packet1.date , packet1.velocity , packet1.aoa , packet1.aos , packet1.pa , packet1.ps , packet1.pt , packet1.tc );
	mavlink_msg_aeroprobe_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_aeroprobe_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_aeroprobe_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.time_device , packet1.date , packet1.velocity , packet1.aoa , packet1.aos , packet1.pa , packet1.ps , packet1.pt , packet1.tc );
	mavlink_msg_aeroprobe_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_airserver(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_ncar_pth(system_id, component_id, last_msg);
	mavlink_test_vector_nav(system_id, component_id, last_msg);
	mavlink_test_aeroprobe(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // AIRSERVER_TESTSUITE_H
