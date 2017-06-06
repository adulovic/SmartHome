#define SN "Radio Quality Tester"       // short Sketch (Node) name
#define SV "0.1"                        // short Sketch (Node) version
#define MY_NODE_ID 99                   // (1-254) to manually set Node ID
/*
    Includes
=========1=========2=========3=========4=========5=========6=========7========*/
#include "R.h"                          // NRF24L01 definitions
#include <MySensors.h>                  // MySensors library
#include "RQT.h"
/*
    Presentation
=========1=========2=========3=========4=========5=========6=========7========*/
void presentation(){
  sendSketchInfo(SN, SV);
    present(0, S_DIMMER,"Counter");             // present counter (use percentage from dimmer value)
  Serial.println((String)" === Node "+MY_NODE_ID+" presented ("+SN+")");
}
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setup() {
    for(int i= 0 ; i <  messageCounterMax ; i++){       // init stores for moving averages
        failStore[i] = true ;
        missedStore[i] = true ;
    }
    missedStorePointer = failStorePointer = 0 ;
    delay(1000);
  Serial.println((String)" === Node "+MY_NODE_ID+" setup ("+SN+")");
}
/* 
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loop() {
    Serial.print("count:") ; Serial.println(messageCounter) ;
    Serial.print("Parent: "); Serial.print(parent); Serial.print("       Fail "); Serial.print(failMessageCounter); Serial.print("   "); Serial.print(getCount(failStore, messageCounterMax)); Serial.println("%");
    Serial.print("Destination: "); Serial.print(DESTINATION_NODE); Serial.print("  Miss "); Serial.print(missedMessageCounter); Serial.print("   "); Serial.print(getCount(missedStore, messageCounterMax)); Serial.println("%");

    missedStore[failStorePointer] = false  ;            // set slot to false (ack message needs to set) ; 
    boolean succes = failStore[failStorePointer] = send(counterMsg.setDestination(DESTINATION_NODE).set(failStorePointer), true);  // send to destination with ack
    if (!succes){
        failMessageCounter++ ; 
        Serial.print("Fail on message: ") ; Serial.print(failStorePointer) ; Serial.print(" # ") ; Serial.println(failMessageCounter);
    }
    failStorePointer++ ;
    if(failStorePointer >= messageCounterMax){
        failStorePointer =  0   ;                       // wrap counter
    }
    parent = getParentNodeId();                         // get the parent node (0 = gateway)
    wait(counterUpdateDelay) ;                          // wait for things to settle and ack's to arrive
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receive(const MyMessage &message) {                // Expect few types of messages from controller
    newMessage = message.getInt();                      // get received value
    switch (message.type){
        case V_PERCENTAGE:
            missedStore[newMessage] = true ;            // set corresponding flag to received.
            if (newMessage > lastMessage){              // number of messages missed from lastMessage (kind of, faulty at wrap)
                Serial.print("Missed messages: ") ; Serial.println( newMessage - lastMessage - 1) ;
                missedMessageCounter += newMessage - lastMessage - 1 ;
            }
            lastMessage = newMessage ;
            break ;
        default: break ;
    }
    //Serial.println("=== Node message received === "); // Debug
}
