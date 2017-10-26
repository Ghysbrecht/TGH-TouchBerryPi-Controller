#include "PiI2C.h"
#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port
#include <iostream>
#include <cstdio>

PiI2C::PiI2C(char *filename, int addr){
  this->filename = filename;
  this->addr = addr;
  initBus(this->filename, this->addr);
}
/*
//Write 4 bytes to the memory address
void Mbed_Eeprom::push(int addr, char *buffer){
  char buffer2[6] = {(char)0x00, ((char)addr), buffer[0], buffer[1], buffer[2], buffer[3] };
  busWrite(buffer2,6);
}

//Set the internal pointer to addr
void Mbed_Eeprom::pull(int addr){
  char buffer[2] = {0x01, ((char)addr)};
  busWrite(buffer,2);
}

//Read the 4 bytes at the current pointer location
void Mbed_Eeprom::readBytes(char *buffer, int length){
  busRead(buffer, length);
}

//Clear the memory
void Mbed_Eeprom::clear(){
  char buffer[] = {0x02};
  busWrite(buffer,sizeof(buffer));
}

//Print the memory to slave UART console
void Mbed_Eeprom::print(){
  char buffer[] = {0x03};
  busWrite(buffer,sizeof(buffer));
}*/

void PiI2C::initBus(char *filename, int addr){
  if ((this->file_i2c = open(filename, O_RDWR)) < 0) printf("Failed to open the i2c bus");
  if (ioctl(this->file_i2c, I2C_SLAVE, addr) < 0) printf("Failed to acquire bus access and/or talk to slave.\n");
}

void PiI2C::busWrite(char *buffer, int length){
  write(this->file_i2c, buffer, length);
}

void PiI2C::busRead(char *buffer, int length){
  if (read(this->file_i2c, buffer, length) != length)	printf("Failed to read from the i2c bus.\n");
}

void PiI2C::readRegister(int address, char *buffer2, int length){
  char buffer[] = {(char)address};
  busWrite(buffer,sizeof(buffer));
  busRead(buffer2, length);
}
