#pragma once
#include "sensorstrategy.h"
#include "Adafruit_SGP30.h"
#include "sensorslastvalue.h"

class TovcSensorStrategy :  public SensorStrategy
{
public:
    TovcSensorStrategy();
    int getMesure() override {
        int ret = 0;
        Adafruit_SGP30 * SGP30 = Adafruit_SGP30::getInstance();
        ret += SGP30->IAQmeasure();
        SensorsLastValue::GetInstance()->seteCOVValue(SGP30->TOVC);
        return ret;
    };
    int wakeUp() override
    {
        return 0;

    };
    int init() override 
    {
        int ret  = 0;
        Adafruit_SGP30 * SGP30 = Adafruit_SGP30::getInstance();
        ret += SGP30->begin();
        ret += SGP30->IAQinit();
        return 0;
    };
    int lowPower() override
    {
         return 0;
    };
};


