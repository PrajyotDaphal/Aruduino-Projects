Connections:
//VCC = 5V
//GND = GND pin
#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 8    

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
// below different versions of DHT
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");

  dht.begin();
}

void loop() {
  delay(2000);  

  float h = dht.readHumidity();          
  float t = dht.readTemperature();       
  // float f = dht.readTemperature(true); // Read temperature in Fahrenheit 

  if (isnan(h) || isnan(t)) {  
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false); 
  // float hif = dht.computeHeatIndex(f, h); // Compute heat index in Fahrenheit 

  // Print in Celsius
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.println(" *C");
  // Print in Fahrenheit
  //Serial.print("Humidity: ");
  //Serial.print(h);
  //Serial.print(" %\t");
  //Serial.print("Temperature: ");
  //Serial.print(f);
  //Serial.print(" *F\t");
  //Serial.print("Heat index: ");
  //Serial.print(hif);
  //Serial.println(" *F");*/

}
