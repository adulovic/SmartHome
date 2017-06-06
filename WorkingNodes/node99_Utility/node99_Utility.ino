#define SN "Utility Board"              // short Sketch (Node) name
#define SV "1.1"                        // short Sketch (Node) version
#define MY_NODE_ID 99                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanation and inital variables
  #include "S4.h"
  #include "S16.h"                      /* IR rx */
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){ 
    sendSketchInfo(SN, SV);
        present(S4, S_BINARY, "PIR Switch");
        present(S16, S_IR, "IR rx Sensor");
    Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup(){
        setupS4();
        setupS16();
    Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop(){
    //Serial.print("S4 value is ");Serial.print(valueS4);
    //Serial.println();
        loopS4();
        loopS16();
    wait(1000); // no 1 second wait for this one !
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {
        //receiveA1(message);
}
