/*
    Water Temperature

    - remember to mount a resistor between VCC and pinS7
*/

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS7(S7, V_TEMP);
#include <OneWire.h>
#include <DallasTemperature.h>

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(pinS7);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS7(){
    pinMode(pinS7, INPUT);      // initialize sensor as an pullup input
    sensors.begin();                   // Start up the library
    Serial.print("Found "); Serial.print(sensors.getDeviceCount()); Serial.println(" devices.");
}

/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS7(){
    sensors.requestTemperatures();     // Send the command to get temperatures
    Serial.print("Temperature for waterproof sensor (0) is: ");
    float valueS7 = sensors.getTempCByIndex(0);       // 0 refers to the first IC on the wire
    Serial.println(valueS7);
}
