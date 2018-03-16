/**
 * Jacuzzi quad relay
=========1=========2=========3=========4=========5=========6=========7========*/
#define SN "Jacuzzi"                    // short Sketch (Node) name
#define SV "1.1 17-12-12"               // short Sketch (Node) version
#define MY_NODE_ID 04                   // (1-254) to manually set Node ID
const bool Printout = true;             // set to false after testing

/**
 * Library Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library

/**
 * Sensors and Activators
=========1=========2=========3=========4=========5=========6=========7========*/
#define A14A            1               // Relay for water pump
#define pinA14A         3

#define A14B            2               // Relay for blower
#define pinA14B         4

#define A14C            3               // Relay for heater
#define pinA14C         5

#define A14D            4               // Relay for lights
#define pinA14D         6

#include "A01_Relay_x4.h"               // 4 channel relay

/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
    sendSketchInfo(SN, SV);
    present(A14A, S_BINARY, "Jacuzzi Water Pump");
    present(A14B, S_BINARY, "Jacuzzi Water Blower");
    present(A14C, S_BINARY, "Jacuzzi Water Heater");
    present(A14D, S_BINARY, "Jacuzzi Light");
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")"); }
}
/* 
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA14();
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")"); }
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
