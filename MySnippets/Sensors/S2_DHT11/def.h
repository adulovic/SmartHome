
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define S2H             1               // Humidity
#define S2T             2               // Temperature


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/
const int pinS2 =       2;              // The pin for DHT data 

float lastHum;                          // last saved humidity value
uint8_t nNoUpdatesHum;                  // number of skipped humidity updates

float lastTemp;                         // last saved temperature value
uint8_t nNoUpdatesTemp;                 // number of skipped temperature updates
