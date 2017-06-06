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
MyMessage msgS1A(S1A, V_TRIPPED);       // type of message sent to MySensors
MyMessage msgS1B(S1B, V_TRIPPED);       // type of message sent to MySensors
/*
    Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS1(){
    pinMode(pinS1A, INPUT_PULLUP);      // pull-up the pin internally
    pinMode(pinS1B, INPUT_PULLUP);      // pull-up the pin internally
}
/*
    Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS1(){
    valueS1A = digitalRead(pinS1A);     // Read the state of the switch
    valueS1B = digitalRead(pinS1B);     // Read the state of the switch
    if (valueS1A != stateS1A) {         // Send in the new value
        if (valueS1A == LOW){           // If the pin reads low, the door is closed.
            Serial.println("S1A is Closed (Untripped)");
        } else {
            Serial.println("S1A is Open (Tripped)");
        }
        send(msgS1A.set(valueS1A));
        stateS1A = valueS1A;
    }

    if (valueS1B != stateS1B) {         // Send in the new value
        if (valueS1B == LOW){           // If the pin reads low, the door is closed.
            Serial.println("S1B is Closed (Untripped)");
        } else {
            Serial.println("S1B is Open (Tripped)");
        }
        send(msgS1B.set(valueS1B));
        stateS1B = valueS1B;
    }
}
/*
    Receive
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to receive
