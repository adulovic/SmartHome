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
		Serial.println("   Using 1.1V internal reference");
        analogReference(INTERNAL1V1);
    #else
		Serial.println("   NOT using 1.1V internal reference");
        analogReference(INTERNAL);
    #endif
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS12(unsigned int frequency){
	
    if ( frequency > S12_Counter ){
        S12_Counter++;
    }
    else if ( frequency == S12_Counter ){
        S12_Counter = 0;
		Serial.println((String)"divider: " + S12_divider);
		
		S12_SensorValue = analogRead(pinS12);    		// get the RAW sensor data
		Serial.println((String)"RAW Sensor Value: " + S12_SensorValue);

        S12_Voltage = S12_SensorValue * 14 / 1024 ;
		Serial.println((String)"Battery Voltage: "+ S12_Voltage + " V");

        S12_Percent = S12_Voltage / 14 * 100 ;
		
		Serial.println((String)"Sending to controller: " + S12_Voltage + " V");
		send(msgS12.set(S12_Voltage,2));      		// send to controller, with 2 decimals
		
		Serial.println(" ");
	}
}
