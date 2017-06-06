
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define A1              1               // Relay
#define S2T             2               // Temperature
#define S2H             3               // Humidity


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/

// A1 - Relay - Spotlight
// ----------------------
const int pinA1 =       2;              // Digital pin number for the relay

/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/

// S2 - Temperature & Humidity (DHT 11)
// ------------------------------------
const int pinS2 =       3;              // The pin for DHT data 
float stateS2H;                         // last saved humidity value
float stateS2T;                         // last saved temperature value
unsigned long tS2 = 0;                  // last saved time the loop fired
unsigned long iS2 = 5;                  // interval at which to fire loop (in seconds)

