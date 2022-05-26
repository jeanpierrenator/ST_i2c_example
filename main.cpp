/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "i2c_ST.h"
#include "mbed_bme680.h"
#include "humidsensorstrategy.h"
#include "presssensorstrategy.h"
#include "tempsensorstrategy.h"
#include "sensorslastvalue.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     5000ms

    I2C i2c(PA_11,PA_12);

    DigitalOut Alim_l1(PA_7);

int main()
{
    Alim_l1 = 0;
    Timer t;

    humidSensorStrategy HumidSensor;
    pressSensorStrategy PressSensor;
    tempSensorStrategy TempSensor;

    HumidSensor.init();
    PressSensor.init();
    TempSensor.init();

    while (true) {
    t.start();
    HumidSensor.wakeUp();
    PressSensor.wakeUp();
    TempSensor.wakeUp();

    HumidSensor.getMesure();
    PressSensor.getMesure();
    TempSensor.getMesure();

    HumidSensor.lowPower();
    PressSensor.lowPower();
    TempSensor.lowPower();

    t.stop();
    
    printf("The time taken was %f seconds\n", t.read());
    printf("Humid = %5.2f, Press = %5.2f, temp = %5.2f \r\n", SensorsLastValue::GetInstance()->getpressValue(), SensorsLastValue::GetInstance()->getHumidValue(), SensorsLastValue::GetInstance()->getTempValue());
    t.reset();

    ThisThread::sleep_for(1000ms);
    }
}
