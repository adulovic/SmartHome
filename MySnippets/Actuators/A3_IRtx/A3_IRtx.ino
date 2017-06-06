#define SN "InfraRed Transmitter"       // short Sketch (Node) name
#define SV "0.0"                        // short Sketch (Node) version
#define MY_NODE_ID 99                   // (1-254) to manually set Node ID
/*
	Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanation and inital variables
  #include "A3.h"                       // PhotoVoltaic Resistor
/*
	Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
  sendSketchInfo(SN, SV);            // Send the sketch version information
    present(A3, S_IR, "IR Tx");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    setupA3();
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/* 
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA3(message);
}