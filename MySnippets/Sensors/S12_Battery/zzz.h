/*       SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/

// Photovoltaic Resistor
#define S1 1                           // Sensor number
const int pinS1 = A0;                  // data pin
int valueS1 = 0;                       // variable for reading the sensor status
int stateS1 = 0;                       // variable for storing the last state
int percentageS1 = 0;
float voltageS1 = 0;
