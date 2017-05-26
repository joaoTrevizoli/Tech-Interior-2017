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
