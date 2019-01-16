/**
    Provides control of the TI ADS1015 which is used to measure the
    post-gain ECG signal.

    @author David Whitters
*/
#include "ads1015.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>

/**
    Reads the passed in number of bytes starting from the address that was
    last written to.

    @param data_len
        The number of bytes to read.
*/
void ADS1015::Read(uint8_t data_len) {
    // read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
    if (read(file_i2c, buffer, data_len) != data_len)
    {
        printf("Failed to read from the i2c bus.\n");
    }
}

/**
    Simplistic implementation of the write command.
    Sets the ADC pointer register to the passed in register.

    @param reg
        The register to set the ADC pointer register to.
*/
void ADS1015::SetRegister(uint8_t reg) {
    buffer[0] = reg;
    Write(1u);
}

/**
    Reads the values from the conversion register (2 8-bit registers that
    contain a 12-bit number).

    @note This must only be used after the ADC pointer register has been pointed to the
          conversion register.
    @note In single-ended mode, the value is an 11-bit number.

    @return
        The conversion value.
*/
int ADS1015::GetConversion() {
    int conversion_val = 0;

    Read(2u); // Read the two conversion registers and store the data in the buffer.

    // Data storage:
    // 15  14  13 12 11 10 9  8  7  6  5  4  3 2 1 0
    // D11 D10 D9 D8 D7 D6 D5 D4 D3 D2 D1 D0 0 0 0 0
    //
    // Buffer[0] is the MSB, Buffer[1] is the LSB.
    conversion_val = buffer[0] << 4;
    conversion_val |= buffer[1] >> 4;

    return conversion_val;
}
/**
    Writes the passed in number of bytes to the ADS1015 from the buffer, starting
    from index 0.

    @param data_len
        The number of bytes to write from the buffer.
*/
void ADS1015::Write(uint8_t data_len) {
    // write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
    if (write(file_i2c, buffer, data_len) != data_len)
    {
        /* ERROR HANDLING: i2c transaction failed */
        printf("Failed to write to the i2c bus.\n");
    }
}

/**
    Initializes the ADS1015 to continuously convert the analog signal
    to a digital one at a frequency of 3300 Hz in single-ended mode.
*/
ADS1015::ADS1015(void) {
    //----- OPEN THE I2C BUS -----
    char *filename = (char*)"/dev/i2c-1";
    if ((file_i2c = open(filename, O_RDWR)) < 0)
    {
        printf("Failed to open the i2c bus");
        return;
    }

    if (ioctl(file_i2c, I2C_SLAVE, ADS1015_I2C_ADDRESS) < 0)
    {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        return;
    }

    buffer[0] = ADS1015_CONFIG_REG;
    buffer[1] = 0x42u;
    buffer[2] = 0xE3u;

    Write(3u); // Write the configuration to the ADC.
}
