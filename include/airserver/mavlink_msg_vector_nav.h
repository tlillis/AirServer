// MESSAGE VECTOR_NAV PACKING

#define MAVLINK_MSG_ID_VECTOR_NAV 241

typedef struct __mavlink_vector_nav_t
{
 uint64_t time_usec; ///< Image timestamp (microseconds since UNIX epoch, according to camera clock)
 uint64_t time_startup; ///< Image timestamp (microseconds since UNIX epoch, according to camera clock)
 uint64_t time_gps; ///< Sample Number
 uint64_t time_syncln; ///< The time since the last SyncIn trigger event expressed in nano seconds.
 double lat; ///< The estimated position
 double lon; ///< The estimated position
 double alt; ///< The estimated position
 uint64_t gps_pps; ///< The time since the last GPS PPS trigger event expressed in nano seconds.f
 float yaw; ///< estimated yaw
 float pitch; ///< estimated pitch
 float roll; ///< estimated roll
 float qtn_0; ///< The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 float qtn_1; ///< The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 float qtn_2; ///< The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 float qtn_3; ///< The estimated attitude quaternion. Scalar value.
 float rate_0; ///< The estimated angular rate measured in rad/s.
 float rate_1; ///< The estimated angular rate measured in rad/s.
 float rate_2; ///< The estimated angular rate measured in rad/s.
 float vel_0; ///< The estimated velocity in the North East Down (NED) frame, given in m/s.
 float vel_1; ///< The estimated velocity in the North East Down (NED) frame, given in m/s.
 float vel_2; ///< The estimated velocity in the North East Down (NED) frame, given in m/s.
 float accel_0; ///< The estimated acceleration in the body frame, given in m/s^2.
 float accel_1; ///< The estimated acceleration in the body frame, given in m/s^2.
 float accel_2; ///< The estimated acceleration in the body frame, given in m/s^2.
 float imu_0; ///< IMU angular rate
 float imu_1; ///< IMU angular rate
 float imu_2; ///< IMU angular rate
 float imu_3; ///< IMU acceleration measurement
 float imu_4; ///< IMU acceleration measurement
 float imu_5; ///< IMU acceleration measurement
 float mag_pres_0; ///< The compensated magnetic, temperature, and pressure measurements from the IMU.
 float mag_pres_1; ///< The compensated magnetic, temperature, and pressure measurements from the IMU.
 float mag_pres_2; ///< The compensated magnetic, temperature, and pressure measurements from the IMU.
 float mag_pres_3; ///< The compensated magnetic, temperature, and pressure measurements from the IMU.(temp)
 float mag_pres_4; ///< The compensated magnetic, temperature, and pressure measurements from the IMU.(pressure)
 float delta_theta_0; ///< delta time
 float delta_theta_1; ///< delta theta
 float delta_theta_2; ///< delta theta
 float delta_theta_3; ///< delta thela
 float delta_theta_4; ///< detla velocity
 float delta_theta_5; ///< delta velocity
 float delta_theta_6; ///< delta velocity
 uint32_t syncln_cnt; ///< The number of SyncIn trigger events that have occurred.
 uint16_t ins_status; ///< The INS status bitfield.
} mavlink_vector_nav_t;

#define MAVLINK_MSG_ID_VECTOR_NAV_LEN 206
#define MAVLINK_MSG_ID_241_LEN 206

#define MAVLINK_MSG_ID_VECTOR_NAV_CRC 178
#define MAVLINK_MSG_ID_241_CRC 178



#define MAVLINK_MESSAGE_INFO_VECTOR_NAV { \
	"VECTOR_NAV", \
	44, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vector_nav_t, time_usec) }, \
         { "time_startup", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_vector_nav_t, time_startup) }, \
         { "time_gps", NULL, MAVLINK_TYPE_UINT64_T, 0, 16, offsetof(mavlink_vector_nav_t, time_gps) }, \
         { "time_syncln", NULL, MAVLINK_TYPE_UINT64_T, 0, 24, offsetof(mavlink_vector_nav_t, time_syncln) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 32, offsetof(mavlink_vector_nav_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 40, offsetof(mavlink_vector_nav_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_DOUBLE, 0, 48, offsetof(mavlink_vector_nav_t, alt) }, \
         { "gps_pps", NULL, MAVLINK_TYPE_UINT64_T, 0, 56, offsetof(mavlink_vector_nav_t, gps_pps) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_vector_nav_t, yaw) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_vector_nav_t, pitch) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_vector_nav_t, roll) }, \
         { "qtn_0", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_vector_nav_t, qtn_0) }, \
         { "qtn_1", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_vector_nav_t, qtn_1) }, \
         { "qtn_2", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_vector_nav_t, qtn_2) }, \
         { "qtn_3", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_vector_nav_t, qtn_3) }, \
         { "rate_0", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_vector_nav_t, rate_0) }, \
         { "rate_1", NULL, MAVLINK_TYPE_FLOAT, 0, 96, offsetof(mavlink_vector_nav_t, rate_1) }, \
         { "rate_2", NULL, MAVLINK_TYPE_FLOAT, 0, 100, offsetof(mavlink_vector_nav_t, rate_2) }, \
         { "vel_0", NULL, MAVLINK_TYPE_FLOAT, 0, 104, offsetof(mavlink_vector_nav_t, vel_0) }, \
         { "vel_1", NULL, MAVLINK_TYPE_FLOAT, 0, 108, offsetof(mavlink_vector_nav_t, vel_1) }, \
         { "vel_2", NULL, MAVLINK_TYPE_FLOAT, 0, 112, offsetof(mavlink_vector_nav_t, vel_2) }, \
         { "accel_0", NULL, MAVLINK_TYPE_FLOAT, 0, 116, offsetof(mavlink_vector_nav_t, accel_0) }, \
         { "accel_1", NULL, MAVLINK_TYPE_FLOAT, 0, 120, offsetof(mavlink_vector_nav_t, accel_1) }, \
         { "accel_2", NULL, MAVLINK_TYPE_FLOAT, 0, 124, offsetof(mavlink_vector_nav_t, accel_2) }, \
         { "imu_0", NULL, MAVLINK_TYPE_FLOAT, 0, 128, offsetof(mavlink_vector_nav_t, imu_0) }, \
         { "imu_1", NULL, MAVLINK_TYPE_FLOAT, 0, 132, offsetof(mavlink_vector_nav_t, imu_1) }, \
         { "imu_2", NULL, MAVLINK_TYPE_FLOAT, 0, 136, offsetof(mavlink_vector_nav_t, imu_2) }, \
         { "imu_3", NULL, MAVLINK_TYPE_FLOAT, 0, 140, offsetof(mavlink_vector_nav_t, imu_3) }, \
         { "imu_4", NULL, MAVLINK_TYPE_FLOAT, 0, 144, offsetof(mavlink_vector_nav_t, imu_4) }, \
         { "imu_5", NULL, MAVLINK_TYPE_FLOAT, 0, 148, offsetof(mavlink_vector_nav_t, imu_5) }, \
         { "mag_pres_0", NULL, MAVLINK_TYPE_FLOAT, 0, 152, offsetof(mavlink_vector_nav_t, mag_pres_0) }, \
         { "mag_pres_1", NULL, MAVLINK_TYPE_FLOAT, 0, 156, offsetof(mavlink_vector_nav_t, mag_pres_1) }, \
         { "mag_pres_2", NULL, MAVLINK_TYPE_FLOAT, 0, 160, offsetof(mavlink_vector_nav_t, mag_pres_2) }, \
         { "mag_pres_3", NULL, MAVLINK_TYPE_FLOAT, 0, 164, offsetof(mavlink_vector_nav_t, mag_pres_3) }, \
         { "mag_pres_4", NULL, MAVLINK_TYPE_FLOAT, 0, 168, offsetof(mavlink_vector_nav_t, mag_pres_4) }, \
         { "delta_theta_0", NULL, MAVLINK_TYPE_FLOAT, 0, 172, offsetof(mavlink_vector_nav_t, delta_theta_0) }, \
         { "delta_theta_1", NULL, MAVLINK_TYPE_FLOAT, 0, 176, offsetof(mavlink_vector_nav_t, delta_theta_1) }, \
         { "delta_theta_2", NULL, MAVLINK_TYPE_FLOAT, 0, 180, offsetof(mavlink_vector_nav_t, delta_theta_2) }, \
         { "delta_theta_3", NULL, MAVLINK_TYPE_FLOAT, 0, 184, offsetof(mavlink_vector_nav_t, delta_theta_3) }, \
         { "delta_theta_4", NULL, MAVLINK_TYPE_FLOAT, 0, 188, offsetof(mavlink_vector_nav_t, delta_theta_4) }, \
         { "delta_theta_5", NULL, MAVLINK_TYPE_FLOAT, 0, 192, offsetof(mavlink_vector_nav_t, delta_theta_5) }, \
         { "delta_theta_6", NULL, MAVLINK_TYPE_FLOAT, 0, 196, offsetof(mavlink_vector_nav_t, delta_theta_6) }, \
         { "syncln_cnt", NULL, MAVLINK_TYPE_UINT32_T, 0, 200, offsetof(mavlink_vector_nav_t, syncln_cnt) }, \
         { "ins_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 204, offsetof(mavlink_vector_nav_t, ins_status) }, \
         } \
}


/**
 * @brief Pack a vector_nav message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_startup Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_gps Sample Number
 * @param time_syncln The time since the last SyncIn trigger event expressed in nano seconds.
 * @param yaw estimated yaw
 * @param pitch estimated pitch
 * @param roll estimated roll
 * @param qtn_0 The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 * @param qtn_1 The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 * @param qtn_2 The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 * @param qtn_3 The estimated attitude quaternion. Scalar value.
 * @param rate_0 The estimated angular rate measured in rad/s.
 * @param rate_1 The estimated angular rate measured in rad/s.
 * @param rate_2 The estimated angular rate measured in rad/s.
 * @param lat The estimated position
 * @param lon The estimated position
 * @param alt The estimated position
 * @param vel_0 The estimated velocity in the North East Down (NED) frame, given in m/s.
 * @param vel_1 The estimated velocity in the North East Down (NED) frame, given in m/s.
 * @param vel_2 The estimated velocity in the North East Down (NED) frame, given in m/s.
 * @param accel_0 The estimated acceleration in the body frame, given in m/s^2.
 * @param accel_1 The estimated acceleration in the body frame, given in m/s^2.
 * @param accel_2 The estimated acceleration in the body frame, given in m/s^2.
 * @param imu_0 IMU angular rate
 * @param imu_1 IMU angular rate
 * @param imu_2 IMU angular rate
 * @param imu_3 IMU acceleration measurement
 * @param imu_4 IMU acceleration measurement
 * @param imu_5 IMU acceleration measurement
 * @param mag_pres_0 The compensated magnetic, temperature, and pressure measurements from the IMU.
 * @param mag_pres_1 The compensated magnetic, temperature, and pressure measurements from the IMU.
 * @param mag_pres_2 The compensated magnetic, temperature, and pressure measurements from the IMU.
 * @param mag_pres_3 The compensated magnetic, temperature, and pressure measurements from the IMU.(temp)
 * @param mag_pres_4 The compensated magnetic, temperature, and pressure measurements from the IMU.(pressure)
 * @param delta_theta_0 delta time
 * @param delta_theta_1 delta theta
 * @param delta_theta_2 delta theta
 * @param delta_theta_3 delta thela
 * @param delta_theta_4 detla velocity
 * @param delta_theta_5 delta velocity
 * @param delta_theta_6 delta velocity
 * @param ins_status The INS status bitfield.
 * @param syncln_cnt The number of SyncIn trigger events that have occurred.
 * @param gps_pps The time since the last GPS PPS trigger event expressed in nano seconds.f
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vector_nav_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, uint64_t time_startup, uint64_t time_gps, uint64_t time_syncln, float yaw, float pitch, float roll, float qtn_0, float qtn_1, float qtn_2, float qtn_3, float rate_0, float rate_1, float rate_2, double lat, double lon, double alt, float vel_0, float vel_1, float vel_2, float accel_0, float accel_1, float accel_2, float imu_0, float imu_1, float imu_2, float imu_3, float imu_4, float imu_5, float mag_pres_0, float mag_pres_1, float mag_pres_2, float mag_pres_3, float mag_pres_4, float delta_theta_0, float delta_theta_1, float delta_theta_2, float delta_theta_3, float delta_theta_4, float delta_theta_5, float delta_theta_6, uint16_t ins_status, uint32_t syncln_cnt, uint64_t gps_pps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VECTOR_NAV_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint64_t(buf, 8, time_startup);
	_mav_put_uint64_t(buf, 16, time_gps);
	_mav_put_uint64_t(buf, 24, time_syncln);
	_mav_put_double(buf, 32, lat);
	_mav_put_double(buf, 40, lon);
	_mav_put_double(buf, 48, alt);
	_mav_put_uint64_t(buf, 56, gps_pps);
	_mav_put_float(buf, 64, yaw);
	_mav_put_float(buf, 68, pitch);
	_mav_put_float(buf, 72, roll);
	_mav_put_float(buf, 76, qtn_0);
	_mav_put_float(buf, 80, qtn_1);
	_mav_put_float(buf, 84, qtn_2);
	_mav_put_float(buf, 88, qtn_3);
	_mav_put_float(buf, 92, rate_0);
	_mav_put_float(buf, 96, rate_1);
	_mav_put_float(buf, 100, rate_2);
	_mav_put_float(buf, 104, vel_0);
	_mav_put_float(buf, 108, vel_1);
	_mav_put_float(buf, 112, vel_2);
	_mav_put_float(buf, 116, accel_0);
	_mav_put_float(buf, 120, accel_1);
	_mav_put_float(buf, 124, accel_2);
	_mav_put_float(buf, 128, imu_0);
	_mav_put_float(buf, 132, imu_1);
	_mav_put_float(buf, 136, imu_2);
	_mav_put_float(buf, 140, imu_3);
	_mav_put_float(buf, 144, imu_4);
	_mav_put_float(buf, 148, imu_5);
	_mav_put_float(buf, 152, mag_pres_0);
	_mav_put_float(buf, 156, mag_pres_1);
	_mav_put_float(buf, 160, mag_pres_2);
	_mav_put_float(buf, 164, mag_pres_3);
	_mav_put_float(buf, 168, mag_pres_4);
	_mav_put_float(buf, 172, delta_theta_0);
	_mav_put_float(buf, 176, delta_theta_1);
	_mav_put_float(buf, 180, delta_theta_2);
	_mav_put_float(buf, 184, delta_theta_3);
	_mav_put_float(buf, 188, delta_theta_4);
	_mav_put_float(buf, 192, delta_theta_5);
	_mav_put_float(buf, 196, delta_theta_6);
	_mav_put_uint32_t(buf, 200, syncln_cnt);
	_mav_put_uint16_t(buf, 204, ins_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#else
	mavlink_vector_nav_t packet;
	packet.time_usec = time_usec;
	packet.time_startup = time_startup;
	packet.time_gps = time_gps;
	packet.time_syncln = time_syncln;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.gps_pps = gps_pps;
	packet.yaw = yaw;
	packet.pitch = pitch;
	packet.roll = roll;
	packet.qtn_0 = qtn_0;
	packet.qtn_1 = qtn_1;
	packet.qtn_2 = qtn_2;
	packet.qtn_3 = qtn_3;
	packet.rate_0 = rate_0;
	packet.rate_1 = rate_1;
	packet.rate_2 = rate_2;
	packet.vel_0 = vel_0;
	packet.vel_1 = vel_1;
	packet.vel_2 = vel_2;
	packet.accel_0 = accel_0;
	packet.accel_1 = accel_1;
	packet.accel_2 = accel_2;
	packet.imu_0 = imu_0;
	packet.imu_1 = imu_1;
	packet.imu_2 = imu_2;
	packet.imu_3 = imu_3;
	packet.imu_4 = imu_4;
	packet.imu_5 = imu_5;
	packet.mag_pres_0 = mag_pres_0;
	packet.mag_pres_1 = mag_pres_1;
	packet.mag_pres_2 = mag_pres_2;
	packet.mag_pres_3 = mag_pres_3;
	packet.mag_pres_4 = mag_pres_4;
	packet.delta_theta_0 = delta_theta_0;
	packet.delta_theta_1 = delta_theta_1;
	packet.delta_theta_2 = delta_theta_2;
	packet.delta_theta_3 = delta_theta_3;
	packet.delta_theta_4 = delta_theta_4;
	packet.delta_theta_5 = delta_theta_5;
	packet.delta_theta_6 = delta_theta_6;
	packet.syncln_cnt = syncln_cnt;
	packet.ins_status = ins_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VECTOR_NAV;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VECTOR_NAV_LEN, MAVLINK_MSG_ID_VECTOR_NAV_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#endif
}

/**
 * @brief Pack a vector_nav message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_startup Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_gps Sample Number
 * @param time_syncln The time since the last SyncIn trigger event expressed in nano seconds.
 * @param yaw estimated yaw
 * @param pitch estimated pitch
 * @param roll estimated roll
 * @param qtn_0 The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 * @param qtn_1 The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 * @param qtn_2 The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 * @param qtn_3 The estimated attitude quaternion. Scalar value.
 * @param rate_0 The estimated angular rate measured in rad/s.
 * @param rate_1 The estimated angular rate measured in rad/s.
 * @param rate_2 The estimated angular rate measured in rad/s.
 * @param lat The estimated position
 * @param lon The estimated position
 * @param alt The estimated position
 * @param vel_0 The estimated velocity in the North East Down (NED) frame, given in m/s.
 * @param vel_1 The estimated velocity in the North East Down (NED) frame, given in m/s.
 * @param vel_2 The estimated velocity in the North East Down (NED) frame, given in m/s.
 * @param accel_0 The estimated acceleration in the body frame, given in m/s^2.
 * @param accel_1 The estimated acceleration in the body frame, given in m/s^2.
 * @param accel_2 The estimated acceleration in the body frame, given in m/s^2.
 * @param imu_0 IMU angular rate
 * @param imu_1 IMU angular rate
 * @param imu_2 IMU angular rate
 * @param imu_3 IMU acceleration measurement
 * @param imu_4 IMU acceleration measurement
 * @param imu_5 IMU acceleration measurement
 * @param mag_pres_0 The compensated magnetic, temperature, and pressure measurements from the IMU.
 * @param mag_pres_1 The compensated magnetic, temperature, and pressure measurements from the IMU.
 * @param mag_pres_2 The compensated magnetic, temperature, and pressure measurements from the IMU.
 * @param mag_pres_3 The compensated magnetic, temperature, and pressure measurements from the IMU.(temp)
 * @param mag_pres_4 The compensated magnetic, temperature, and pressure measurements from the IMU.(pressure)
 * @param delta_theta_0 delta time
 * @param delta_theta_1 delta theta
 * @param delta_theta_2 delta theta
 * @param delta_theta_3 delta thela
 * @param delta_theta_4 detla velocity
 * @param delta_theta_5 delta velocity
 * @param delta_theta_6 delta velocity
 * @param ins_status The INS status bitfield.
 * @param syncln_cnt The number of SyncIn trigger events that have occurred.
 * @param gps_pps The time since the last GPS PPS trigger event expressed in nano seconds.f
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vector_nav_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,uint64_t time_startup,uint64_t time_gps,uint64_t time_syncln,float yaw,float pitch,float roll,float qtn_0,float qtn_1,float qtn_2,float qtn_3,float rate_0,float rate_1,float rate_2,double lat,double lon,double alt,float vel_0,float vel_1,float vel_2,float accel_0,float accel_1,float accel_2,float imu_0,float imu_1,float imu_2,float imu_3,float imu_4,float imu_5,float mag_pres_0,float mag_pres_1,float mag_pres_2,float mag_pres_3,float mag_pres_4,float delta_theta_0,float delta_theta_1,float delta_theta_2,float delta_theta_3,float delta_theta_4,float delta_theta_5,float delta_theta_6,uint16_t ins_status,uint32_t syncln_cnt,uint64_t gps_pps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VECTOR_NAV_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint64_t(buf, 8, time_startup);
	_mav_put_uint64_t(buf, 16, time_gps);
	_mav_put_uint64_t(buf, 24, time_syncln);
	_mav_put_double(buf, 32, lat);
	_mav_put_double(buf, 40, lon);
	_mav_put_double(buf, 48, alt);
	_mav_put_uint64_t(buf, 56, gps_pps);
	_mav_put_float(buf, 64, yaw);
	_mav_put_float(buf, 68, pitch);
	_mav_put_float(buf, 72, roll);
	_mav_put_float(buf, 76, qtn_0);
	_mav_put_float(buf, 80, qtn_1);
	_mav_put_float(buf, 84, qtn_2);
	_mav_put_float(buf, 88, qtn_3);
	_mav_put_float(buf, 92, rate_0);
	_mav_put_float(buf, 96, rate_1);
	_mav_put_float(buf, 100, rate_2);
	_mav_put_float(buf, 104, vel_0);
	_mav_put_float(buf, 108, vel_1);
	_mav_put_float(buf, 112, vel_2);
	_mav_put_float(buf, 116, accel_0);
	_mav_put_float(buf, 120, accel_1);
	_mav_put_float(buf, 124, accel_2);
	_mav_put_float(buf, 128, imu_0);
	_mav_put_float(buf, 132, imu_1);
	_mav_put_float(buf, 136, imu_2);
	_mav_put_float(buf, 140, imu_3);
	_mav_put_float(buf, 144, imu_4);
	_mav_put_float(buf, 148, imu_5);
	_mav_put_float(buf, 152, mag_pres_0);
	_mav_put_float(buf, 156, mag_pres_1);
	_mav_put_float(buf, 160, mag_pres_2);
	_mav_put_float(buf, 164, mag_pres_3);
	_mav_put_float(buf, 168, mag_pres_4);
	_mav_put_float(buf, 172, delta_theta_0);
	_mav_put_float(buf, 176, delta_theta_1);
	_mav_put_float(buf, 180, delta_theta_2);
	_mav_put_float(buf, 184, delta_theta_3);
	_mav_put_float(buf, 188, delta_theta_4);
	_mav_put_float(buf, 192, delta_theta_5);
	_mav_put_float(buf, 196, delta_theta_6);
	_mav_put_uint32_t(buf, 200, syncln_cnt);
	_mav_put_uint16_t(buf, 204, ins_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#else
	mavlink_vector_nav_t packet;
	packet.time_usec = time_usec;
	packet.time_startup = time_startup;
	packet.time_gps = time_gps;
	packet.time_syncln = time_syncln;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.gps_pps = gps_pps;
	packet.yaw = yaw;
	packet.pitch = pitch;
	packet.roll = roll;
	packet.qtn_0 = qtn_0;
	packet.qtn_1 = qtn_1;
	packet.qtn_2 = qtn_2;
	packet.qtn_3 = qtn_3;
	packet.rate_0 = rate_0;
	packet.rate_1 = rate_1;
	packet.rate_2 = rate_2;
	packet.vel_0 = vel_0;
	packet.vel_1 = vel_1;
	packet.vel_2 = vel_2;
	packet.accel_0 = accel_0;
	packet.accel_1 = accel_1;
	packet.accel_2 = accel_2;
	packet.imu_0 = imu_0;
	packet.imu_1 = imu_1;
	packet.imu_2 = imu_2;
	packet.imu_3 = imu_3;
	packet.imu_4 = imu_4;
	packet.imu_5 = imu_5;
	packet.mag_pres_0 = mag_pres_0;
	packet.mag_pres_1 = mag_pres_1;
	packet.mag_pres_2 = mag_pres_2;
	packet.mag_pres_3 = mag_pres_3;
	packet.mag_pres_4 = mag_pres_4;
	packet.delta_theta_0 = delta_theta_0;
	packet.delta_theta_1 = delta_theta_1;
	packet.delta_theta_2 = delta_theta_2;
	packet.delta_theta_3 = delta_theta_3;
	packet.delta_theta_4 = delta_theta_4;
	packet.delta_theta_5 = delta_theta_5;
	packet.delta_theta_6 = delta_theta_6;
	packet.syncln_cnt = syncln_cnt;
	packet.ins_status = ins_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_VECTOR_NAV;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VECTOR_NAV_LEN, MAVLINK_MSG_ID_VECTOR_NAV_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#endif
}

/**
 * @brief Encode a vector_nav struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vector_nav C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vector_nav_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vector_nav_t* vector_nav)
{
	return mavlink_msg_vector_nav_pack(system_id, component_id, msg, vector_nav->time_usec, vector_nav->time_startup, vector_nav->time_gps, vector_nav->time_syncln, vector_nav->yaw, vector_nav->pitch, vector_nav->roll, vector_nav->qtn_0, vector_nav->qtn_1, vector_nav->qtn_2, vector_nav->qtn_3, vector_nav->rate_0, vector_nav->rate_1, vector_nav->rate_2, vector_nav->lat, vector_nav->lon, vector_nav->alt, vector_nav->vel_0, vector_nav->vel_1, vector_nav->vel_2, vector_nav->accel_0, vector_nav->accel_1, vector_nav->accel_2, vector_nav->imu_0, vector_nav->imu_1, vector_nav->imu_2, vector_nav->imu_3, vector_nav->imu_4, vector_nav->imu_5, vector_nav->mag_pres_0, vector_nav->mag_pres_1, vector_nav->mag_pres_2, vector_nav->mag_pres_3, vector_nav->mag_pres_4, vector_nav->delta_theta_0, vector_nav->delta_theta_1, vector_nav->delta_theta_2, vector_nav->delta_theta_3, vector_nav->delta_theta_4, vector_nav->delta_theta_5, vector_nav->delta_theta_6, vector_nav->ins_status, vector_nav->syncln_cnt, vector_nav->gps_pps);
}

/**
 * @brief Encode a vector_nav struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vector_nav C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vector_nav_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vector_nav_t* vector_nav)
{
	return mavlink_msg_vector_nav_pack_chan(system_id, component_id, chan, msg, vector_nav->time_usec, vector_nav->time_startup, vector_nav->time_gps, vector_nav->time_syncln, vector_nav->yaw, vector_nav->pitch, vector_nav->roll, vector_nav->qtn_0, vector_nav->qtn_1, vector_nav->qtn_2, vector_nav->qtn_3, vector_nav->rate_0, vector_nav->rate_1, vector_nav->rate_2, vector_nav->lat, vector_nav->lon, vector_nav->alt, vector_nav->vel_0, vector_nav->vel_1, vector_nav->vel_2, vector_nav->accel_0, vector_nav->accel_1, vector_nav->accel_2, vector_nav->imu_0, vector_nav->imu_1, vector_nav->imu_2, vector_nav->imu_3, vector_nav->imu_4, vector_nav->imu_5, vector_nav->mag_pres_0, vector_nav->mag_pres_1, vector_nav->mag_pres_2, vector_nav->mag_pres_3, vector_nav->mag_pres_4, vector_nav->delta_theta_0, vector_nav->delta_theta_1, vector_nav->delta_theta_2, vector_nav->delta_theta_3, vector_nav->delta_theta_4, vector_nav->delta_theta_5, vector_nav->delta_theta_6, vector_nav->ins_status, vector_nav->syncln_cnt, vector_nav->gps_pps);
}

/**
 * @brief Send a vector_nav message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_startup Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_gps Sample Number
 * @param time_syncln The time since the last SyncIn trigger event expressed in nano seconds.
 * @param yaw estimated yaw
 * @param pitch estimated pitch
 * @param roll estimated roll
 * @param qtn_0 The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 * @param qtn_1 The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 * @param qtn_2 The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 * @param qtn_3 The estimated attitude quaternion. Scalar value.
 * @param rate_0 The estimated angular rate measured in rad/s.
 * @param rate_1 The estimated angular rate measured in rad/s.
 * @param rate_2 The estimated angular rate measured in rad/s.
 * @param lat The estimated position
 * @param lon The estimated position
 * @param alt The estimated position
 * @param vel_0 The estimated velocity in the North East Down (NED) frame, given in m/s.
 * @param vel_1 The estimated velocity in the North East Down (NED) frame, given in m/s.
 * @param vel_2 The estimated velocity in the North East Down (NED) frame, given in m/s.
 * @param accel_0 The estimated acceleration in the body frame, given in m/s^2.
 * @param accel_1 The estimated acceleration in the body frame, given in m/s^2.
 * @param accel_2 The estimated acceleration in the body frame, given in m/s^2.
 * @param imu_0 IMU angular rate
 * @param imu_1 IMU angular rate
 * @param imu_2 IMU angular rate
 * @param imu_3 IMU acceleration measurement
 * @param imu_4 IMU acceleration measurement
 * @param imu_5 IMU acceleration measurement
 * @param mag_pres_0 The compensated magnetic, temperature, and pressure measurements from the IMU.
 * @param mag_pres_1 The compensated magnetic, temperature, and pressure measurements from the IMU.
 * @param mag_pres_2 The compensated magnetic, temperature, and pressure measurements from the IMU.
 * @param mag_pres_3 The compensated magnetic, temperature, and pressure measurements from the IMU.(temp)
 * @param mag_pres_4 The compensated magnetic, temperature, and pressure measurements from the IMU.(pressure)
 * @param delta_theta_0 delta time
 * @param delta_theta_1 delta theta
 * @param delta_theta_2 delta theta
 * @param delta_theta_3 delta thela
 * @param delta_theta_4 detla velocity
 * @param delta_theta_5 delta velocity
 * @param delta_theta_6 delta velocity
 * @param ins_status The INS status bitfield.
 * @param syncln_cnt The number of SyncIn trigger events that have occurred.
 * @param gps_pps The time since the last GPS PPS trigger event expressed in nano seconds.f
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vector_nav_send(mavlink_channel_t chan, uint64_t time_usec, uint64_t time_startup, uint64_t time_gps, uint64_t time_syncln, float yaw, float pitch, float roll, float qtn_0, float qtn_1, float qtn_2, float qtn_3, float rate_0, float rate_1, float rate_2, double lat, double lon, double alt, float vel_0, float vel_1, float vel_2, float accel_0, float accel_1, float accel_2, float imu_0, float imu_1, float imu_2, float imu_3, float imu_4, float imu_5, float mag_pres_0, float mag_pres_1, float mag_pres_2, float mag_pres_3, float mag_pres_4, float delta_theta_0, float delta_theta_1, float delta_theta_2, float delta_theta_3, float delta_theta_4, float delta_theta_5, float delta_theta_6, uint16_t ins_status, uint32_t syncln_cnt, uint64_t gps_pps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VECTOR_NAV_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint64_t(buf, 8, time_startup);
	_mav_put_uint64_t(buf, 16, time_gps);
	_mav_put_uint64_t(buf, 24, time_syncln);
	_mav_put_double(buf, 32, lat);
	_mav_put_double(buf, 40, lon);
	_mav_put_double(buf, 48, alt);
	_mav_put_uint64_t(buf, 56, gps_pps);
	_mav_put_float(buf, 64, yaw);
	_mav_put_float(buf, 68, pitch);
	_mav_put_float(buf, 72, roll);
	_mav_put_float(buf, 76, qtn_0);
	_mav_put_float(buf, 80, qtn_1);
	_mav_put_float(buf, 84, qtn_2);
	_mav_put_float(buf, 88, qtn_3);
	_mav_put_float(buf, 92, rate_0);
	_mav_put_float(buf, 96, rate_1);
	_mav_put_float(buf, 100, rate_2);
	_mav_put_float(buf, 104, vel_0);
	_mav_put_float(buf, 108, vel_1);
	_mav_put_float(buf, 112, vel_2);
	_mav_put_float(buf, 116, accel_0);
	_mav_put_float(buf, 120, accel_1);
	_mav_put_float(buf, 124, accel_2);
	_mav_put_float(buf, 128, imu_0);
	_mav_put_float(buf, 132, imu_1);
	_mav_put_float(buf, 136, imu_2);
	_mav_put_float(buf, 140, imu_3);
	_mav_put_float(buf, 144, imu_4);
	_mav_put_float(buf, 148, imu_5);
	_mav_put_float(buf, 152, mag_pres_0);
	_mav_put_float(buf, 156, mag_pres_1);
	_mav_put_float(buf, 160, mag_pres_2);
	_mav_put_float(buf, 164, mag_pres_3);
	_mav_put_float(buf, 168, mag_pres_4);
	_mav_put_float(buf, 172, delta_theta_0);
	_mav_put_float(buf, 176, delta_theta_1);
	_mav_put_float(buf, 180, delta_theta_2);
	_mav_put_float(buf, 184, delta_theta_3);
	_mav_put_float(buf, 188, delta_theta_4);
	_mav_put_float(buf, 192, delta_theta_5);
	_mav_put_float(buf, 196, delta_theta_6);
	_mav_put_uint32_t(buf, 200, syncln_cnt);
	_mav_put_uint16_t(buf, 204, ins_status);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VECTOR_NAV, buf, MAVLINK_MSG_ID_VECTOR_NAV_LEN, MAVLINK_MSG_ID_VECTOR_NAV_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VECTOR_NAV, buf, MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#endif
#else
	mavlink_vector_nav_t packet;
	packet.time_usec = time_usec;
	packet.time_startup = time_startup;
	packet.time_gps = time_gps;
	packet.time_syncln = time_syncln;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.gps_pps = gps_pps;
	packet.yaw = yaw;
	packet.pitch = pitch;
	packet.roll = roll;
	packet.qtn_0 = qtn_0;
	packet.qtn_1 = qtn_1;
	packet.qtn_2 = qtn_2;
	packet.qtn_3 = qtn_3;
	packet.rate_0 = rate_0;
	packet.rate_1 = rate_1;
	packet.rate_2 = rate_2;
	packet.vel_0 = vel_0;
	packet.vel_1 = vel_1;
	packet.vel_2 = vel_2;
	packet.accel_0 = accel_0;
	packet.accel_1 = accel_1;
	packet.accel_2 = accel_2;
	packet.imu_0 = imu_0;
	packet.imu_1 = imu_1;
	packet.imu_2 = imu_2;
	packet.imu_3 = imu_3;
	packet.imu_4 = imu_4;
	packet.imu_5 = imu_5;
	packet.mag_pres_0 = mag_pres_0;
	packet.mag_pres_1 = mag_pres_1;
	packet.mag_pres_2 = mag_pres_2;
	packet.mag_pres_3 = mag_pres_3;
	packet.mag_pres_4 = mag_pres_4;
	packet.delta_theta_0 = delta_theta_0;
	packet.delta_theta_1 = delta_theta_1;
	packet.delta_theta_2 = delta_theta_2;
	packet.delta_theta_3 = delta_theta_3;
	packet.delta_theta_4 = delta_theta_4;
	packet.delta_theta_5 = delta_theta_5;
	packet.delta_theta_6 = delta_theta_6;
	packet.syncln_cnt = syncln_cnt;
	packet.ins_status = ins_status;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VECTOR_NAV, (const char *)&packet, MAVLINK_MSG_ID_VECTOR_NAV_LEN, MAVLINK_MSG_ID_VECTOR_NAV_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VECTOR_NAV, (const char *)&packet, MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_VECTOR_NAV_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vector_nav_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint64_t time_startup, uint64_t time_gps, uint64_t time_syncln, float yaw, float pitch, float roll, float qtn_0, float qtn_1, float qtn_2, float qtn_3, float rate_0, float rate_1, float rate_2, double lat, double lon, double alt, float vel_0, float vel_1, float vel_2, float accel_0, float accel_1, float accel_2, float imu_0, float imu_1, float imu_2, float imu_3, float imu_4, float imu_5, float mag_pres_0, float mag_pres_1, float mag_pres_2, float mag_pres_3, float mag_pres_4, float delta_theta_0, float delta_theta_1, float delta_theta_2, float delta_theta_3, float delta_theta_4, float delta_theta_5, float delta_theta_6, uint16_t ins_status, uint32_t syncln_cnt, uint64_t gps_pps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint64_t(buf, 8, time_startup);
	_mav_put_uint64_t(buf, 16, time_gps);
	_mav_put_uint64_t(buf, 24, time_syncln);
	_mav_put_double(buf, 32, lat);
	_mav_put_double(buf, 40, lon);
	_mav_put_double(buf, 48, alt);
	_mav_put_uint64_t(buf, 56, gps_pps);
	_mav_put_float(buf, 64, yaw);
	_mav_put_float(buf, 68, pitch);
	_mav_put_float(buf, 72, roll);
	_mav_put_float(buf, 76, qtn_0);
	_mav_put_float(buf, 80, qtn_1);
	_mav_put_float(buf, 84, qtn_2);
	_mav_put_float(buf, 88, qtn_3);
	_mav_put_float(buf, 92, rate_0);
	_mav_put_float(buf, 96, rate_1);
	_mav_put_float(buf, 100, rate_2);
	_mav_put_float(buf, 104, vel_0);
	_mav_put_float(buf, 108, vel_1);
	_mav_put_float(buf, 112, vel_2);
	_mav_put_float(buf, 116, accel_0);
	_mav_put_float(buf, 120, accel_1);
	_mav_put_float(buf, 124, accel_2);
	_mav_put_float(buf, 128, imu_0);
	_mav_put_float(buf, 132, imu_1);
	_mav_put_float(buf, 136, imu_2);
	_mav_put_float(buf, 140, imu_3);
	_mav_put_float(buf, 144, imu_4);
	_mav_put_float(buf, 148, imu_5);
	_mav_put_float(buf, 152, mag_pres_0);
	_mav_put_float(buf, 156, mag_pres_1);
	_mav_put_float(buf, 160, mag_pres_2);
	_mav_put_float(buf, 164, mag_pres_3);
	_mav_put_float(buf, 168, mag_pres_4);
	_mav_put_float(buf, 172, delta_theta_0);
	_mav_put_float(buf, 176, delta_theta_1);
	_mav_put_float(buf, 180, delta_theta_2);
	_mav_put_float(buf, 184, delta_theta_3);
	_mav_put_float(buf, 188, delta_theta_4);
	_mav_put_float(buf, 192, delta_theta_5);
	_mav_put_float(buf, 196, delta_theta_6);
	_mav_put_uint32_t(buf, 200, syncln_cnt);
	_mav_put_uint16_t(buf, 204, ins_status);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VECTOR_NAV, buf, MAVLINK_MSG_ID_VECTOR_NAV_LEN, MAVLINK_MSG_ID_VECTOR_NAV_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VECTOR_NAV, buf, MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#endif
#else
	mavlink_vector_nav_t *packet = (mavlink_vector_nav_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->time_startup = time_startup;
	packet->time_gps = time_gps;
	packet->time_syncln = time_syncln;
	packet->lat = lat;
	packet->lon = lon;
	packet->alt = alt;
	packet->gps_pps = gps_pps;
	packet->yaw = yaw;
	packet->pitch = pitch;
	packet->roll = roll;
	packet->qtn_0 = qtn_0;
	packet->qtn_1 = qtn_1;
	packet->qtn_2 = qtn_2;
	packet->qtn_3 = qtn_3;
	packet->rate_0 = rate_0;
	packet->rate_1 = rate_1;
	packet->rate_2 = rate_2;
	packet->vel_0 = vel_0;
	packet->vel_1 = vel_1;
	packet->vel_2 = vel_2;
	packet->accel_0 = accel_0;
	packet->accel_1 = accel_1;
	packet->accel_2 = accel_2;
	packet->imu_0 = imu_0;
	packet->imu_1 = imu_1;
	packet->imu_2 = imu_2;
	packet->imu_3 = imu_3;
	packet->imu_4 = imu_4;
	packet->imu_5 = imu_5;
	packet->mag_pres_0 = mag_pres_0;
	packet->mag_pres_1 = mag_pres_1;
	packet->mag_pres_2 = mag_pres_2;
	packet->mag_pres_3 = mag_pres_3;
	packet->mag_pres_4 = mag_pres_4;
	packet->delta_theta_0 = delta_theta_0;
	packet->delta_theta_1 = delta_theta_1;
	packet->delta_theta_2 = delta_theta_2;
	packet->delta_theta_3 = delta_theta_3;
	packet->delta_theta_4 = delta_theta_4;
	packet->delta_theta_5 = delta_theta_5;
	packet->delta_theta_6 = delta_theta_6;
	packet->syncln_cnt = syncln_cnt;
	packet->ins_status = ins_status;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VECTOR_NAV, (const char *)packet, MAVLINK_MSG_ID_VECTOR_NAV_LEN, MAVLINK_MSG_ID_VECTOR_NAV_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VECTOR_NAV, (const char *)packet, MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE VECTOR_NAV UNPACKING


/**
 * @brief Get field time_usec from vector_nav message
 *
 * @return Image timestamp (microseconds since UNIX epoch, according to camera clock)
 */
static inline uint64_t mavlink_msg_vector_nav_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field time_startup from vector_nav message
 *
 * @return Image timestamp (microseconds since UNIX epoch, according to camera clock)
 */
static inline uint64_t mavlink_msg_vector_nav_get_time_startup(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field time_gps from vector_nav message
 *
 * @return Sample Number
 */
static inline uint64_t mavlink_msg_vector_nav_get_time_gps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  16);
}

/**
 * @brief Get field time_syncln from vector_nav message
 *
 * @return The time since the last SyncIn trigger event expressed in nano seconds.
 */
static inline uint64_t mavlink_msg_vector_nav_get_time_syncln(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  24);
}

/**
 * @brief Get field yaw from vector_nav message
 *
 * @return estimated yaw
 */
static inline float mavlink_msg_vector_nav_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field pitch from vector_nav message
 *
 * @return estimated pitch
 */
static inline float mavlink_msg_vector_nav_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field roll from vector_nav message
 *
 * @return estimated roll
 */
static inline float mavlink_msg_vector_nav_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field qtn_0 from vector_nav message
 *
 * @return The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 */
static inline float mavlink_msg_vector_nav_get_qtn_0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field qtn_1 from vector_nav message
 *
 * @return The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 */
static inline float mavlink_msg_vector_nav_get_qtn_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field qtn_2 from vector_nav message
 *
 * @return The estimated attitude quaternion. respect to the local North East Down (NED) frame.
 */
static inline float mavlink_msg_vector_nav_get_qtn_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  84);
}

/**
 * @brief Get field qtn_3 from vector_nav message
 *
 * @return The estimated attitude quaternion. Scalar value.
 */
static inline float mavlink_msg_vector_nav_get_qtn_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  88);
}

/**
 * @brief Get field rate_0 from vector_nav message
 *
 * @return The estimated angular rate measured in rad/s.
 */
static inline float mavlink_msg_vector_nav_get_rate_0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  92);
}

/**
 * @brief Get field rate_1 from vector_nav message
 *
 * @return The estimated angular rate measured in rad/s.
 */
static inline float mavlink_msg_vector_nav_get_rate_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  96);
}

/**
 * @brief Get field rate_2 from vector_nav message
 *
 * @return The estimated angular rate measured in rad/s.
 */
static inline float mavlink_msg_vector_nav_get_rate_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  100);
}

/**
 * @brief Get field lat from vector_nav message
 *
 * @return The estimated position
 */
static inline double mavlink_msg_vector_nav_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  32);
}

/**
 * @brief Get field lon from vector_nav message
 *
 * @return The estimated position
 */
static inline double mavlink_msg_vector_nav_get_lon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  40);
}

/**
 * @brief Get field alt from vector_nav message
 *
 * @return The estimated position
 */
static inline double mavlink_msg_vector_nav_get_alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_double(msg,  48);
}

/**
 * @brief Get field vel_0 from vector_nav message
 *
 * @return The estimated velocity in the North East Down (NED) frame, given in m/s.
 */
static inline float mavlink_msg_vector_nav_get_vel_0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  104);
}

/**
 * @brief Get field vel_1 from vector_nav message
 *
 * @return The estimated velocity in the North East Down (NED) frame, given in m/s.
 */
static inline float mavlink_msg_vector_nav_get_vel_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  108);
}

/**
 * @brief Get field vel_2 from vector_nav message
 *
 * @return The estimated velocity in the North East Down (NED) frame, given in m/s.
 */
static inline float mavlink_msg_vector_nav_get_vel_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  112);
}

/**
 * @brief Get field accel_0 from vector_nav message
 *
 * @return The estimated acceleration in the body frame, given in m/s^2.
 */
static inline float mavlink_msg_vector_nav_get_accel_0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  116);
}

/**
 * @brief Get field accel_1 from vector_nav message
 *
 * @return The estimated acceleration in the body frame, given in m/s^2.
 */
static inline float mavlink_msg_vector_nav_get_accel_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  120);
}

/**
 * @brief Get field accel_2 from vector_nav message
 *
 * @return The estimated acceleration in the body frame, given in m/s^2.
 */
static inline float mavlink_msg_vector_nav_get_accel_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  124);
}

/**
 * @brief Get field imu_0 from vector_nav message
 *
 * @return IMU angular rate
 */
static inline float mavlink_msg_vector_nav_get_imu_0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  128);
}

/**
 * @brief Get field imu_1 from vector_nav message
 *
 * @return IMU angular rate
 */
static inline float mavlink_msg_vector_nav_get_imu_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  132);
}

/**
 * @brief Get field imu_2 from vector_nav message
 *
 * @return IMU angular rate
 */
static inline float mavlink_msg_vector_nav_get_imu_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  136);
}

/**
 * @brief Get field imu_3 from vector_nav message
 *
 * @return IMU acceleration measurement
 */
static inline float mavlink_msg_vector_nav_get_imu_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  140);
}

/**
 * @brief Get field imu_4 from vector_nav message
 *
 * @return IMU acceleration measurement
 */
static inline float mavlink_msg_vector_nav_get_imu_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  144);
}

/**
 * @brief Get field imu_5 from vector_nav message
 *
 * @return IMU acceleration measurement
 */
static inline float mavlink_msg_vector_nav_get_imu_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  148);
}

/**
 * @brief Get field mag_pres_0 from vector_nav message
 *
 * @return The compensated magnetic, temperature, and pressure measurements from the IMU.
 */
static inline float mavlink_msg_vector_nav_get_mag_pres_0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  152);
}

/**
 * @brief Get field mag_pres_1 from vector_nav message
 *
 * @return The compensated magnetic, temperature, and pressure measurements from the IMU.
 */
static inline float mavlink_msg_vector_nav_get_mag_pres_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  156);
}

/**
 * @brief Get field mag_pres_2 from vector_nav message
 *
 * @return The compensated magnetic, temperature, and pressure measurements from the IMU.
 */
static inline float mavlink_msg_vector_nav_get_mag_pres_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  160);
}

/**
 * @brief Get field mag_pres_3 from vector_nav message
 *
 * @return The compensated magnetic, temperature, and pressure measurements from the IMU.(temp)
 */
static inline float mavlink_msg_vector_nav_get_mag_pres_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  164);
}

/**
 * @brief Get field mag_pres_4 from vector_nav message
 *
 * @return The compensated magnetic, temperature, and pressure measurements from the IMU.(pressure)
 */
static inline float mavlink_msg_vector_nav_get_mag_pres_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  168);
}

/**
 * @brief Get field delta_theta_0 from vector_nav message
 *
 * @return delta time
 */
static inline float mavlink_msg_vector_nav_get_delta_theta_0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  172);
}

/**
 * @brief Get field delta_theta_1 from vector_nav message
 *
 * @return delta theta
 */
static inline float mavlink_msg_vector_nav_get_delta_theta_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  176);
}

/**
 * @brief Get field delta_theta_2 from vector_nav message
 *
 * @return delta theta
 */
static inline float mavlink_msg_vector_nav_get_delta_theta_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  180);
}

/**
 * @brief Get field delta_theta_3 from vector_nav message
 *
 * @return delta thela
 */
static inline float mavlink_msg_vector_nav_get_delta_theta_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  184);
}

/**
 * @brief Get field delta_theta_4 from vector_nav message
 *
 * @return detla velocity
 */
static inline float mavlink_msg_vector_nav_get_delta_theta_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  188);
}

/**
 * @brief Get field delta_theta_5 from vector_nav message
 *
 * @return delta velocity
 */
static inline float mavlink_msg_vector_nav_get_delta_theta_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  192);
}

/**
 * @brief Get field delta_theta_6 from vector_nav message
 *
 * @return delta velocity
 */
static inline float mavlink_msg_vector_nav_get_delta_theta_6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  196);
}

/**
 * @brief Get field ins_status from vector_nav message
 *
 * @return The INS status bitfield.
 */
static inline uint16_t mavlink_msg_vector_nav_get_ins_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  204);
}

/**
 * @brief Get field syncln_cnt from vector_nav message
 *
 * @return The number of SyncIn trigger events that have occurred.
 */
static inline uint32_t mavlink_msg_vector_nav_get_syncln_cnt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  200);
}

/**
 * @brief Get field gps_pps from vector_nav message
 *
 * @return The time since the last GPS PPS trigger event expressed in nano seconds.f
 */
static inline uint64_t mavlink_msg_vector_nav_get_gps_pps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  56);
}

/**
 * @brief Decode a vector_nav message into a struct
 *
 * @param msg The message to decode
 * @param vector_nav C-struct to decode the message contents into
 */
static inline void mavlink_msg_vector_nav_decode(const mavlink_message_t* msg, mavlink_vector_nav_t* vector_nav)
{
#if MAVLINK_NEED_BYTE_SWAP
	vector_nav->time_usec = mavlink_msg_vector_nav_get_time_usec(msg);
	vector_nav->time_startup = mavlink_msg_vector_nav_get_time_startup(msg);
	vector_nav->time_gps = mavlink_msg_vector_nav_get_time_gps(msg);
	vector_nav->time_syncln = mavlink_msg_vector_nav_get_time_syncln(msg);
	vector_nav->lat = mavlink_msg_vector_nav_get_lat(msg);
	vector_nav->lon = mavlink_msg_vector_nav_get_lon(msg);
	vector_nav->alt = mavlink_msg_vector_nav_get_alt(msg);
	vector_nav->gps_pps = mavlink_msg_vector_nav_get_gps_pps(msg);
	vector_nav->yaw = mavlink_msg_vector_nav_get_yaw(msg);
	vector_nav->pitch = mavlink_msg_vector_nav_get_pitch(msg);
	vector_nav->roll = mavlink_msg_vector_nav_get_roll(msg);
	vector_nav->qtn_0 = mavlink_msg_vector_nav_get_qtn_0(msg);
	vector_nav->qtn_1 = mavlink_msg_vector_nav_get_qtn_1(msg);
	vector_nav->qtn_2 = mavlink_msg_vector_nav_get_qtn_2(msg);
	vector_nav->qtn_3 = mavlink_msg_vector_nav_get_qtn_3(msg);
	vector_nav->rate_0 = mavlink_msg_vector_nav_get_rate_0(msg);
	vector_nav->rate_1 = mavlink_msg_vector_nav_get_rate_1(msg);
	vector_nav->rate_2 = mavlink_msg_vector_nav_get_rate_2(msg);
	vector_nav->vel_0 = mavlink_msg_vector_nav_get_vel_0(msg);
	vector_nav->vel_1 = mavlink_msg_vector_nav_get_vel_1(msg);
	vector_nav->vel_2 = mavlink_msg_vector_nav_get_vel_2(msg);
	vector_nav->accel_0 = mavlink_msg_vector_nav_get_accel_0(msg);
	vector_nav->accel_1 = mavlink_msg_vector_nav_get_accel_1(msg);
	vector_nav->accel_2 = mavlink_msg_vector_nav_get_accel_2(msg);
	vector_nav->imu_0 = mavlink_msg_vector_nav_get_imu_0(msg);
	vector_nav->imu_1 = mavlink_msg_vector_nav_get_imu_1(msg);
	vector_nav->imu_2 = mavlink_msg_vector_nav_get_imu_2(msg);
	vector_nav->imu_3 = mavlink_msg_vector_nav_get_imu_3(msg);
	vector_nav->imu_4 = mavlink_msg_vector_nav_get_imu_4(msg);
	vector_nav->imu_5 = mavlink_msg_vector_nav_get_imu_5(msg);
	vector_nav->mag_pres_0 = mavlink_msg_vector_nav_get_mag_pres_0(msg);
	vector_nav->mag_pres_1 = mavlink_msg_vector_nav_get_mag_pres_1(msg);
	vector_nav->mag_pres_2 = mavlink_msg_vector_nav_get_mag_pres_2(msg);
	vector_nav->mag_pres_3 = mavlink_msg_vector_nav_get_mag_pres_3(msg);
	vector_nav->mag_pres_4 = mavlink_msg_vector_nav_get_mag_pres_4(msg);
	vector_nav->delta_theta_0 = mavlink_msg_vector_nav_get_delta_theta_0(msg);
	vector_nav->delta_theta_1 = mavlink_msg_vector_nav_get_delta_theta_1(msg);
	vector_nav->delta_theta_2 = mavlink_msg_vector_nav_get_delta_theta_2(msg);
	vector_nav->delta_theta_3 = mavlink_msg_vector_nav_get_delta_theta_3(msg);
	vector_nav->delta_theta_4 = mavlink_msg_vector_nav_get_delta_theta_4(msg);
	vector_nav->delta_theta_5 = mavlink_msg_vector_nav_get_delta_theta_5(msg);
	vector_nav->delta_theta_6 = mavlink_msg_vector_nav_get_delta_theta_6(msg);
	vector_nav->syncln_cnt = mavlink_msg_vector_nav_get_syncln_cnt(msg);
	vector_nav->ins_status = mavlink_msg_vector_nav_get_ins_status(msg);
#else
	memcpy(vector_nav, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_VECTOR_NAV_LEN);
#endif
}
