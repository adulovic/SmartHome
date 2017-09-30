/* 
 * S01 
 * Reed Switch
 * 
 * Notes:
 *- 	Since one end of the reed switch is connected to ground, 
 *	we need to pull-up the reed switch pin internally
 *- 	Use Arduino’s internal pull-up resistor to bias the switch high
 *- 	This effectively inverts the behavior of the INPUT mode, 
 *	where HIGH means the sensor is off, and LOW means the sensor is on.
 */


/* Initialize =====2=========3=========4=========5=========6=========7========*/
MyMessage msgS1(S1, V_TRIPPED);         // type of message sent to MySensors


/* Setup ==========2=========3=========4=========5=========6=========7========*/
void setupS1(){
    // pull-up the pin internally !!!
    pinMode(pinS1, INPUT_PULLUP);
}


/* Loop ===========2=========3=========4=========5=========6=========7========*/
void loopS1(){
    // Read the state of the switch
    valueS1 = digitalRead(pinS1);
    // If different from last state
    if (valueS1 != stateS1) {
        // Pin reads low, the switch is closed
        if (valueS1 == LOW){
            // Debug Printout
            ////Serial.println((String)"S1 is Closed (Door Closed/Untripped)");
        } else {
            // Debug Printout
            ////Serial.println((String)"S1 is Open (Door Open/Tripped)");
        }
        // send to controller
        send(msgS1.set(valueS1));
        // update state
        stateS1 = valueS1;
    }
}


/* Receive ========2=========3=========4=========5=========6=========7========*/
// nothing to receive
