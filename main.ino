const int trigPin = 9;
const int echoPin = 10;
const int sirenPin = 11;

float distance;
float duration;

#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sirenPin, OUTPUT);
  digitalWrite(sirenPin, LOW);
  Serial.begin(9600);
  lcd.begin(16, 2);
  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 30000);  // 30ms timer
  
  if (duration == 0) { // If no sound is detected in 30ms
    Serial.println("No Echo Detected");
    lcd.setCursor(0, 0);
    lcd.print("No Echo Detected");
  } else {
    distance = duration * 0.0343 / 2; 

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    lcd.clear();  // Clear LCD before printing
    lcd.setCursor(0, 0);
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm");
  }
  if ((distance <= 50) && (distance != 0)) {
      tone(sirenPin, (2000-(40*distance))); //Siren frequency
  } else {
      noTone(sirenPin); //Stop if >50cm or none detected
  }
  lcd.setCursor(0, 1);
  lcd.print("Uptime: ");
  lcd.print(millis() / 1000);
  lcd.print("s  ");

  delay(100);
}
