#ifndef I2C_H 
#define I2C_H

#include "mbed.h"
class I2C_ST{
public:
    I2C_ST (PinName sda, PinName scl);
    int write(int address,const char *data,int length,bool repeted);
    int read (int address,char *data, int length, bool repeted );
protected:
    I2C _i2c;
 
};

#endif