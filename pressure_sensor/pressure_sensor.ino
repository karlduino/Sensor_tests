/* pressure sensor
 *
 * based on code from www.ladyada.net/learn/sensors
 *
 * This could be identical to the light sensor (photocell)
 * 
 * one leg of pressure sensor connected to 5V
 * the other connected to analog input (here, pin 5)
 *     as well as a 10k pull-down resistor connected to ground
 * 
 * when light pressure: sensor has 100k ohm resistance
 * when max pressure:   sensor has  200 ohm resistance
 * if no pressure, connected to ground
 *
 * have LED attached to pin 11; lit brighter when photocell reads darker
 */

int photocellPin = 5;
int LEDpin = 11;

void setup(void)
{
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
  pinMode(photocellPin, INPUT);
}

void loop(void)
{
  int photocellReading;
  int LEDbrightness;

  photocellReading = analogRead(photocellPin);
 
  Serial.print("Raw analog reading = ");
  Serial.print(photocellReading);
  // 0 = no pressure; 1023 = max pressure

  // make LED more bright when more pressure
  if(photocellReading > 50) {
    LEDbrightness = map(photocellReading, 50, 1023, 0, 255);

    Serial.print("\tLED brightness = ");
    Serial.println(LEDbrightness);

    analogWrite(LEDpin, LEDbrightness);
  }
  else {
    Serial.println("\tLED off");
    digitalWrite(LEDpin, LOW);
  }
 
  delay(100);
}
