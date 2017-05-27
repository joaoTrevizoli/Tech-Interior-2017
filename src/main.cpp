#include "Arduino.h"
#include "SoilMoisture.hpp"
#include "WiFiManager.hpp"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

WiFiManager wifi(WIFI_SSID, WIFI_PASSWORD);
IPAddress localIp;

SoilMoisture soilMoistureSensor(A0);

WiFiClientSecure wifiClient;
Adafruit_MQTT_Client mqtt(&wifiClient, "mqtt.labmet.tech", 8883, \
 MQTT_ID, MQTT_PASSWORD);

 Adafruit_MQTT_Publish publisher(&mqtt, "/tech_interior/");

void setup()
{
  Serial.begin(115200);
  wifi.begin();
  mqtt.connect();
  soilMoistureSensor.begin();
}

void loop()
{
  wifi.checkWifi();
  uint16_t soilMoisture = soilMoistureSensor.soilHumidityPercent(0, 100);

  if(mqtt.ping() != 0 | mqtt.connect())
  {
    Serial.println("We can publish!");
    if(!publisher.publish(soilMoisture))
    {
      Serial.println("Not published...");
    }
    else
    {
      Serial.println("published");

    }
  }
  else
  {
    Serial.println("We can't publish :( ");
  }
  delay(500);
}
