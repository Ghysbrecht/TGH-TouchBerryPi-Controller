#include "PiTouch.h"

PiTouch::PiTouch(){
  address = 0x1B;
  i2c = new PiI2C((char*)"/dev/i2c-1", address);
}


int PiTouch::getVendorID(){
  return getRegisterValue(0);
}

Key PiTouch::getButtonState(){
  return (Key)getRegisterValue(3);
}

int PiTouch::getRegisterValue(int addr){
  char buffer[1];
  i2c->readRegister(addr,buffer,1);
  return (int)buffer[0];
}

void PiTouch::calibrate(){
  i2c->writeRegister(56, 255);
}

void PiTouch::reset(){
  i2c->writeRegister(57, 255);
}

std::string PiTouch::getButtonName(Key key){
  std::string button = "NONE";
  switch(key){
    case LEFT:  button = "LEFT";  break;
    case RIGHT: button = "RIGHT"; break;
    case UP:    button = "UP";    break;
    case DOWN:  button = "DOWN";  break;
    case B:     button = "B";     break;
    case A:     button = "A";     break;
    case X:     button = "X";     break;
  }
  return button;
}
