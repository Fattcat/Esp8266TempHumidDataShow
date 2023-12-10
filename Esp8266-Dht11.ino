#include <ESP8266WiFi.h>
#include <DHT.h>

const char *ssid = "TvojeSSID";
const char *password = "TvojeHeslo";

const char *serverIP = "IP_adresa_druheho_ESP8266";
const int serverPort = 80;

DHT dht(D2, DHT11);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Odoslanie údajov na druhý ESP8266
  sendToServer(temperature, humidity);

  delay(6000);  // Pauza 6 sekúnd
}

void sendToServer(float temp, float hum) {
  // Implementuj kód pre odosielanie údajov na druhý ESP8266 cez HTTP POST request
}
