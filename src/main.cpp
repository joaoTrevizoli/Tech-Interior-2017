#include "Arduino.h"
#include "WiFiManager.hpp"

WiFiManager wifi(WIFI_SSID, WIFI_PASSWORD);

void setup()
{
  Serial.begin(115200);
  wifi.begin();
}

void loop()
{
  wifi.checkWifi();
  delay(500);
}
