/**********************************************************************
 * accelerometer sensor, for ADXL335
 *
 * based on code from
 *   http://bildr.org/2011/04/sensing-orientation-with-the-adxl335-arduino/
 *
 * The 6 pins are well labeled, and there's also an indication of 
 * the X, Y, and Z directions
 * 
 * connect 3V to 3.3V, GND to ground, and x,y,z to analog input pins
 **********************************************************************/ 

// pins
const int Pins[3] = {2, 1, 0};

// min and max values (from accelerometer_find_minmax)
const int minVal[3] = {261, 255, 261};
const int maxVal[3] = {418, 424, 486};

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
  int i, readings[3];
  double angles[3], xyz[3];

  for(i=0; i<3; i++) {
    // read pin
    readings[i] = analogRead(Pins[i]);

    // convert to degrees -90 to 90
    angles[i] = map(readings[i], minVal[i], maxVal[i], -90, 90);
  }

  // Calculate 360 deg values like so: atan2(-yAng, -zAng)
  // atan2 outputs the value of -π to π (radians)
  // We then convert the radians to degrees
  xyz[0] = RAD_TO_DEG * (atan2(-angles[0], -angles[2]) + PI);
  xyz[1] = RAD_TO_DEG * (atan2(-angles[1], -angles[2]) + PI);
  xyz[2] = RAD_TO_DEG * (atan2(-angles[1], -angles[0]) + PI);

  // Print 
  for(i=0; i<3; i++) {
    Serial.print(xyz[i]);
    Serial.print(" | ");
  }
  Serial.println();

  delay(500);
}
