#include "serialdata.h"
#include <iostream>  /* Standard input/output stream */
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

#include "common/mavlink.h"

SerialData::SerialData()
{

}

int SerialData::OpenPort(const char *port, int baud, char* device)
{

    struct termios options;

    //std::cout << device << std::endl;

    this->fd = open(port, O_RDONLY | O_NDELAY);
    if (fd == -1)
    {
        perror("open_port: Unable to open /dev/ttyACM0 - ");
        return -1;
    }

    //Get current options for the port
    tcgetattr(fd, &options);

    baud = 0; //Need to convert baud
    baud++;

    //Set baud rates to 38400
    cfsetispeed(&options, B38400);
    cfsetospeed(&options, B38400);

    //Enable the receiver and set local mode
    options.c_cflag |= (CLOCAL | CREAD);

    //Set the new options for the port
    tcsetattr(fd, TCSANOW, &options);

    return 0;
}

int SerialData::Read(char (&buffer)[256])
{
    //Read to the buffer
    ssize_t length = read(this->fd, &buffer, sizeof(buffer));
    if (length == -1)
    {
        printf("Error reading from serial port\n");
        return -1;
    }

    //Print buffer
    buffer[length] = '\0';
    //printf("%s", buffer);
    return 0;
}

int SerialData::Write(char* const buffer)
{
    printf("%s",buffer);
    return 0;
}

SerialData::~SerialData()
{
    close(fd);
}
