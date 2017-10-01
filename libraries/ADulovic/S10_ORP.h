/* 
	ORP Sensor

    S_WATER_QUALITY, V_ORP

*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS10(S10, V_ORP);         // type of message sent to MySensors


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS10(){
    pinMode(pinS10, INPUT);             // pin
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS10(){
    fakeCounter++;
    if (fakeCounter == 600) {           // 10 minutes - assuming 1 loop per second
        fakeCounter = 0;
        send(msgS10.set(1));
    }
}

/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
// nothing to receive
