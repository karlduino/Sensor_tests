/* magnet sensor ("hall effect")
 *
 * with side with numbers facing toward you (mine says U58 136):
 *     left pin to 5V
 *     center pin to ground
 *     right pin to digital input 2
 *     
 *  Also connect 10k pull-up resistor from right pin to 5V
 *     (ensures that, if no magnet, kept high)
 *
 *  Alternatively, you can use the built-in resistor by using 
 *     digitalWrite(magnetSensorPin, HIGH)
 *
 * no magnet: 5V (HIGH)
 * magnet:    ground (LOW)
 * 
 * only detects one pole of the magnet, and it has to be 
 * quite strong and close (like < 1cm)
 */

int magnetSensorPin = 2;

void setup(void)
{
  Serial.begin(9600);
  pinMode(magnetSensorPin, INPUT); 

  // built-in pull-up resistor
  digitalWrite(magnetSensorPin, HIGH); 
}

void loop(void)
{
   int magnetReading = digitalRead(magnetSensorPin);
  
   Serial.print("Digital reading = ");
   if(magnetReading) Serial.println("HIGH (no magnet)");
   else Serial.println("LOW (magnet)");
   
   delay(500);
}
