/**
 * Battery Sensor
 * 
 * made from script found at
 * http://www.mysensors.org/build/battery
 * 
 * for a rechargable 9V battery 
 * https://www.amazon.com/dp/B06XD4Z5RS
 * 
 * 2 x 10k voltage divider across battery
 * http://www.ohmslawcalculator.com/voltage-divider-calculator
 */

const uint8_t BATT_pin = A0;     		// analog pin

unsigned long BATT_timer;               // last time loop fired

uint8_t BATT_percent = 100;				// default value

/**
   Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupBATT () {
    pinMode(BATT_pin, INPUT);         	// initialize inputs and outputs   
}

/**
   Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopBATT(uint16_t frequency) {
	if ( millis()/1000 >= (frequency + BATT_timer) ) {
        
		BATT_timer = millis()/1000;								// set timer to now
		
        uint16_t battery_SensorValue = analogRead(BATT_pin);                                // read the sensor, returns 0-1023
		if (Printout==true) {Serial.println( battery_SensorValue ); }
        float battery_NominalVoltage = 9.96;                                                // for the 9v rechargable battery
        float battery_Voltage = battery_SensorValue * battery_NominalVoltage / 1024 ;       // 0-9.5
        uint8_t BATT_percent = battery_Voltage / 9.5 * 100 ;                             	// 0-100
		
		sendBatteryLevel(BATT_percent,true);					// send the message
	}
}