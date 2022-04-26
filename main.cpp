/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "i2c_ST.h"
#include "mbed_bme680.h"
#include "tempsensorstrategy.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     5000ms

    I2C i2c(PA_11,PA_12);
int main()
{
    printf("hello\n");
    BME680 bme680;
    bme680.begin();
    char test[5]; 
    I2C_ST i2c_test(PA_11,PA_12);
    while(1){
        //printf(" mesure? :%d\n",sensor.IAQmeasure());
          if (bme680.performReading())
        {
            printf("   %.2f      ", bme680.getTemperature());
            printf("%.2f    ", bme680.getHumidity());
            printf("%.2f    ", bme680.getPressure() / 100.0);
            printf("%0.2f\r\n", bme680.getGasResistance());
        }
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
