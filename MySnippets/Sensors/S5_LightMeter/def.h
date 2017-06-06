
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define S5              1               // Photovoltaic sensor


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/
const int pinS5 =       A1;             // data pin

int valueS5 = 0;                       // variable for reading the sensor status
int stateS5 = 0;                       // variable for storing the last state

