/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "i2c_ST.h"
#include "scd30.h"
#include "sensorstrategy.h"
#include "humidsensorstrategy.h"
#include "tempsensorstrategy.h"
#include "co2sensorstrategy.h"
#include "sensorslastvalue.h"
#include "Adafruit_SGP30.h"
// Blinking rate in milliseconds
#define BLINKING_RATE     5000ms

int main()
{
    SensorStrategy * saCo2Strategy = new Co2SensorStrategy(); 
    saCo2Strategy->init();
   
    while(1) {
        ThisThread::sleep_for(CO2_SENSOR_PERIOD*1000);
        if(saCo2Strategy->getMesure() ==0){
            printf(" CO2: %9.3f   Temp: %7.3f   Hum: %5.2f\r\n",SensorsLastValue::GetInstance()->getCO2Value(),SensorsLastValue::GetInstance()->getHumidValue(),SensorsLastValue::GetInstance()->getTempValue());
        }
    }
}