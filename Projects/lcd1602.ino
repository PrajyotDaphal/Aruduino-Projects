// Connections:
// VSS, RW, K = GND
// VDD, A = 5V  Before a is connecting to 5V place 220ohm resistro betwen A and 5V connection
// RS = Pin no 7 
// E = Pin no 6
// D4 = Pin no 5
// D5 = Pin no 4
// D6 = Pin no 3
// D7 = Pin no 2

#include <Arduinio.h> // remove this line if using Arduino IDE
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello World!");
}

void loop() {
}
