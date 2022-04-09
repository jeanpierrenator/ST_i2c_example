#include "i2c_ST.h"

I2C_ST::I2C_ST (PinName sda, PinName scl) : _i2c(sda, scl) {
    _i2c.start();
    _i2c.frequency(400000);
}

int I2C_ST::read(int address, char *data, int length, bool repeted){
 return _i2c.read(address,data,length,repeted);
}

int I2C_ST::write(int address,const char *data,int length,bool repeted){
 return _i2c.write(address,data,length,repeted);
}