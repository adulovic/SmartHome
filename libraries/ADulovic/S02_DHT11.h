/**
 * S02
 * DHT11 Sensor - Humidity and Temperature
 */


/**
	Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS02h(S02h, V_HUM);         // humidity sensor message
MyMessage msgS02t(S02t, V_TEMP);        // temperature sensor message

#include <DHT.h>
DHT dht;                           		// start the DHT sensor
bool metric = true;                     // use metric units


/**
	Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS02(){
	
	dht.setup(pinS02);
	if ( dht.getMinimumSamplingPeriod() ) {
		delay( 3 * dht.getMinimumSamplingPeriod() );		// Sleep the minimum sampling period to let the sensor power up 
	}
    if (Printout==true) {Serial.print(F("     S02 --- DHT11 setup --- Temperature:")); Serial.print(dht.getTemperature()); Serial.print(F(" - Humidity:")); Serial.println(dht.getHumidity());}
}


/**
	Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS02(uint16_t frequency) {

	if ( millis()/1000 >= (frequency + tS02) ) {
		tS02 = millis()/1000;									// set timer to now
        dht.readSensor(true);									// Force reading sensor, so it works also after sleep()
              
        // Temperature
		float S02_temperature_state = request(S02t,V_TEMP);		// get state from controller
        float S02_temperature = dht.getTemperature();			// read temperature from sensor

		if (Printout==true) { Serial.print(F(" comparing T ... ")); Serial.print(S02_temperature); Serial.print(F(" with ")); Serial.println(S02_temperature_state);  }

		if (S02_temperature != S02_temperature_state){			// if different from controller state
			send(msgS02t.set(S02_temperature, 1),true);			// send current state to controller
			if (Printout==true) {Serial.print(millis()/1000); Serial.print(F(" sec, DHT temperature is ")); Serial.print(S02_temperature); Serial.println(F(" °C"));}			
		}
        
        // Humidity
		float S02_humidity_state = request(S02h,V_HUM);			// get state from controller
        float S02_humidity = dht.getHumidity();					// read humidity from sensor

		if (Printout==true) { Serial.print(F(" comparing H ... ")); Serial.print(S02_humidity); Serial.print(F(" with ")); Serial.println(S02_humidity_state);  }

		if (S02_humidity != S02_humidity_state){				// if different from controller state
			send(msgS02h.set(S02_humidity, 1),true);			// send current state to controller
			if (Printout==true) {Serial.print(millis()/1000); Serial.print(F(" sec, DHT humidity is ")); Serial.print(S02_humidity); Serial.println(F(" °%"));}
		}
    }
}


/**
	Receive
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to receive
