/*
    Water Temperature

		- Vktech DS18b20 Waterproof Temperature Sensors

		- You will need a pull-up resistor of about 5 KOhm between the 1-Wire data line and your 5V power.
		- If you are using the DS18B20, ground pins 1 and 3. The centre pin is the data line '1-wire'.

*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS7(S7, V_TEMP);
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(pinS7);																											// Setup a oneWire instance to communicate with any OneWire devices

DallasTemperature sensors(&oneWire);																					// Pass our oneWire reference to Dallas Temperature.

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS7(){
	Serial.begin(9600); 			//Begin serial communication at 9600
    pinMode(pinS7, INPUT);      																						// initialize sensor as an pullup input
    sensors.begin();                   																			// Start up the library
    Serial.print("Found "); Serial.print(sensors.getDeviceCount()); Serial.println(" devices.");
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS7(){
	if( millis() - tS7 > iS7*1000 ) {
		tS7 = millis();        																									// save the last time this fired
		sensors.requestTemperatures();  																				// Send the command to get temperatures
		Serial.print("Temperature for waterproof sensor (0) is: ");
		Serial.println(sensors.getTempCByIndex(0));															// 0 refers to the first IC on the wire
		send(msgS7.set( sensors.getTempCByIndex(0),2 ));
	}
}
