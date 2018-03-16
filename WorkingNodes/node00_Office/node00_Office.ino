/**
    Sketch Information
=========1=========2=========3=========4=========5=========6=========7========*/
#define SN "Office (Gateway)"           // short Sketch (Node) name
#define SV "18-01-30"                   // short Sketch (Node) version
#define MY_NODE_ID 00                   // (1-254) to manually set Node ID
const bool Printout = false;             // set to false after testing

/**
 * Library Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include <SPI.h>                        // Serial Peripheral Interface Bus
#include <Ethernet.h>                   // Ethernet library for W5100 shield
#include "GW.h"                         // NRF24L01 definitions for Gateway
#include <MySensors.h>                  // MySensors library
#define MQTT_MAX_PACKET_SIZE 512

/**
 * Sensors and Activators
=========1=========2=========3=========4=========5=========6=========7========*/

    /**
     * S01 - Reed switch, office door
     */
    #define S01             2           // Sensor number
    #define pinS01          4           // data pin with pull-up resistor
    bool armedS01;                      // is armed?
    bool trippedS01;                    // is tripped?
    unsigned long tS01;                 // last time loop fired
    #include "S01_ReedSwitch.h"         // from library

    /**
     * S2 - Temperature & Humidity (DHT 11)
     *      This one has two sensors on the same pin
     */
    #define S02t            3           // Sensor number - Temperature
    #define S02h            4           // Sensor number - Humidity
    #define pinS02          3           // data pin
    unsigned long tS02;                 // last time loop fired
    #include "S02_DHT11.h"              // from library

/**
 * Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
    sendSketchInfo(SN, SV);
    present(S01, S_DOOR, "Office ReedSwitch");
    present(S02t, S_TEMP,"Office Temperature");
    present(S02h, S_HUM,"Office Humidity");
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");}
}

/**
 * Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
//    setupS01();
    setupS02();
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");}
}

/**
 * Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
//    loopS01(1);
    loopS02(10*60);
}

/**
 * Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
   receiveS01(message);
}
