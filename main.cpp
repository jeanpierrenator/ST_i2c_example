/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "i2c_ST.h"
#include "SI1145.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     5000ms

    I2C i2c(PA_11,PA_12);
Timer t;
int main()
{
    printf("hello\n");
    int test =0;
    
    SI1145 capteur(PA_11,PA_12);
    t.start();
    capteur.initalize();
    test = capteur.getUV();
    test = capteur.getUV();

    t.stop();
    printf("The time taken was %f seconds\n", t.read());
    printf(" mesure uv :%d\n",test);
    t.reset();
    //char test[5]; 
    I2C_ST i2c_test(PA_11,PA_12);
    while(1){
        //printf(" mesure? :%d\n",sensor.IAQmeasure());
        
        test = capteur.getUV();
        printf(" mesure uv :%d\n",test);
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
