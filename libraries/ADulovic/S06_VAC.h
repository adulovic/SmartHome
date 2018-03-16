/*
    VAC Sensor (ACS712)
*/

#include <Filters.h>


/* Initialize    
=========1=========2=========3=========4=========5=========6=========7========*/
///MyMessage msgS06s(S06s, V_STATUS);
MyMessage msgS06(S06, V_WATT);


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS06(){
    pinMode(pinS06, INPUT);
}


/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS06(unsigned long printPeriod){

	const float testFrequency = 60;     			// test signal frequency (Hz)
	const float intercept = -0.2650;     			// -0.1129 to be adjusted based on calibration testing
	const float slope = 0.0580;         			// 0.0405 to be adjusted based on calibration testing

	RunningStatistics inputStats;       			// create statistics to look at the raw test signal
	inputStats.setWindowSecs( 60/testFrequency );	// how long to average the signal (1 second)

	int valueS06 = analogRead(pinS06);       		// read the analog in value:
	inputStats.input(valueS06);              		// log to Stats function

	//*/ debug
	if( (unsigned long)(millis() - tS06) >= printPeriod * 1000 ) {
		tS06 = millis();   						// update time
		float current_amps = intercept + slope * inputStats.sigma();		// convert signal sigma value to current in amps
		float current_watts = current_amps * 117.5;							// convert signal sigma value to
		
		//*/ debug
		Serial.println( "" );
		Serial.print( "\traw: " ); Serial.print( valueS06 );	// output sigma (variation values)
		Serial.print( "\tsigma: " ); Serial.print( inputStats.sigma() );	// output sigma (variation values)
		Serial.print( "\tamps: " ); Serial.print( current_amps );			// output calculated current amps
		Serial.print( "\twatts: " ); Serial.print( current_watts );			// output calculated current watts (W = PF × A × V)
		//*/

		// send to mycontroller (ON or OFF)
		if (current_amps > 0.10){
			stateS06=1;
			Serial.println(F("AC is ON"));
			///send(msgS06s.set(1));
			send(msgS06.set(current_watts,1));
		} else if (stateS06==1) {
			stateS06=0;
			Serial.println(F("AC is OFF"));	
			///send(msgS06s.set(0));
			send(msgS06.set(0));
		}
	}
}
 