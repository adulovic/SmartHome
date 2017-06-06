/*
    UV Sensor

*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS1(S1, V_UV);    // define type of message sent to MySensors

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS1(){
    pinMode(pinS1, INPUT);             // initialize sensor as an input
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS1(){
    unsigned long currentTime = millis();
    valueS1 = analogRead(pinS1);        // Get UV value
    if (valueS1>1170)
        valueS1=1170;
    Serial.print("UV Analog reading: "); Serial.println(valueS1);
    int i;
    for (i = 0; i < 12; i++){
        if (valueS1 <= uvIndexValue[i]){
            uvIndex = i;
            break;
        }
    }
    //calculate 1 decimal if possible
    if (i>0) {
        float vRange=uvIndexValue[i]-uvIndexValue[i-1];
        float vCalc=valueS1-uvIndexValue[i-1];
        uvIndex+=(1.0/vRange)*vCalc-1.0;
    }
    Serial.print("UVI: "); Serial.println(uvIndex,2);
    //Send value to gateway if changed, or at least every 5 minutes
    if ((uvIndex != stateS1)||(currentTime-lastSend >= 5UL*60UL*1000UL)) {
        lastSend=currentTime;
        send(msgS1.set(uvIndex,2));
        stateS1 = uvIndex;
    }
  
  sleep(60000);
}

