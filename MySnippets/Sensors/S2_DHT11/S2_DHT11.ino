#define SN "DHT11"                      // short Sketch (Node) name
#define SV "0.1"                        // short Sketch (Node) version
#define MY_NODE_ID 99                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanation and inital variables
  #include "S2.h"                       // DHT11 for Humidity and Temperature
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){
  sendSketchInfo(SN, SV);
    present(S2H, S_HUM,"Humidity");             // present sensor to gateway
    present(S2T, S_TEMP,"Temperature");         // present sensor to gateway
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    setupS2();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/* 
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {
    loopS2();
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    // nothing to receive
}
