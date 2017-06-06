
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define A1              1               // Relay for lights
#define A2              2               // Electric Door Lock
#define S1              3               // Reed switch
#define S4              4               // PIR switch 


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/

// A1 - Relay for lights
// ---------------------
const int pinA1 =       2;              // data pin
const int nightLight =  1;           	// a light that only works at night

// A2 - Lock/Unlock front door via electrick lock
// ----------------------------------------------
const int pinA2L =      3;          	// pin that locks the door
const int pinA2U =    	4;         		// pin that unlocks the door


/*       SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/

// S1 - Reed switch - to sense if the door is open or closed
// ---------------------------------------------------------
const int pinS1 =       5;              // data pin with pull-up resistor
int valueS1 = 0;                        // reading the sensor status
int stateS1 = 0;                        // storing the last state

// S4 - PIR switch - to check if someone is in front of the door
// -------------------------------------------------------------
const int pinS4 =       6;              // data pin
bool valueS4 = 0;                       // reading the sensor status
bool stateS4 = 0;                       // storing the last state
unsigned long tS4;                      // store time of last trigger

