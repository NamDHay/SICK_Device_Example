#include <Arduino.h>
#define MPB10_SICK 0
#include <SICK.h>
#include <ArduinoJson.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

SICK_SENSOR sickSensor;

void setup()
{
  Serial.begin(115200);

  // Mapping: Distance(4byte) / Scale(1byte) / Qualifier(1byte)

  // Mapping: Alarm(4byte) / X_Axis(4byte) / Y_Axis(4byte) / Z_Axis(4byte) / Temperature(4byte)

  xTaskCreatePinnedToCore(TaskSICKSensor, "TaskSICKSensor", 5000, NULL, 3, NULL, 1);
}

void loop()
{
}
