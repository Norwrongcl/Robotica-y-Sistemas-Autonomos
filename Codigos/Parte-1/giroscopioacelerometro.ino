#include <Wire.h>
#include <MPU6050.h>

MPU6050 imu;

void setup() {
  Wire.begin();
  imu.initialize();
  Serial.begin(9600);
  while (!imu.testConnection());
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  Serial.print("Giro Z: ");
  Serial.print(gz / 131.0);
  Serial.print(" | Inclinación Y: ");
  Serial.println(ay);

  delay(300);
}
