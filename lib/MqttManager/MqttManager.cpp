/*Mqtt Mqtt Manager
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the Mqtt Manager object

Created by: Joao Trevizoli Esteves
*/

#include "MqttManager.hpp"


// -------------------------Constructor-------------------------------------- //

MqttManager::MqttManager(const char* host, uint16_t port, const char* topic, \
  const char* stationId):
  wifiClient(WiFiClientSecure()),
  mqtt(Adafruit_MQTT_Client(&wifiClient, host, port)),
  sensor_publisher(Adafruit_MQTT_Publish(&mqtt, topic))
{
  _stationId = stationId;
}

// -------------------------Public methods----------------------------------- //

void MqttManager::begin()
{
  mqtt.connect();
}

// -------------------------------------------------------------------------- //

bool MqttManager::checkConnection()
{
  if(mqtt.ping() != 0 | mqtt.connect())
  {
    return true;
  }
  Serial.println("Mqtt host disconnected!");
  return false;
}

// -------------------------------------------------------------------------- //

void MqttManager::publish(float_t sensorMeasurement)
{
  uint message_size = strlen(JSON)+ strlen(_stationId) + 8;

  char message[message_size];
  char floatChar[8];

  dtostrf(sensorMeasurement, 3, 4, floatChar);

  snprintf(message, message_size, JSON, _stationId, floatChar);

  if(!sensor_publisher.publish(message))
  {
    Serial.println("Not published...");
  }
  else
  {
    Serial.println("published!");
  }

  memset(message, '\0', message_size);
  memset(floatChar, '\0', sizeof(float));
}

// -------------------------------------------------------------------------- //
