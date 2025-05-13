// Define analog input
#define RELAY_PIN 7

void setup() {  
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
      digitalWrite(RELAY_PIN, HIGH);   // turn the RELAY on 
      delay(10000); 
    digitalWrite(RELAY_PIN, LOW);    // turn the RELAY off
    delay(10000);
}
