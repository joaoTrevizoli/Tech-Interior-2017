#include "MqttManager.hpp"

MqttManager::MqttManager(const char* host, uint16_t port, const char* topic, \
  const char* id, const char* password):
  wifiClient(WiFiClientSecure()),
  mqtt(Adafruit_MQTT_Client(&wifiClient, host, port, id, password)),
  sensor_publisher(Adafruit_MQTT_Publish(&mqtt, topic))
{

}
void MqttManager::begin()
{
  mqtt.connect();
}
bool MqttManager::checkConnection()
{
  if(mqtt.ping() != 0 | mqtt.connect())
  {
    return true;
  }
  Serial.println("Mqtt host disconnected!");
  return false;
}

void MqttManager::publish(uint16_t sensorMeasurement)
{
  if(!sensor_publisher.publish(sensorMeasurement))
  {
    Serial.println("Not published...");
  }
  else
  {
    Serial.println("published!");
  }
}
