/**
 *   Passive InfraRed Switch	
 */


/**
	Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS04(S04,V_TRIPPED);      	// type of message sent to MySensors


/**
	Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS04(){
	
    pinMode(pinS04,INPUT);						// initialize sensor as an input
    bool trippedS04 = request(S04,V_TRIPPED);	// get tripped state from controller
	bool armedS04 = request(S04, V_ARMED);		// get armed state from controller

	if (Printout==true) { Serial.print(F("     S04 --- PIR setup... Armed:")); Serial.print(armedS04); Serial.print(F(" Tripped:")); Serial.println(trippedS04);}
}


/**
	Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS04(uint16_t frequency){

	if ( !request(S04, V_ARMED) ) { return; }					// do not loop unless the sensor is armed
		
	if ( millis()/1000 >= (frequency + tS04) ) {
		tS04 = millis()/1000;									// set timer to now
		
		bool trippedS04 = digitalRead(pinS04);					// Read the PIR switch - returns 0 | 1

		if (trippedS04 != request(S04,V_TRIPPED)) {				// if different from controller state
			send(msgS04.set(trippedS04),true);					// send current state to controller
		}
		
		if (Printout==true) { Serial.print(millis()/1000); Serial.println(F("sec, S04 tripped state is: ")); Serial.println(trippedS04);}
	}
}


/**
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveS04(const MyMessage &message){
	
    if ( message.type == V_ARMED ) {
		if (Printout==true) {Serial.print(millis()/1000); Serial.print(F(" sec, S04 armed state is: "));Serial.println(message.getBool());}
	} 
}