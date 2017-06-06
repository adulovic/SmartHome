/*
    InfraRed Receiver
    
    - should display data when exposed to the light of a remote controller.
    
    G - ground
    R - VCC 3.3-5
    Y - data
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS16(S16, V_IR_RECEIVE);
IRrecv irrecv(pinS16);                  // create a receiver object
decode_results results;                 // decode the results 

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS16(){
    irrecv.enableIRIn();                // Start the receiver
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS16(){
    if (irrecv.decode(&results)){
        Serial.print("IR: "); Serial.println(results.value, HEX);
        send(msgS16.set(results.value));
        irrecv.resume();                // Receive the next value
    }
}

/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to receive