/**
	Relay (2 channels)
 */

 
/**
	Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA01a( A01a, V_STATUS );
MyMessage msgA01b( A01b, V_STATUS );


/**
	Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA01ab(){
    pinMode(pinA01a, OUTPUT);           // set relay pin in output mode
    pinMode(pinA01b, OUTPUT);           // set relay pin in output mode
    //digitalWrite(pinA01a, loadState(A01a) ? 0 : 1); // load state from eeprom
    //digitalWrite(pinA01b, loadState(A01b) ? 0 : 1); // load state from eeprom
}


/**
	Loop
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to loop


/**
	Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA01ab(const MyMessage &message){
    if (message.type == V_STATUS) {
        if (message.sensor == A01a){
            digitalWrite(pinA01a, message.getBool() ? 0 : 1);   // Toggle relay state
			//saveState(A01a,message.getBool());					// save state to eeprom
            Serial.print(F("Toggle - New state of A01a is ")); Serial.println(message.getBool());
        }
        if (message.sensor == A01b){
            digitalWrite(pinA01b, message.getBool() ? 0 : 1);   // Toggle relay state
			//saveState(A01b,message.getBool());					// save state to eeprom
            Serial.print(F("Toggle - New state of A01b is ")); Serial.println(message.getBool());
        }
   } 
}
