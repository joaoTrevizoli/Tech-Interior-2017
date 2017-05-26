/*WiFiManager
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/
Implementation of the WiFiManager object
This object is responsable for facilitating the management
of the the wifi connection.
Created by: Joao Trevizoli Esteves
*/

#include "WiFiManager.hpp"

// -------------------------Constructor-------------------------------------- //

WiFiManager::WiFiManager(const char* ssid, const char* password):
  _ssid(ssid),
  _password(password)
{
}
// -------------------------Public methods----------------------------------- //

void WiFiManager::begin()
{
  this->connect();
}

// -------------------------------------------------------------------------- //

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

// -------------------------------------------------------------------------- //

void WiFiManager::disconnect()
{
  WiFi.disconnect();
}

// -------------------------------------------------------------------------- //

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

// -------------------------------------------------------------------------- //

void WiFiManager::ipChanged()
{
  if(localIp != WiFi.localIP())
  {
    localIp = WiFi.localIP();
    Serial.print("The Ip changed to: ");
    Serial.println(localIp);
  }
}

// -------------------------------------------------------------------------- //
