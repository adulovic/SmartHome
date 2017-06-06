#define SN "Kitchen"                    // short Sketch (Node) name
#define SV "1.1"                        // short Sketch (Node) version
#define MY_NODE_ID 7                    // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanation and inital variables
  #include "A1.h"                       // Relay - pantry lights
  #include "S1.h"                       // Reed - pantry door
  #include "S14.h"                      // MQ2 - gas and smoke
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
  sendSketchInfo(SN, SV);
    present(A1, S_BINARY, "Pantry Lights");
    present(S1, S_DOOR, "Pantry Door");
    present(S14, S_AIR_QUALITY, "Gas Detection");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA1();
    setupS1();
    setupS14();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    loopS1();
    loopS14();
  wait(1000);
}
/*
Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA1(message);
}
