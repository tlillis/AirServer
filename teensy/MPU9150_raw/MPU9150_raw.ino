// I2C device class (I2Cdev) demonstration Arduino sketch for MPU9150
// 1/4/2013 original by Jeff Rowberg <jeff@rowberg.net> at https://github.com/jrowberg/i2cdevlib
//          modified by Aaron Weiss <aaron@sparkfun.com>
//
// Changelog:
//     2011-10-07 - initial release
//     2013-1-4 - added raw magnetometer output

/* ============================================
I2Cdev device library code is placed under the MIT license
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

#include "../mavlink/include/airserver/mavlink.h"  

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include "Wire.h"

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU6050.h"

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
//!MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t mx, my, mz;

#define LED_PIN 13
bool blinkState = false;

// Initialize the required buffers 
mavlink_message_t msg_imu;
mavlink_message_t msg_pth; 
uint8_t buf[MAVLINK_MAX_PACKET_LEN];

int system_type = 0;
int autopilot_type = 0;

uint16_t len = 0;

int sampleNo = 0;
float pressure = 0;
float externalTemp = 0;
float rh1 = 0;
float rh2 = 0;
float internalTemp = 0;

int fieldNo = 0;
char field[16];
int fieldIndex = 0;

char incomingByte;

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();
    
    Serial.begin(9600);
    Serial1.begin(19200,SERIAL_8N1);

    //!accelgyro.initialize();
    
    // configure Arduino LED for
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // read raw accel/gyro measurements from device
    //!accelgyro.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);
	
    // Pack the message
    mavlink_msg_raw_imu_pack(0, 0, &msg_imu, 0, ax,ay,az,gx,gy,gz,mx,my,mz);
    
	
    // Copy the message to send buffer 
    len = mavlink_msg_to_send_buffer(buf, &msg_imu);
	
    // Send the message (.write sends as bytes) 
    //Serial.write(buf, len);
    
    if (Serial1.available() > 0) {
        incomingByte = Serial1.read();
        
        //input tab-delimated fields
        switch(incomingByte) {
          case '\t': //end of field
            switch(fieldNo) { //Depending on the field give to different variable
              case 0:
                sampleNo = atoll(field);
              case 1:
                pressure = atof(field);
              case 2:
                externalTemp = atof(field);
              case 3:
                rh1 = atof(field);
              case 4:
                rh2 = atof(field); 
            }
            fieldNo++;
            fieldIndex = 0;
            field[0] = '\0'; //empty for next variable read
            break;
            
          case '\n': //Handle end of input line
            internalTemp = atof(field); //handle last variable
            
            //Prepare mavlink
            mavlink_msg_ncar_pth_pack(0, 0, &msg_pth, 0, sampleNo, pressure, externalTemp,rh1,rh2,internalTemp);
            len = mavlink_msg_to_send_buffer(buf, &msg_pth);
            
            Serial.write(buf, len);
            
            //reset everything for next line
            fieldNo = 0;
            field[0] = '\0';
            fieldIndex = 0;
            break;
            
          case 0://Handle NULL char
            break;
            
          default: //append lastest byte to field
            field[fieldIndex] = incomingByte;
            fieldIndex++;
        }
    }
    //delay(500);

    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
}
