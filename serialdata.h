#ifndef SERIALDATA_H
#define SERIALDATA_H

class SerialData
{
public:
    SerialData();
    int OpenPort(const char *port, int baud, char* const device);
    int Read(char (&buffer)[256]);
    int Write(char* buffer);
    ~SerialData();
private:
    int fd;
};

#endif // SERIALDATA_H
