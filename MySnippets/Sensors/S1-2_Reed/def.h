
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define S1A              1              // Reed switch A
#define S1B              2              // Reed switch B
#define numberOfS1       2              // Number of Reed switches


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/
const int pinS1A =       5;             // data pin with pull-up resistor
int valueS1A = 0;                       // reading the sensor status
int stateS1A = 0;                       // storing the last state

const int pinS1B =       6;             // data pin with pull-up resistor
int valueS1B = 0;                       // reading the sensor status
int stateS1B = 0;                       // storing the last state

int fakeCounter = 0;

/* void aaa(){

    for ( i,c; i <= numberOfS1; c++,i++){
        Serial.println((String)"Sensor"+i+" is S1"+c);
    }

}*/
