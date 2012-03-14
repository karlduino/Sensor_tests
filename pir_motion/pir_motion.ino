/* pir motion sensor
 *
 * attached to pin 12; using a 10k pull-down resistor
 * when activated, the pir motion sensor sends 5v to input pin; otherwise low
 */
 
const int inPin = 12;
int iteration=1;

void setup(void)
{
  pinMode(inPin, INPUT);
  Serial.begin(9600);
}

void loop(void)
{
  int reading = digitalRead(inPin);

  Serial.print(iteration);
  Serial.print("\t");
  Serial.println(reading);

  delay(100);

  iteration++;
}
