/*
    MQ-2 Gas/Smoke Sensor 
    The MQ-2 sensor is sensitive to smoke and LPG, Butane, Propane, Methane, Alcohol, Hydrogen...
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS15(S15, V_LEVEL);


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS15(){
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(pinS15, INPUT);
}


/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS15(){
    int analogSensor = analogRead(pinS15);
    Serial.print("Pin A0: "); Serial.println(analogSensor);
    // Checks if it has reached the threshold value
    if (analogSensor > sensorThres){
        digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, LOW);
        tone(buzzer, 1000, 200);
    } else {
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
        noTone(buzzer);
    }
    delay(100);
}
