/* 
    Passive InfraRed Switch
	
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS4(S4, V_TRIPPED);        // type of message sent to MySensors

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS4(){
    pinMode(pinS4, INPUT);             // initialize sensor as an input
	stateS4 = request(S4, V_TRIPPED);  // get status from controller
    digitalWrite(pinS4, stateS4);      // turn on/off based on controller state

}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS4(){
	valueS4 = digitalRead(pinS4);       // Read the state of the switch
	if (valueS4 != stateS4) {           // If different from last state
        if (valueS4 == 0){              // Pin reads low
			Serial.println((String)"- Standing down after "+ ((millis()-tS4)/1000) + " seconds");
        } else if (valueS4 == 1){
			tS4 = millis();				// time when loop fired (for calibrating the timer)
			Serial.println("--- Motion detected! --- ");
        }
        send(msgS4.set(valueS4));       // send to controller
        stateS4 = valueS4;              // update state
		wait(2000);						// wait 2 seconds so it doesnt bounce
    }
}