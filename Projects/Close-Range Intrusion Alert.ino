constexpr uint8_t EchoPin = 7;
constexpr uint8_t TrigPin = 8;
constexpr uint8_t BuzzPin = 10;
constexpr uint16_t frequency = 555;

float distance , duration; 

void setup() {
  Serial.begin(9600);
  pinMode(BuzzPin, OUTPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  digitalWrite(BuzzPin, LOW);

}

void loop() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  duration = pulseIn(EchoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance : ");
  Serial.println(distance);
  delay(100);

  if( duration > 0 && distance < 10 ){
    tone(BuzzPin, frequency);
  }
  else{
    noTone(BuzzPin);
  }

}
