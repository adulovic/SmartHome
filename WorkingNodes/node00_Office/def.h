
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define A1              1               // Relay
#define S1              2               // Reed switch


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/

// A1 - Relay for projector power cord
// -----------------------------------
const int pinA1 =       2;              // the pin that the relay is atteched to

// S1 - Reed switch - office door
// ------------------------------
const int pinS1 =       3;             // data pin with pull-up resistor
int valueS1 = 0;                        // reading the sensor status
int stateS1 = 0;                        // storing the last state
