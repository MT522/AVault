/*
 * Quick 1.3" I2C OLED smoke test (Arduino Uno)
 *
 * Wiring (Uno):
 *   OLED GND -> GND
 *   OLED VCC -> 5V   (or 3.3V if your module is 3.3V-only)
 *   OLED SCL -> A5
 *   OLED SDA -> A4
 *
 * Libraries (Library Manager):
 *   - Adafruit GFX Library
 *   - Adafruit SSD1306
 *
 * If the screen stays blank or looks garbled, your 1.3" module
 * is probably SH1106 — open OLED_Test_SH1106.ino instead.
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define OLED_ADDR     0x3C   // try 0x3D if nothing shows

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  delay(200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("SSD1306 not found — check wiring / try 0x3D / try SH1106 sketch"));
    for (;;) { delay(1000); }
  }

  Serial.println(F("OLED OK"));

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(10, 8);
  display.println(F("OLED OK"));

  display.setTextSize(1);
  display.setCursor(18, 36);
  display.println(F("1.3\" I2C test"));
  display.setCursor(28, 50);
  display.println(F("Arduino Uno"));
  display.display();
}

void loop() {
  // Blink a corner pixel so you can tell it's alive
  static bool on = false;
  on = !on;
  display.fillRect(120, 56, 6, 6, on ? SSD1306_WHITE : SSD1306_BLACK);
  display.display();
  delay(400);
}
