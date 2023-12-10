#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --------- CONNECTION ---------
//       ESP8266 --> Oled Display
//         3.3V  -->  VCC
//          D1   -->  SDA
//          D2   -->  SCL
// --------- CONNECTION ---------

const char *ssid = "EspWiFi";
const char *password = "TvojeHeslo";

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  connectToWiFi();
  setupDisplay();
}

void loop() {
  // Implementuj kód pre prijatie údajov od prvého ESP8266 cez UDP alebo TCP

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
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
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
