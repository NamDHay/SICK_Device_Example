#include <Arduino.h>
#define MPB10_SICK 0
#include <SICK.h>

SICK_SENSOR sickSensor;


void setup()
{
  Serial.begin(115200);

  // Mapping: Distance(4byte) / Scale(1byte) / Qualifier(1byte)
  byte dis1[6] = {252, 250, 4, 230, 247, 3};   // 79.3
  byte dis2[6] = {255, 155, 128, 239, 247, 1}; // 123.4
  byte dis3[6] = {251, 207, 93, 45, 247, 1};   // 59.7

  Serial.println("Distance 1: " + String(sickSensor.getIntValue(dis1, 130, -6)) + " mm");
  Serial.println("Distance 2: " + String(sickSensor.getIntValue(dis2, 130, -6)) + " mm");
  Serial.println("Distance 3: " + String(sickSensor.getIntValue(dis3, 130, -6)) + " mm");

  // Mapping: Alarm(4byte) / X_Axis(4byte) / Y_Axis(4byte) / Z_Axis(4byte) / Temperature(4byte)
  uint8_t value[20] = {66, 44, 0, 0, 63, 170, 107, 11, 64, 10, 34, 251, 64, 9, 242, 125, 0, 0, 0, 192};
  Serial.println("X axis 1: " + String(sickSensor.getFloatValue(&value[12])));
  Serial.println("Y axis 2: " + String(sickSensor.getFloatValue(&value[8])));
  Serial.println("Z axis 3: " + String(sickSensor.getFloatValue(&value[4])));
  Serial.println("Temperature: " + String(sickSensor.getFloatValue(&value[0])));
}

void loop()
{
}
