#pragma once
#include "sensorstrategy.h"
#include "mbed_bme680.h"

class pressSensorStrategy : public SensorStrategy
{
public:
    virtual ~pressSensorStrategy() {};
    int getMesure() override{
        // retreve the value after the measurment (values already calculated)
        float press = BME680::getInstance()->getPressure()/100;
        SensorsLastValue::GetInstance()->setpressValue(press);
        return 0;
    };
    int wakeUp() override{
            // wake the sensore and read the environement and do to sleep
    // the wait for measurment buit-in
    // true = 0K / false = not good
        return BME680::getInstance()->performReading();
    };
    int init() override{
            // iitialize the sensor 
    // true = 0K / false = not good
         return BME680::getInstance()->begin();
    };
    int lowPower() override{
         //already done in the performReading method (after the measurments)
        return 0;
    };
};

