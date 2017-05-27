#include "Arduino.h"
#include "SoilMoisture.hpp"
#include "WiFiManager.hpp"
#include "MqttManager.hpp"

WiFiManager wifi(WIFI_SSID, WIFI_PASSWORD);

MqttManager mqttManager("mqtt.labmet.tech", 8883,\
 "/tech_interior/", MQTT_ID, MQTT_PASSWORD);

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
  wifi.checkWifi();
  mqttManager.publish(soilMoisture);
  delay(500);
}
