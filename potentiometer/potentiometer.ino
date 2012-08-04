/**
 * Potentiometer example
 *
 * 2k pot with pins attached to 3.3V, analog input 0, and ground
 * With knob pointing towards you and pins pointing down, put 
 * right pin to 3.3V and left pin to ground.  Then, turning the
 * knob to the right will give higher values (0-1023)
 **/

const int sensorPin = 0;
int sensorValue = 0;

const int ledPin1 = 10, ledPin2 = 11;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  analogWrite(ledPin1, sensorValue/4);
  analogWrite(ledPin2, sensorValue/4);
  Serial.println(sensorValue);
}
