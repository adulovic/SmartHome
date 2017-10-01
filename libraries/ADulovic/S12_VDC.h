/*
    Battery sensor

	https://www.mysensors.org/build/battery
	https://startingelectronics.org/articles/arduino/measuring-voltage-with-arduino/
	http://www.electroschematics.com/9351/arduino-digital-voltmeter/
	
	Vout = Vin * (R2/(R1+R2))
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS12(S12, V_VOLTAGE);   // define type of message sent to MySensors

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS12(){
    #if defined(__AVR_ATmega2560__)     // use the 1.1 V internal reference
		Serial.println("Using 1.1V internal reference");
        analogReference(INTERNAL1V1);
    #else
		Serial.println("NOT using 1.1V internal reference");
        analogReference(INTERNAL);
    #endif
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS12(){
    voltageS12 = analogRead(pinS12);    		// get the RAW voltage data
	Serial.print("RAW Voltage: "); Serial.print(voltageS12); Serial.println("");
	
    voltageS12 = (voltageS12/1024) * 5; 		// convert to actual voltage
	Serial.print("Actual Voltage: "); Serial.print(voltageS12); Serial.println(" V");
	
	voltageS12 = voltageS12/dividerS12; 		// convert to voltage before divider
	Serial.print("divider: "); Serial.print(dividerS12); Serial.println(" V");
    Serial.print("Battery Voltage: "); Serial.print(voltageS12); Serial.println(" V");
	
	Serial.print("Sending to controller: "); Serial.print(voltageS12,2); Serial.println(" V");
	send(msgS12.set(voltageS12,2));      		// send to controller, with 2 decimals
	
	Serial.println(" ");
}
