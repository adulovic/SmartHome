/**
    Barometric Pressure Sensor
	BMP085
	
	VCC (5.0)
	GND
	SCL
	SDA
	3.3
*/


/**
	Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS03t(S03t, V_TEMP);
MyMessage msgS03b(S03b, V_PRESSURE);

#include <Wire.h>
#include "Adafruit_BMP085.h"
Adafruit_BMP085 bmp;


/**
	Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS03(){
    if ( bmp.begin(3) ) {
        if (Printout==true) {Serial.println(F("     S03 --- BMP085 setup." ));}
    } else {
        if (Printout==true) {Serial.println(F(" ⚠  S03 --- BMP085 has a problem!" ));}
    }
}


/**
	Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS03(uint16_t frequency){
	
	if ( millis()/1000 >= (frequency) + tS03 ) {
        
		tS03 = millis()/1000;									// set timer to now
		
        // Temperature
		float S03_temperature_state = request(S03t,V_TEMP);		// get state from controller
        float S03_temperature = bmp.readTemperature();			// read temperature from sensor
		if (S03_temperature != S03_temperature_state){			// if different from controller state
			send(msgS03t.set(S03_temperature,1),true);			// send current state to controller
			if (Printout==true) {Serial.print(millis()/1000); Serial.print(F(" sec, BMP Temperature is ")); Serial.print(S03_temperature); Serial.println(F(" C"));}
		}
		// Pressure
		float S03_pressure_state = request(S03b, V_PRESSURE);	// get state from controller
        float S03_pressure = bmp.readPressure()/100;			// read pressure from sensor
		if (S03_pressure != S03_pressure_state){				// if different from controller state
			send(msgS03b.set( S03_pressure,2 ),true);			// send current state to controller
			if (Printout==true) {Serial.print(millis()/1000); Serial.print(F(" sec, BMP Pressure is ")); Serial.print(S03_pressure); Serial.println(F(" Pa\n"));}
		}
	}
}
