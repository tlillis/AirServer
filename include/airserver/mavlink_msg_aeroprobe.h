// MESSAGE AEROPROBE PACKING

#define MAVLINK_MSG_ID_AEROPROBE 242

typedef struct __mavlink_aeroprobe_t
{
 uint64_t time_usec; ///< Image timestamp (microseconds since UNIX epoch, according to camera clock)
 uint32_t time_device; ///< Sample Number
 uint32_t date; ///< Sample Number
 float velocity; ///< Velocity
 float aoa; ///< Angle of Attack
 float aos; ///< Angle of Slideslip
 float pa; ///< Pressure Altitude
 float ps; ///< Static Pressure
 float pt; ///< Total Pressure
 float tc; ///< Thermocouple Temp
} mavlink_aeroprobe_t;

#define MAVLINK_MSG_ID_AEROPROBE_LEN 44
#define MAVLINK_MSG_ID_242_LEN 44

#define MAVLINK_MSG_ID_AEROPROBE_CRC 24
#define MAVLINK_MSG_ID_242_CRC 24



#define MAVLINK_MESSAGE_INFO_AEROPROBE { \
	"AEROPROBE", \
	10, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_aeroprobe_t, time_usec) }, \
         { "time_device", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_aeroprobe_t, time_device) }, \
         { "date", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_aeroprobe_t, date) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_aeroprobe_t, velocity) }, \
         { "aoa", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_aeroprobe_t, aoa) }, \
         { "aos", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_aeroprobe_t, aos) }, \
         { "pa", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_aeroprobe_t, pa) }, \
         { "ps", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_aeroprobe_t, ps) }, \
         { "pt", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_aeroprobe_t, pt) }, \
         { "tc", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_aeroprobe_t, tc) }, \
         } \
}


/**
 * @brief Pack a aeroprobe message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param date Sample Number
 * @param velocity Velocity
 * @param aoa Angle of Attack
 * @param aos Angle of Slideslip
 * @param pa Pressure Altitude
 * @param ps Static Pressure
 * @param pt Total Pressure
 * @param tc Thermocouple Temp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_aeroprobe_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, uint32_t time_device, uint32_t date, float velocity, float aoa, float aos, float pa, float ps, float pt, float tc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AEROPROBE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint32_t(buf, 12, date);
	_mav_put_float(buf, 16, velocity);
	_mav_put_float(buf, 20, aoa);
	_mav_put_float(buf, 24, aos);
	_mav_put_float(buf, 28, pa);
	_mav_put_float(buf, 32, ps);
	_mav_put_float(buf, 36, pt);
	_mav_put_float(buf, 40, tc);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AEROPROBE_LEN);
#else
	mavlink_aeroprobe_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.date = date;
	packet.velocity = velocity;
	packet.aoa = aoa;
	packet.aos = aos;
	packet.pa = pa;
	packet.ps = ps;
	packet.pt = pt;
	packet.tc = tc;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AEROPROBE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AEROPROBE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AEROPROBE_LEN, MAVLINK_MSG_ID_AEROPROBE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AEROPROBE_LEN);
#endif
}

/**
 * @brief Pack a aeroprobe message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param date Sample Number
 * @param velocity Velocity
 * @param aoa Angle of Attack
 * @param aos Angle of Slideslip
 * @param pa Pressure Altitude
 * @param ps Static Pressure
 * @param pt Total Pressure
 * @param tc Thermocouple Temp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_aeroprobe_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,uint32_t time_device,uint32_t date,float velocity,float aoa,float aos,float pa,float ps,float pt,float tc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AEROPROBE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint32_t(buf, 12, date);
	_mav_put_float(buf, 16, velocity);
	_mav_put_float(buf, 20, aoa);
	_mav_put_float(buf, 24, aos);
	_mav_put_float(buf, 28, pa);
	_mav_put_float(buf, 32, ps);
	_mav_put_float(buf, 36, pt);
	_mav_put_float(buf, 40, tc);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AEROPROBE_LEN);
#else
	mavlink_aeroprobe_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.date = date;
	packet.velocity = velocity;
	packet.aoa = aoa;
	packet.aos = aos;
	packet.pa = pa;
	packet.ps = ps;
	packet.pt = pt;
	packet.tc = tc;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AEROPROBE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AEROPROBE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AEROPROBE_LEN, MAVLINK_MSG_ID_AEROPROBE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AEROPROBE_LEN);
#endif
}

/**
 * @brief Encode a aeroprobe struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param aeroprobe C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_aeroprobe_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_aeroprobe_t* aeroprobe)
{
	return mavlink_msg_aeroprobe_pack(system_id, component_id, msg, aeroprobe->time_usec, aeroprobe->time_device, aeroprobe->date, aeroprobe->velocity, aeroprobe->aoa, aeroprobe->aos, aeroprobe->pa, aeroprobe->ps, aeroprobe->pt, aeroprobe->tc);
}

/**
 * @brief Encode a aeroprobe struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param aeroprobe C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_aeroprobe_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_aeroprobe_t* aeroprobe)
{
	return mavlink_msg_aeroprobe_pack_chan(system_id, component_id, chan, msg, aeroprobe->time_usec, aeroprobe->time_device, aeroprobe->date, aeroprobe->velocity, aeroprobe->aoa, aeroprobe->aos, aeroprobe->pa, aeroprobe->ps, aeroprobe->pt, aeroprobe->tc);
}

/**
 * @brief Send a aeroprobe message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Image timestamp (microseconds since UNIX epoch, according to camera clock)
 * @param time_device Sample Number
 * @param date Sample Number
 * @param velocity Velocity
 * @param aoa Angle of Attack
 * @param aos Angle of Slideslip
 * @param pa Pressure Altitude
 * @param ps Static Pressure
 * @param pt Total Pressure
 * @param tc Thermocouple Temp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_aeroprobe_send(mavlink_channel_t chan, uint64_t time_usec, uint32_t time_device, uint32_t date, float velocity, float aoa, float aos, float pa, float ps, float pt, float tc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AEROPROBE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint32_t(buf, 12, date);
	_mav_put_float(buf, 16, velocity);
	_mav_put_float(buf, 20, aoa);
	_mav_put_float(buf, 24, aos);
	_mav_put_float(buf, 28, pa);
	_mav_put_float(buf, 32, ps);
	_mav_put_float(buf, 36, pt);
	_mav_put_float(buf, 40, tc);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AEROPROBE, buf, MAVLINK_MSG_ID_AEROPROBE_LEN, MAVLINK_MSG_ID_AEROPROBE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AEROPROBE, buf, MAVLINK_MSG_ID_AEROPROBE_LEN);
#endif
#else
	mavlink_aeroprobe_t packet;
	packet.time_usec = time_usec;
	packet.time_device = time_device;
	packet.date = date;
	packet.velocity = velocity;
	packet.aoa = aoa;
	packet.aos = aos;
	packet.pa = pa;
	packet.ps = ps;
	packet.pt = pt;
	packet.tc = tc;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AEROPROBE, (const char *)&packet, MAVLINK_MSG_ID_AEROPROBE_LEN, MAVLINK_MSG_ID_AEROPROBE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AEROPROBE, (const char *)&packet, MAVLINK_MSG_ID_AEROPROBE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_AEROPROBE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_aeroprobe_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint32_t time_device, uint32_t date, float velocity, float aoa, float aos, float pa, float ps, float pt, float tc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_uint32_t(buf, 8, time_device);
	_mav_put_uint32_t(buf, 12, date);
	_mav_put_float(buf, 16, velocity);
	_mav_put_float(buf, 20, aoa);
	_mav_put_float(buf, 24, aos);
	_mav_put_float(buf, 28, pa);
	_mav_put_float(buf, 32, ps);
	_mav_put_float(buf, 36, pt);
	_mav_put_float(buf, 40, tc);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AEROPROBE, buf, MAVLINK_MSG_ID_AEROPROBE_LEN, MAVLINK_MSG_ID_AEROPROBE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AEROPROBE, buf, MAVLINK_MSG_ID_AEROPROBE_LEN);
#endif
#else
	mavlink_aeroprobe_t *packet = (mavlink_aeroprobe_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->time_device = time_device;
	packet->date = date;
	packet->velocity = velocity;
	packet->aoa = aoa;
	packet->aos = aos;
	packet->pa = pa;
	packet->ps = ps;
	packet->pt = pt;
	packet->tc = tc;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AEROPROBE, (const char *)packet, MAVLINK_MSG_ID_AEROPROBE_LEN, MAVLINK_MSG_ID_AEROPROBE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AEROPROBE, (const char *)packet, MAVLINK_MSG_ID_AEROPROBE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE AEROPROBE UNPACKING


/**
 * @brief Get field time_usec from aeroprobe message
 *
 * @return Image timestamp (microseconds since UNIX epoch, according to camera clock)
 */
static inline uint64_t mavlink_msg_aeroprobe_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field time_device from aeroprobe message
 *
 * @return Sample Number
 */
static inline uint32_t mavlink_msg_aeroprobe_get_time_device(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field date from aeroprobe message
 *
 * @return Sample Number
 */
static inline uint32_t mavlink_msg_aeroprobe_get_date(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field velocity from aeroprobe message
 *
 * @return Velocity
 */
static inline float mavlink_msg_aeroprobe_get_velocity(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field aoa from aeroprobe message
 *
 * @return Angle of Attack
 */
static inline float mavlink_msg_aeroprobe_get_aoa(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field aos from aeroprobe message
 *
 * @return Angle of Slideslip
 */
static inline float mavlink_msg_aeroprobe_get_aos(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field pa from aeroprobe message
 *
 * @return Pressure Altitude
 */
static inline float mavlink_msg_aeroprobe_get_pa(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field ps from aeroprobe message
 *
 * @return Static Pressure
 */
static inline float mavlink_msg_aeroprobe_get_ps(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field pt from aeroprobe message
 *
 * @return Total Pressure
 */
static inline float mavlink_msg_aeroprobe_get_pt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field tc from aeroprobe message
 *
 * @return Thermocouple Temp
 */
static inline float mavlink_msg_aeroprobe_get_tc(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Decode a aeroprobe message into a struct
 *
 * @param msg The message to decode
 * @param aeroprobe C-struct to decode the message contents into
 */
static inline void mavlink_msg_aeroprobe_decode(const mavlink_message_t* msg, mavlink_aeroprobe_t* aeroprobe)
{
#if MAVLINK_NEED_BYTE_SWAP
	aeroprobe->time_usec = mavlink_msg_aeroprobe_get_time_usec(msg);
	aeroprobe->time_device = mavlink_msg_aeroprobe_get_time_device(msg);
	aeroprobe->date = mavlink_msg_aeroprobe_get_date(msg);
	aeroprobe->velocity = mavlink_msg_aeroprobe_get_velocity(msg);
	aeroprobe->aoa = mavlink_msg_aeroprobe_get_aoa(msg);
	aeroprobe->aos = mavlink_msg_aeroprobe_get_aos(msg);
	aeroprobe->pa = mavlink_msg_aeroprobe_get_pa(msg);
	aeroprobe->ps = mavlink_msg_aeroprobe_get_ps(msg);
	aeroprobe->pt = mavlink_msg_aeroprobe_get_pt(msg);
	aeroprobe->tc = mavlink_msg_aeroprobe_get_tc(msg);
#else
	memcpy(aeroprobe, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_AEROPROBE_LEN);
#endif
}
