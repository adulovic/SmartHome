/*
    Single Relay
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA1(A1, V_STATUS);


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA1(){
    pinMode(pinA1, OUTPUT);             // set relay pin in output mode
    stateA1 = request(A1, V_STATUS);    // get status from controller
    digitalWrite(pinA1, stateA1);       // turn the relay on/off based on state
}


/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA1(const MyMessage &message){
    if (message.type==V_STATUS) {
        digitalWrite(pinA1, message.getBool() ? 1 : 0);     // Toggle relay state
        //EEPROM.write(A1, message.getBool());                // save state
        Serial.print("Toggle relay. New state is "); Serial.println(message.getBool());
    }
}
