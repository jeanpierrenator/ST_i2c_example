/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "VEML7700.h"
#include "inttypes.h"
#include "luxSensorStrategy.h"
#include <cstdint>
#include <ctime>


// Blinking rate in milliseconds
#define STEPPING     5s

I2C i2c(PA_11,PA_12);


int main()
{
    
    
    LuxSensorStrategy luxCapteur;
    luxCapteur.init();
    char data[0];
    int32_t luminausite;
    Timer t;
   
    while (true) {
         t.start();
    luxCapteur.wakeUp();
    luxCapteur.getMesure();
    luxCapteur.lowPower();
    t.stop();
    
    printf("The time taken was %f seconds\n", t.read());
    printf("ALS = %5.2f \r\n", SensorsLastValue::GetInstance()->getLumiValue());
    t.reset();

    ThisThread::sleep_for(1000ms);

    }
}

