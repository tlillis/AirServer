// MESSAGE NCAR_PTH PACKING

#define MAVLINK_MSG_ID_NCAR_PTH 240

typedef struct __mavlink_ncar_pth_t
{
 uint64_t time_usec; ///< Image timestamp (microseconds since UNIX epoch, according to camera clock)
 float pressure; ///< Pressure
 float external_temp; ///< External Temperature
 float rh1; ///< RH1
 float rh2; ///< RH2
 float internal_temp; ///< Internal Temperature
 uint8_t sample_num; ///< Sample Number
} mavlink_ncar_pth_t;

#define MAVLINK_MSG_ID_NCAR_PTH_LEN 29
#define MAVLINK_MSG_ID_240_LEN 29

#define MAVLINK_MSG_ID_NCAR_PTH_CRC 114
#define MAVLINK_MSG_ID_240_CRC 114



#define MAVLINK_MESSAGE_INFO_NCAR_PTH { \
	"NCAR_PTH", \
	7, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ncar_pth_t, time_usec) }, \
         { "pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_ncar_pth_t, pressure) }, \
         { "external_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_ncar_pth_t, external_temp) }, \
         { "rh1", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_ncar_pth_t, rh1) }, \
         { "rh2", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ncar_pth_t, rh2) }, \
         { "internal_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_ncar_pth_t, internal_temp) }, \
         { "sample_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_ncar_pth_t, sample_num) }, \
         } \
}


/**
 * @brief Pack a ncar_pth message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param sample_num Sample Number
 * @param pressure Pressure
 * @param external_temp External Temperature
 * @param rh1 RH1
 * @param rh2 RH2
 * @param internal_temp Internal Temperature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ncar_pth_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, uint8_t sample_num, float pressure, float external_temp, float rh1, float rh2, float internal_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_NCAR_PTH_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, pressure);
	_mav_put_float(buf, 12, external_temp);
	_mav_put_float(buf, 16, rh1);
	_mav_put_float(buf, 20, rh2);
	_mav_put_float(buf, 24, internal_temp);
	_mav_put_uint8_t(buf, 28, sample_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NCAR_PTH_LEN);
#else
	mavlink_ncar_pth_t packet;
	packet.time_usec = time_usec;
	packet.pressure = pressure;
	packet.external_temp = external_temp;
	packet.rh1 = rh1;
	packet.rh2 = rh2;
	packet.internal_temp = internal_temp;
	packet.sample_num = sample_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NCAR_PTH_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_NCAR_PTH;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NCAR_PTH_LEN, MAVLINK_MSG_ID_NCAR_PTH_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NCAR_PTH_LEN);
#endif
}

/**
 * @brief Pack a ncar_pth message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param sample_num Sample Number
 * @param pressure Pressure
 * @param external_temp External Temperature
 * @param rh1 RH1
 * @param rh2 RH2
 * @param internal_temp Internal Temperature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ncar_pth_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,uint8_t sample_num,float pressure,float external_temp,float rh1,float rh2,float internal_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_NCAR_PTH_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, pressure);
	_mav_put_float(buf, 12, external_temp);
	_mav_put_float(buf, 16, rh1);
	_mav_put_float(buf, 20, rh2);
	_mav_put_float(buf, 24, internal_temp);
	_mav_put_uint8_t(buf, 28, sample_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NCAR_PTH_LEN);
#else
	mavlink_ncar_pth_t packet;
	packet.time_usec = time_usec;
	packet.pressure = pressure;
	packet.external_temp = external_temp;
	packet.rh1 = rh1;
	packet.rh2 = rh2;
	packet.internal_temp = internal_temp;
	packet.sample_num = sample_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NCAR_PTH_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_NCAR_PTH;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_NCAR_PTH_LEN, MAVLINK_MSG_ID_NCAR_PTH_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_NCAR_PTH_LEN);
#endif
}

/**
 * @brief Encode a ncar_pth struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ncar_pth C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ncar_pth_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ncar_pth_t* ncar_pth)
{
	return mavlink_msg_ncar_pth_pack(system_id, component_id, msg, ncar_pth->time_usec, ncar_pth->sample_num, ncar_pth->pressure, ncar_pth->external_temp, ncar_pth->rh1, ncar_pth->rh2, ncar_pth->internal_temp);
}

/**
 * @brief Encode a ncar_pth struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ncar_pth C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ncar_pth_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ncar_pth_t* ncar_pth)
{
	return mavlink_msg_ncar_pth_pack_chan(system_id, component_id, chan, msg, ncar_pth->time_usec, ncar_pth->sample_num, ncar_pth->pressure, ncar_pth->external_temp, ncar_pth->rh1, ncar_pth->rh2, ncar_pth->internal_temp);
}

/**
 * @brief Send a ncar_pth message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param sample_num Sample Number
 * @param pressure Pressure
 * @param external_temp External Temperature
 * @param rh1 RH1
 * @param rh2 RH2
 * @param internal_temp Internal Temperature
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ncar_pth_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t sample_num, float pressure, float external_temp, float rh1, float rh2, float internal_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_NCAR_PTH_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, pressure);
	_mav_put_float(buf, 12, external_temp);
	_mav_put_float(buf, 16, rh1);
	_mav_put_float(buf, 20, rh2);
	_mav_put_float(buf, 24, internal_temp);
	_mav_put_uint8_t(buf, 28, sample_num);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NCAR_PTH, buf, MAVLINK_MSG_ID_NCAR_PTH_LEN, MAVLINK_MSG_ID_NCAR_PTH_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NCAR_PTH, buf, MAVLINK_MSG_ID_NCAR_PTH_LEN);
#endif
#else
	mavlink_ncar_pth_t packet;
	packet.time_usec = time_usec;
	packet.pressure = pressure;
	packet.external_temp = external_temp;
	packet.rh1 = rh1;
	packet.rh2 = rh2;
	packet.internal_temp = internal_temp;
	packet.sample_num = sample_num;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NCAR_PTH, (const char *)&packet, MAVLINK_MSG_ID_NCAR_PTH_LEN, MAVLINK_MSG_ID_NCAR_PTH_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NCAR_PTH, (const char *)&packet, MAVLINK_MSG_ID_NCAR_PTH_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_NCAR_PTH_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ncar_pth_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t sample_num, float pressure, float external_temp, float rh1, float rh2, float internal_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, pressure);
	_mav_put_float(buf, 12, external_temp);
	_mav_put_float(buf, 16, rh1);
	_mav_put_float(buf, 20, rh2);
	_mav_put_float(buf, 24, internal_temp);
	_mav_put_uint8_t(buf, 28, sample_num);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NCAR_PTH, buf, MAVLINK_MSG_ID_NCAR_PTH_LEN, MAVLINK_MSG_ID_NCAR_PTH_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NCAR_PTH, buf, MAVLINK_MSG_ID_NCAR_PTH_LEN);
#endif
#else
	mavlink_ncar_pth_t *packet = (mavlink_ncar_pth_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->pressure = pressure;
	packet->external_temp = external_temp;
	packet->rh1 = rh1;
	packet->rh2 = rh2;
	packet->internal_temp = internal_temp;
	packet->sample_num = sample_num;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NCAR_PTH, (const char *)packet, MAVLINK_MSG_ID_NCAR_PTH_LEN, MAVLINK_MSG_ID_NCAR_PTH_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NCAR_PTH, (const char *)packet, MAVLINK_MSG_ID_NCAR_PTH_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE NCAR_PTH UNPACKING


/**
 * @brief Get field time_usec from ncar_pth message
 *
 * @return Image timestamp (microseconds since UNIX epoch, according to camera clock)
 */
static inline uint64_t mavlink_msg_ncar_pth_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field sample_num from ncar_pth message
 *
 * @return Sample Number
 */
static inline uint8_t mavlink_msg_ncar_pth_get_sample_num(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field pressure from ncar_pth message
 *
 * @return Pressure
 */
static inline float mavlink_msg_ncar_pth_get_pressure(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field external_temp from ncar_pth message
 *
 * @return External Temperature
 */
static inline float mavlink_msg_ncar_pth_get_external_temp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field rh1 from ncar_pth message
 *
 * @return RH1
 */
static inline float mavlink_msg_ncar_pth_get_rh1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field rh2 from ncar_pth message
 *
 * @return RH2
 */
static inline float mavlink_msg_ncar_pth_get_rh2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field internal_temp from ncar_pth message
 *
 * @return Internal Temperature
 */
static inline float mavlink_msg_ncar_pth_get_internal_temp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a ncar_pth message into a struct
 *
 * @param msg The message to decode
 * @param ncar_pth C-struct to decode the message contents into
 */
static inline void mavlink_msg_ncar_pth_decode(const mavlink_message_t* msg, mavlink_ncar_pth_t* ncar_pth)
{
#if MAVLINK_NEED_BYTE_SWAP
	ncar_pth->time_usec = mavlink_msg_ncar_pth_get_time_usec(msg);
	ncar_pth->pressure = mavlink_msg_ncar_pth_get_pressure(msg);
	ncar_pth->external_temp = mavlink_msg_ncar_pth_get_external_temp(msg);
	ncar_pth->rh1 = mavlink_msg_ncar_pth_get_rh1(msg);
	ncar_pth->rh2 = mavlink_msg_ncar_pth_get_rh2(msg);
	ncar_pth->internal_temp = mavlink_msg_ncar_pth_get_internal_temp(msg);
	ncar_pth->sample_num = mavlink_msg_ncar_pth_get_sample_num(msg);
#else
	memcpy(ncar_pth, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_NCAR_PTH_LEN);
#endif
}
