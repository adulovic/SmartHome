
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define S1              1              // Reed switch A


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/
const int pinS1 =       5;             // data pin with pull-up resistor
int valueS1 = 0;                       // reading the sensor status
int stateS1 = 0;                       // storing the last state

int fakeCounter = 0;
