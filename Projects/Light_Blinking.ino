// Connections:
// GND = GND Pin
// Before  LED positive is connecting to Arduino connect 1k resistor between arduino and LED connection  

#include <Arduino.h> // remove this line if using Arduino IDE
  
void setup() {
  pinMode(13, OUTPUT); // Set pin 13 as an output
}

void loop() {
  digitalWrite(13, HIGH); // Turn the LED on
  delay(1000);           // Wait for 1 second
  digitalWrite(13, LOW);  // Turn the LED off
  delay(1000);           // Wait for 1 second
}
