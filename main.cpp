#include <iostream>
#include <cstdio>
#include "lib/PiTouch.h"
#include "lib/PiLed.h"
#include <unistd.h>

int main(void){
  std::cout << "Starting I2C program" << std::endl;
  PiTouch piTouch;
  PiLed piLed;

  //Testpatern for the leds
  piLed.setBrightness(0.05);
  piLed.setLed(0,1.0,0.0,0.0);
  piLed.setLed(1,0.0,1.0,0.0);
  piLed.setLed(2,0.0,0.0,1.0);
  piLed.setLed(3,1.0,1.0,0.0);
  piLed.setLed(4,0.0,1.0,1.0);

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
