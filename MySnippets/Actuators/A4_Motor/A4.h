/*
    DC Motor

    - reversible, for raising/lowering curtain, projector, etc.
    - auto shut-off when it reaches the limits
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA4(A4, V_DIMMER);

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA4(){
      pinMode(pinA4, OUTPUT);
      while (! Serial);
      Serial.println("Speed 0 to 255");
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopA4(){
    if (Serial.available())  {
        int speed = Serial.parseInt();
        if (speed >= 0 && speed <= 255)    {
            analogWrite(pinA4, speed);
        }
    }
}

/* Receive
=========1=========2=========3=========4=========5=========6=========7========*/
void receiveA4(const MyMessage &message){
    if (message.type==V_DIMMER) {
        
    }
}
