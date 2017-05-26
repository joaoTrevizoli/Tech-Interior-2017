#include "Arduino.h"
#include <ESP8266WiFi.h>

IPAddress localIp;

void setup()
{
  Serial.begin(115200);
  WiFi.begin("__ssid__", "__password__");
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
  delay(500);
}
