/* 
    Reed Switch

 - Since one end of the reed switch is connected to ground, we need to pull-up the reed switch pin internally
 - Use Arduino’s internal pull-up resistor to bias the switch high
 - This effectively inverts the behavior of the INPUT mode, where HIGH means the sensor is off, and LOW means the sensor is on.
 - So, when the switch closes, it will connect pin 2 directly to ground, and it should read low
*/
/*
    Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS1(S1, V_TRIPPED);         // type of message sent to MySensors
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS1(){
    pinMode(pinS1, INPUT_PULLUP);       // pull-up the pin internally
}
/* 
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS1(){
    valueS1 = digitalRead(pinS1);       // Read the state of the switch
    if (valueS1 != stateS1) {           // If different from last state
        if (valueS1 == LOW){            // Pin reads low, the door is closed.
            Serial.println("S1 is Closed (Untripped)");
        } else {
            Serial.println("S1 is Open (Tripped)");
        }
        send(msgS1.set(valueS1));       // send to controller
        stateS1 = valueS1;              // update state
    }
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to receive
