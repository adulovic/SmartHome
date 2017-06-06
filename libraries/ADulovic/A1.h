/*
    Single Relay
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA1(A1, V_STATUS);


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA1(){
	// set relay pin in output mode
    pinMode(pinA1, OUTPUT);
	// load state from eeprom
	digitalWrite(pinA1, loadState(A1));
}


/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA1(const MyMessage &message){
    if (message.type==V_STATUS) {
		// toggle relay state
		digitalWrite(pinA1,message.getBool());
		// save state to eeprom
		saveState(A1,message.getBool());
		// Printout
		Serial.println((String)"Toggle A1 relay. New state is "+message.getBool());
	}
}