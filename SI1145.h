

#include "mbed.h"
#define SI1145_ADDRESS (0x60 << 1)


/** SI1145 class
 *  SI1145: A library to correct environmental data using adafruit SI1145 device
 */
 
class SI1145
{
public:

    /** Create a SI1145 instance
     *  which is connected to specified I2C pins with specified address
     * @param sda I2C-bus SDA pin
     * @param scl I2C-bus SCL pin
     * @param slave_adr (option) I2C-bus address (default: 0x60)
     */
    SI1145(PinName sda, PinName sck, char slave_adr = SI1145_ADDRESS);
    /** Create a SI1145 instance
     *  which is connected to specified I2C pins with specified address
     * @param i2c_obj I2C object (instance)
     * @param slave_adr (option) I2C-bus address (default: 0x60)
     */
    SI1145(I2C &i2c_obj, char slave_adr = SI1145_ADDRESS);
    /** Destructor of SI1145
     */
    //virtual ~SI1145();
    /** Initialize SI1145 sensor
     *  Configure sensor setting and read parameters for calibration
     */
    void initalize(void);
   /** Begin Initialization SI1145 sensor
     *  Configure sensor setting and read parameters for calibration
     */
    uint16_t getUV(void);
    /** Read the current VIS value from SI1145 sensor
     */
    uint16_t getVIS(void);
    float getUVlsb(void);
    float getUVmsb(void);
    /** Read the current IR value from SI1145 sensor
     */
    uint16_t getIR(void);
    /** Read the current PROX value from SI1145 sensor
     */
    uint16_t getPROX(void);

private:

    I2C         *i2c_p;
    I2C         &i2c;
    char        address;
    int32_t     t_fine;
};

