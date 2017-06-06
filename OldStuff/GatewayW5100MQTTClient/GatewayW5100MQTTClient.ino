#include <SPI.h>

// Enable debug prints to serial monitor
#define MY_DEBUG 

// Enables and select radio type (if attached)
#define MY_RADIO_NRF24
//#define MY_RADIO_RFM69

#define MY_GATEWAY_MQTT_CLIENT

// Set this nodes subscripe and publish topic prefix
#define MY_MQTT_PUBLISH_TOPIC_PREFIX "gw-out"
#define MY_MQTT_SUBSCRIBE_TOPIC_PREFIX "gw-in"

// Set MQTT client id
#define MY_MQTT_CLIENT_ID "ADgw"

// W5100 Ethernet module SPI enable (optional if using a shield/module that manages SPI_EN signal)
//#define MY_W5100_SPI_EN 4  

// Enable Soft SPI for NRF radio (note different radio wiring is required)
// The W5100 ethernet module seems to have a hard time co-operate with 
// radio on the same spi bus.
#if !defined(MY_W5100_SPI_EN) && !defined(ARDUINO_ARCH_SAMD)
  #define MY_SOFTSPI
  #define MY_SOFT_SPI_SCK_PIN 14
  #define MY_SOFT_SPI_MISO_PIN 16
  #define MY_SOFT_SPI_MOSI_PIN 15
#endif  

// When W5100 is connected we have to move CE/CSN pins for NRF radio
#ifndef MY_RF24_CE_PIN 
  #define MY_RF24_CE_PIN 5
#endif
#ifndef MY_RF24_CS_PIN 
  #define MY_RF24_CS_PIN 6
#endif

// Enable these if your MQTT broker requires usenrame/password
//#define MY_MQTT_USER "username"
//#define MY_MQTT_PASSWORD "password"

// Enable MY_IP_ADDRESS here if you want a static ip address (no DHCP)
#define MY_IP_ADDRESS 10,0,0,33

// If using static ip you need to define Gateway and Subnet address as well
#define MY_IP_GATEWAY_ADDRESS 10,0,0,1
#define MY_IP_SUBNET_ADDRESS 255,255,255,0

// MQTT broker ip address or url. Define one or the other. 
//#define MY_CONTROLLER_URL_ADDRESS "m20.cloudmqtt.com"
#define MY_CONTROLLER_IP_ADDRESS 10, 0, 0, 32

// The MQTT broker port to to open 
#define MY_PORT 1883      

 /*
// Flash leds on rx/tx/err
#define MY_LEDS_BLINKING_FEATURE
// Set blinking period
#define MY_DEFAULT_LED_BLINK_PERIOD 300

// Enable inclusion mode
#define MY_INCLUSION_MODE_FEATURE
// Enable Inclusion mode button on gateway
#define MY_INCLUSION_BUTTON_FEATURE
// Set inclusion mode duration (in seconds)
#define MY_INCLUSION_MODE_DURATION 60 
// Digital pin used for inclusion mode button
#define MY_INCLUSION_MODE_BUTTON_PIN  3 

// Uncomment to override default HW configurations
//#define MY_DEFAULT_ERR_LED_PIN 16  // Error led pin
//#define MY_DEFAULT_RX_LED_PIN  16  // Receive led pin
//#define MY_DEFAULT_TX_LED_PIN  16  // the PCB, on board LED
*/

#include <Ethernet.h>
#include <MySensors.h>

void setup() { 
}

void presentation() {
  // Present locally attached sensors here    
}


void loop() {
  // Send locally attech sensors data here
}



