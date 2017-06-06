
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define A1              1               // Relay
#define S1              2               // Reed switch
#define S14             3               // MQ2 (Gas/Smoke)


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/

// A1 - Relay for lights
// ---------------------
const int pinA1 =       2;              // the pin that the relay is atteched to

// S1 - Reed switch - pantry
// -----------------------
const int pinS1 =       3;              // data pin with pull-up resistor
int valueS1 = 0;                        // reading the sensor status
int stateS1 = 0;                        // storing the last state

// S14 - Gas/Smoke
// -----------------------
const int pinS14 =     A0;             // data pin
#define         RL_VALUE                     (5)     //define the load resistance on the board, in kilo ohms
#define         RO_CLEAN_AIR_FACTOR          (9.83)  //RO_CLEAR_AIR_FACTOR=(Sensor resistance in clean air)/RO, which is derived from the chart in datasheet
#define         CALIBARAION_SAMPLE_TIMES     (50)    //define how many samples you are going to take in the calibration phase
#define         CALIBRATION_SAMPLE_INTERVAL  (500)   //define the time interal(in milisecond) between each samples in the calibration phase
#define         READ_SAMPLE_INTERVAL         (50)    //define how many samples you are going to take in normal operation
#define         READ_SAMPLE_TIMES            (5)     //define the time interal(in milisecond) between each samples in normal operation
#define         GAS_LPG                      (0)
#define         GAS_CO                       (1)
#define         GAS_SMOKE                    (2)
float Ro = 10000.0;    // this has to be tuned 10K Ohm
int valueS14 = 0;           // variable to store the value coming from the sensor
float valMQ =0.0;
float lastMQ =0.0;
float LPGCurve[3]  =  {2.3,0.21,-0.47};   //two points are taken from the curve. with these two points, a line is formed which is "approximately equivalent" to the original curve.
//data format:{ x, y, slope}; point1: (lg200, 0.21), point2: (lg10000, -0.59)
float COCurve[3]  =  {2.3,0.72,-0.34};    //two points are taken from the curve. with these two points, a line is formed which is "approximately equivalent" to the original curve.
//data format:{ x, y, slope}; point1: (lg200, 0.72), point2: (lg10000,  0.15)
float SmokeCurve[3] = {2.3,0.53,-0.44};   //two points are taken from the curve. with these two points, a line is formed which is "approximately equivalent" to the original curve.
//data format:{ x, y, slope}; point1: (lg200, 0.53), point2:(lg10000,-0.22)
