#include "Arduino.h"
#include "WiFiManager.hpp"

WiFiManager wifi("RN-9737", "Du83cXmn");

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
