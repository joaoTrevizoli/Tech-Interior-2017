#include "Arduino.h"
#include "SoilMoisture.hpp"
#include <ESP8266WiFi.h>

IPAddress localIp;

SoilMoisture soilMoisture(A0);

void setup()
{
  Serial.begin(115200);
  WiFi.begin("__ssid__", "__password__");
  soilMoisture.begin();
}

void loop()
{
  if(WiFi.status() == WL_CONNECTED)
  {
    localIp = WiFi.localIP();
    Serial.print("Connected with Ip: ");
    Serial.println(localIp);
  }
  else
  {
    Serial.println("Not Connected");
  }

  Serial.print("Humidity in percentage: ");
  Serial.println(soilMoisture.soilHumidityPercent(0, 100));
  delay(500);
}
