/****
 Press button to turn LED on; press again to turn off
 including simple de-bouncing

 From Massimo Banzi, _Getting started with Arduino_, Ch 4, pg 49

 I have the button with a pull-down resistor, so pressed=HIGH; unpressed = LOW
    digital pin 7 -> ]
                     ] -> button -> 5V
    GND -> 10k Ohm   ]

 The LED is connected to digital pin 12 with a 680 Ohm resistor:
    digital pin 12 -> led -> 680 Ohm -> GND
****/

const int LED = 12;   // pin for LED
const int BUTTON = 7; // pin for pushbutton

int button_val = 0;      // state of button
int prev_button_val = 0; // previous state of button
int led_state = 0;       // state of LED: 0 = off; 1 = on

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop(){
  button_val = digitalRead(BUTTON); // read input value and store it

  // check if there was a transition
  if ((button_val == HIGH) && (prev_button_val == LOW)){
    led_state = 1 - led_state;
    delay(20);
  }

  prev_button_val = button_val;
  if (led_state == 1) {
    digitalWrite(LED, HIGH); // LED on
  } else {
    digitalWrite(LED, LOW);  // LED off
  }
}
