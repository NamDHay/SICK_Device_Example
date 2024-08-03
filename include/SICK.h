#ifndef __SICK_H__
#define __SICK_H__

#include <Arduino.h>
#include <math.h>

class SICK_SENSOR
{
private:
#ifdef MPB10_SICK
    union float_to_bits
    {
        float f;
        uint32_t u;
    } Measurement_value;
#endif // MPB10_SICK
public:
#ifdef MPB10_SICK
    float axisValue(byte *arr)
    {
        Measurement_value.u = ((uint32_t)arr[0] << 24) | ((uint32_t)arr[1] << 16) | ((uint32_t)arr[2] << 8) | (uint32_t)arr[3];
        return Measurement_value.f;
    }
    float tempValue(byte *arr)
    {
        Measurement_value.u = ((uint32_t)arr[0] << 24) | ((uint32_t)arr[1] << 16) | ((uint32_t)arr[2] << 8) | (uint32_t)arr[3];
        return Measurement_value.f;
    }
    float magnitudeCal(float x, float y, float z)
    {
        return sqrt(x * x + y * y + z * z);
    }
#endif // MPB10_SICK

#ifdef OD2000_SICK
    // scale is -6 because value unit read from sensor is nm so we need to convert to mm
    float  distance(byte *arr, uint16_t zeroPoss = 0, int8_t scale = -6)
    {
        int Measurement_value = ((uint32_t)arr[0] << 24) | ((uint32_t)arr[1] << 16) | ((uint32_t)arr[2] << 8) | (uint32_t)arr[3];
        float relativeData = Measurement_value * pow(10, -6);
        return relativeData + zeroPoss;
    }
#endif // OD2000_SICK

#ifdef WTMxL_SICK
#endif // WTMxL_SICK
};
extern SICK_SENSOR sickSensor;

#endif //__SICK_H__