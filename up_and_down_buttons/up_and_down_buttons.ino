/****
  Up and down buttons

  Test my understanding of pull-up and pull-down resistors

  button 2: pull-up resistor, so pressed = LOW; unpressed = HIGH
    digital pin 2 -> ]
                     ] -> button -> GND
    5V  -> 10k Ohm   ]


  button 7: pull-down resistor, so pressed = HIGH; unpressed = LOW
    digital pin 7 -> ]
                     ] -> button -> 5V
    GND -> 10k Ohm   ]
****/

const int button2pin = 2, button7pin = 7;

int button2state, button7state;

void setup()
{
  Serial.begin(9600);
  pinMode(button2pin, INPUT);
  pinMode(button7pin, INPUT);
}

void loop()
{
  button2state = digitalRead(button2pin);
  button7state = digitalRead(button7pin);

  Serial.print("button 2 = ");
  if(button2state) {
    Serial.print("high    ");
  } else {
    Serial.print("low     ");
  }

  Serial.print("button 7 = ");
  if(button7state) {
    Serial.println("high");
  } else {
    Serial.println("low");
  }

  delay(500);
}
