/* 
    Passive Buzzer
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA5(A5, V_STATUS);          // define type of message sent to MySensors
#include "Music.h"                      // the notes & durations

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA5(){
    pinMode(pinA5, OUTPUT);             // initialize sensor as an output
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopA5(){
    // nothing to loop
}

/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA5(const MyMessage &message){
    if (message.type==V_STATUS) {
        Serial.println("message received");
        ImperialMarch();
    }
}
