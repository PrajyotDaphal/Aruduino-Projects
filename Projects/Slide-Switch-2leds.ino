// Connections:
// LDE1 - = GND
// LED1 + = Slide Switch 1:1 (pin no.1) 
// Slide Switch 1:2 (pin no.2) = connect 220ohm resistor then connectto arduino pin no.13
// LED2 + = Slide Switch 1:3 (pin no.3)
// LED2 - = GND

#include <Arduino.h> // remove this line if using Arduino IDE

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
