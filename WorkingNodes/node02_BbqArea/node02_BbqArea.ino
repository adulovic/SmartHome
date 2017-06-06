#define SN "BBQ Area"                  // short Sketch (Node) name
#define SV "1.1"                       // short Sketch (Node) version
#define MY_NODE_ID 2                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                         // NRF24L01 definitions
#include <MySensors.h>                 // MySensors library
#include "def.h"                       // Explanation and inital variables
  #include "A1inverted.h"              // Relay for BBQ lights
  #include "A3.h"                      // InfraRed transmitter (RGB LED diode)
  #include "S3.h"                      // Barometric Pressure
  #include "S7.h"                      // Water temperature sensor
/* 
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation() {
  sendSketchInfo(SN, SV);
    present(A1, S_LIGHT, "BBQ Lights");
    present(A3, S_IR, "Poolside RGB Control");
    present(S3T, S_TEMP, "Poolside Temperature");
    present(S3B, S_BARO, "Poolside Barometer");
    present(S7, S_TEMP, "Water Temperature");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    setupA1();
    setupA3();
    setupS3();
    setupS7();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {
    loopS3();
    loopS7();
  wait(1000);
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA1(message);
    receiveA3(message);
}
