/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "i2c_ST.h"
#include "scd30.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     5000ms


int main()
{
    char test[5]; 
    I2C_ST i2c_test(PA_11,PA_12);
    scd30 scd(PA_11,PA_12,400000);
    // Initialise the digital pin LED1 as an output
    scd.getSerialNumber();
    DigitalOut led(LED1);
    for(int i = 0; i < sizeof(scd.scdSTR.sn); i++) printf("%c", scd.scdSTR.sn[i]);
    printf("hello\r\n");
        
    scd.setMeasInterval(5);

    while (true) {
        int count = 0;
            scd.getReadyStatus();
        uint16_t redy = scd.scdSTR.ready;
        if(redy == scd30::SCDisReady) {
            uint8_t crcc = scd.readMeasurement();
            count++;
            if(crcc != scd30::SCDnoERROR) printf("ERROR: %d\r\n", crcc);
            else printf("%5d  -> CO2: %9.3f   Temp: %7.3f   Hum: %5.2f\r\n",count, scd.scdSTR.co2f, scd.scdSTR.tempf, scd.scdSTR.humf);
        }

        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);

        i2c_test.read(0x55, test, 2, 0);
    }
}
