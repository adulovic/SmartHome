#define SN "Workshop"                   // short Sketch (Node) name
#define SV "0.1"                        // short Sketch (Node) version
#define MY_NODE_ID 12                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                         // NRF24L01 definitions
#include <MySensors.h>                 // MySensors library
#include "def.h"                       // Explanation and inital variables
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){
  sendSketchInfo(SN, SV);
    present(S1, S_MULTIMETER,"Battery Voltage");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    ADCVal = analogRead(pinS1);             // read the voltage on the divider on analog pin
    pinVoltage = ADCVal * 0.00488;          // Calculate the voltage on the pin
    batteryVoltage = pinVoltage * ratio;    // Use the Ratio calculated for the voltage divider
    Serial.println((String)" Voltage: " + batteryVoltage);
    send(msgS1.set(batteryVoltage,2));      // send to controller, with 2 decimals
  wait(5000);
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
//void receive(const MyMessage &message) {}
