/**
 * Test for intrusion detection
 * 
=========1=========2=========3=========4=========5=========6=========7========*/
#define MY_NODE_ID 88                   // (1-254) to manually set Node ID
#define SN "Test intrusion Detection"   // short Sketch (Node) name
#define SV "0.171001"                   // short Sketch (Node) version

/**
 * Library Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library

/**
 * Sensors and Activators
=========1=========2=========3=========4=========5=========6=========7========*/

/**
 * S04 - Passive InfraRed
 */
#define S04                 1       // Sensor number
const int pinS04 =          2;      // Data pin
int valueS04 =              0;      // Reading the current status
int stateS04 =              0;      // Storing the last status
float timerS04 =            0;      // Timer
MyMessage msgS04(S04, V_TRIPPED);   // type of message sent to MySensors

/**
 * S13 - Ultrasonic
 */
#define S13                 2       // Sensor number
const int pinS13E =         3;      // Data pin
const int pinS13T =         4;      // Data pin
float valueS13 =            0;      // Reading the current status
float stateS13 =            0;      // Storing the last status
float durationS13 =         0;      // Duration of ping
MyMessage msgS13(S13, V_DISTANCE);  // type of message sent to MySensors

/**
 * S20 - Hall Effect
 */
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
    Serial.println((String)"\n === Node "+MY_NODE_ID+" presented ("+SN+")\n");
}

/**
 * Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){

    if (S04){
        // initialize sensor as an input
        pinMode(pinS04, INPUT);
        // get status from controller
        ////stateS04 = request(S04, V_TRIPPED);  
        // set status based on controller state
        ////digitalWrite(pinS04, stateS04);
    }
    
    if (S13){
        // initialize inputs and outputs
        pinMode(pinS13T, OUTPUT);
        pinMode(pinS13E, INPUT);
    }
    
    // Debug Printout
    Serial.println((String)"\n === Node "+MY_NODE_ID+" setup ("+SN+")\n");
}

/**
 * Loop ... once a second only
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){

    if (S04){
        // Read the state of the switch
        valueS04 = digitalRead(pinS04);
        // If different from last state
        if (valueS04 != stateS04) {
            // Pin reads low
            if (valueS04 == 0){
                // Debug Printout
                Serial.println((String)"- Standing down after "+ ((millis()-timerS04)/1000) + " seconds");
            } else 
            if (valueS04 == 1){
                // time when loop fired (for calibrating the timer)
                timerS04 = millis();
                // Debug Printout
                Serial.println("--- Motion detected! --- ");
            }
            // send to controller
            send(msgS04.set(valueS04));
            // update state
            stateS04 = valueS04;
            // wait 2 seconds so it doesn't bounce
            wait(2000);
        }
    }

    if (S13){
        // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
        // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
        digitalWrite(pinS13T, LOW);   delayMicroseconds(5);
        digitalWrite(pinS13T, HIGH);  delayMicroseconds(10);
        digitalWrite(pinS13T, LOW);

        // Read the signal from the sensor
        // a HIGH pulse whose duration is the time (in microseconds) from the 
        // sending of the ping to the reception of its echo off an object.
        pinMode(pinS13E, INPUT);
        durationS13 = pulseIn(pinS13E, HIGH);
        // convert the time into a distance
        float cm = (durationS13/2) / 29.1;
        float inches = (durationS13/2) / 74; 

        Serial.print(inches); Serial.print("in, "); Serial.print(cm); Serial.print("cm"); Serial.println();
        delay(250);
    }
    
    // loop once per second only
    wait(1000);
}
