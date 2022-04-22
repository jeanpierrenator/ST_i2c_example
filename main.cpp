/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "i2c_ST.h"
#include "Adafruit_SGP30.h"
#include"sensorslastvalue.h"
#include "eco2sensorstrategy.h"
// Blinking rate in milliseconds
#define BLINKING_RATE     5000ms


int main()
{
    char test[5]; 
    I2C_ST i2c_test(PA_11,PA_12);
    ECo2SensorStrategy saEco2Strategy;
    saEco2Strategy.init();
    while(1){
        //printf(" mesure? :%d\n",sensor.IAQmeasure());
        saEco2Strategy.getMesure();
        printf(" ECO2 : %5.2f \n" , SensorsLastValue::GetInstance()->geteCO2Value());

        ThisThread::sleep_for(BLINKING_RATE);
    }
}
