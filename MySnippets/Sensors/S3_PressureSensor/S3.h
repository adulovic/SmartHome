/*
    Barometric Pressure Sensor
*/


/*  LIBRARIES
=========1=========2=========3=========4=========5=========6=========7========*/
#include <Wire.h>                      // include libraries
#include "Adafruit_BMP085.h"
Adafruit_BMP085 bmp;

/* Initialize
=========1=========2=========3=========4=========5=========6=========7========*/
MyMessage msgS3T(S3T, V_TEMP);          // message sent to MySensors
MyMessage msgS3B(S3B, V_PRESSURE);      // message sent to MySensors


/* Setup
=========1=========2=========3=========4=========5=========6=========7========*/
void setupS3(){
    if( bmp.begin()){
        Serial.println("~~~ bmp started ~~~" );
    } else {
        Serial.println("~~~ bmp has a problem ~~~" );
    }
}


/* Loop
=========1=========2=========3=========4=========5=========6=========7========*/
void loopS3(){
    Serial.print("Temperature = "); Serial.print(bmp.readTemperature()); Serial.println(" C");
    send(msgS3T.set( bmp.readTemperature(),2 ));
    Serial.print("Pressure = "); Serial.print(bmp.readPressure()); Serial.println(" Pa");
    send(msgS3B.set( bmp.readPressure(),2 ));
    Serial.println();
}

