/* 
    Sound Sensor

 - This one must have no delay in the loopS19
 - Once the microphone picks up a sound that is above the sensitivity threshold, 
	the sensor sends a high (1) signal from the SIG line
 - The red leds are controlled by the low frequencies (bass),
	the green by the mid frequencies and
	the blue by the high frequencies.  
 
*/

/*
    Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS19(S19, V_LEVEL);         // type of message sent to MySensors
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS19(){
    pinMode(pinS19, INPUT);       		//
}
/* 
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS19(){
    valueS19 = digitalRead(pinS19);     // Read the state
	if (valueS19 != stateS19){
		stateS19 = valueS19;
		Serial.println((String)" Decibel level " + valueS19);
	}
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to receive
