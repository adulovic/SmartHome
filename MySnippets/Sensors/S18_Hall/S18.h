/*
    VAC Sensor (ACS712)
    
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS1(S1, V_TRIPPED);

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS1(){
      pinMode(pinS1, INPUT);
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS1(){
    valueS1 = digitalRead(pinS1);                       // read the state of the hall sensor
    if (valueS1 == HIGH && stateS1 == LOW) {
        Serial.println(" == DOOR IS OPEN == ");
        stateS1 = 1;
        send(msgS1.set(1));
    } else if (valueS1 == LOW && stateS1 == HIGH) {
        Serial.println(" == DOOR IS CLOSED == ");
        stateS1 = 0;
        send(msgS1.set(0));
    }
}
