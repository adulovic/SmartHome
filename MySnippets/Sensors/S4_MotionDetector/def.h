
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define S4              4               // PIR switch


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/
const int pinS4 =       6;              // data pin
int valueS4 = 0;                        // reading the sensor status
int stateS4 = 0;                        // storing the last state
unsigned long tS4;                      // store time of last trigger
int iS4 = 0;                            // counter

