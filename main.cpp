/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "i2c_ST.h"
#include "uvsensorstrategy.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     5000ms
I2C i2c(PA_11,PA_12);
Timer t;
int main()
{

    UvSensorStrategy UvCapteur;
    UvCapteur.init();
    char data[0];

    Timer t;
   
    while (true) {
    t.start();
    UvCapteur.wakeUp();
    UvCapteur.getMesure();
    UvCapteur.lowPower();
    t.stop();
    
    printf("The time taken was %f seconds\n", t.read());
    printf("UV2 = %5.2f \r\n", SensorsLastValue::GetInstance()->getUVValue());
    t.reset();

    ThisThread::sleep_for(10000ms);

    }
}
