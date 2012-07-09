/****
 Momentary pushbutton: LED on only when button is held down

 From Massimo Banzi, _Getting started with Arduino_, Ch 4

 I have the button with a pull-down resistor, so pressed=HIGH; unpressed = LOW
    digital pin 7 -> ]
                     ] -> button -> 5V
    GND -> 10k Ohm   ]

 The LED is connected to digital pin 12 with a 680 Ohm resistor:
    digital pin 12 -> led -> 680 Ohm -> GND
****/

const int LED = 12;   // pin for LED
const int BUTTON = 7; // pin for pushbutton

void setup() {
  pinMode(LED, OUTPUT); // tell Arduino LED is an output
  pinMode(BUTTON, INPUT); // and BUTTON is an input
}

void loop(){
  digitalWrite(LED, digitalRead(BUTTON));
}
