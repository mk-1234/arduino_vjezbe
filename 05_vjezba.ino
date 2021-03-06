#include <Servo.h>

int motorPin = 9;
int trigPin = 13;
int echoPin = 12;

Servo servo;

void setup() {
  Serial.begin(9600);
  
  pinMode(motorPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  servo.attach(motorPin);
  servo.write(0);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print("Udaljenost: ");
  Serial.print(distance);
  Serial.print(" cm --- ");
  distance = (distance > 100) ? 100 : distance;
  servo.write(1.8 * distance);
  Serial.print("Kut: ");
  Serial.println(servo.read());
  delay(500);
}