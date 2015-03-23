#include <iostream>
#include <queue>
#include <string>
#include <sstream>

#include "Poco/Util/IniFileConfiguration.h"
#include "Poco/AutoPtr.h"
#include "Poco/Logger.h"
#include "Poco/Message.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadPool.h"
#include "Poco/RWLock.h"
#include "Poco/Mutex.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPMessage.h"
#include "Poco/Net/WebSocket.h"
#include "Poco/Net/HTTPClientSession.h"

#include "serialdata.h"
#include "serial_port.h"

using namespace std;
using Poco::AutoPtr;
using Poco::Util::IniFileConfiguration;
using Poco::SimpleFileChannel;
using Poco::Logger;
using Poco::FileChannel;
using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::Net::WebSocket;

class AutopilotSerialThread : public Poco::Runnable{
private:
    int _id;
    Poco::Mutex * _lock;
    queue <mavlink_message_t> * _collector;
public:
    AutopilotSerialThread (int id, Poco::Mutex * lock, queue <mavlink_message_t> * collector) : _id(id), _lock(lock), _collector(collector) {}
    void run(){
        mavlink_message_t message;
        //char * port = "/dev/ttyACM0";
        //int baud = 38400;
        char * port = "/dev/pts/8";
        int baud = 9600;
        Serial_Port serial_port(port,baud);
        try {
            serial_port.start();

            while(true){

                _lock->lock(); //acquire lock
                if (serial_port.status == 1){
                serial_port.read_message(message);
                }
                else {
                    break;

                }
                //printf("In thread %d\n",message.msgid);
                _collector->push(message);
                _lock->unlock();  //release lock
            }
        }
        catch (exception& e)
        {
            cout << e.what() << '\n';
        }
        catch (int exit_failure)
        {
            cout << exit_failure << endl;
        }
    }
};

int decode(mavlink_message_t &message)
{
    int msgid = message.msgid;
    //int compid = message.compid;
    //int sysid = message.sysid;

    // Handle Message ID
    switch (message.msgid)
    {

        case MAVLINK_MSG_ID_HEARTBEAT:
        {
            // Heart Beat
            mavlink_heartbeat_t heartbeat;

            printf("MAVLINK_MSG_ID_HEARTBEAT\n");
            mavlink_msg_heartbeat_decode(&message, &(heartbeat));
            printf("Heart Beat:\n");
            printf("Type:%i   AutoPilot:%i   Base Mode:%i\n",heartbeat.type,heartbeat.autopilot,heartbeat.base_mode);
            printf("Custom Mode:%i   System Status:%i   Mavlink Version:%i\n",heartbeat.custom_mode,heartbeat.system_status,heartbeat.mavlink_version);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_SYS_STATUS:
        {
            // System Status
            mavlink_sys_status_t sys_status;

            printf("MAVLINK_MSG_ID_SYS_STATUS\n");
            mavlink_msg_sys_status_decode(&message, &(sys_status));
            printf("System Status\n");
            printf("Onboard Control Sensors Present: %i \nOnboard Control Sensors Enabled: %i \nOnboard Control Sensors Health: %i\n",sys_status.onboard_control_sensors_present,sys_status.onboard_control_sensors_enabled,sys_status.onboard_control_sensors_health);
            printf("Load: %i\n",sys_status.load);
            printf("Voltage: %i, Current: %i, Remaining: %i\n",sys_status.voltage_battery,sys_status.current_battery,sys_status.battery_remaining);
            printf("Communication Drops(percent): %i\n", sys_status.drop_rate_comm);
            printf("Communication Errors: %i\n", sys_status.errors_comm);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_BATTERY_STATUS:
        {
            // Battery Status
            mavlink_battery_status_t battery_status;

            printf("MAVLINK_MSG_ID_BATTERY_STATUS\n");
            mavlink_msg_battery_status_decode(&message, &(battery_status));
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_RADIO_STATUS:
        {
            // Radio Status
            mavlink_radio_status_t radio_status;

            printf("MAVLINK_MSG_ID_RADIO_STATUS\n");
            mavlink_msg_radio_status_decode(&message, &(radio_status));
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_LOCAL_POSITION_NED:
        {
            // Local Position
            mavlink_local_position_ned_t local_position_ned;

            printf("MAVLINK_MSG_ID_LOCAL_POSITION_NED\n");
            mavlink_msg_local_position_ned_decode(&message, &(local_position_ned));
            printf("    pos  (NED):  %f %f %f (m)\n\n", local_position_ned.x, local_position_ned.y, local_position_ned.z );
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
        {
            // Global Position
            mavlink_global_position_int_t global_position_int;

            printf("MAVLINK_MSG_ID_GLOBAL_POSITION_INT\n");
            mavlink_msg_global_position_int_decode(&message, &(global_position_int));
            printf("GPS:\n");
            printf("Time Stamp: %i",global_position_int.time_boot_ms);
            printf("Lat: %i  Lon: %i  Alt: %i Relative Alt: %i\n",global_position_int.lat, global_position_int.lon, global_position_int.alt,global_position_int.relative_alt);
            printf("Speed X: %i  Speed Y: %i Speed Z: %i\n",global_position_int.vx,global_position_int.vy,global_position_int.vz);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED:
        {
            // Local Position Target
            mavlink_position_target_local_ned_t position_target_local_ned;

            printf("MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED\n");
            mavlink_msg_position_target_local_ned_decode(&message, &(position_target_local_ned));
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT:
        {
            // Global Position Target
            mavlink_position_target_global_int_t position_target_global_int;

            printf("MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT\n");
            mavlink_msg_position_target_global_int_decode(&message, &(position_target_global_int));
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_HIGHRES_IMU:
        {
            // HiRes IMU
            mavlink_highres_imu_t imu;

            printf("MAVLINK_MSG_ID_HIGHRES_IMU\n");
            mavlink_msg_highres_imu_decode(&message, &(imu));
            printf("Got message HIGHRES_IMU (spec: https://pixhawk.ethz.ch/mavlink/#HIGHRES_IMU)\n");
            printf("    ap time:     %lu \n", imu.time_usec);
            printf("    acc  (NED):  % f % f % f (m/s^2)\n", imu.xacc , imu.yacc , imu.zacc );
            printf("    gyro (NED):  % f % f % f (rad/s)\n", imu.xgyro, imu.ygyro, imu.zgyro);
            printf("    mag  (NED):  % f % f % f (Ga)\n"   , imu.xmag , imu.ymag , imu.zmag );
            printf("    baro:        %f (mBar) \n"  , imu.abs_pressure);
            printf("    altitude:    %f (m) \n"     , imu.pressure_alt);
            printf("    temperature: %f C \n"       , imu.temperature );
            printf("\n");

            return 0;
        }

        case MAVLINK_MSG_ID_ATTITUDE:
        {
             // Attitude
            mavlink_attitude_t attitude;

            printf("MAVLINK_MSG_ID_ATTITUDE\n");
            mavlink_msg_attitude_decode(&message, &(attitude));
            printf("Attitude:\n");
            printf("Time Stamp: %i\n", attitude.time_boot_ms);
            printf("R:%f P:%f Y:%f RS:%f PS:%f YS:%f\n", attitude.roll,attitude.pitch,attitude.yaw,attitude.rollspeed,attitude.pitchspeed,attitude.yawspeed);
            printf("\n");

            return 0;
        }

        case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
        {
            // Raw RC Channels
            mavlink_rc_channels_raw_t channels;

            printf("MAVLINK_MSG_ID_RC_CHANNELS_RAW\n");
            mavlink_msg_rc_channels_raw_decode(&message, &(channels));
            printf("Raw RC Channels:\n");
            printf("Time Stamp: %i    Port: %i\n",channels.time_boot_ms,channels.port);
            printf("1: %i \n2: %i \n3: %i \n4: %i \n5: %i \n6: %i \n7: %i \n8: %i\n",channels.chan1_raw,channels.chan2_raw,channels.chan3_raw,channels.chan4_raw,channels.chan5_raw,channels.chan6_raw,channels.chan7_raw,channels.chan8_raw);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_TERRAIN_REPORT:
        {
            // Terrain Report (136)
            mavlink_terrain_report_t terrain;

            printf("MAVLINK_MSG_ID_TERRAIN_REPORT\n");
            mavlink_msg_terrain_report_decode(&message, &(terrain));
            printf("Terrain Report:\n");
            printf("Lat: %i  Lon: %i\n",terrain.lat,terrain.lon);
            printf("Spacing: %i\n", terrain.spacing);
            printf("Terrain Height: %f  Current Height %f\n", terrain.terrain_height, terrain.current_height);
            printf("Pending: %i  Loaded: %i\n",terrain.pending,terrain.loaded);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW:
        {
            // Servo Output Raw (36)
            mavlink_servo_output_raw_t servo;

            printf("MAVLINK_MSG_ID_SERVO_OUTPUT_RAW\n");
            mavlink_msg_servo_output_raw_decode(&message, &(servo));
            printf("Raw Servo Output:\n");
            printf("Time Stamp: %i    Port: %i\n",servo.time_usec,servo.port);
            printf("1: %i \n2: %i \n3: %i \n4: %i \n5: %i \n6: %i \n7: %i \n8: %i\n",servo.servo1_raw,servo.servo2_raw,servo.servo3_raw,servo.servo4_raw,servo.servo5_raw,servo.servo6_raw,servo.servo7_raw,servo.servo8_raw);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_MISSION_CURRENT:
        {
            // Mission Current (42)
            mavlink_mission_current_t mission_current;

            printf("MAVLINK_MSG_ID_MISSION_CURRENT\n");
            mavlink_msg_mission_current_decode(&message, &(mission_current));
            printf("Mission Current:\n");
            printf("Seq: %i\n",mission_current.seq);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_SYSTEM_TIME:
        {
            // System Time (2)
            mavlink_system_time_t time;

            printf("MAVLINK_MSG_ID_SYSTEM_TIME\n");
            mavlink_msg_system_time_decode(&message, &(time));
            printf("System Time:\n");
            printf("Master Clock: %lld    Component Clock: %i\n",(long long)time.time_unix_usec,time.time_boot_ms);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_SCALED_PRESSURE:
        {
            // Scaled Pressure (29)
            mavlink_scaled_pressure_t pressure;

            printf("MAVLINK_MSG_ID_SCALED_PRESSURE\n");
            mavlink_msg_scaled_pressure_decode(&message, &(pressure));
            printf("Scaled Pressure:\n");
            printf("Time Stamp: %i \n",pressure.time_boot_ms);
            printf("Absolute: %f  Differential: %f  Temperature: %i\n",pressure.press_abs,pressure.press_diff,pressure.temperature);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_SCALED_IMU2:
        {
            // Scaled IMU2 (116)
            mavlink_scaled_imu2_t imu2;

            printf("MAVLINK_MSG_ID_SCALED_IMU2\n");
            mavlink_msg_scaled_imu2_decode(&message, &(imu2));
            printf("Raw IMU 2:\n");
            printf("Time Stamp: %i\n",imu2.time_boot_ms);
            printf("ACC   X:%i  Y:%i  Z:%i\n",imu2.xacc,imu2.yacc,imu2.zacc);
            printf("GYRO  X:%i  Y:%i  Z:%i\n",imu2.xgyro,imu2.ygyro,imu2.zgyro);
            printf("MAG   X:%i  Y:%i  Z:%i\n",imu2.xmag,imu2.ymag,imu2.zmag);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_GPS_RAW_INT:
        {
            // GPS RAW INT (24)
            mavlink_gps_raw_int_t gps_raw;

            printf("MAVLINK_MSG_ID_GPS_RAW_INT\n");
            mavlink_msg_gps_raw_int_decode(&message, &(gps_raw));
            printf("GPS Raw:\n");
            printf("Time Stamp: %lld\n",(long long)gps_raw.time_usec);
            printf("Fix Type: %i\n",gps_raw.fix_type);
            printf("Lat:%i  Lon:%i  Alt:%i\n",gps_raw.lat,gps_raw.lon,gps_raw.alt);
            printf("EPH:%i  EPV:%i  Vel:%i  COG: %i\n",gps_raw.eph,gps_raw.epv,gps_raw.vel,gps_raw.cog);
            printf("Satellites:%i\n",gps_raw.satellites_visible);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_RAW_IMU:
        {
            // RAW IMU (27)
            mavlink_raw_imu_t imu_raw;

            printf("MAVLINK_MSG_ID_RAW_IMU\n");
            mavlink_msg_raw_imu_decode(&message, &(imu_raw));
            printf("Raw IMU:\n");
            printf("Time Stamp: %lld\n",(long long)imu_raw.time_usec);
            printf("ACC   X:%i  Y:%i  Z:%i\n",imu_raw.xacc,imu_raw.yacc,imu_raw.zacc);
            printf("GYRO  X:%i  Y:%i  Z:%i\n",imu_raw.xgyro,imu_raw.ygyro,imu_raw.zgyro);
            printf("MAG   X:%i  Y:%i  Z:%i\n",imu_raw.xmag,imu_raw.ymag,imu_raw.zmag);
            printf("\n");
            return 0;
        }

        case MAVLINK_MSG_ID_VFR_HUD:
        {
            // VFW_HUD (74)
            mavlink_vfr_hud_t vfr;

            printf("MAVLINK_MSG_ID_VFR_HUD\n");
            mavlink_msg_vfr_hud_decode(&message, &(vfr));
            printf("VFR HUD:\n");
            printf("Airspeed: %f  Groundspeed: %f\n",vfr.airspeed,vfr.groundspeed);
            printf("Heading: %i\n",vfr.heading);
            printf("Throttle: %i\n",vfr.throttle);
            printf("Alt: %f  Climb: %f\n",vfr.alt,vfr.climb);
            printf("\n");
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

int main()
{
    cout << "Starting AirServer..." << endl << endl;

    //Get data from configuration file
    AutoPtr<IniFileConfiguration> pConf(new IniFileConfiguration("airserver.ini"));

    std::string autopilot_type = pConf->getString("autopilot.type");
    std::string autopilot_file = pConf->getString("autopilot.file");
    int autopilot_sitl = pConf->getInt("autopilot.sitl");

    std::string teensy_file = pConf->getString("teensy.file");
    int teensy_baud = pConf->getInt("teensy.baud");
    int teensy_imu = pConf->getInt("teensy.imu");

    cout << "~~CONFIGURATION~~" << endl << endl;

    cout << "AUTOPILOT:" << endl;
    cout << "AutoPilot Type: " << autopilot_type << endl;
    cout << "AutoPilot Port: " << autopilot_file << endl;
    cout << "SITL: " << autopilot_sitl << endl << endl;

    cout << "TEENSY:" << endl;
    cout << "Teensy Port: " << teensy_file << endl;
    cout << "Teensy Baud Rate: " << teensy_baud << endl;
    cout << "Teensy IMU: " << teensy_imu << endl << endl;

    //Create a queue for getting data between threads
    queue <mavlink_message_t> msg_queue_send;

    Poco::Mutex lock;

    cout << "Starting autopilot serial connection..." << endl;

    AutopilotSerialThread autopilot_thread(1, &lock, &msg_queue_send);

    Poco::ThreadPool pool;
    pool.start(autopilot_thread);

    mavlink_message_t message;
    mavlink_message_t msg;

    //uint16_t len;
    uint8_t buf[2041];

    Poco::Net::SocketAddress sa("localhost", 514);
    Poco::Net::DatagramSocket dgs;
    dgs.connect(sa);

    HTTPClientSession cs("localhost",9980);
    HTTPRequest request(HTTPRequest::HTTP_GET, "/",HTTPMessage::HTTP_1_1);
    request.set("origin", "http://www.websocket.org");
    HTTPResponse response;

    try {
        WebSocket* m_psock = new WebSocket(cs, request, response);
        char *testStr="Hello echo websocket!";
        char receiveBuff[strlen(testStr)];

        int len=m_psock->sendFrame(testStr,strlen(testStr),WebSocket::FRAME_TEXT);
        std::cout << "Sent bytes " << len << std::endl;
        int flags=0;

        int rlen=m_psock->receiveFrame(receiveBuff,strlen(testStr),flags);
        std::cout << "Received bytes " << rlen << std::endl;
        std::cout << receiveBuff << std::endl ;

        m_psock->close();

    } catch (std::exception &e) {
        std::cout << "Exception " << e.what();
    }

    printf("Waiting for first data from devices...");
    while(msg_queue_send.empty())
    {
    }

    mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
    mavlink_msg_to_send_buffer(buf, &msg);

    int previous_id = -1;
    while(!msg_queue_send.empty())
    {
        lock.lock();
        message = msg_queue_send.front();
        msg_queue_send.pop();
        lock.unlock();

        if(message.msgid != previous_id)
        {
            mavlink_msg_to_send_buffer(buf, &msg);
            //printf("Main Thread: %d\n",message.msgid);
            decode(message);
            //cout << dgs.sendBytes(&buf, sizeof(buf)) << "/" << sizeof(message) << endl;
            previous_id = message.msgid;
            sleep(1);
        }

    }
    printf("Reached end of loop...");
    pool.joinAll();
    return 0;
}
