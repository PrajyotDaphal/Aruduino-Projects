#include <Servo.h>  

Servo s;  // Create a servo object

void setup() {
  s.attach(9);  
}

void loop() {
  // Move from 0° to 180° (forward direction)
  for (int pos = 0; pos <= 180; pos += 5) { 
    s.write(pos);  // Set servo position
    delay(100);  // Small delay for smooth movement
  }

  // Move from 180° back to 0° (reverse direction)
  for (int pos = 180; pos >= 0; pos -= 5) { 
    s.write(pos);  // Set servo position
    delay(100);  // Small delay for smooth movement
  }
}
