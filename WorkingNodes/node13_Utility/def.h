#include <IRremote.h>
#include <IRremoteInt.h>
/*  
    SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define A1              1               // Relay for lights
#define S4              2               // PIR Switch
#define S16             3               // IR rx sensor
/*  
    PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/
//
// A1 - Relay for lights
// ---------------------
const int pinA1 =       2;               // data pin
bool valueA1 = 0;                        // value read from pin
//
// S4 - PIR switch
// ----------------
const int pinS4 =       3;               // data pin
bool valueS4 = 0;                        // value read from pin
bool stateS4 = 0;                        // last saved state
unsigned long tS4 = 0;                   // timer
//
// S16 - IR rx
// -----------
const int pinS16 =      4;              // data pin
float valueS16 = 0;                     // value read from pin
float stateS16 = 0;                     // last saved state
//
