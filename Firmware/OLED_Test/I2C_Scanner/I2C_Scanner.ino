/*
 * I2C address scanner — run this first if the display sketches fail.
 *
 * Wiring (Uno):
 *   OLED GND -> GND
 *   OLED VCC -> 5V
 *   OLED SCL -> A5
 *   OLED SDA -> A4
 *
 * Open Serial Monitor at 9600 baud.
 * A working OLED usually answers at 0x3C (or 0x3D).
 */

#include <Wire.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) { /* Leonardo / some boards */ }
  Wire.begin();
  Serial.println(F("\nI2C scanner"));
}

void loop() {
  byte found = 0;

  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print(F("Found device at 0x"));
      if (addr < 16) Serial.print('0');
      Serial.println(addr, HEX);
      found++;
    }
  }

  if (found == 0) {
    Serial.println(F("No I2C devices — check GND/VCC/SCL/SDA"));
  } else {
    Serial.print(found);
    Serial.println(F(" device(s) found"));
  }

  Serial.println(F("---"));
  delay(2000);
}
