/**
 * Gateway in Office
=========1=========2=========3=========4=========5=========6=========7========*/
#define MY_NODE_ID 00                   // (1-254) to manually set Node ID
#define SN "Office (Gateway)"           // short Sketch (Node) name
#define SV "1.170930"                   // short Sketch (Node) version

/**
 * Library Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include <SPI.h>                        // Serial Peripheral Interface Bus
#include <Ethernet.h>                   // Ethernet library for W5100 shield
#include "GW.h"                         // NRF24L01 definitions for Gateway
#include <MySensors.h>                  // MySensors library

/**
 * Sensors and Activators
=========1=========2=========3=========4=========5=========6=========7========*/

    /**
     * A1 - Relay for projector power cord
     */
    #define A1              1               // Sensor number
    const int pinA1 =       2;              // Data pin
    #include "A01_relayInverted.h"          // Relay - for Projector Power

    /**
     * S1 - Reed switch - office door
     */
    #define S1              2               // Sensor number
    const int pinS1 =       4;              // Data pin (with pull-up resistor)
    int valueS1 = 0;                        // reading the sensor status
    int stateS1 = 0;                        // storing the last status
    #include "S01_ReedSwitch.h"             // Reed switch - Office Door

    /**
     * S2 - Temperature & Humidity (DHT 11)
     *      This one has two sensors on the same pin
     */
    #define S2T             3               // Sensor number - Temperature
    #define S2H             4               // Sensor number - Humidity
    const int pinS2 =       3;              // data pin
    float stateS2H;                         // last saved humidity value
    float stateS2T;                         // last saved temperature value
    unsigned long tS2 = 0;                  // last saved time the loop fired
    unsigned long iS2 = 5;                  // interval at which to fire loop (in minutes)
    #include <DHT.h>                        // include the DHT 11 library
    #include "S02_DHT11"                    // DHT 11 for Humidity and Temperature

/**
 * Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
    /* Present the node */
    sendSketchInfo(SN, SV);
    /* Present the Actuators and Sensors */
    present(A1, S_BINARY, "Projector Power");
    present(S1, S_DOOR, "Office ReedSwitch");
    present(S2T, S_TEMP,"Office Temperature");
    present(S2H, S_HUM,"Office Humidity");
    /* Debug Printout */
    // Serial.println((String)"\n === Node "+MY_NODE_ID+" presented ("+SN+")\n");
}

/**
 * Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA1();
    setupS1();
    setupS2();
    /* Debug Printout */
    // Serial.println((String)"\n === Node "+MY_NODE_ID+" setup ("+SN+")\n");
}

/**
 * Loop ... once a second only
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    loopS1();
    loopS2();
    wait(1000);
}

/**
 * Receive ... messages to the actuator(s)
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {

    receiveA1(message);
}