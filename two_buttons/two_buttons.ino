/**
 Two momentary pushbuttons and two LEDs
 The LEDs are on only when the corresponding button is held down

 LED connections:
    pin -> resisitor -> LED -> gnd
    
 button connections:
    pin -> button -> gnd

**/

const int LED = 12;
const int BUTTON = 7;

const int LED2 = 9;
const int BUTTON2 = 4;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, HIGH); // turn on pull-up resistor

  pinMode(LED2, OUTPUT);
  pinMode(BUTTON2, INPUT);
  digitalWrite(BUTTON2, HIGH);
}

void loop(){
  digitalWrite(LED, 1-digitalRead(BUTTON));   // button HIGH when released
  digitalWrite(LED2, 1-digitalRead(BUTTON2));

}
