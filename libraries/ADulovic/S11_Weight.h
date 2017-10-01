/* 
	Weight Sensor

    S_WEIGHT, V_WEIGHT

*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS11(S11, V_WEIGHT);         // type of message sent to MySensors


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS11(){
    pinMode(pinS11, INPUT);             // pin
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS11(){
    fakeCounter++;
    if (fakeCounter == 600) {           // 10 minutes - assuming 1 loop per second
        fakeCounter = 0;
        send(msgS11.set(1));
    }
}

/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to receive
