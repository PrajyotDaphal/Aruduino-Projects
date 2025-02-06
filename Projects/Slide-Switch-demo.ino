// Connections:
// LED + = pin 13
// LED - = GND
// Slide Switch 1:3 (pin no.3) = Pin no.5
// Sliden Switch 1:2 (pin no.2) = GND

#include <Arduino.h> // remove this line if using Arduino IDE

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(5, INPUT_PULLUP);
}

void loop() {
  digitalWrite(LED_BUILTIN, digitalRead((5)));
}
