/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "i2c_ST.h"
#include "scd30.h"
#include "humidsensorstrategy.h"
#include "tempsensorstrategy.h"
#include "co2sensorstrategy.h"
// Blinking rate in milliseconds
#define BLINKING_RATE     5000ms


int main()
{
    char test[5]; 
    I2C_ST i2c_test(PA_11,PA_12);
    // Initialise the digital pin LED1 as an output
    scd30 * scd = scd30::getInstance();
    Co2SensorStrategy c02;
    printf("hello\r\n");
        
    c02.init();

    while (true) {
        int count = 0;
            scd->getReadyStatus();
        uint16_t redy = scd->scdSTR.ready;
        if(c02.getMesure() == scd30::SCDisReady) {

         printf("%5d  -> CO2: %9.3f   Temp: %7.3f   Hum: %5.2f\r\n",count, scd->scdSTR.co2f, scd->scdSTR.tempf, scd->scdSTR.humf);
        }

        ThisThread::sleep_for(BLINKING_RATE);

        i2c_test.read(0x55, test, 2, 0);
    }
}
