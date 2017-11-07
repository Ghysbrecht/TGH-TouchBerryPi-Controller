#include "PiLed.h"

PiLed::PiLed(){
  address = 0x60;
  i2c = new PiI2C((char*)"/dev/i2c-1", address);
  initialize();
}

void PiLed::initialize()
{
    enable();
    setOutputState(0xFF,0xFF,0xFF,0xFF);
}

void PiLed::enable()
{
    setRegister(0,0);
}

void PiLed::setOutputState(int ledout0, int ledout1, int ledout2, int ledout3)
{
    setRegister(0x14,ledout0);
    setRegister(0x15,ledout1);
    setRegister(0x16,ledout2);
    setRegister(0x17,ledout3);
}

void PiLed::setChannel(int led, float brightness)
{
    char data[] = {(char)(0x02 + led), (char)(brightness * 255.0)};
    i2c->busWrite(data, 2);
}


void PiLed::setBrightness(float brightness)
{
    setRegister(0x12, brightness * 255.0);
}

void PiLed::setRegister(int reg, int value)
{
    char data[] = {(char)reg, (char)value};
    i2c->busWrite(data, 2);
}

void PiLed::setLed(int led, float red, float green, float blue){
  int startLed = led*3;
  setChannel(startLed, red);
  setChannel(startLed+1, green);
  setChannel(startLed+2, blue);
}

void PiLed::setProgressBar(float value, float min, float max){
  if(value > max) value = max;
  if(value < min) value = min;
  float percentage = (value - min) / (max - min);
  int numberLeds = (int)percentage*4;
  for(int i=0;i<5;i++){
    if(i <= numberLeds) setLed(i, 1.0, 0.0, 0.0);
    else setLed(i, 0.0, 1.0, 0.0);
  }
}
