/*
    PhotoVoltaic Sensor

    - used to determine if the lights should switch on when motion is detected

*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS5(S5, V_LIGHT_LEVEL);    // define type of message sent to MySensors

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS5(){
    pinMode(pinS5, INPUT);             // initialize sensor as an input
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS5(){
    valueS5 = analogRead(pinS5);       // read and store sensor value
    Serial.print("Analog reading: "); Serial.print(valueS5);

    int iv = (1023-valueS5);          // invert the reading
    Serial.print(" --- Inverted reading: "); Serial.print(iv);

    int sh = map(iv, 0, 1023, 0, 10); // map to 10 shades of light ;)
    Serial.print(" --- Shade (0-10): "); Serial.println(sh);
    
    if (stateS5 != valueS5){           // if the state has changed
        stateS5 = valueS5;             // update state
        //Serial.print("---> Updating controller: "); Serial.println(valueS5);
        send(msgS5.set(valueS5));      // send message to mycontroller
    }
}

/*
    // a few threshholds, qualitatively determined
    if (valueS1 < 10) {
        Serial.println(" - Dark");
    } else if (valueS1 < 200) {
        Serial.println(" - Dim");
    } else if (valueS1 < 500) {
        Serial.println(" - Light");
    } else if (valueS1 < 800) {
        Serial.println(" - Bright");
    } else {
        Serial.println(" - Very bright");
    }
 */
