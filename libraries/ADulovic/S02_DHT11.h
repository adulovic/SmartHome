/*
 * S02
 * DHT11 Sensor - Humidity and Temperature
 */


/* Initialize =====2=========3=========4=========5=========6=========7========*/
MyMessage msgS2H(S2H, V_HUM);           // humidity sensor message
MyMessage msgS2T(S2T, V_TEMP);          // temperature sensor message
DHT dht;                                // start the DHT sensor
bool metric = true;                     // use metric units


/* Setup ==========2=========3=========4=========5=========6=========7========*/
void setupS2(){
    // set data pin in input mode
    dht.setup(pinS2);
	
    // Sleep the minimum sampling period to let the sensor power up 
    wait( 3 * dht.getMinimumSamplingPeriod() );
}


/* Loop ===========2=========3=========4=========5=========6=========7========*/
void loopS2() {
    // if no last saved time OR interval has passed
    if( tS2==0 || millis() - tS2 > iS2*60*1000 ) {
        // Debug Printout
        ////Serial.println((String)"- S2 Loop fired, at time "  + millis() + "-" + tS2 + ">" + iS2*60*1000 );	
        
        // update when the last reading was made
        tS2 = millis();
        
        // Force reading sensor, so it works also after sleep()
        dht.readSensor(true);
        
        // Debug Printout
        ////Serial.println((String)"- Reading DHT temp" + dht.getTemperature() );
        
        // Get temperature from DHT
        float valueS2T = dht.getTemperature();
        
        // Debug Printout
        ////Serial.println((String)"- Reading DHT hum" + dht.getHumidity() );
        
        // Get humidity from DHT
        float valueS2H = dht.getHumidity();
        
        // Only send temperature if it changed
        if (valueS2T != stateS2T) {
                stateS2T = valueS2T;
                send(msgS2T.set(valueS2T, 1));
        }
        
        // Only send humidity if it changed
        if (valueS2H != stateS2H) {
                stateS2H = valueS2H;
                send(msgS2H.set(valueS2H, 1));
        }
    }
}


/* Receive ========2=========3=========4=========5=========6=========7========*/
// nothing to receive
