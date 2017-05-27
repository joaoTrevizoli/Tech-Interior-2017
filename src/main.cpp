#include "Arduino.h"
#include "SoilMoisture.hpp"
#include "WiFiManager.hpp"

WiFiConn wifi("H Recreio 19");
IPAddress localIp;

SoilMoisture soilMoisture(A0);

void setup()
{
  Serial.begin(115200);
  wifi.begin();
  Serial.println(wifi.clientLocalIp);
  soilMoisture.begin();
}

void loop()
{
  wifi.checkWiFi();

  Serial.print("Humidity in percentage: ");
  Serial.println(soilMoisture.soilHumidityPercent(0, 100));
  delay(500);
}
