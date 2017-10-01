
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define S6              1               // VAC sensor
#define S12             2               // VDC sensor


/*  PINS & VARIABLES - S6 - AC Voltage sensor
=========1=========2=========3=========4=========5=========6=========7========*/
const int pinS6 =        A0;            // 

int valueS6 = 0;                        // reading the sensor status
int stateS6 = 0;                        // storing the last state
int mVperAmp = 185;                     // use 185 for 5A, 
                                        // 100 for 20A Module and 
                                        // 66 for 30A Module

/*  PINS & VARIABLES - S12 - DC Voltage sensor
=========1=========2=========3=========4=========5=========6=========7========*/
const int pinS12 =      A1;             // analog pin
const int R1 =          10000;          // resistor 10k
const int R2 =          2000;           // resistor 2k
const float dividerS12 = (float)R2/(R2+R1);

float voltageS12 =      0;              // storing the voltage



