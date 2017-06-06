// for webserver
#include <swDuino.h>
swDuino objswDuino;

// for DHT11,
#include <SimpleDHT.h>
//  VCC: 5V or 3V
//  GND: GND
//  DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11;

// set variables
byte temperature = 0;
byte humidity = 0;
byte data[40] = {0};

const int redLED = 13;
const int yellowLED = 12;
const int sensorLight = A0;
const float Res = 10;                         // using a 10k resistor

// --------------------------------------------------
void setup() {
  objswDuino.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}

// --------------------------------------------------
void loop() {
  // read data from temp/humidity sensor
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    //Serial.print("Read DHT11 failed");
    return;
  }
  // read data from light sensor
  int light = analogRead(sensorLight);
  float Vout = light * 0.0048828125;      // calculate the voltage
  int lux = 500 / Res* ( (5-Vout) / Vout ) ;    // calculate the Lux
  // sample data
  // 925 -> 795 lx
  // 800 -> 40 lx
  // 400 -> 0 lx

  // write data to webserver
  objswDuino.write("M", String(int(millis() / 1000 / 60)));
  objswDuino.write("T", String((int)temperature));
  objswDuino.write("H", String((int)humidity));
  objswDuino.write("L", String((int)light));

  // read the trigger
  objswDuino.read(trigger);

  delay(500);
}

// --------------------------------------------------
void trigger(String VARIABLE, String VALUE) {
  if (VARIABLE == "redLED" && VALUE == "1") {
    digitalWrite(redLED, HIGH);
  }
  else if (VARIABLE == "redLED" && VALUE == "0") {
    digitalWrite(redLED, LOW);
  }
  else if (VARIABLE == "yellowLED" && VALUE == "1") {
    digitalWrite(yellowLED, HIGH);
  }
  else if (VARIABLE == "yellowLED" && VALUE == "0") {
    digitalWrite(yellowLED, LOW);
  }
}
