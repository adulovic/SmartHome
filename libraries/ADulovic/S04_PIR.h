/* 
    Passive InfraRed Switch
	
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS4(S4, V_TRIPPED);        // type of message sent to MySensors

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS4(){
    // initialize sensor as an input
    pinMode(pinS4, INPUT);
    // get status from controller
    stateS4 = request(S4, V_TRIPPED);
    // set status based on controller state
    digitalWrite(pinS4, stateS4);
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS4(){
    // Read the state of the switch
    valueS04 = digitalRead(pinS04);
    // If different from last state
    if (valueS04 != stateS04) {
        // Pin reads low
        if (valueS04 == 0){
            // Debug Printout
            Serial.println((String)"- Standing down after "+ ((millis()-tS04)/1000) + " seconds");
        } else 
        if (valueS04 == 1){
            // time when loop fired (for calibrating the timer)
            tS04 = millis();
            // Debug Printout
            Serial.println("--- Motion detected! --- ");
        }
        // send to controller
        send(msgS4.set(valueS4));
        // update state
        stateS4 = valueS4;
        // wait 2 seconds so it doesn't bounce
        wait(2000);
    }
}