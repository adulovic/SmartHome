/*
    Multi Relay actuator (4 channels)
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA14A( A14A, V_STATUS );
MyMessage msgA14B( A14B, V_STATUS );
MyMessage msgA14C( A14C, V_STATUS );
MyMessage msgA14D( A14D, V_STATUS );

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA14(){
    pinMode(pinA14A, OUTPUT);           // set relay pin in output mode
    digitalWrite(pinA14A, loadState(A14A) ? 0 : 1); // load state from eeprom

    pinMode(pinA14B, OUTPUT);           // set relay pin in output mode
    digitalWrite(pinA14B, loadState(A14B) ? 0 : 1); // load state from eeprom

    pinMode(pinA14C, OUTPUT);           // set relay pin in output mode
    digitalWrite(pinA14C, loadState(A14C) ? 0 : 1); // load state from eeprom

    pinMode(pinA14D, OUTPUT);           // set relay pin in output mode
    digitalWrite(pinA14D, loadState(A14D) ? 0 : 1); // load state from eeprom
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA14(const MyMessage &message){
    if (message.type == V_STATUS) {
        if (message.sensor == A14A){
            digitalWrite(pinA14A, message.getBool() ? 0 : 1);	// Toggle relay state
			saveState(A14A,message.getBool());					// save state to eeprom
            Serial.print("Toggle - New state is of A14A is "); Serial.println(message.getBool());
        }
        if (message.sensor == A14B){
            digitalWrite(pinA14B, message.getBool() ? 0 : 1);   // Toggle relay state
			saveState(A14B,message.getBool());					// save state to eeprom
            Serial.print("Toggle - New state is of A14B is "); Serial.println(message.getBool());
        }
        if (message.sensor == A14C){
            digitalWrite(pinA14C, message.getBool() ? 0 : 1);   // Toggle relay state
			saveState(A14C,message.getBool());					// save state to eeprom
            Serial.print("Toggle - New state is of A14C is "); Serial.println(message.getBool());
        }
        if (message.sensor == A14D){
            digitalWrite(pinA14D, message.getBool() ? 0 : 1);   // Toggle relay state
			saveState(A14D,message.getBool());					// save state to eeprom
            Serial.print("Toggle - New state is of A14D is "); Serial.println(message.getBool());
        }
    } 
}
