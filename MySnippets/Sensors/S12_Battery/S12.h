/*
    Battery sensor

*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS1(S1, V_LIGHT_LEVEL);    // define type of message sent to MySensors

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS1(){
    #if defined(__AVR_ATmega2560__)               // use the 1.1 V internal reference
        analogReference(INTERNAL1V1);
    #else
        analogReference(INTERNAL);
    #endif
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS1(){
    valueS1 = analogRead(pinS1);         // get the battery Voltage
    // 1M, 470K divider across battery and using internal ADC ref of 1.1V
    // Sense point is bypassed with 0.1 uF cap to reduce noise at that point
    // ((1e6+470e3)/470e3)*1.1 = Vmax = 3.44 Volts
    // 3.44/1023 = Volts per bit = 0.003363075
    percentageS1 = valueS1 / 10;
    voltageS1  = valueS1 * 0.003363075;
    
    Serial.print("Battery Value: "); Serial.print(valueS1); Serial.println(" ?");
    Serial.print("Battery Voltage: "); Serial.print(voltageS1); Serial.println(" V");
    Serial.print("Battery Percent: "); Serial.print(percentageS1); Serial.println(" %");
    
    if (stateS1 != percentageS1) {
        sendBatteryLevel(percentageS1);
        stateS1 = percentageS1;
    }
}
