/*WiFiManager
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/
Interface of the WiFiManager object
This object is responsable for facilitating the management
of the the wifi connection.
Created by: Joao Trevizoli Esteves
*/

#ifndef WIFICONN_HPP
#define  WIFICONN_HPP
// -------------------------------------------------------------------------- //
#include <ESP8266WiFi.h>

class WiFiManager
{
public:

  IPAddress localIp;

  WiFiManager(const char* ssid, const char* password);
  void begin();
  void connect();
  void disconnect();
  bool checkWifi();
  void ipChanged();

private:
  const char* _ssid;
  const char* _password;

};

#endif
