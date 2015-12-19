/* RHT03 temperture/humidity sensor
   (equivalent to DHT22)
 
   Use DHT sensor library from Adafruit, https://github.com/adafruit/DHT-sensor-library
   This is based on the example with that library

   pin 1 (far left) of RHT03 to V5
   pin 2 to arduino digital pin (I'm using A0) + with 10k resistor to pin 1
   pin 3 unconnected
   pin 4 to ground

 */

#include "DHT.h"

#define DHTPIN  A0
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("RHT03 test.");

  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(true);

  if(isnan(h) || isnan(t))
    Serial.println("Failed to read from sensor.");
  else {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print("%    ");
    Serial.print("Temp: ");
    Serial.print(t);
    Serial.println("*F");
  }
  
  delay(2000); // only get a reading every 2 sec
}
