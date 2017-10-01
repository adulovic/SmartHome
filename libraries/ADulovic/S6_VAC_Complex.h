/*
    VAC Sensor (ACS712)
	
	http://arduinosensors.com/index.php/interfacing-a-hall-effect-current-sensor-with-an-arduino/

*/

/* Initialize    
=========1=========2=========3=========4=========5=========6=========7========*/
//MyMessage msgS6V(S6, V_VOLTAGE);
//MyMessage msgS6C(S6, V_CURRENT);
MyMessage msgS6W(S6, V_WATT);


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS6(){
    pinMode(pinS6, INPUT);
	// header row printout
	Serial.print(" max |");Serial.print(" min |");Serial.print(" dif |");Serial.print(" avg |");
	Serial.print("   V  |");Serial.print("   A  |");Serial.print("   W  |");Serial.print(" rmsV |");Serial.print(" rmsA |");
}


/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS6(){
	int maxValue = 0;          			// store max value here
	int minValue = 1024;          		// store min value here
 
	uint32_t start_time = millis();
	while((millis()-start_time) < 1000) {	//sample for 1 Sec
	   int readValue = analogRead(pinS6);
	   if (readValue > maxValue){maxValue = readValue;}		// record the maximum sensor value
	   if (readValue < minValue) {minValue = readValue;}	// record the minimum sensor value
	}

	int diff = maxValue - minValue;
	int avg = minValue + (diff/2);		// the average reading
	float Voltage = (avg * 5.0 / 1024.0);	// 5 volts, 1024 values, should give 2.5v at no current

	if (diff>50){
		Voltage = (maxValue * 5.0 / 1024.0);
	}
	
	float Amps = (Voltage - 2.5) * 1000 / mVperAmp;
	float Watts = 1 * Amps * 117.0;			// W = PF × A × V
	// RMS (root mean square))
	float RMSvoltage = Voltage / 1.414213562373095;  // root of 2
	float RMSamps = RMSvoltage * 1000 / mVperAmp;

	// printout
	Serial.print(" "); Serial.print(maxValue);
	Serial.print("   "); Serial.print(minValue);
	Serial.print("    "); Serial.print(diff);
	Serial.print("   "); Serial.print(avg);
	Serial.print("   "); Serial.print(Voltage);
	Serial.print("  "); if(Amps>=0){Serial.print(" ");} Serial.print(Amps);
	Serial.print("  "); if(Watts>=0){Serial.print(" ");} Serial.print(Watts);
	Serial.print("   "); Serial.print(RMSvoltage);
	Serial.print("  "); if(RMSamps>=0){Serial.print(" ");} Serial.println(RMSamps);
	
	// send to mycontroller
	// (only if changed significantly)
	//send(msgS6V.set(Voltage,2));
	//send(msgS6C.set(Amps,2));
	send(msgS6W.set(Watts,2));
}
 