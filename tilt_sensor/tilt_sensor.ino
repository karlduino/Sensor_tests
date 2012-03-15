/* tilt sensor test, with a debouncer
 *
 * Code based on http://www.ladyada.net/learn/sensor/tilt.html
 *
 * one leg to ground
 * other leg to digital input 7
 *     input leg also connects to 10k ohm pull-up resistor that is connected to 5v
 *     (could just use the built-in pull-up resistor)
 * 
 * tilt sensor is normally closed
 *   not tilted (closed): connected to ground (LOW)
 *   tilted (open):       connected to 5V     (HIGH)
 *
 * LED connected to 13 (or just the built-in LED at 13)
 */

int inPin = 7;
int outPin = 13;

int LEDstate = HIGH;
int reading;
int previousReading = LOW;

long lastTime = 0;
long debounceTime = 50;
 
void setup(void)
{
  pinMode(inPin, INPUT);
  digitalWrite(inPin, HIGH);   // turn on the built in pull-up resistor
  pinMode(outPin, OUTPUT);

  Serial.begin(9600);
}
 
void loop(void)
{
  reading = digitalRead(inPin);

  if (reading != previousReading) { // change in state
    // reset the debounce timer
    lastTime = millis();
  } 
 
  if((millis() - lastTime) > debounceTime) { // long time since last change
    if(reading == HIGH) {
      LEDstate = HIGH;
      Serial.println("High");
    }
    else {
      LEDstate = LOW;
      Serial.println("Low");
    }
  }
  digitalWrite(outPin, LEDstate);
 
  // Save the last reading so we keep a running tally
  previousReading = reading;
}
