#include "epdif.h"


// void EpdIf::DigitalWrite(int pin, int value) {
//     digitalWrite(pin, value);
// }

// int EpdIf::DigitalRead(int pin) {
//     return digitalRead(pin);
// }

// void EpdIf::DelayMs(unsigned int delaytime) {
//     delay(delaytime);
// }

int fd = 0;
static struct spi_ioc_transfer tr;

void SpiTransfer(uint8_t data) {
    tr.delay_usecs = 0;
    uint8_t rbuf[1];
    tr.len = 1;
    tr.tx_buf =  (unsigned long)&data;
    tr.rx_buf =  (unsigned long)rbuf;

    digitalWrite(CS_PIN, LOW);
    // TODO:
    // SPI.transfer(data);
    // write(fd, &data, 1);
    // printf("Writing: %d\n", data);

    if ( ioctl(fd, SPI_IOC_MESSAGE(1), &tr) < 1 )  
        printf("can't send spi message\r\n"); 

    digitalWrite(CS_PIN, HIGH);
}

int IfInit(void) {
    pinMode(CS_PIN, OUTPUT);
    pinMode(RST_PIN, OUTPUT);
    pinMode(DC_PIN, OUTPUT);
    pinMode(BUSY_PIN, INPUT); 
    pullUpDnControl(BUSY_PIN, PUD_UP);

    // TODO:
    // SPI.begin();
    fd = open("/dev/spidev0.0", O_RDWR);
    // SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));

    static uint8_t mode = 0;
    // mode |= SPI_LSB_FIRST;
    // mode |= SPI_CPHA;
    // mode |= SPI_CPOL;

    static uint8_t bits = 8;
    static uint32_t speed = 10000000;

    printf("FD: %d mode %d\n", fd, mode);

    int ret;
    ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret == -1)
		perror("can't set spi mode");

	ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
	if (ret == -1)
		perror("can't get spi mode");

        ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1)
		perror("can't set bits per word");

	ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1)
		perror("can't get bits per word");

	/*
	 * max speed hz
	 */
	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		perror("can't set max speed hz");

	ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1)
		perror("can't get max speed hz");



    return 0;
}