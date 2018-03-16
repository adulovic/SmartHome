/* 
    NRF24L01 definitions

=========1=========2=========3=========4=========5=========6=========7========*/
//#define MY_DEBUG                              // Enable debug prints to serial monitor
//#define MY_DEBUG_VERBOSE_RF24                 // Enable for verbose debug prints related to the RF24 driver. Requires DEBUG to be enabled.

#define MY_RADIO_NRF24                          // Enable if you want to use a NRF24L01+ radio
#define MY_REPEATER_FEATURE                     // Enables repeater functionality (relays messages from other nodes).

#define MY_RF24_PA_LEVEL RF24_PA_HIGH          	// Set radio power (Options are: _MIN, _LOW, _HIGH or _MAX)
#define MY_RF24_DATARATE RF24_250KBPS           // Set radio transmission rate
//#define MY_RF24_DATARATE RF24_1MBPS


/*
	Optional & Additional
=========1=========2=========3=========4=========5=========6=========7========*/
#define MY_SIGNAL_REPORT_ENABLED                // Enables signal report functionality.
//#define MY_RF24_CHANNEL 76                    // Change radio channel, has to be done on all nodes

//#define MY_SIGNING_ATSHA204                   // Enables hardware signing using ATSHA204
//#define MY_SIGNING_SOFT                       // Enables software signing

//#define MY_PARENT_NODE_ID                     // Gateway is 0
//#define MY_PARENT_NODE_IS_STATIC

//#define MY_DISABLED_SERIAL                    // Enable if you want to use TX(1), RX(0) as normal I/O pin
//#define MY_RF24_ENABLE_ENCRYPTION


//#define MY_TRANSPORT_SANITY_CHECK             // Check transport in regular intervals to detect HW issues and re-initialize in case of failure
//#define MY_TRANSPORT_SANITY_CHECK_INTERVAL_MS (15*60*1000ul)

//#define MY_OTA_FIRMWARE_FEATURE				// only used with sensebender, not with MYSBL