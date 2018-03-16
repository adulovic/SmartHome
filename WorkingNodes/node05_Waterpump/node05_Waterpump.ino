/**
    Sketch Information
=========1=========2=========3=========4=========5=========6=========7========*/
#define SN "Water Pump"                 // short Sketch (Node) name
#define SV "1.1 17-12-12"               // short Sketch (Node) version
#define MY_NODE_ID 05                   // (1-254) to manually set Node ID
const bool Printout = false;            // set to false after testing

/**
 * Library Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library

/**
 * Sensors and Activators
=========1=========2=========3=========4=========5=========6=========7========*/

    /**
     * A01 - Relay for LED strip
     */
    #define A01                 1       // sensor number
    #define pinA01              3       // data pin
    bool stateA01;                      // is on ?
    #include "A01_Relay_Inverted.h"     // from library

    /**
     * S04 - PIR switch
     */
    #define S04                 2       // sensor number
    #define pinS04              4       // data pin
    bool trippedS04;                    // is tripped ?
    bool armedS04;                      // is armed ?
    unsigned long tS04;                 // last time loop fired
    #include "S04_PIR.h"                // from library

/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
    sendSketchInfo(SN,SV);
    present(A01,S_BINARY,"Water Pump Lights");    // V_STATUS
    present(S04,S_MOTION,"Water Pump PIR");       // V_TRIPPED, V_ARMED
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");}
}

/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA01();
    setupS04();
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");}
}

/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    loopA01();                  // loop constantly
    loopS04(1);                 // loop every 1 second
}

/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
   receiveA01(message);
   receiveS04(message);
}
