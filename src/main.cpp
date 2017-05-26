#include "Arduino.h"
#include "SoilMoisture.hpp"
#include "WiFiManager.hpp"

WiFiManager wifi(WIFI_SSID, WIFI_PASSWORD);
IPAddress localIp;

SoilMoisture soilMoisture(A0);

void setup()
{
  Serial.begin(115200);
  wifi.begin();

  soilMoisture.begin();
}

void loop()
{
  wifi.checkWifi();
  Serial.print("Humidity in percentage: ");
  Serial.println(soilMoisture.soilHumidityPercent(0, 100));
  delay(500);
}
