/* 
    DHT Sensor - Humidity and Temperature

*/


/*  LIBRARIES
=========1=========2=========3=========4=========5=========6=========7========*/
#include <DHT.h>                        // include the DHT 11 library


/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS2H(S2H, V_HUM);           // humidity sensor message
MyMessage msgS2T(S2T, V_TEMP);          // temperature sensor message

// Force sending an update of the sensor value after 10 sensor reads,
// so a timestamp of the last update doesn't show something like 3 hours
// in the unlikely case that the value didn't change since.
static const uint8_t FORCE_UPDATE_N_READS = 10;             
// Sleep time between sensor updates (in milliseconds). Must be >2000ms for DHT11
static const uint64_t UPDATE_INTERVAL = 60000;              

DHT dht;                                // start the DHT sensor
bool metric = true;                     // use metric units

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS2(){
    dht.setup(pinS2);                  // set data pin of DHT sensor
    if (UPDATE_INTERVAL <= dht.getMinimumSamplingPeriod()) {
        Serial.println("Warning: UPDATE_INTERVAL is smaller than supported by the sensor!");
    }
    // Sleep for the time of the minimum sampling period to give the sensor time to power up 
    // (otherwise, timeout errors might occure for the first reading)
    wait(2*dht.getMinimumSamplingPeriod());
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS2() {
    dht.readSensor(true);                                   // Force reading sensor, so it works also after sleep()

    // Get temperature from DHT library
    float temperature = dht.getTemperature();
    if (isnan(temperature)) {
        Serial.println("Failed reading temperature from DHT!");
    } else if (temperature != lastTemp || nNoUpdatesTemp == FORCE_UPDATE_N_READS) { // Only send temperature if it changed since the last measurement or if we didn't send an update for n times
        lastTemp = temperature;
        if (!metric) {
            temperature = dht.toCelsius(temperature);
        }
        nNoUpdatesTemp = 0;                         // Reset no updates counter
        send(msgS2T.set(temperature, 1));
    } else {
        nNoUpdatesTemp++;                           // Increase no update counter if the temperature stayed the same
    }

    // Get humidity from DHT library
    float humidity = dht.getHumidity();
    if (isnan(humidity)) {
        Serial.println("Failed reading humidity from DHT");
    } else if (humidity != lastHum || nNoUpdatesHum == FORCE_UPDATE_N_READS) { // Only send humidity if it changed since the last measurement or if we didn't send an update for n times
        lastHum = humidity;
        nNoUpdatesHum = 0;                          // Reset no updates counter
        send(msgS2H.set(humidity, 1));
    } else {
        nNoUpdatesHum++;                            // Increase no update counter if the humidity stayed the same
    }
    wait(UPDATE_INTERVAL);                          // Sleep for a while to save energy
}
