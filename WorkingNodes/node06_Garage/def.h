
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define A1              1               // Relay
#define S1              2               // Reed switch
#define S4              3               // PIR
#define S13             4               // UltraSonic


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/

// A1 - Relay for lights
// ---------------------
const int pinA1 =       2;              // the pin that the relay is atteched to

// S1 - Reed switch - gate
// -----------------------
const int pinS1 =       3;              // data pin with pull-up resistor
int valueS1 = 0;                        // reading the sensor status
int stateS1 = 0;                        // storing the last state

// S4 - PIR switch
// ---------------
const int pinS4 =       4;              // data pin
int valueS4 = 0;                        // reading the sensor status
int stateS4 = 0;                        // storing the last state
unsigned long tS4;                      // store time of last trigger
int iS4 = 0;                            // counter

// S13 - Ultrasonic
// ----------------
const int pinS13T = 		 5;             	// Trig - green Jumper
const int pinS13E = 		 6;              // Echo - yellow Jumper
long duration, cm, inches;


