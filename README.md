# Esp8266TempHumidDataShow
Esp8266 code for send data from first Esp8266 (temperature and Humidity) outside from house and show on 0.96 Oled Display on second Esp8266.

# Connection
## First module
ESP8266 --> Oled Display
- 3.3V  -->  VCC
- GND   -->  GND
- D1    -->  SDA
- D2    -->  SCL

## Second module
ESP8266 --> DHT11
- 3.3V  -->  VCC
- D2    -->  DHT Pin

