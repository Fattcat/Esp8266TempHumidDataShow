#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  setupDisplay();
}

void loop() {
  // Prijatie údajov od prvého ESP8266
  float temperature = 25.5;  // Nahrad s reálnymi údajmi
  float humidity = 60.0;    // Nahrad s reálnymi údajmi

  // Zobrazenie údajov na displeji
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Teplota:");
  display.setCursor(0, 16);
  display.print(temperature);
  display.println(" \xB0C");
  display.setCursor(0, 40);
  display.println("Vlhkost:");
  display.setCursor(0, 56);
  display.print(humidity);
  display.println(" %");
  display.display();

  delay(6000);  // Pauza 6 sekúnd

  // Vypnutie displeja na 2 sekundy
  displayOff();
  delay(2000);
  displayOn();
}

void setupDisplay() {
  if (!display.begin(SSD1306_I2C, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);
  display.display();
  delay(2000);
  display.clearDisplay();
}

void displayOff() {
  display.ssd1306_command(SSD1306_DISPLAYOFF);
}

void displayOn() {
  display.ssd1306_command(SSD1306_DISPLAYON);
}
