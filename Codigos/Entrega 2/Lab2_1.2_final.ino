
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define trigPin 9
#define echoPin 8

#define RGB_R A0
#define RGB_G A1
#define RGB_B A2

#define motorA1 2
#define motorA2 3
#define motorB1 4
#define motorB2 5
#define ENA 6
#define ENB 7

long readUltrasonicDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}

String detectColor() {
  int r = analogRead(RGB_R);
  int g = analogRead(RGB_G);
  int b = analogRead(RGB_B);
  if (r > g && r > b && r > 200) return "RED";
  if (g > r && g > b && g > 200) return "GREEN";
  if (b > r && b > g && b > 200) return "BLUE";
  return "UNKNOWN";
}

void moveForward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void moveBackward() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void turnLeft() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void turnRight() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void stopMotors() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RGB_R, INPUT);
  pinMode(RGB_G, INPUT);
  pinMode(RGB_B, INPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  long distance = readUltrasonicDistance();
  String color = detectColor();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Color: ");
  Serial.println(color);

  if (distance < 10) {
    stopMotors();
  } else if (color == "RED") {
    turnLeft();
  } else if (color == "GREEN") {
    turnRight();
  } else if (color == "BLUE") {
    moveForward();
  } else {
    stopMotors();
  }

  delay(200);
}
