#define SN "Workshop"                   // short Sketch (Node) name
#define SV "1.1"                        // short Sketch (Node) version
#define MY_NODE_ID 12                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                         // NRF24L01 definitions
#include <MySensors.h>                 // MySensors library
#include "def.h"                       // Explanation and inital variables
  //#include "S6.h"                      // VAC sensor
  #include "S12.h"                     // VDC sensor
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){
  sendSketchInfo(SN, SV);
    present(S6, S_POWER, "Inverter VAC");
    present(S12, S_MULTIMETER,"Battery VDC");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    //setupS6();
    setupS12();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    //loopS6();
    loopS12();
  wait(1000);
}

/*
void loop(){
    ADCVal = analogRead(pinS12);             // read the voltage on the divider on analog pin
    pinVoltage = ADCVal * 0.00488;          // Calculate the voltage on the pin
    batteryVoltage = pinVoltage * ratio;    // Use the Ratio calculated for the voltage divider
    Serial.println((String)" Voltage: " + batteryVoltage);
  wait(5000);
}
*/

/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
//void receive(const MyMessage &message) {}
