/*Mqtt Mqtt Manager
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the Mqtt Manager object

Created by: Joao Trevizoli Esteves
*/

#ifndef MQTTMANAGER_HPP
#define  MQTTMANAGER_HPP

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define JSON "{\"id\": %s, \"soil_umidity\": %s}"

class MqttManager
{
public:
  MqttManager(const char* host, uint16_t port, const char* topic, \
    const char* mqttId, const char* password, const char* stationId);
  void begin();
  bool checkConnection();
  void publish(float_t sensorMeasurement);
private:
  const char* _stationId;
  WiFiClientSecure wifiClient;
  Adafruit_MQTT_Client mqtt;
  Adafruit_MQTT_Publish sensor_publisher;

};

#endif
