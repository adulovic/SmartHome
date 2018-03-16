/**
    UV Sensor
	
	Guva-s12sd
*/


/**
	Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS08(S08, V_UV);


/**
	Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS08(){
    pinMode(pinS08, INPUT);
	if (Printout==true) {Serial.println(F("     S08 --- UV sensor setup. "));}
}


/**
	Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS08(uint16_t frequency){

    float uvIndex = 0;
    uint16_t uvIndexValue [12] = { 50, 227, 318, 408, 503, 606, 696, 795, 881, 976, 1079, 1170};
	
	if ( millis()/1000 >= (frequency) + tS08 ) {
        // set timer to now
		tS08 = millis()/1000;
		
		uint16_t valueS08 = analogRead(pinS08);	// Get UV value
		if (valueS08>1170) {
			valueS08=1170;
		}
		
		if (Printout==true) {Serial.print(millis()/1000); Serial.print(F(" sec, UV Analog reading: ")); Serial.println(valueS08);}
		int i;
		for (i = 0; i < 12; i++){
			if (valueS08 <= uvIndexValue[i]){
				uvIndex = i;
				break;
			}
		}
		
		//calculate 1 decimal if possible
		if (i>0) {
			float vRange = uvIndexValue[i] - uvIndexValue[i-1];
			float vCalc = valueS08 - uvIndexValue[i-1];
			uvIndex+=(1.0/vRange)*vCalc-1.0;
		}
		
		if (Printout==true) {Serial.print(millis()/1000); Serial.print(F(" sec, UVI: ")); Serial.println(uvIndex,2);}
		send(msgS08.set(uvIndex,2));
	}
}