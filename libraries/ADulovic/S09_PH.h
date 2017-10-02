/*
    PH Sensor
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS09(S09, V_PH);

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS09(){
      //Setup your PH sensor here (I2C,Serial,Phidget...)
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS09(){
    float valuePH = analogRead(pinS1);
    if (statePH != valuePH) {
        send(msgS1.set(valuePH, 1));       // Send in the new PH value
        statePH = valuePH;                 // Save new PH value for next compare
    }
    wait(60000);
}


