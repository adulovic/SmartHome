/* 
	Reed Switch

	- use the Arduino’s internal pull-up resistor on pin 2 to bias the switch high
	- when the switch closes, it will connect pin 2 directly to ground, and it should read low
	- since one end of the reed switch is connected to ground, we need to pull-up the reed switch pin internally
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS1A(S1A, V_TRIPPED);         // type of message sent to MySensors
MyMessage msgS1B(S1B, V_TRIPPED);         // type of message sent to MySensors


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS1(){
    pinMode(pinS1A, INPUT_PULLUP);      // pull-up the pin internally
    pinMode(pinS1B, INPUT_PULLUP);      // pull-up the pin internally
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS1(){
    valueS1A = digitalRead(pinS1A);     // Read the state of the switch
    valueS1B = digitalRead(pinS1B);       // Read the state of the switch

    fakeCounter++;
    if (fakeCounter == 600) {           // 10 minutes - assuming 1 loop per second
        fakeCounter = 0;
        valueS1A = (valueS1A == 1) ? 0: 1;
        valueS1B = (valueS1B == 1) ? 0: 1;
    }

    if (valueS1A != stateS1A) {         // Send in the new value
        send(msgS1A.set(valueS1A==HIGH ? 0 : 1));
        stateS1A = valueS1A;
        if (valueS1A == LOW){            // If the pin reads low, the door is closed.
            Serial.println("S1A is Open (Tripped)");
        } else if (valueS1A == HIGH){
            Serial.println("S1A is Closed (Untripped)");
        }
    }

    if (valueS1B != stateS1B) {   // Send in the new value
        send(msgS1B.set(valueS1B==HIGH ? 0 : 1));
        stateS1B = valueS1B;
        if (valueS1B == LOW){            // If the pin reads low, the door is closed.
            Serial.println("S1B is Open (Tripped)");
        } else if (valueS1B == HIGH){
            Serial.println("S1B is Closed (Untripped)");
        }
    }
}

/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to receive
