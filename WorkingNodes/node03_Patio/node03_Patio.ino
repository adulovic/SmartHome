/**
    Sketch Information
=========1=========2=========3=========4=========5=========6=========7========*/
#define SN "Patio"                      // short Sketch (Node) name
#define SV "1.1 17-12-12"               // short Sketch (Node) version
#define MY_NODE_ID 3                    // (1-254) to manually set Node ID
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
     * A01 - Relay, patio spotlight
     */
    #define A01                 1
    #define pinA01              2          
    bool stateA01;
    #include "A01_Relay_Inverted.h"
    
    /**
     * S02 - DHT 11
     */
    #define S02t                2       // Temperature
    #define S02h                3       // Humidity
    #define pinS02              3       // The pin for DHT data 
    float stateS02h;                    // last saved humidity value
    float stateS02t;                    // last saved temperature value
    unsigned long tS02;                 // last time loop fired
    #include "S02_DHT11.h"

/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
    sendSketchInfo(SN, SV);
    present(A01, S_BINARY,"Patio Spotlight");
    present(S02t, S_TEMP,"Patio Temperature");
    present(S02h, S_HUM,"Patio Humidity");
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")"); }
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    setupA01();
    setupS02();
    if (Printout==true) {Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")"); }
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    loopS02(5*60);                      // every 5 minutes (300) seconds
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
    receiveA01(message);
}
