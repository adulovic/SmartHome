/*
    Dimmer LED
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgA6L(A6L, V_LIGHT);         // on/off
MyMessage msgA6D(A6D, V_DIMMER);        // what type of messsage to send to the controller


#define EPROM_LIGHT_STATE 0             // saved in eeprom
int LastLightState=0;                   // rememeber the last state, for comparisons
#define EPROM_DIMMER_LEVEL 0            // saved in eeprom
int LastDimValue=0;                     // rememeber the last state, for comparisons


/*=======1=========2=========3=========4=========5=========6=========7========*/
void SendCurrentState2Controller(){
    if ((LastLightState==0)||(LastDimValue==0)) {
        send(msgA6L.set(0));
        send(msgA6D.set(0));
    } else {
        send(msgA6D.set(LastDimValue));
        send(msgA6L.set(1));
    }
}
/*=======1=========2=========3=========4=========5=========6=========7========*/
void SetCurrentState2Hardware(){
    if (LastLightState==0) {
        digitalWrite(pinA6, 0);                  // Switch off
        Serial.println( "Light state: OFF" );
    } else {
        analogWrite(pinA6, LastDimValue);        // Switch on to a percentage
        Serial.print( "Light state: ON, Level: " ); Serial.println( LastDimValue );
    }
    SendCurrentState2Controller();               //Send current state to the controller
}

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupA6(){
    pinMode(pinA6, OUTPUT);
    int LightState=loadState(EPROM_LIGHT_STATE);            // Retreive our light state from the eprom
    if (LightState<=1) {                                    // if less than 1
        LastLightState=LightState;                          // change the last state
        int DimValue=loadState(EPROM_DIMMER_LEVEL);         // load dimmer value from eeprom
        if ((DimValue>0)&&(DimValue<=100)) {                // There should be no Dim value of 0, this would mean 0
            LastDimValue=DimValue;
        }
    }
    SetCurrentState2Hardware();                             //Here you actualy switch on/off the light with the last known dim level
}
/*=======1=========2=========3=========4=========5=========6=========7========*/
void receiveA6(const MyMessage &message){
    /* When receiving a V_LIGHT command we switch the light between OFF and the last received dimmer value
     * This means if you previously set the lights dimmer value to 50%, and turn the light ON it will do so at 50%
     */
    if (message.type == V_STATUS) {
        Serial.println( "V_LIGHT command received..." );
        int lstate= atoi( message.data );
        if ((lstate<0)||(lstate>1)) {
            Serial.println( "V_LIGHT data invalid (should be 0/1)" );
            return;
        }
        LastLightState=lstate;
        saveState(EPROM_LIGHT_STATE, LastLightState);
    
        if ((LastLightState==1)&&(LastDimValue==0)) {
            /* In the case that the Light State = On, but the dimmer value is zero, then something (probably the controller) did something wrong, for the Dim value to 100%
            */
            LastDimValue=100;
            saveState(EPROM_DIMMER_LEVEL, LastDimValue);
        }
    
    } else if (message.type == V_DIMMER) {
        Serial.println( "V_DIMMER command received..." );  
        int dimvalue= atoi( message.data );
        if ((dimvalue<0)||(dimvalue>100)) {
            Serial.println( "V_DIMMER data invalid (should be 0..100)" );
            return;
        }
        if (dimvalue==0) {
            LastLightState=0;
        } else {
            LastLightState=1;
            LastDimValue=dimvalue;
            saveState(EPROM_DIMMER_LEVEL, LastDimValue);
        }
    } else {
        Serial.println( "Invalid command received..." );  
        return;
    }
    SetCurrentState2Hardware();                             //Here you set the actual light state/level
}
