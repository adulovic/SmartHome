#define SN "TV Room"                    // short Sketch (Node) name
#define SV "1.1"                        // short Sketch (Node) version
#define MY_NODE_ID 8                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                         // NRF24L01 definitions
#include <MySensors.h>                 // MySensors library
#include "def.h"                       // Explanation and inital variables
  #include "A1.h"                       // Relay for lights
  #include "S2.h"                       // DHT11
  #include "S4.h"                       // PIR switch
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
  sendSketchInfo(SN, SV);
    present(A1, S_BINARY, "AC");
    present(S2T, S_TEMP, "Temp");
    present(S2H, S_HUM, "Humidity");
    present(S4, S_MOTION, "Hallway PIR");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA1();
    setupS2();
    setupS4();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    loopS2();
    loopS4();
  wait(1000);
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
  //receiveA1(message);
}
