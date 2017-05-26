
#include "WiFiManager.hpp"

WiFiManager::WiFiManager(const char* ssid, const char* password):
  _ssid(ssid),
  _password(password)
{

}

void WiFiManager::begin()
{
  this->connect();
}

void WiFiManager::connect()
{

  Serial.print("Conecting to:");
  Serial.println("_ssid");

  WiFi.begin(_ssid, _password);
  delay(300);
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println("connected!");
    localIp = WiFi.localIP();
  }
  else
  {
    Serial.println("Failed to connect!");
  }
}

void WiFiManager::disconnect()
{
  WiFi.disconnect();
}

bool WiFiManager::checkWifi()
{
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Still connected!");
    return true;
  }
  else
  {
    Serial.println("Not connected!");
    return false;
  }
}

void WiFiManager::ipChanged()
{
  if(localIp != WiFi.localIP())
  {
    localIp = WiFi.localIP();
    Serial.print("The Ip changed to: ");
    Serial.println(localIp);
  }
}
