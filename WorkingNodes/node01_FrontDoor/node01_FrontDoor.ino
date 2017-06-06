#define SN "Front Door"                 // short Sketch name
#define SV "1.1"                        // short Sketch version
#define MY_NODE_ID 1                    // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanation and inital variables
  #include "A1.h"                       // Relay for lights
  #include "A2.h"                       // Front Door Electronic Lock
  #include "S1.h"                       // Reed switch
  #include "S4.h"                       // PIR switch
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
  sendSketchInfo(SN, SV);
    present(A1, S_BINARY, "Entryway Lights");
    present(A2, S_LOCK, "Entryway Lock");
    present(S1, S_DOOR, "Entryway Reed");
    present(S4, S_MOTION, "Entryway PIR");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    setupA1();
    setupA2();
    setupS1();
    setupS4();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {
    loopS1();
    loopS4();
  wait(1000);
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA1(message);
    receiveA2(message);
}
