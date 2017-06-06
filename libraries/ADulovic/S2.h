/* 
    DHT Sensor - Humidity and Temperature

*/


/*  LIBRARIES
=========1=========2=========3=========4=========5=========6=========7========*/
#include <DHT.h>                        // include the DHT 11 library


/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS2H(S2H, V_HUM);           // humidity sensor message
MyMessage msgS2T(S2T, V_TEMP);          // temperature sensor message
DHT dht;                                // start the DHT sensor
bool metric = true;                     // use metric units

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS2(){
    dht.setup(pinS2);                  // set data pin of DHT sensor

    // Sleep for the time of the minimum sampling period to give the sensor time to power up 
    wait( 3 * dht.getMinimumSamplingPeriod() );
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS2() {
	if( millis() - tS2 > iS2*60*1000 ) {
		tS2 = millis();							// update when the last reading was made
		dht.readSensor(true);					// Force reading sensor, so it works also after sleep()
		float valueS2T = dht.getTemperature();	// Get temperature from DHT library
		float valueS2H = dht.getHumidity();		// Get humidity from DHT library
		if (valueS2T != stateS2T) { 			// Only send temperature if it changed
			stateS2T = valueS2T;
			send(msgS2T.set(valueS2T, 1));
		}
		if (valueS2H != stateS2H) { 			// Only send humidity if it changed
			stateS2H = valueS2H;
			send(msgS2H.set(valueS2H, 1));
		}
	}
}
