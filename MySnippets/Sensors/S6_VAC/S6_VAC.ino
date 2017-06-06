#define SN "VAC Sensor"                 // short Sketch (Node) name
#define SV "0.0"                        // short Sketch (Node) version
#define MY_NODE_ID 99                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "def.h"                        // Explanation and inital variables
  #include "S6.h"                         // VAC Sensor

/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){
  sendSketchInfo(SN, SV);
    //present(S6, S_MULTIMETER, "VAC Sensor");
    present(S6, S_POWER, "VAC Sensor");
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    setupS6();
    Serial.print( " === Node " ); Serial.print(MY_NODE_ID);
    Serial.print(" setup === ");Serial.println(SN);
}


/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {
    loopS6();
    wait(1000);
}


/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to receive
