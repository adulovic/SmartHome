#define SN "Garage"                     // short Sketch (Node) name
#define SV "1.1"                        // short Sketch (Node) version
#define MY_NODE_ID 6                    // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanation and inital variables
  #include "A1.h"                       // Relay - lights
  #include "S1.h"                       // Reed - gate
  #include "S4.h"                       // PIR
  #include "S13.h"                      // UltraSonic
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
  sendSketchInfo(SN, SV);
    present(A1, S_BINARY, "Garage Lights");
    present(S1, S_DOOR, "Garage Gate");
    present(S4, S_MOTION, "Garage PIR");
    present(S13, S_DISTANCE, "Garage Parking");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/* 
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA1();
    setupS1();
    setupS4();
    setupS13();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    loopS1();
    loopS4();
    loopS13();
  wait(1000);
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA1(message);
}
