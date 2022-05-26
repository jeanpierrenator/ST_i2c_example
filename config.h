#pragma once
#include "mbed.h"
DigitalOut Alim_l1(PA_7);
DigitalOut Alim_l2(PA_4);
DigitalOut Alim_l3(PA_9);

#define TEMP_SENSOR 0x01
#define TEMP_SENSOR_PERIOD 4000
#define TEMP_STRATEGIE tempSensorStrategy()
DigitalOut & TEMP_POWER_LINE = Alim_l1;

#define HUMID_SENSOR 0x02
#define HUMID_SENSOR_PERIOD 3000
#define HUMID_STRATEGIE HumidSensorStrategy()
DigitalOut & HUMID_POWER_LINE = Alim_l1;

#define CO2_SENSOR 0x03
#define CO2_SENSOR_PERIOD 5
#define CO2_STRATEGIE Co2SensorStrategy()

#define PRESS_SENSOR 0x04
#define PRESS_SENSOR_PERIOD 7000
#define PRESS_STRATEGIE PressSensorStrategy()
DigitalOut & PRESS_POWER_LINE = Alim_l1;
/*#define LUX_SENSOR 0x05
#define LUX_SENSOR_PERIOD 11000
#define LUX_STRATEGIE LuxSensorStrategy()
#define LUX_POWER_LINE Alim_l1;
*/
#define UV_SENSOR 0x06
#define UV_SENSOR_PERIOD 7000
#define UV_STRATEGIE UvSensorStrategy()
//DigitalOut & UV_POWER_LINE = Alim_l1;
