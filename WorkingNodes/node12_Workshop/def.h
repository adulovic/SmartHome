
/*  SENSORS
=========1=========2=========3=========4=========5=========6=========7========*/
#define S1              1               // Voltage


/*  PINS & VARIABLES
=========1=========2=========3=========4=========5=========6=========7========*/
const int pinS1 =       A4;             // Digital pin number for the relay
MyMessage msgS1(S1, V_VOLTAGE);         // type of message sent to MySensors
float ADCVal;
float pinVoltage;
float batteryVoltage;
int ratio =             4;


/*
    20v as the input, 5v as the output, 3k for R1 and 1k for R2
    Vout = (R2 / (R1 + R2)) * Vin
    Vout = (1000 / (3000 + 1000)) * 20
    Vout = (1000 / 4000) * 20 = 0.25 * 20 = 5 
    Ratio = 20v / 5v = 4

    Because the Arduino has a 10-bit ADC, it outputs 0-1023 (1024 steps) for a 0-5v input. That's 0.00488v / step
*/
