#ifndef __SICK_H__
#define __SICK_H__

#include <Arduino.h>
#include <math.h>

class SICK_SENSOR
{
public:
    float getIntValue(byte *arr, uint16_t zeroPos = 0, int8_t scale = 0)
    {
        int Measurement_value = ((uint32_t)arr[0] << 24) | ((uint32_t)arr[1] << 16) | ((uint32_t)arr[2] << 8) | (uint32_t)arr[3];
        float relativeData = Measurement_value * pow(10, scale);
        float absoluteData = relativeData + zeroPos;
        return absoluteData;
    }
    float getFloatValue(byte *arr, uint16_t zeroPos = 0, int8_t scale = 0)
    {
        union type_t {
            float f;
            uint32_t u;
        }Measurement_value;
        Measurement_value.u = ((uint32_t)arr[0] << 24) | ((uint32_t)arr[1] << 16) | ((uint32_t)arr[2] << 8) | (uint32_t)arr[3];
        float relativeData = Measurement_value.f * pow(10, scale);
        float absoluteData = relativeData + zeroPos;
        return absoluteData;
    }

#ifdef MPB10_SICK
    float magnitudeCal(float x, float y, float z)
    {
        return sqrt(x * x + y * y + z * z);
    }
#endif // MPB10_SICK
};
extern SICK_SENSOR sickSensor;

#endif //__SICK_H__