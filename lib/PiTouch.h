#pragma once

#include <iostream>
#include <string>
#include "PiI2C.h"

enum Key{
  LEFT = 1,
  RIGHT = 2,
  UP = 4,
  DOWN = 8,
  B = 16,
  A = 32,
  X = 64
};

class PiTouch{

private:
  int address;
  PiI2C* i2c;

public:
  PiTouch();
  int getVendorID();
  Key getButtonState();
  void calibrate();
  void reset();
  static std::string getButtonName(Key key);

};
