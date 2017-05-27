#include "Arduino.h"
#include "SoilMoisture.hpp"
#include "WiFiManager.hpp"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

WiFiManager wifi(WIFI_SSID);
IPAddress localIp;

SoilMoisture soilMoistureSensor(A0);

WiFiClientSecure wifiClient;
Adafruit_MQTT_Client mqtt(&wifiClient, "192.168.200.69", 8883);

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
  wifi.checkWiFi();
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
