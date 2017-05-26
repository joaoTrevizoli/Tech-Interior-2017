
#include "SoilMoisture.hpp"

SoilMoisture::SoilMoisture(const uint8_t pin)
{
  _pin = pin;
}

void SoilMoisture::begin()
{
  pinMode(_pin, INPUT);
}

float SoilMoisture::soilHumidityPercent(int minReading, int maxReading)
{
  uint16_t sensorValue = map(this->rawHumidity(), 1024, 0, minReading, \
    maxReading*100);
  float moisture = static_cast<float>(sensorValue)/100;
  return moisture;
}

uint16_t SoilMoisture::rawHumidity()
{
  return (uint16_t)analogRead(_pin);
}
