/* pir motion sensor, using interrupt 
 *
 * attached to pin 2; using a 10k pull-down resistor
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
