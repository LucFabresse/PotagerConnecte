#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// BH1750 => 0x23
// BME280 => 0x76
// BMP180 => 0x77

Adafruit_BME280 bme; // I2C

void setup() {
  Serial.begin(115200);
  Serial.println(F("BMP280 test"));

  Wire.begin(SDA,SCL);

  Serial.print("SDA = ");
  Serial.println(SDA);

  Serial.print("SCL = ");
  Serial.println(SCL);

//   SDA = 4
//   SCL = 5

  Serial.println("Look for BMP280 sensor");
  while (!bme.begin(0x76)) {
    Serial.print(".");
    delay(1000);
  }
}

void loop() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bme.readPressure());
    Serial.println(" Pa");

    Serial.print("Approx altitude = ");
    Serial.print(bme.readAltitude(1013.25)); // this should be adjusted to your local forcase
    Serial.println(" m");

    Serial.println();
    delay(5000);
}