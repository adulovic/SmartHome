/*
    Multi Relay (2 channels)
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA12A( A12A, V_STATUS );
MyMessage msgA12B( A12B, V_STATUS );

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA1_2(){
    pinMode(pinA12A, OUTPUT);           // set relay pin in output mode
    digitalWrite(pinA12A, loadState(A12A) ? 0 : 1); // load state from eeprom
	
    pinMode(pinA12B, OUTPUT);           // set relay pin in output mode
    digitalWrite(pinA12B, loadState(A12B) ? 0 : 1); // load state from eeprom
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA1_2(const MyMessage &message){
    if (message.type == V_STATUS) {
        if (message.sensor == A12A){
            digitalWrite(pinA12A, message.getBool() ? 0 : 1);   // Toggle relay state
			saveState(A12A,message.getBool());					// save state to eeprom
            Serial.print("Toggle - New state of A12A is "); Serial.println(message.getBool());
        }
        if (message.sensor == A12B){
            digitalWrite(pinA12B, message.getBool() ? 0 : 1);   // Toggle relay state
			saveState(A12B,message.getBool());					// save state to eeprom
            Serial.print("Toggle - New state of A12B is "); Serial.println(message.getBool());
        }
   } 
}
