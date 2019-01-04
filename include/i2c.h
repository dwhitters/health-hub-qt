/**
    Provides control of the TI ADS1015 which is used to measure the
    post-gain ECG signal.

    @author David Whitters
*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

/** The I2C address of the ADS1015. */
#define ADS1015_I2C_ADDRESS    0x48u
/** The conversion register address on the ADS1015. */
#define ADS1015_CONVERSION_REG 0x00u
/** The configuration register address on the ADS1015. */
#define ADS1015_CONFIG_REG     0x01u

/** File descriptor for the I2C data stream. */
int file_i2c;
/** The buffer that is used to send and receive messages via I2C. */
unsigned char buffer[60] = {0};

/**
    Reads the passed in number of bytes starting from the address that was
    last written to.

    @param data_len
        The number of bytes to read.
*/
void i2cRead(uint8_t data_len) {
    // read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
    if (read(file_i2c, buffer, data_len) != data_len)
    {
        printf("Failed to read from the i2c bus.\n");
    }
    else
    {
        printf("Data read: 0x");
        for(int i = 0; i < data_len; ++i)
        {
            printf("%X", buffer[i]);
        }
        printf("\n");
    }
}

/**
    Writes the passed in number of bytes to the ADS1015 from the buffer, starting
    from index 0.

    @param data_len
        The number of bytes to write from the buffer.
*/
void i2cWrite(uint8_t data_len) {
    // write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
    if (write(file_i2c, buffer, data_len) != data_len)
    {
        /* ERROR HANDLING: i2c transaction failed */
        printf("Failed to write to the i2c bus.\n");
    }
}

void i2cInit(void) {
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

    i2cWrite(3u);

    i2cRead(2u);
}
