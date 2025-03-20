const int trigPin = 9;
const int echoPin = 10;
const int sirenPin = 11;

float distance;
float duration; //Duration until wave return

#include <LiquidCrystal.h> //LCD library

const int rs = 7, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sirenPin, OUTPUT);
  digitalWrite(sirenPin, LOW);
  Serial.begin(9600); //9600 baud monitor
  lcd.begin(16, 2); //display size
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 30000);  // 30ms timer
  
  if (duration == 0) { // If no sound back in 30ms, read invalid
    Serial.println("No Echo Detected");
    lcd.setCursor(0, 0);
    lcd.print("No Echo Detected");
  } else {
    distance = duration * 0.0343 / 2; 
    
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    lcd.clear();  // Clear LCD before printing
    lcd.setCursor(0, 0); //Start LCD print at top leftmost square
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print(" cm");

    lcd.setCursor(0, 1); //Start LCD at bottom leftmost square
    lcd.print("Uptime: ");
    lcd.print(millis() / 1000);
    lcd.print("s  ");
    
  if (distance > 0 && distance < 50) { //Siren if >0cm and <50cm
    digitalWrite(sirenPin, HIGH);
    Serial.println("Siren ON");
  } else {
    digitalWrite(sirenPin, LOW); 
  }
  delay(500);
  }
}
