#include "../mavlink/include/airserver/mavlink.h"  
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
  
    Serial.begin(9600); 
    Serial1.begin(19200,SERIAL_8N1); //ncar pth
    
    pinMode(12, INPUT); //Digital pin for GPS pulse
    
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
  time = micros(); //Overflows after 70 minutes
  
  //Handle GPS Pulses
  if (digitalRead(12)) {
    Serial.print("Original:");
    Serial.println(time);
    pin_12 = false;
    time_decimal = time % 1000000;
    time_offset = 1000000 - time_decimal;
    if (time_offset < 500000) {
      time = time + time_offset;
    } else {
      time = time - time_decimal;
    }
    Serial.print("Fix:");
    Serial.println(time);
  } else {
  }
  
  //Handle ncar pth serial data
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
