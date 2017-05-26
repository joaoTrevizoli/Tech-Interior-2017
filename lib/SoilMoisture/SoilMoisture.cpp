
/*SoilMoisture
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the Soil Moisture Sensor

Created by: João Trevizoli Este ves
*/

#include "SoilMoisture.hpp"

// -------------------------Constructor-------------------------------------- //

SoilMoisture::SoilMoisture(const uint8_t pin)
{
  _pin = pin;
}

// -------------------------Public methods----------------------------------- //

void SoilMoisture::begin()
{
  pinMode(_pin, INPUT);
}

// -------------------------------------------------------------------------- //

float SoilMoisture::soilHumidityPercent(int minReading, int maxReading)
{
  uint16_t sensorValue = map(this->rawHumidity(), 1024, 0, minReading, \
    maxReading*100);
  float moisture = static_cast<float>(sensorValue)/100;
  return moisture;
}

// -------------------------------------------------------------------------- //

uint16_t SoilMoisture::rawHumidity()
{
  return (uint16_t)analogRead(_pin);
}

// -------------------------------------------------------------------------- //
