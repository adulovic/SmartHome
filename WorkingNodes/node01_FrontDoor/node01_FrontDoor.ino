/**
 * Sketch Information
=========1=========2=========3=========4=========5=========6=========7========*/
#define SN "Front Door"                 // short Sketch name
#define SV "1.1 17-12-12"               // short Sketch (Node) version
#define MY_NODE_ID 01                   // (1-254) to manually set Node ID
const bool Printout = true;             // set to false after testing

/**
    Library Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library

/**
    Sensors and Activators
=========1=========2=========3=========4=========5=========6=========7========*/
    /**
     * A01 - Relay, entryway lights
     */
    #define A01                 1
    #define pinA01              2
    bool statusA01;                     // last known state
    #include "A01_Relay_Inverted.h"

    /**
     * A01_manual - Wall switch, entryway lights
     */
    #define A01_manual          2
    #define pinA01_manual       6

    /**
     * A02 - Electronic Lock, front door
     */
    #define A02                 3
    #define pinA02L             3      // pin that locks the door
    #define pinA02U             4      // pin that unlocks the door
    bool statusA02;                    // last known state
    #include "A02_Deadbolt.h"

    /**
     * S01 - Reed switch, front door
     */
    #define S01                 4
    #define pinS01              7       // data pin with pull-up resistor
    bool trippedS01;                    // last known state
    bool armedS01;
    unsigned long tS01;                 // last time loop fired
    #include "S01_ReedSwitch.h"

    /**
     * S02 - DHT 11
     */
    #define S02t                5       // Temperature
    #define S02h                6       // Humidity
    #define pinS02              8       // The pin for DHT data 
    unsigned long tS02;                 // last time loop fired
    #include "S02_DHT11.h"

    /**
     * S04 - PIR switch, entryway lights
     */
    #define S04                 7
    #define pinS04              5       // data pin
    bool trippedS04;                    // last known state
    bool armedS04;
    unsigned long tS04;                 // last time loop fired
    #include "S04_PIR.h"

/**
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
    sendSketchInfo(SN, SV);
    present(A01, S_BINARY, "Entryway Lights");      // V_STATUS
    present(A02, S_LOCK, "Entryway Lock");          // V_LOCK_STATUS
    present(S01, S_DOOR, "Entryway Reed");          // V_TRIPPED, V_ARMED
    present(S02t, S_TEMP,"Downstairs Temperature"); // V_TEMP
    present(S02h, S_HUM,"Downstairs Humidity");     // V_HUM
    present(S04, S_MOTION, "Entryway PIR");         // V_TRIPPED, V_ARMED
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");}
}

/**
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    setupA01();
    setupA02();
    setupS01();
    setupS02();
    setupS04();    
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");}
}

/**
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {
    loopA01();
    loopA02();
    loopS01(1);
    loopS02(10*60);
    loopS04(1);
}

/**
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA01(message);
    receiveA02(message);
}
