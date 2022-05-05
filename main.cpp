/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "VEML7700.h"
#include "inttypes.h"
#include <cstdint>
#include <ctime>


// Blinking rate in milliseconds
#define STEPPING     5s

I2C i2c(PA_11,PA_12);


int main()
{
    // param I2C
    //PinName I2CSCL = PA_12;
    //PinName I2CSDA = PA_11; 

    //char addr_capteur = 0x76;


    char data[0];
    int32_t luminausite;
    Timer t;
    t.start();
    init();
    ThisThread::sleep_for(110ms);
    getMesure(&luminausite);
    t.stop();
    printf("The time taken was %f seconds\n", t.read());
    printf("ALS = %d \r\n", luminausite);
    //printf("Oui cela marche !!! \r\n");
    //lowPower();
    while (true) {
        

    }
}

