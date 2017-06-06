#define MY_DEBUG                            // Enable debug prints to serial monitor

#define MY_RADIO_NRF24                          // Enable and select radio type attached
#define MY_RF24_PA_LEVEL RF24_PA_LOW            // Set radio power
//#define MY_RF24_DATARATE RF24_1MBPS           //

#define MY_GATEWAY_SERIAL                   // Enable serial gateway

// Define a lower baud rate for Arduino's running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
//#if F_CPU == 8000000L
//    #define MY_BAUD_RATE 38400
//#endif

#include <SPI.h>
#include <MySensors.h>  

void setup() { 
    // Setup locally attached sensors
}

void presentation() {
    // Present locally attached sensors 
}

void loop() { 
    // Send locally attached sensor data here 
}
