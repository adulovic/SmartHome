/*
 * A01
 * Single Relay - INVERTED VERSION
 */


/* Initialize =====2=========3=========4=========5=========6=========7========*/
MyMessage msgA1(A1, V_STATUS);          // type of message sent to MySensors


/* Setup ==========2=========3=========4=========5=========6=========7========*/
void setupA1(){
    // set relay pin in output mode
    pinMode(pinA1, OUTPUT);
    
    // load state from EEPROM
    ////digitalWrite(pinA1, loadState(A1) ? 0 : 1);
}


/* Loop ===========2=========3=========4=========5=========6=========7========*/
// nothing to loop


/* Receive ========2=========3=========4=========5=========6=========7========*/
void receiveA1(const MyMessage &message){
    
    if ( message.type == V_STATUS ) {
        
        // toggle relay state
        digitalWrite( pinA1, message.getBool() ? 0 : 1 );
        
        // save state to EEPROM
        ////saveState( A1, message.getBool() );
        
        // Debug Printout
        ////Serial.println( (String)"Toggle A1 inverted relay. New state is "+message.getBool() );
    }
}