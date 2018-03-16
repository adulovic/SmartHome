/**
    Water Temperature

		- Vktech DS18b20 Waterproof Temperature Sensors

		- You will need a pull-up resistor of about 5 KOhm between the 1-Wire data line and your 5V power.
		- If you are using the DS18B20, ground pins 1 and 3. The centre pin is the data line '1-wire'.

*/


/**
	Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS07(S07, V_TEMP);

#include <OneWire.h>
#include <DallasTemperature.h>
OneWire oneWire(pinS07);														// Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire);											// Pass our oneWire reference to Dallas Temperature.


/**
	Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS07(){
    pinMode(pinS07, INPUT_PULLUP);      										// initialize sensor as an pullup input
    sensors.begin();                   											// Start up the library
    if (Printout==true) {Serial.print(F("     S07 --- DallasTemperature found ")); Serial.print(sensors.getDeviceCount()); Serial.println(F(" devices."));}
}


/**
	Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS07(uint16_t frequency){
	
	if ( millis()/1000 >= (frequency) + tS07 ) {
        // set timer to now
		tS07 = millis()/1000;													// save the last time this fired
		sensors.requestTemperatures();  										// Send the command to get temperature(s) from the sensor(s)
		
		if (Printout==true) {Serial.print(millis()/1000); Serial.print(F(" sec, Temperature for waterproof sensor is: ")); Serial.println(sensors.getTempCByIndex(0)); }
		send(msgS07.set( sensors.getTempCByIndex(0),2 ));
	}
}
