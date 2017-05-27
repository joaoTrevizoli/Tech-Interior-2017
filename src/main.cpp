#include "Arduino.h"
#include "SoilMoisture.hpp"
#include "WiFiManager.hpp"
#include "MqttManager.hpp"

WiFiManager wifi(WIFI_SSID);

MqttManager mqttManager("192.168.200.69", 8883,\
 "/tech_interior/");

SoilMoisture soilMoistureSensor(A0);


void setup()
{
  Serial.begin(115200);
  wifi.begin();
  mqttManager.begin();
  soilMoistureSensor.begin();
}

void loop()
{
  uint16_t soilMoisture = soilMoistureSensor.soilHumidityPercent(0, 100);
  wifi.checkWiFi();
  mqttManager.checkConnection();
  mqttManager.publish(soilMoisture);
  delay(500);
}
