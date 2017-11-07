#pragma once

#include <iostream>
#include "PiI2C.h"

class PiLed{

private:
  int address;
  PiI2C* i2c;

public:
  PiLed();
  void setBrightness(float brightness);
  void setChannel(int channel, float brightness);
  void enable();
  void initialize();
  void setOutputState(int ledout0, int ledout1, int ledout2, int ledout3);
  void setLed(int led, float red, float green, float blue);
  void setProgressBar(float value, float min, float max);

private:
  void setRegister(int reg, int value);



};
