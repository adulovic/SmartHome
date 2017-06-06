#define SN "Two Channel Relay"          // short Sketch name
#define SV "0.0"                        // short Sketch version
#define MY_NODE_ID 99                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanation and inital variables
  #include "A1_2.h"                         // Two Channel Relay
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){
  sendSketchInfo(SN, SV);
    present(A12A, S_BINARY, "Relay A");
    present(A12B, S_BINARY, "Relay B");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    setupA12();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/* 
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {
    // nothing to loop
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA12(message);
}
