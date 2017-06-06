
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define A14A           1                // Relay A
#define A14B           2                // Relay B
#define A14C           3                // Relay B
#define A14D           4                // Relay B


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/
const int pinA14A =    3;
bool stateA14A = 0;                     // state of the relay A14A

const int pinA14B =    4;
bool stateA14B = 0;                     // state of the relay A14B

const int pinA14C =    5;
bool stateA14C = 0;                     // state of the relay A14C

const int pinA14D =    6;
bool stateA14D = 0;                     // state of the relay A14D

/*
 *** EEPROM
 * void saveState(uint8_t pos, uint8_t value);
    You can save a state (in local EEPROM) which is good for actuators to "remember" state between power cycles. 
    You have 256 bytes to play with. Note that there is a limitation on the number of writes the EEPROM can handle (~100 000 cycles).
    - pos - The position to store value in (0-255)
    - value - Value to store in position
 * uint8_t loadState(uint8_t pos);
    - pos - The position to fetch from EEPROM (0-255)

 *** Fetching time from controller
 * void requestTime();
    Requests time from controller. Answer will be delivered to your receiveTime()-function function in sketch.
 * void receiveTime(unsigned long ts);
    - ts - Time in seconds since 1970. Adjusted for timezone by controller.

 *** Requesting data
 * void request(uint8_t childSensorId, uint8_t variableType, uint8_t destination);
    Requests a variable value from gateway or some other sensor in the radio network. 
    Make sure to add a receive()-function to handle request responses. 
    If you send this request to some other sensor-node you must handle the reply message yourself in the destination node.
    - childSensorId - The unique child id for the different sensors connected to this Arduino. 0-254.
    - variableType - The variableType to fetch.
    - destination - The nodeId of other node to request data from in radio network. Default is gateway.


*/
