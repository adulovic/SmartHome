/*
    DESCRIPTION

    This sketch clears radioId, relayId and 
    other routing information in EEPROM 
    back to factory default
*/

#define MY_CORE_ONLY        // load core modules only
#include <EEPROM.h>
#include <MySensors.h>  

void setup(){ 
    Serial.begin(MY_BAUD_RATE);
    Serial.println("=== Started clearing. Please wait...");
    for (int i=0;i<EEPROM_LOCAL_CONFIG_ADDRESS;i++) {
        hwWriteConfig(i,0xFF);  
    }
    Serial.println("=== Clearing done. You're ready to go!");
}

void loop(){ 
    // Nothing to do here...
} 
