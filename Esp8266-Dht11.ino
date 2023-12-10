#include <ESP8266WiFi.h>
#include <DHT.h>

// --------- CONNECTION ---------
//       ESP8266 --> DHY 11
//         3.3V  -->  VCC
//          D2   -->  DHT Pin
// --------- CONNECTION ---------

const char *ssid = "EspWiFi";
const char *password = "TvojeHeslo";

DHT dht(D2, DHT11);

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Implementuj kód pre odoslanie údajov na druhý ESP8266 cez UDP alebo TCP

  delay(6000);  // Pauza 6 sekúnd
}
