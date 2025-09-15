#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin(5, 4); // SDA = GPIO5, SCL = GPIO4
  delay(1000);

  Serial.println("Initializing MPU6050...");

  if (!mpu.begin(0x68, &Wire)) {
    Serial.println("Failed to find MPU6050 chip at 0x68");
    while (1) { delay(10); }
  }
  Serial.println("MPU6050 found!");

  // Configure sensor ranges
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
}
