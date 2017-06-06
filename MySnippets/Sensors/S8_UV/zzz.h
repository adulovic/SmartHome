/*       SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/

// UV sensor
#define S1 1                           // Sensor number
const int pinS1 = A0;                  // data pin
uint16_t valueS1 = 0;                  // variable for reading the sensor status
float stateS1 = -1;                    // variable for storing the last state
float uvIndex;

unsigned long lastSend =0; 
uint16_t uvIndexValue [12] = { 50, 227, 318, 408, 503, 606, 696, 795, 881, 976, 1079, 1170};

/*
 * DESCRIPTION
 * Arduino UVM-30A
 * Index table taken from: http://www.elecrow.com/sensors-c-111/environment-c-111_112/uv-sensor-moduleuvm30a-p-716.html
 * Because this table is pretty lineair, we can calculate a UVI with one decimal 
 *
 * Connect sensor:
 *
 *   +   >>> 5V
 *   -   >>> GND
 *   out >>> A0     
 * 
 */

