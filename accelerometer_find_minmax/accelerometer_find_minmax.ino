/**********************************************************************
 * accelerometer_find_minmax
 * Find min and max xyz values for ADXL335 accelerometer
 **********************************************************************/

// analog read pins
const int pins[3] = {2, 1, 0};
const int yPin = 1;
const int zPin = 0;

int minval[3] = {1000, 1000, 1000};
int maxval[3] = {-1000, -1000, -1000};
int reading[3];

void setup(){
  Serial.begin(9600);
}

void loop(){
  int i;

  // read analog pins; compare to min/max
  for(i=0; i<3; i++) {
    reading[i] = analogRead(pins[i]);
    minval[i] = min(minval[i], reading[i]);
    maxval[i] = max(maxval[i], reading[i]);
  }

  for(i=0; i<3; i++) {
    Serial.print(minval[i]);
    Serial.print("|");
    Serial.print(maxval[i]);
    Serial.print("\t");
  }
  Serial.println();
}

// readings: x = 234 | 418    261 | 407
//           y = 251 | 424    255 | 418
//           z = 265 | 467    261 | 486


