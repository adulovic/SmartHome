/**
 * S01 
 * Reed Switch
 * 
 * Notes:
 *	- 	Since one end of the reed switch is connected to ground, we need to pull-up the reed switch pin internally
 *	- 	Use Arduino’s internal pull-up resistor to bias the switch high
 *	- 	This effectively inverts the behavior of the INPUT mode, where HIGH means the sensor is off, and LOW means the sensor is on.
 */


/**
	Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS01(S01,V_TRIPPED);		// type of message sent to MySensors


/**
	Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS01(){
	
    pinMode(pinS01,INPUT_PULLUP);				// pull-up the pin internally
	
    trippedS01 = request(S01,V_TRIPPED);		// get tripped state from controller
	armedS01 = request(S01, V_ARMED);			// get armed state from controller

	if (Printout==true) { Serial.print(F("     S01 --- Reed setup --- Armed:")); Serial.print(armedS01); Serial.print(F(" - Tripped:")); Serial.println(trippedS01);}
}


/**
	Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS01(uint16_t frequency){

	if ( armedS01 == false ) { return; }						// do not loop unless the sensor is armed

	if ( millis()/1000 >= (frequency + tS01) ) {
		tS01 = millis()/1000;									// set timer to now
		
		bool trippedS01_state = request(S01,V_TRIPPED);			// get state from controller
		trippedS01 = digitalRead(pinS01);						// read the sensor - returns 0|1
	
		if (trippedS01 != trippedS01_state ) {					// if different from controller state
			send(msgS01.set(trippedS01),true);					// send current state to controller
		}

		if (Printout==true) { Serial.print(millis()/1000); Serial.println(F("sec, S01 tripped state is: ")); Serial.println(trippedS01);}
    }
}


/**
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveS01(const MyMessage &message){
	
    if ( message.type == V_ARMED ) {
		armedS01 = message.getBool();
		if (Printout==true) { Serial.print(millis()/1000); Serial.print(F(" sec, S01 armed state is: "));Serial.println(armedS01); }
	} 
}