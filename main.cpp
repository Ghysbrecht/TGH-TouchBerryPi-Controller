#include <iostream>
#include <cstdio>
#include "lib/PiTouch.h"
#include <unistd.h>

int main(void){
  std::cout << "Starting I2C program" << std::endl;
  PiTouch piTouch;

  //Reading ID
  std::cout << "Reading ID..." << std::endl;
  std::cout << piTouch.getVendorID() << std::endl;

  //Reading the buttonstates
  std::cout << "Reading Buttonstate..." << std::endl;
  bool state = true;
  while(state){
    std::cout << PiTouch::getButtonName(piTouch.getButtonState()) << std::endl;
    if(PiTouch::getButtonName(piTouch.getButtonState()) == "X") state = false;
    usleep(100000);
  }

  std::cout << "End of program" << std::endl;

  piTouch.calibrate();
  piTouch.reset();

  return 0;
}
