#define SN "Jacuzzi"                    // short Sketch (Node) name
#define SV "1.1"                        // short Sketch (Node) version
#define MY_NODE_ID 4                    // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanation and inital variables
  #include "A1_4.h"                     // 4 channel relay
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
  sendSketchInfo(SN, SV);
    present(A14A, S_BINARY, "Jacuzzi Water Pump");
    present(A14B, S_BINARY, "Jacuzzi Water Blower");
    present(A14C, S_BINARY, "Jacuzzi Water Heater");
    present(A14D, S_BINARY, "Jacuzzi Light");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/* 
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA14();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/*
Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    // nothing to loop
}
/* 
Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA14(message);
}
