/* light detector (photocell)
 *
 * based on code from www.ladyada.net/learn/sensors/cds.html
 *
 * one leg of photocell connected to 5V
 * the other connected to analog input (here, pin 5)
 *     as well as a 10k pull-down resistor connected to ground
 * 
 * when very dark:   photo sensor has 200k ohm resistance
 * when very bright: photo sensor has  10k ohm resistance
 * if totally dark, connected to ground
 *
 * for better discrimination in brighter light, use a 1k ohm resistor
 * (but this would give less sensitivity in dim light)
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
  // 0 = dark; 1023 = bright

  // make LED more bright when it's darker
  if(photocellReading < 800) {
    LEDbrightness = map(photocellReading, 0, 800, 255, 0);

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
