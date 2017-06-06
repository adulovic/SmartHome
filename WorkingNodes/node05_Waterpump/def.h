
/*      SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define A12A            1               // Relay for pump
#define A12B            2               // Relay for lights
#define S4              3               // PIR
#define S6              4               // VAC sensor


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/

// A12 - 2 Channel Relay
// ---------------------
const int pinA12A =     2;             // Relay - for shutting off pump at night
const int pinA12B =     3;             // Relay - for activating lights on PIR


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/

// S4 - PIR switch
// ---------------
const int pinS4 =       4;              // data pin
int valueS4 = 0;                        // reading the sensor status
int stateS4 = 0;                        // storing the last state
unsigned long tS4;                      // store time of last trigger
int iS4 = 0;                            // counter
unsigned long startS4;

// S6 - AC Voltage sensor
// ----------------------
const int pinS6 =       A1;             // data pin
int valueS6 = 0;                        // reading the sensor status
int stateS6 = 0;                        // storing the last state
int mVperAmp = 185; // use 185 for 5A, 100 for 20A Module and 66 for 30A Module
