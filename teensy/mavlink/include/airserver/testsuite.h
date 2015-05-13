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
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_airserver(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_airserver(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_meminfo(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_meminfo_t packet_in = {
		17235,17339
    };
	mavlink_meminfo_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.brkval = packet_in.brkval;
        	packet1.freemem = packet_in.freemem;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_meminfo_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_meminfo_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_meminfo_pack(system_id, component_id, &msg , packet1.brkval , packet1.freemem );
	mavlink_msg_meminfo_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_meminfo_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.brkval , packet1.freemem );
	mavlink_msg_meminfo_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_meminfo_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_meminfo_send(MAVLINK_COMM_1 , packet1.brkval , packet1.freemem );
	mavlink_msg_meminfo_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ap_adc(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ap_adc_t packet_in = {
		17235,17339,17443,17547,17651,17755
    };
	mavlink_ap_adc_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.adc1 = packet_in.adc1;
        	packet1.adc2 = packet_in.adc2;
        	packet1.adc3 = packet_in.adc3;
        	packet1.adc4 = packet_in.adc4;
        	packet1.adc5 = packet_in.adc5;
        	packet1.adc6 = packet_in.adc6;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ap_adc_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ap_adc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ap_adc_pack(system_id, component_id, &msg , packet1.adc1 , packet1.adc2 , packet1.adc3 , packet1.adc4 , packet1.adc5 , packet1.adc6 );
	mavlink_msg_ap_adc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ap_adc_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.adc1 , packet1.adc2 , packet1.adc3 , packet1.adc4 , packet1.adc5 , packet1.adc6 );
	mavlink_msg_ap_adc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ap_adc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ap_adc_send(MAVLINK_COMM_1 , packet1.adc1 , packet1.adc2 , packet1.adc3 , packet1.adc4 , packet1.adc5 , packet1.adc6 );
	mavlink_msg_ap_adc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ahrs(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ahrs_t packet_in = {
		17.0,45.0,73.0,101.0,129.0,157.0,185.0
    };
	mavlink_ahrs_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.omegaIx = packet_in.omegaIx;
        	packet1.omegaIy = packet_in.omegaIy;
        	packet1.omegaIz = packet_in.omegaIz;
        	packet1.accel_weight = packet_in.accel_weight;
        	packet1.renorm_val = packet_in.renorm_val;
        	packet1.error_rp = packet_in.error_rp;
        	packet1.error_yaw = packet_in.error_yaw;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs_pack(system_id, component_id, &msg , packet1.omegaIx , packet1.omegaIy , packet1.omegaIz , packet1.accel_weight , packet1.renorm_val , packet1.error_rp , packet1.error_yaw );
	mavlink_msg_ahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.omegaIx , packet1.omegaIy , packet1.omegaIz , packet1.accel_weight , packet1.renorm_val , packet1.error_rp , packet1.error_yaw );
	mavlink_msg_ahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ahrs_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs_send(MAVLINK_COMM_1 , packet1.omegaIx , packet1.omegaIy , packet1.omegaIz , packet1.accel_weight , packet1.renorm_val , packet1.error_rp , packet1.error_yaw );
	mavlink_msg_ahrs_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_simstate(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_simstate_t packet_in = {
		17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,963499336,963499544
    };
	mavlink_simstate_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.roll = packet_in.roll;
        	packet1.pitch = packet_in.pitch;
        	packet1.yaw = packet_in.yaw;
        	packet1.xacc = packet_in.xacc;
        	packet1.yacc = packet_in.yacc;
        	packet1.zacc = packet_in.zacc;
        	packet1.xgyro = packet_in.xgyro;
        	packet1.ygyro = packet_in.ygyro;
        	packet1.zgyro = packet_in.zgyro;
        	packet1.lat = packet_in.lat;
        	packet1.lng = packet_in.lng;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_simstate_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_simstate_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_simstate_pack(system_id, component_id, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.lat , packet1.lng );
	mavlink_msg_simstate_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_simstate_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.lat , packet1.lng );
	mavlink_msg_simstate_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_simstate_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_simstate_send(MAVLINK_COMM_1 , packet1.roll , packet1.pitch , packet1.yaw , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.lat , packet1.lng );
	mavlink_msg_simstate_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_hwstatus(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_hwstatus_t packet_in = {
		17235,139
    };
	mavlink_hwstatus_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.Vcc = packet_in.Vcc;
        	packet1.I2Cerr = packet_in.I2Cerr;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hwstatus_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_hwstatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hwstatus_pack(system_id, component_id, &msg , packet1.Vcc , packet1.I2Cerr );
	mavlink_msg_hwstatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hwstatus_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Vcc , packet1.I2Cerr );
	mavlink_msg_hwstatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_hwstatus_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hwstatus_send(MAVLINK_COMM_1 , packet1.Vcc , packet1.I2Cerr );
	mavlink_msg_hwstatus_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wind(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_wind_t packet_in = {
		17.0,45.0,73.0
    };
	mavlink_wind_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.direction = packet_in.direction;
        	packet1.speed = packet_in.speed;
        	packet1.speed_z = packet_in.speed_z;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_wind_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_wind_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_wind_pack(system_id, component_id, &msg , packet1.direction , packet1.speed , packet1.speed_z );
	mavlink_msg_wind_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_wind_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.direction , packet1.speed , packet1.speed_z );
	mavlink_msg_wind_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_wind_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_wind_send(MAVLINK_COMM_1 , packet1.direction , packet1.speed , packet1.speed_z );
	mavlink_msg_wind_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ahrs2(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_ahrs2_t packet_in = {
		17.0,45.0,73.0,101.0,963498296,963498504
    };
	mavlink_ahrs2_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.roll = packet_in.roll;
        	packet1.pitch = packet_in.pitch;
        	packet1.yaw = packet_in.yaw;
        	packet1.altitude = packet_in.altitude;
        	packet1.lat = packet_in.lat;
        	packet1.lng = packet_in.lng;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs2_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_ahrs2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs2_pack(system_id, component_id, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.altitude , packet1.lat , packet1.lng );
	mavlink_msg_ahrs2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs2_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.altitude , packet1.lat , packet1.lng );
	mavlink_msg_ahrs2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_ahrs2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_ahrs2_send(MAVLINK_COMM_1 , packet1.roll , packet1.pitch , packet1.yaw , packet1.altitude , packet1.lat , packet1.lng );
	mavlink_msg_ahrs2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

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

static void mavlink_test_airserver(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_meminfo(system_id, component_id, last_msg);
	mavlink_test_ap_adc(system_id, component_id, last_msg);
	mavlink_test_ahrs(system_id, component_id, last_msg);
	mavlink_test_simstate(system_id, component_id, last_msg);
	mavlink_test_hwstatus(system_id, component_id, last_msg);
	mavlink_test_wind(system_id, component_id, last_msg);
	mavlink_test_ahrs2(system_id, component_id, last_msg);
	mavlink_test_ncar_pth(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // AIRSERVER_TESTSUITE_H
