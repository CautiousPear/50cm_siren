const int trigPin = 9;
const int echoPin = 10;
const int sirenPin = 11;

float distance;
float duration;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sirenPin, OUTPUT);
  digitalWrite(sirenPin, LOW);
  Serial.begin(9600);
}

void loop() {
  /*digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 30000);  // 30ms timer
  
  if (duration == 0) { // If no sound back in 30ms, read invalid
    Serial.println("No Echo Detected");
  } else {
    distance = duration * 0.0343 / 2; 
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
  if (distance > 0 && distance < 50) {
    digitalWrite(sirenPin, HIGH);
    Serial.println("Siren ON");
  } else {
    digitalWrite(sirenPin, LOW);
  }
  delay(100);
  }*/
}
