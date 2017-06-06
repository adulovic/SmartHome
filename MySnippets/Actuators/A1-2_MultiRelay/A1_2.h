/*
    Multi Relay (2 channels)
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA12A( A12A, V_STATUS );
MyMessage msgA12B( A12B, V_STATUS );

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA12(){
    pinMode(pinA12A, OUTPUT);           // set relay pin in output mode
    stateA12A = request(A12A, V_STATUS);// get status from controller
    digitalWrite(pinA12A, stateA12A);   // turn the relay on/off based on state

    pinMode(pinA12B, OUTPUT);           // set relay pin in output mode
    stateA12B = request(A12B, V_STATUS);// get status from controller
    digitalWrite(pinA12B, stateA12B);   // turn the relay on/off based on state
}

/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA12(const MyMessage &message){
    if (message.type == V_STATUS) {
        if (message.sensor == A12A){
            digitalWrite(pinA12A, message.getBool() ? 0 : 1);     // Toggle relay state
            Serial.print("Toggle - New state of A12A is "); Serial.println(message.getBool());
        }
        if (message.sensor == A12B){
            digitalWrite(pinA12B, message.getBool() ? 0 : 1);     // Toggle relay state
            Serial.print("Toggle - New state of A12B is "); Serial.println(message.getBool());
        }
   } 
}
