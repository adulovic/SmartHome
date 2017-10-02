/*
    VAC Sensor (ACS712)
	

*/

/* Initialize    
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS6W(S6, V_WATT);


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS6(){
    pinMode(pinS6, INPUT);
	stateS6 = analogRead(pinS6);
}


/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS6(){
	valueS6 = analogRead(pinS6);
	float Voltage = (valueS6 * 5.0 / 1024.0);					// 5 volts, 1024 values, should give 2.5v at no current
	float Amps = abs((Voltage - 2.5) * 1000 / mVperAmp);		// absolute value
	float Watts = 1 * Amps * 117.0;								// W = PF × A × V

	// printout
	//Serial.print("   V:"); Serial.print(Voltage);
	//Serial.print("  A:"); if(Amps>=0){Serial.print(" ");} Serial.print(Amps);
	//Serial.print("  W:"); if(Watts>=0){Serial.print(" ");} Serial.println(Watts);
	
	// send to mycontroller (only if changed significantly ?? )
	if ( Watts<40 ) {
		send(msgS6W.set(0));
	}
	else {
		send(msgS6W.set(Watts,2));
	}
}
 