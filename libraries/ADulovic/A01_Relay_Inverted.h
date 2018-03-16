/**
 *	A01
 *	Single Relay - INVERTED VERSION
 * 
 *	53x18x18.5mm
 *	Case A: https://www.tinkercad.com/things/hoQyeAjUAXz-single-relay-case
 */


/**
	Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA01(A01, V_STATUS);          // type of message sent to MySensors


/**
	Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA01(){
    // set relay pin in output mode
    pinMode(pinA01, OUTPUT);
    
	// load status from Controller
	stateA01 = request(A01, V_STATUS);
	// switch on or off based on status
	digitalWrite( pinA01, stateA01);
	if (Printout==true) {Serial.print(F("     A01 --- Relay status from controller: "));Serial.println(stateA01);}
}


/**
	Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopA01(){
	
	#if defined(A01_manual)										// If wall/manual switch is on/off, use that value	
		bool A01_manual_value = digitalRead(pinA01_manual);		// Read the Manual switch - returns 0 | 1
		if (A01_manual_value==1){								
			digitalWrite( pinA01, A01_manual_value );			// toggle relay status
			return;
		}
	#endif
}


/**
	Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA01(const MyMessage &message){
    
    if ( message.type == V_STATUS ) {
        digitalWrite( pinA01, message.getBool() ? 0 : 1 );		// switch on or off based on message
		if (Printout==true) {Serial.print(millis()/1000); Serial.print(F(" sec, A01 received message, new status is: "));Serial.println(message.getBool());}
    }
}