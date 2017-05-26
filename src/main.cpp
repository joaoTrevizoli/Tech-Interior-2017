#include "Arduino.h"
#include "SoilMoisture.hpp"

SoilMoisture soilMoisture(A0);

void setup()
{
  Serial.begin(115200);
  soilMoisture.begin();
}

void loop()
{
  Serial.print("Humidity in percentage: ");
  Serial.println(soilMoisture.soilHumidityPercent(0, 100));
  delay(500);
}
