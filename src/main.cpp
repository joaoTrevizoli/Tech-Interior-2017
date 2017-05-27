#include "Arduino.h"
#include "SoilMoisture.hpp"
#include "WiFiManager.hpp"

SoilMoisture soilMoisture(A0);
WiFiManager wifi("H Recreio 19");
void setup()
{
  Serial.begin(115200);
  // WiFi.begin("__ssid__", "__password__");
  wifi.begin();
  soilMoisture.begin();
}

void loop()
{
  wifi.checkWiFi();
  Serial.print("Humidity in percentage: ");
  Serial.println(soilMoisture.soilHumidityPercent(0, 100));
  delay(500);
}
