#include <iostream>
#include <cstdio>
#include "lib/PiTouch.h"
#include <unistd.h>

int main(void){
  std::cout << "Starting I2C program" << std::endl;
  PiTouch piTouch;

  //Wait a second before doing things
  //sleep(3);

  //Reading from that address
  std::cout << "Reading ID..." << std::endl;
  std::cout << piTouch.getVendorID() << std::endl;

  std::cout << "Reading Buttonstate..." << std::endl;
  while(1){
    std::cout << PiTouch::getButtonName(piTouch.getButtonState()) << std::endl;
    usleep(100000);
  }

  std::cout << "End of program" << std::endl;

  return 0;
}
