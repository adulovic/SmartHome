#define SN "Battery sensor"      // short Sketch (Node) name
#define SV "0.1"                        // short Sketch (Node) version
#define MY_NODE_ID 99                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "zzz.h"                        // Explanation and inital variables

#include "S1.h"                         // Battery sensor
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){
  sendSketchInfo(SN, SV);
    present(S1, S_LIGHT_LEVEL, "PV");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    setupS1();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/* 
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {
    loopS1();
  wait(1000);
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    // nothing to receive
}
