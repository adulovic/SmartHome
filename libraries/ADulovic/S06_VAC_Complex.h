/*
    VAC Sensor (ACS712)
	
	http://arduinosensors.com/index.php/interfacing-a-hall-effect-current-sensor-with-an-arduino/

*/

/* Initialize    
=========1=========2=========3=========4=========5=========6=========7========*/
///MyMessage msgS06v(S06, V_VOLTAGE);
///MyMessage msgS06c(S06, V_CURRENT);
///MyMessage msgS06w(S06, V_WATT);


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS06(){
    pinMode(pinS06, INPUT);
	// header row printout
	Serial.print(" max |");Serial.print(" min |");Serial.print(" dif |");Serial.print(" avg |");
	Serial.print("   V  |");Serial.print("   A  |");Serial.print("   W  |");Serial.print(" rmsV |");Serial.print(" rmsA |");
}


/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS06(){
	int maxValue = 0;          			// store max value here
	int minValue = 1024;          		// store min value here
 	uint32_t start_time = millis();
	
	while((millis()-start_time) < 1000) {	//sample for 1 Sec
	   int readValue = analogRead(pinS06);
	   if (readValue > maxValue) {maxValue = readValue;}	// record the maximum sensor value
	   if (readValue < minValue) {minValue = readValue;}	// record the minimum sensor value
	}

	int diff = maxValue - minValue;
	int avg = minValue + (diff/2);			// the average reading between min/max values
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
	///send(msgS06v.set(Voltage,2));
	///send(msgS06c.set(Amps,2));
	///send(msgS06w.set(Watts,2));
}
 