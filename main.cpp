/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "i2c_ST.h"
#include "presssensorsstrategy.h"
#include "tempsensorstrategy.h"
#include "humidsensorstrategy.h"
#include "sensorstrategy.h"
#include "sensorslastvalue.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     5000ms

   I2C i2c(PA_11,PA_12);

  SensorStrategy * saTempstrategy = new tempSensorStrategy();
  SensorStrategy * saHumidstrategy = new HumidSensorStrategy();
  SensorStrategy * saPressstrategy = new PressSensorStrategy();
int main()
{
    saPressstrategy->init();
    saTempstrategy->init();
    saHumidstrategy->init();

    saPressstrategy->lowPower();
    saTempstrategy->lowPower();
    saHumidstrategy->lowPower();
    printf("hello\n");
    
    char test[5]; 
    I2C_ST i2c_test(PA_11,PA_12);
    while(1){
        saPressstrategy->wakeUp();
    saTempstrategy->wakeUp();
    saHumidstrategy->wakeUp();

    saPressstrategy->getMesure();
    saTempstrategy->getMesure();
    saHumidstrategy->getMesure();

       saPressstrategy->lowPower();
    saTempstrategy->lowPower();
    saHumidstrategy->lowPower();

    printf(" press: %.2f, temp : %.2f , humid %.2f \n", SensorsLastValue::GetInstance()->getpressValue(),SensorsLastValue::GetInstance()->getTempValue(),SensorsLastValue::GetInstance()->getHumidValue());
    
        //printf(" mesure? :%d\n",sensor.IAQmeasure());
         
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
