#pragma once

#include "sensorstrategy.h"
#include "Adafruit_SGP30.h"
#include "sensorslastvalue.h"

class ECo2SensorStrategy : public SensorStrategy
{
public:
    ECo2SensorStrategy() {};
    virtual ~ECo2SensorStrategy() {};
    int getMesure() override {
        int ret = 0;
        Adafruit_SGP30 * SGP30 = Adafruit_SGP30::getInstance();
        ret += SGP30->IAQmeasure();
        SensorsLastValue::GetInstance()->seteCO2Value(SGP30->eCO2);
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
