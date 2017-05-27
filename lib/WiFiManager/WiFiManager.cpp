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

WiFiManager::WiFiManager(const char* SSID, const char* Password)
{
    this->ssid = SSID;
    this->password = Password;
}

// -------------------------Destructor-------------------------------------- -//


WiFiManager::~WiFiManager()
{
    if (this->checkWiFi())
    {
        WiFi.disconnect();
    }
}

// -------------------------Public methods----------------------------------- //

void WiFiManager::begin()
{
    this->connect();
}

// -------------------------------------------------------------------------- //


bool WiFiManager::checkWiFi()
{
    if (millis() - this->previousUpdate > this->ipChangeUpdateInterval)
    {
        this->previousUpdate = millis();
        this->localIpChange();
    }
    if(WiFi.status() == WL_CONNECTED)
    {
        Serial.println("conected");
        return true;
    }
    else
    {
        Serial.println("not conected");
        return false;
    }
}

// -------------------------------------------------------------------------- //

void WiFiManager::localIpChange()
{
    if (clientLocalIp != WiFi.localIP())
    {
        clientLocalIp = WiFi.localIP();
        Serial.print("The local IP has changed to ");
        Serial.println(clientLocalIp);
    }
}

// -------------------------------------------------------------------------- //
void WiFiManager::disconnect()
{
    WiFi.disconnect();
}

// -------------------------Private methods---------------------------------- //

void WiFiManager::connect()
{

    if(password)
    {
        WiFi.begin(this->ssid, this->password);
    }
    else
    {
        WiFi.begin(this->ssid);
    }

    delay(1000);

    if (WiFi.status() == WL_CONNECTED)
    {
        clientLocalIp = WiFi.localIP();
        Serial.print("WiFi connected!\n IP: ");
        Serial.println(clientLocalIp);
    }
    {
        Serial.println("Can't connect");
    }
}

// -------------------------End of class implementation---------------------- //
