/* NRF24L01 defintions
=========1=========2=========3=========4=========5=========6=========7========*/
//#define MY_DEBUG                               // Enable debug prints to serial monitor
//#define MY_DEBUG_VERBOSE_RF24                  // Enable for verbose debug prints related to the RF24 driver. Requires DEBUG to be enabled.
#define MY_RADIO_NRF24                           // Enable and select radio type attached


#define MY_RF24_PA_LEVEL RF24_PA_HIGH            // Set radio power
#define MY_RF24_DATARATE RF24_250KBPS            // Set radio transmission rate
//#define MY_RF24_DATARATE RF24_1MBPS

/* MQTT definitions
=========1=========2=========3=========4=========5=========6=========7========*/
#define MY_GATEWAY_MQTT_CLIENT                   // MQTT client
#define MY_MQTT_PUBLISH_TOPIC_PREFIX "AD_gw_out"
#define MY_MQTT_SUBSCRIBE_TOPIC_PREFIX "AD_gw_in"
#define MY_MQTT_CLIENT_ID "AD_gateway"           // Set MQTT client id

/* w5100 setup
=========1=========2=========3=========4=========5=========6=========7========*/
//#define MY_W5100_SPI_EN 4                     // W5100 Ethernet module SPI enable (keep disabled)
#if !defined(MY_W5100_SPI_EN) && !defined(ARDUINO_ARCH_SAMD)
  #define MY_SOFTSPI                            // Enable Soft SPI for NRF radio (note different radio wiring is required)
  #define MY_SOFT_SPI_SCK_PIN 14                // (A0)
  #define MY_SOFT_SPI_MOSI_PIN 15               // (A1)
  #define MY_SOFT_SPI_MISO_PIN 16               // (A2)
#endif  
#define MY_RF24_CE_PIN 5                        // For W5100 we have to move CE pin for radio
#define MY_RF24_CS_PIN 6                        // For W5100 we have to move CSN pin for radio

/* MQTT broker definitions
=========1=========2=========3=========4=========5=========6=========7========*/
//#define MY_MQTT_USER "yypgbgnf"
//#define MY_MQTT_PASSWORD "gelw1BJpmddw"
//#define MY_CONTROLLER_IP_ADDRESS 54,196,24,81
//#define MY_PORT 15089

#define MY_MQTT_USER "AD"
#define MY_MQTT_PASSWORD "AD"
//#define MY_CONTROLLER_IP_ADDRESS 10,0,0,5     // dulovic mycloud
#define MY_CONTROLLER_IP_ADDRESS 10,0,0,4       // raspberry pi
#define MY_PORT 1883    // 5003 ?


/* IP Address (or DHCP)
=========1=========2=========3=========4=========5=========6=========7========*/
#define MY_IP_ADDRESS 10,0,0,9                  // Enable MY_IP_ADDRESS here if you want a static ip address (no DHCP)
#define MY_IP_GATEWAY_ADDRESS 10,0,0,1          // If using static ip you need to define Gateway and Subnet address as well
#define MY_IP_SUBNET_ADDRESS 255,255,255,0      // When this doesnt work, check what pins are being used!!!

/* Optional & Additional
=========1=========2=========3=========4=========5=========6=========7========*/
//#define MY_RF24_CHANNEL 76                    // Change radio channel, has to be done on all nodes
//#define MY_SIGNING_ATSHA204                   // Enables hardware signing using ATSHA204
//#define MY_SIGNING_SOFT                       // Enables software signing
//#define MY_PARENT_NODE_ID                             
//#define MY_PARENT_NODE_IS_STATIC
//#define MY_DISABLED_SERIAL                    // Enable if you want to use TX(1), RX(0) as normal I/O pin
//#define MY_RF24_ENABLE_ENCRYPTION
//#define MY_SIGNAL_REPORT_ENABLED              // Enables signal report functionality.
//#define MY_TRANSPORT_SANITY_CHECK             // Check transport in regular intervals to detect HW issues and re-initialize in case of failure
//#define MY_TRANSPORT_SANITY_CHECK_INTERVAL_MS (15*60*1000ul)

