/**
    Sketch Information
=========1=========2=========3=========4=========5=========6=========7========*/
#define SN "BBQ Area"                   // short Sketch (Node) name
#define SV "18-03-15"                   // short Sketch (Node) version
#define MY_NODE_ID 02                   // (1-254) to manually set Node ID
const bool Printout = false;            // set to false after testing

/**
    Library Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "RSSI.h"                       // RSSI reporting
#define MQTT_MAX_PACKET_SIZE 512        // needed for FOTA over MQTT

/**
    Sensors and Activators
=========1=========2=========3=========4=========5=========6=========7========*/

    /**
     * A01 - Relay, BBQ gazebo light strip
     */
    #define A01                 1
    #define pinA01              2          
    bool stateA01;
    #include "A01_Relay_Inverted.h"

    /**
     * A03 - InfraRed transmitter for LED lights around pool
     */
    #define A03                 2
    #define pinA03              3       // the data pin must be PWM
    #include "A03_IR_Remote.h"

    /**
     * S03 - Barometric Pressure and outside temperature
     */
    #define S03t                3       // Temperature
    #define S03b                4       // Pressure
    #define pinS03sdl          A4       // analog data pin for SDL (data)
    #define pinS03scl          A5       // analog data pin for SCL (clock)
    unsigned long tS03;                 // last time loop fired
    #include "S03_Barometer.h"

    /**
     * S07 - Water temperature, a Dallas
     */
    #define S07                 5       // Water Temperature
    #define pinS07              4       // data pin
    unsigned long tS07;                 // last time loop fired
    #include "S07_WaterTemp.h"          // Water temperature sensor

    /**
     * S8 - UV receiver
     */
    #define S08                 6       // UV
    #define pinS08             A2       // data pin
    unsigned long tS08;                 // last time loop fired
    #include "S08_UV.h"                 // UV sensor

/**
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation() {
    sendSketchInfo(SN, SV);
    present(A01, S_BINARY, "BBQ Lights");           // V_STATUS
    present(A03, S_IR, "Poolside RGB Control");     // V_IR_SEND
    present(S03t, S_TEMP, "Poolside Temperature");  // V_TEMP
    present(S03b, S_BARO, "Poolside Barometer");    // V_PRESSURE
    present(S07, S_TEMP, "Pool Water Temperature"); // V_TEMP
    present(S08, S_UV, "Poolside UV sensor");       // V_UV
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")"); }
}

/**
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    setupRSSI();
    setupA01();
    setupA03();
    setupS03();
    setupS07();
    setupS08();
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")\n"); }
}

/**
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {
    loopRSSI(10*60);                    // report RSSI (if possible on NRF24)   
    loopS03(300);                       // every 5 minutes (300) seconds
    loopS07(300);
    loopS08(300);
}

/**
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA01(message);
    receiveA03(message);
}
