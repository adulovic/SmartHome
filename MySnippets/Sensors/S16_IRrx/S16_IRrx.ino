#define SN "InfraRed Receiver"          // short Sketch (Node) name
#define SV "0.0"                        // short Sketch (Node) version
#define MY_NODE_ID 99                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "zzz.h"                        // Explanation and inital variables

#include "S16.h"                        // InfraRed Receiver
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){
  sendSketchInfo(SN, SV);
    present(S16, S_IR, "IR rx");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    setupS16();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/* 
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {
    loopS16();
  wait(1000);
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to receive
