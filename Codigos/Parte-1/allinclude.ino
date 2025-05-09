#include <Wire.h>
#include <MPU6050.h>

MPU6050 imu;

int IN1 = 7;
int IN2 = 6;
int IN3 = 4;
int IN4 = 3;

int TRIG = 9;
int ECHO = 8;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Wire.begin();
  imu.initialize();

  Serial.begin(9600);
  while (!imu.testConnection());
}

void loop() {
  moverAdelante();
  delay(1000);
  detenerMotores();
  delay(500);

  float distancia = medirDistancia();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  leerIMU();
  delay(1000);

  moverAtras();
  delay(1000);
  detenerMotores();
  delay(500);

  moverIzquierda();
  delay(1000);
  detenerMotores();
  delay(500);

  moverDerecha();
  delay(1000);
  detenerMotores();
  delay(500);
}

void moverAdelante() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moverAtras() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moverIzquierda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moverDerecha() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void detenerMotores() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

float medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duracion = pulseIn(ECHO, HIGH);
  return duracion * 0.034 / 2;
}

void leerIMU() {
  int16_t ax, ay, az, gx, gy, gz;
  imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  Serial.print("Giro Z: ");
  Serial.print(gz / 131.0);
  Serial.print(" | Inclinación Y: ");
  Serial.println(ay);
}
