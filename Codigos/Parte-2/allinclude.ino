#include <Wire.h>
#include <MPU6050.h>

MPU6050 imu;

int IN1 = 7;
int IN2 = 6;
int ENA = 5;

int IN3 = 4;
int IN4 = 3;
int ENB = 10;

float velocidad = 200;  //
unsigned long t_anterior = 0;
float orientacion_deseada = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Wire.begin();
  imu.initialize();

  Serial.begin(9600);
  while (!imu.testConnection());

  orientacion_deseada = obtenerGiroZ();
  t_anterior = millis();
}

void loop() {
  unsigned long t_actual = millis();
  float dt = (t_actual - t_anterior) / 1000.0;
  t_anterior = t_actual;

  float giro_actual = obtenerGiroZ();
  float error = giro_actual - orientacion_deseada;

  if (abs(error) < 5) {
    moverAdelante(velocidad);
  } else if (error > 5) {
    corregirIzquierda(velocidad);
  } else if (error < -5) {
    corregirDerecha(velocidad);
  }

  float distancia = velocidad * dt;
  Serial.print("Distancia estimada: ");
  Serial.print(distancia, 2);
  Serial.print(" m | Giro Z: ");
  Serial.println(giro_actual);

  delay(100);
}

void moverAdelante(int velocidad) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidad);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidad);
}

void corregirIzquierda(int velocidad) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidad);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidad);
}

void corregirDerecha(int velocidad) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidad);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidad);
}

float obtenerGiroZ() {
  int16_t gx, gy, gz, ax, ay, az;
  imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  return gz / 131.0; // en grados por segundo
}
