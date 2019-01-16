/**
    Provides control of the TI ADS1015 which is used to measure the
    post-gain ECG signal.

    @author David Whitters
*/
#ifndef ADS1015_H
#define ADS1015_H

#include <stdint.h>

/** The I2C address of the ADS1015. */
#define ADS1015_I2C_ADDRESS    0x48u
/** The conversion register address on the ADS1015. */
#define ADS1015_CONVERSION_REG 0x00u
/** The configuration register address on the ADS1015. */
#define ADS1015_CONFIG_REG     0x01u

class ADS1015 {

    /** File descriptor for the I2C data stream. */
    int file_i2c;
    /** The buffer that is used to send and receive messages via I2C. */
    unsigned char buffer[60] = {0};

public:
    ADS1015();
    void Read(uint8_t);
    void Write(uint8_t);
    void SetRegister(uint8_t);
    int GetConversion();
};

#endif // ADS1015_H
