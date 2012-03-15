/* temperature sensor
 *
 * with flat side with numbers facing toward you (mine says TMP / 36GZ / # 1139 / 217182
 *
 *     left pin to 3.3V (5V would work too, but with 3.3V results are more precise)
 *     center pin to analog input 5
 *     right pin to ground
 *     
 * Convert 0-1023 input to 0-5000 mV
 *
 * temp in deg C = (mV - 500) / 10
 */


int tempPin = 5;  // analog input

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  int tempReading;
  float temp_mV, tempC, tempF;

  tempReading = analogRead(tempPin);  // returns 0-1023

  temp_mV = map(tempReading, 0, 1023, 0, 5000); // convert to milliVolts

  tempC = (temp_mV - 500)/10;
  tempF = 9*tempC/5 + 32;
  
  Serial.print("Analog reading = ");
  Serial.print(tempReading);
  Serial.print("\tmV=");
  Serial.print(temp_mV);
  Serial.print("\tdeg C=");
  Serial.print(tempC);
  Serial.print("\tdeg F=");
  Serial.print(tempF);
  Serial.print("\n");
   
  delay(1000);
}
