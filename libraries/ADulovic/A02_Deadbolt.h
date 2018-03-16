/**
    Electronic Deadbolt control
	
	- setting A low and B high will operate the lock's motor in one direction
	  setting B low and A hight will operate the motor in the opposite direction
	- the power to both needs to cut off after x seconds, leaving them both low
	- I really just need to unlock, as it should lock itself in 30 seconds
	- how to get the status ?
	- Needs an H bridge circuit, like for remote controlled cars ?
	- RFID card some day ?
	- will 5V be enough to operate ?
*/


/**
	Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA02(A02, V_LOCK_STATUS);			// type of message sent to MySensors


/**
	Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA02(){
	pinMode(pinA02L, OUTPUT);							// set pin to output mode
	pinMode(pinA02U, OUTPUT);		 					// set pin to output mode
}


/**
	Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopA02(){
	// nothing to loop
}

/**
	Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA02(const MyMessage &message){
	if (message.type==V_LOCK_STATUS) {
        if (Printout==true) {Serial.print("Received message: "); Serial.println(message.getInt());}
		if (message.getInt() == 1){
            if (Printout==true) {Serial.println("Lock Requested");}
            digitalWrite(pinA02L, HIGH);
            digitalWrite(pinA02U, LOW);
            delay(1000);
            digitalWrite(pinA02L, LOW);
		} else if (message.getInt() == 0){
            if (Printout==true) {Serial.println("Unlock Requested");}
            digitalWrite(pinA02U, HIGH);
            digitalWrite(pinA02L, LOW);
            delay(1000);
            digitalWrite(pinA02U, LOW);
        }
    }
}
