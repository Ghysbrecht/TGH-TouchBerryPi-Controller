#include "PiTouch.h"

PiTouch::PiTouch(){
  address = 0x1B;
  i2c = new PiI2C((char*)"/dev/i2c-1", address);
}


int PiTouch::getVendorID(){
  char buffer[1];
  i2c->readRegister(0,buffer,1);
  return (int)buffer[0];
}

Key PiTouch::getButtonState(){
  char buffer[1];
  i2c->readRegister(3,buffer,1);
  return (Key)buffer[0];
}

void PiTouch::calibrate(){

}

void PiTouch::reset(){

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
