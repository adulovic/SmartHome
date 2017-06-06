
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define A1              1               // Relay for BBQ floodlight
#define A3              2               // InfraRed transmitter 
#define S3T             3               // Temperature
#define S3B             4               // Pressure
#define S7              5               // Water Temperature
#define S8              6               // UV


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/

// A1 - Relay for BBQ floodlight
// -----------------------------
const int pinA1 =       2;              // the pin that the relay is atteched to
bool stateA1;                           // state of the button in the controller

// A3 - InfraRed transmitter - (RGB LED diode), to control the RGB strip
// -------------------------
const int pinA3 =       3;              // the data pin must be PWM

// S3 - Barometric Pressure
// ------------------------
const int pinS3sdl =    A4;             // data pin for SDL (data)
const int pinS3scl =    A5;             // data pin for SCL (clock)
unsigned long tS3 = 0;                  // will store last time loop fired
unsigned long iS3 = 5*60;               // interval at which to fire loop (seconds)

// S7 - Water temperature, a Dallas 
// ----------------------
const int pinS7 =       4;              // data pin
unsigned long tS7 = 0;                  // will store last time loop fired
unsigned long iS7 = 10*60;              // interval at which to fire loop (seconds)

// S8 - UV receiver
// ----------------
const int pinS8sdl =    A2;             // data pin for SDL (data)
const int pinS8scl =    A3;             // data pin for SCL (clock)
uint16_t valueS8 = 0;                   // reading the sensor status
unsigned long tS8 = 0;                  // will store last time loop fired
unsigned long iS8 = 5*60;               // interval at which to fire loop (seconds)
float uvIndex;
uint16_t uvIndexValue [12] = { 50, 227, 318, 408, 503, 606, 696, 795, 881, 976, 1079, 1170};

