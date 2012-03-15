/* pir motion sensor, using interrupt 
 *
 * attached to pin 12
 * using a 10k pull-down resistor (probably unnecessary)
 * 
 * I'm using the parallax 555-28027, rev B
 *
 * when activated, the pir motion sensor sends 5v to input pin; otherwise low
 */
 
const int inPin = 2;
unsigned long lastTime=0, curTime;
int reading;
 
void setup(void)
{
  pinMode(inPin, INPUT);
  attachInterrupt(0, printGap, CHANGE);
  Serial.begin(9600);
}


void printGap(void)
{
  curTime = millis();
  reading = digitalRead(inPin);

  Serial.print(reading);
  Serial.print("\t");
  Serial.println(curTime - lastTime);

  lastTime = curTime;
}


void loop(void)
{
}
