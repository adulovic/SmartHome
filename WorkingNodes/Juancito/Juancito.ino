#define MY_CORE_ONLY        // load core modules only
/**
 * Test for intrusion detection
 * 
=========1=========2=========3=========4=========5=========6=========7========*/
#define MY_NODE_ID 88                   // (1-254) to manually set Node ID
#define SN "Test intrusion Detection"   // short Sketch (Node) name
#define SV "0.171001"                   // short Sketch (Node) version
#define Loop 500                        // loop interval
/**
 * Library Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library

/**
 * Sensors and Activators
=========1=========2=========3=========4=========5=========6=========7========*/

/* S04 - Passive InfraRed  */
#define S04                 1       // Sensor number
const int pinS04 =          2;      // Data pin
int valueS04 =              0;      // Reading the current status
int stateS04 =              0;      // Storing the last status
unsigned long timerS04 =    0;      // Timer for storing when fired
unsigned long rearmS04 =   30;      // How long before rearming PIR
MyMessage msgS04(S04, V_TRIPPED);   // type of message sent to MySensors

/* S13 - Ultrasonic */
#define S13                 2       // Sensor number
const int pinS13E =         3;      // Data pin
const int pinS13T =         4;      // Data pin
float durationS13 =         0;      // Duration of ping
float valueS13 =            0;      // The distance in mm
float stateS13 =            0;      // Storing the last distance
int inactiveS13 =           0;      // inactivity switch
unsigned long timerS13 =    0;      // Timer for storing when fired
unsigned long rearmS13 =   30;      // How long before rearming Ultrasonic
MyMessage msgS13(S13, V_TRIPPED);   // type of message sent to MySensors

/* S20 - Hall Effect */
#define S20                 3       // Sensor number
const int pinS20 =          5;      // Data pin
int valueS20 =              0;      // reading the sensor status
int stateS20 =              0;      // storing the last status

/**
 * Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
    
    // Present the node
    sendSketchInfo(SN, SV);
    
    // Present the Sensors
    present(S04, S_MOTION, "PIR");
    present(S13, S_DISTANCE, "Ultrasonic Distance");
    ////present(S20, S_HALL, "Hall Effect");
    
    // Debug Printout
    Serial.println((String)"\n === Node "+MY_NODE_ID+" was presented ("+SN+")\n");
}

/**
 * Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
    Serial.begin(MY_BAUD_RATE);
    
    /* S04 - Passive InfraRed  */
    if (S04){
        // initialize sensor as an input
        pinMode(pinS04, INPUT);
        // get status from controller        stateS04 = request(S04, V_TRIPPED);  
        // set status based on controller state        digitalWrite(pinS04, stateS04);
    }
    
    /* S13 - Ultrasonic */
    if (S13){
        // initialize inputs and outputs
        pinMode(pinS13T, OUTPUT);
        pinMode(pinS13E, INPUT);
    }

    /* S20 - Hall Effect */
    if (S20){
        // initialize sensor as an input
        pinMode(pinS20, INPUT);        
    }
    
    // Debug Printout
    Serial.println((String)"\n === Setup of Node "+MY_NODE_ID+" ("+SN+") was completed!\n");//*/
}

/**
 * Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){

    delay(Loop);
    /*/ Debug Printout
    Serial.println((String)"- Looping every " + Loop + "ms: ");//*/

    /* S04 - Passive InfraRed  */
    if (S04){
        // Read the state of the switch
        valueS04 = digitalRead(pinS04);

        // If value is different from last state
        if (valueS04 != stateS04) {
            // if motion was detected
            if (valueS04 == 1){
                // time when motion was detected
                timerS04 = millis();
                // Debug Printout
                Serial.println((String)"### PIR Motion was detected at "+ timerS04 +" ### ");//*/
                // set state to on
                stateS04 = valueS04;
            }
            // if motion is no longer detected, rearm
            else if (valueS04 == 0 && (millis()-timerS04)/1000 >= rearmS04 ){
                // set state to off
                stateS04 = valueS04;
                // Debug Printout
                Serial.println((String)"--- Rearming PIR after "+ rearmS04 + " seconds ---");//*/
            }
        }
        
        /*/ Debug Printout
        Serial.println((String)"Sensor S04 on pin " + pinS04 + " reads "+ valueS04 +" and stores " + stateS04 + " at " + millis() );//*/
    }

    /* S13 - Ultrasonic */
    if (S13){       
        // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
        // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
        digitalWrite(pinS13T, LOW);   delayMicroseconds(5);
        digitalWrite(pinS13T, HIGH);  delayMicroseconds(10);
        digitalWrite(pinS13T, LOW);
        
        // Read the signal from the sensor
        // a HIGH pulse whose duration is the time (in microseconds) from the 
        // sending of the ping to the reception of its echo off an object.
        durationS13 = pulseIn(pinS13E, HIGH);
        /*/ Debug Printout
        Serial.println((String)"Ping duration is:" + durationS13 );//*/
        
        // convert the ping duration time into a distance
        valueS13 = durationS13 / 2 / 2.91;
       
        // rearming
        if ( inactiveS13 == 1 && millis()-timerS13 >= rearmS13*1000 ){
            inactiveS13 = 0;
            // Debug Printout
            Serial.println((String)"--- Rearming UltSon after "+ rearmS13 + " seconds ---");//*/
        }

        // If value is different from last state
        if ( inactiveS13 == 0 && round(valueS13/50) != round(stateS13/50) ) {
            // if state is not set
            if (stateS13 == 0 ){
                // set state value
                stateS13 = valueS13;
                // activate sensor
                inactiveS13 = 0;
                // Debug Printout
                Serial.println((String)"### Setting initial UltSon state to "+stateS13+" ###");//*/
            }
            // if motion was detected
            else {
                // time when motion was detected
                timerS13 = millis();
                // set state value
                stateS13 = valueS13;
                // deactivate
                inactiveS13 = 1;
                /*/ Debug Printout
                Serial.println((String)"V: " + valueS13 + " S:" + stateS13 + " rounded V: " + round(valueS13/50) + " rounded S:" + round(stateS13/50));//*/
                // Debug Printout
                Serial.println((String)"### UltSon Motion was detected at "+ timerS13 +" ### ");
            }

            /*/ Debug Printout
            Serial.println((String)"millis: " + millis() + " timer:" + timerS13 + " rearm: " + rearmS13);//*/
        }

        /*/ Debug Printout
        Serial.println((String)"Distance is " + valueS13 + "mm and last state is " + stateS13);//*/
    }
    
    /* S20 - Hall Effect */
    if (S20){
        
    }

}
