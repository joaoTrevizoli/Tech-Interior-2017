#ifndef SOILMOISTURE_HPP
#define  SOILMOISTURE_HPP


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


// -------------------------Class Interface---------------------------------- //

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
