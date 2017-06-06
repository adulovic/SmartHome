//----------
// define radio and role
//----------
#define MY_DEBUG                            // Enable debug prints to serial monitor
#define MY_RADIO_NRF24                      // Enable and select radio type attached
#define MY_RF24_PA_LEVEL RF24_PA_LOW        // Set radio power
#define MY_RF24_DATARATE RF24_250KBPS       // Set radio transmission rate
#define MY_GATEWAY_W5100                    // Enable gateway ethernet module type 
//#define MY_SIGNING_ATSHA204               // Enables hardware signing using ATSHA204
//#define MY_SIGNING_SOFT                   // Enables software signing

#define SN "GateWay"
#define SV "1.0"

// Enable Hard SPI for NRF radio (D12=MISO, D11=MOSI, D13=SCK, D6=CSN, D5=CE)
#define MY_W5100_SPI_EN 4                       // W5100 Ethernet module SPI enable (optional if using a shield/module that manages SPI_EN signal)

// Enable Soft SPI for NRF radio (A2=MISO, A1=MOSI, A0=SCK, D6=CSN, D5=CE)
// The W5100 ethernet module seems to have a hard time co-operate with radio on the same spi bus.
#if !defined(MY_W5100_SPI_EN) && !defined(ARDUINO_ARCH_SAMD)
    #define MY_SOFTSPI
    #define MY_SOFT_SPI_SCK_PIN 14
    #define MY_SOFT_SPI_MISO_PIN 16
    #define MY_SOFT_SPI_MOSI_PIN 15
#endif  

// When W5100 is connected we have to move CE/CSN pins for NRF radio
#define MY_RF24_CE_PIN 5
#define MY_RF24_CS_PIN 6

#define MY_IP_ADDRESS 10,0,0,33                 // If this is disabled, DHCP is used to retrieve address
#define MY_PORT 5003                            // The port to keep open on node server mode / or port to contact in client mode
#define MY_CONTROLLER_IP_ADDRESS 10,0,0,32      // Controller ip address. Enables client mode (default is "server" mode). Also enable this if MY_USE_UDP is used and you want sensor data sent somewhere. 
 
// The MAC address can be anything you want but should be unique on your network.
// Newer boards have a MAC address printed on the underside of the PCB, which you can (optionally) use.
// Note that most of the Ardunio examples use  "DEAD BEEF FEED" for the MAC address.
#define MY_MAC_ADDRESS 0xDE, 0xAD, 0xBE, 0xEF, 0x00, 0x33

//#define MY_LEDS_BLINKING_FEATURE                // Flash leds on rx/tx/err
#define MY_DEFAULT_LED_BLINK_PERIOD 250         // Set blinking period

#define MY_INCLUSION_MODE_FEATURE               // Enable inclusion mode
//#define MY_INCLUSION_BUTTON_FEATURE             // Enable Inclusion mode button on gateway
//#define MY_INCLUSION_MODE_DURATION 60           // Set inclusion mode duration (in seconds)
//#define MY_INCLUSION_MODE_BUTTON_PIN  3         // Digital pin used for inclusion mode button

//----------
// include
//----------
#if defined(MY_USE_UDP)
  #include <EthernetUdp.h>
#endif
#include <Ethernet.h>
#include <MySensors.h>

//------------------------------------------------------------------------------
void setup(){}

//------------------------------------------------------------------------------
void loop() {}

//------------------------------------------
void presentation()  {
  sendSketchInfo(SN, SV);           // Send the sketch version information
}
