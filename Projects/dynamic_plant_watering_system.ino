#include <Servo.h>
// Change the dry and web value according to you
#define dry 500
#define wet 277
#define Relay_Pin 13

const int sensorPins[] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10};
const int servoPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

const int numSensors = sizeof(sensorPins) / sizeof(sensorPins[0]);

Servo servos[numSensors];

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < numSensors; i++) {
    pinMode(sensorPins[i], INPUT);
    servos[i].attach(servoPins[i]);
    servos[i].write(0); // Initial position: closed
  }

  pinMode(Relay_Pin, OUTPUT);
  digitalWrite(Relay_Pin, LOW); // Start with pump OFF
}

void loop() {
  for (int i = 0; i < numSensors; i++) {
    int moisture = analogRead(sensorPins[i]);
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(" output: ");
    Serial.println(moisture);

    if (moisture >= dry) {
      Serial.println("Status: Soil moisture is Dry -- Need Water");

      // Open only the servo for the dry sensor
      for (int j = 0; j < numSensors; j++) {
        servos[j].write(j == i ? 90 : 0);
      }

      digitalWrite(Relay_Pin, HIGH); // Start watering

      // Keep checking the sensor until soil is wet
      while (analogRead(sensorPins[i]) > wet) {
        Serial.print("Watering... Sensor ");
        Serial.print(i);
        Serial.print(" now reads: ");
        Serial.println(analogRead(sensorPins[i]));
        delay(500); 
      }

      // Stop watering when soil becomes wet
      digitalWrite(Relay_Pin, LOW);
      Serial.println("Soil is wet. Stopping pump.");

      // Close the valve
      servos[i].write(0);
    }
    else if (moisture < dry && moisture > wet) {
      Serial.println("Status: Soil moisture is Perfect");
    }
    else {
      Serial.println("Status: Soil moisture is Too Wet");
    }

    Serial.println("------------------------");
    delay(1000); // Wait a bit before checking the next sensor
  }
}
