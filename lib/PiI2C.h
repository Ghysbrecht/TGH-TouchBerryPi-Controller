#pragma once

class PiI2C{

  private:
    char *filename;
    int addr;
    int file_i2c;


  public:
    //Filename of I2C bus file, Address of I2C slave
    PiI2C(char *filename, int addr);
    void initBus(char *filename, int addr);
    void busWrite(char *buffer, int length);
    void busRead(char *buffer, int length);
    void readRegister(int address, char *buffer2, int length);
};
