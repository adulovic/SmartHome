#define SN "Gateway"                    // short Sketch (Node) name
#define SV "1.1"                        // short Sketch (Node) version
#define MY_NODE_ID 00                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include <SPI.h>                        // Serial Peripheral Interface Bus
#include <Ethernet.h>                   // Ethernet library for W5100 shield
#include "GW.h"                         // NRF24L01 definitions for Gateway
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanations and initialization
  #include "A1inverted.h"               // Projector power cord (Relay Switch)
  #include "S1.h"                       // Office Door (Reed switch)
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
  sendSketchInfo(SN, SV);
    present(A1, S_BINARY, "Projector Power");
    present(S1, S_DOOR, "Office Door Reed");
  Serial.println((String)"\n === Node "+MY_NODE_ID+" presented ("+SN+")\n");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA1();
    setupS1();
  Serial.println((String)"\n === Node "+MY_NODE_ID+" setup ("+SN+")\n");
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    loopS1();
  wait(1000);
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA1(message);
}
