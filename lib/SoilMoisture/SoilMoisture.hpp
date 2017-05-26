/*SoilMoisture
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the Soil Moisture Sensor

Created by: João Trevizoli Este ves
*/

#ifndef SOILMOISTURE_HPP
#define  SOILMOISTURE_HPP


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class SoilMoisture
{
public:
  SoilMoisture(const uint8_t pin=A0);
  void begin();
  float soilHumidityPercent(int minReading, int maxReading);
  uint16_t rawHumidity();

private:
  uint8_t _pin;
};

 #endif
