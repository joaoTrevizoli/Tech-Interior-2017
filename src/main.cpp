#include "Arduino.h"

uint16_t rawHumidity(uint pin);
float mapSoilHumidity(uint16_t humidity, uint8_t minReading, uint maxReading);

uint analogPin = A0;
uint16_t humidity;

void setup()
{
  Serial.begin(115200);
  pinMode(analogPin, INPUT);
}

void loop()
{
  humidity = rawHumidity(A0);
  Serial.println("Raw humidity: ");
  Serial.println(humidity);
  Serial.print("Muisture in percentage: ");
  Serial.println(mapSoilHumidity(humidity, 0, 100));
  delay(500);
}

uint16_t rawHumidity(uint pin)
{
  return (uint16_t)analogRead(pin);
}

float mapSoilHumidity(uint16_t humidity, uint8_t minReading, uint maxReading)
{
  uint16_t sensorValue = map(humidity, 1024, 0, minReading, maxReading*100);
  float moisture = static_cast<float>(sensorValue)/100;
  return moisture;
}
