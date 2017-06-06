
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define S6              1               // Voltage


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/
const int pinS6 =       A0;             // data pin
int valueS6 = 0;                        // reading the sensor status
int stateS6 = 0;                        // storing the last state

int mVperAmp = 185; // use 185 for 5A, 100 for 20A Module and 66 for 30A Module
