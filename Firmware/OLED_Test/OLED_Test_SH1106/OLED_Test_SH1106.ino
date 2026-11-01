/*
 * 1.3" I2C OLED smoke test — SH1106 controller (common on 1.3")
 *
 * Wiring (Uno):
 *   OLED GND -> GND
 *   OLED VCC -> 5V
 *   OLED SCL -> A5
 *   OLED SDA -> A4
 *
 * Libraries (Library Manager):
 *   - Adafruit GFX Library
 *   - Adafruit SH110X
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define OLED_ADDR     0x3C   // try 0x3D if nothing shows

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  delay(200);

  if (!display.begin(OLED_ADDR, true)) {
    Serial.println(F("SH1106 not found — check wiring / try 0x3D"));
    for (;;) { delay(1000); }
  }

  Serial.println(F("OLED OK (SH1106)"));

  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);

  display.setTextSize(2);
  display.setCursor(10, 8);
  display.println(F("OLED OK"));

  display.setTextSize(1);
  display.setCursor(10, 36);
  display.println(F("1.3\" SH1106 test"));
  display.setCursor(28, 50);
  display.println(F("Arduino Uno"));
  display.display();
}

void loop() {
  static bool on = false;
  on = !on;
  display.fillRect(120, 56, 6, 6, on ? SH110X_WHITE : SH110X_BLACK);
  display.display();
  delay(400);
}
