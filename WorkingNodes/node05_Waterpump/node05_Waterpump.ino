#define SN "Water Pump"                 // short Sketch (Node) name
#define SV "1.1"                        // short Sketch (Node) version
#define MY_NODE_ID 5                    // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanation and inital variables
  #include "A1_2.h"                     // Double relay
  #include "S4.h"                       // PIR
  #include "S6.h"                       // VAC sensor
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
  sendSketchInfo(SN, SV);
    present(A12A, S_BINARY, "Water Pump");
    present(A12B, S_BINARY, "Water Pump Lights");
    present(S4, S_MOTION, "Water Pump PIR");
    present(S6, S_POWER, "Water Pump VAC");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA1_2();
    setupS4();
    setupS6();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    loopS4();
    loopS6();
  wait(1000);
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA1_2(message);
}
