/*
    Ultrasonic Distance Sensor
    
    - Pins   VCC: +5VDC, GND: GND, Trig : Trigger (INPUT), Echo: Echo (OUTPUT)
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS13(S13, V_DISTANCE);

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS13(){
      // initialize inputs and outputs
      pinMode(pinS13T, OUTPUT);
      pinMode(pinS13E, INPUT);
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS13(){
      // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
      // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
      digitalWrite(pinS13T, LOW);   delayMicroseconds(5);
      digitalWrite(pinS13T, HIGH);  delayMicroseconds(10);
      digitalWrite(pinS13T, LOW);
     
      // Read the signal from the sensor: a HIGH pulse whose duration is the time (in microseconds)
      // from the sendingof the ping to the reception of its echo off of an object.
      pinMode(pinS13E, INPUT);
      duration = pulseIn(pinS13E, HIGH);
     
      // convert the time into a distance
      cm = (duration/2) / 29.1;
      inches = (duration/2) / 74; 
      
      Serial.print(inches); Serial.print("in, "); Serial.print(cm); Serial.print("cm"); Serial.println();
      delay(250);
}
