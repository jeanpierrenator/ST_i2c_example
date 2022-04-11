#pragma once

#include "sensorstrategy.h"
#include "scd30.h"
#include "sensorslastvalue.h"

class Co2SensorStrategy : public SensorStrategy
{
public:
    Co2SensorStrategy() {};
    virtual ~Co2SensorStrategy() {};
    int getMesure() override {
        scd30 * scd = scd30::getInstance();
            scd->getReadyStatus();
        uint16_t redy = scd->scdSTR.ready;
        if(redy == scd30::SCDisReady) {
            uint8_t crcc = scd->readMeasurement();
            if(crcc != scd30::SCDnoERROR) return crcc;
            SensorsLastValue::GetInstance()->setCO2Value(scd->scdSTR.co2f);
            SensorsLastValue::GetInstance()->setTempValue(scd->scdSTR.tempf);
            SensorsLastValue::GetInstance()->setHumidValue(scd->scdSTR.humf);
            return crcc;
        }
        return 1;
    };
    int wakeUp() override
    {
        return 0;

    };
    int init() override 
    {
        return scd30::getInstance()->setMeasInterval(5);
    };
    int lowPower() override
    {
         return 0;
    };
};
