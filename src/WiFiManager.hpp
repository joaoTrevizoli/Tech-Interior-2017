/*WiFiConn
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the WiFiConn Sensor object

This object is responsable for facilitating the management
of the the wifi connection.

Created by: Joao Trevizoli Esteves
*/

#ifndef WIFIMANAGER_HPP
#define  WIFIMANAGER_HPP
// -------------------------------------------------------------------------- //
#include <ESP8266WiFi.h>

// -------------------------------------------------------------------------- //

class WiFiManager
{
public:
  IPAddress clientLocalIp;
  WiFiManager(const char* SSID, const char* Password='\0');
  ~WiFiManager();
  void begin();
  bool checkWiFi();
  void localIpChange();
  void disconnect();

private:
  void connect();
  const uint32_t ipChangeUpdateInterval = 5000;
  uint32_t previousUpdate = 0;
  const char* ssid;
  const char* password;
};
#endif
