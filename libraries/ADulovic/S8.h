/*
    UV Sensor

*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS8(S8, V_UV);    			// define type of message sent to MySensors

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS8(){
    pinMode(pinS8sdl, INPUT);           // initialize sensor as an input
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS8(){
	if( millis() - tS8 > iS8*1000 ) {
		tS8 = millis();        			// save the last time this fired
		valueS8 = analogRead(pinS8sdl);	// Get UV value
		if (valueS8>1170) {valueS8=1170;}
		Serial.print("UV Analog reading: "); Serial.println(valueS8);
		int i;
		for (i = 0; i < 12; i++){
			if (valueS8 <= uvIndexValue[i]){
				uvIndex = i;
				break;
			}
		}
		//calculate 1 decimal if possible
		if (i>0) {
			float vRange = uvIndexValue[i] - uvIndexValue[i-1];
			float vCalc = valueS8 - uvIndexValue[i-1];
			uvIndex+=(1.0/vRange)*vCalc-1.0;
		}
		Serial.print("UVI: "); Serial.println(uvIndex,2);
		send(msgS8.set(uvIndex,2));
	}
}

