#pragma once

#include "sensorstrategy.h"
#include "scd30.h"
#include "sensorslastvalue.h"

class Co2SensorStrategy : public SensorStrategy
{
public:
    Co2SensorStrategy() {};
    virtual ~Co2SensorStrategy() {};
    int getMesure() {
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
    };
    int wakeUp() 
    {
        return 0;

    };
    int init()  
    {
        return scd30::getInstance()->setMeasInterval(5);
    };
    int lowPower() 
    {
         return 0;
    };
};
