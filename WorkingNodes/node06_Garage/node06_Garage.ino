/**
    Sketch Information
=========1=========2=========3=========4=========5=========6=========7========*/
#define SN "Garage"                     // short Sketch (Node) name
#define SV "1.1"                        // short Sketch (Node) version
#define MY_NODE_ID 6                    // (1-254) to manually set Node ID
const bool Printout = false;            // set to false after testing

/**
    Library Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library

/**
    Sensors and Activators
=========1=========2=========3=========4=========5=========6=========7========*/

    /**
     * A01 - Relay
     */
    #define A01                 1       // sensor number
    #define pinA01              2       // data pin
    bool stateA01;                      // is on ?
    #include "A01_Relay_Inverted.h"     // from library

    /**
     * S01 - Reed switch
     */
    #define S01                 2       // sensor number
    #define pinS01              7       // data pin with pull-up resistor
    bool trippedS01;                    // is tripped ?
    bool armedS01;                      // is armed ?
    unsigned long tS01;                 // last time loop fired
    #include "S01_ReedSwitch.h"         // from library

    /**
     * S04 - PIR switch
     */
    #define S04                 3       // sensor number
    #define pinS04              3       // data pin
    bool trippedS04;                    // is tripped ?
    bool armedS04;                      // is armed ?
    unsigned long tS04;                 // last time loop fired
    #include "S04_PIR.h"                // from library

    /**
     * S13 - Sonar
     */
    #define S13                 4       // sensor number
    #define pinS13T             4       // data pin TRIG
    #define pinS13E             5       // data pin ECHO
    unsigned long tS13;                 // last time loop fired
    #include "S13_Ultrasonic.h"         // UltraSonic
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
    sendSketchInfo(SN, SV);
    present(A01, S_BINARY, "Garage Lights");
    present(S01, S_DOOR, "Garage Gate");
    present(S04, S_MOTION, "Garage PIR");
    present(S13, S_DISTANCE, "Garage Parking");
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");}
}
/* 
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA01();
    setupS01();
    setupS04();
    setupS13();
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");}
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    loopS01(1);
    loopS04(1);
    loopS13(1);
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA01(message);
}
