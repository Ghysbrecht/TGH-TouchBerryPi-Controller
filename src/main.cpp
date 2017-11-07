#include <iostream>
#include <cstdio>
#include "lib/PiTouch.h"
#include "lib/PiLed.h"
#include "lib/ThumperControl.h"
#include <unistd.h>

int main(void){
  std::cout << "Starting I2C program" << std::endl;
  PiTouch piTouch;
  PiLed piLed;
  ThumperControl thumperControl("192.168.1.125:3000");

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
    switch(piTouch.getButtonState()){
      case 1:  thumperControl.driveLeft(); break;
      case 2:  thumperControl.driveRight(); break;
      case 4:  thumperControl.driveForw(); break;
      case 8:  thumperControl.driveBack(); break;
      case 16: thumperControl.turnHornOn(); break;
      case 32: thumperControl.turnHornOff(); break;
      case 64: thumperControl.setRandomLed(); break;
    }
    piLed.setProgressBar(thumperControl.getVoltage(), 9.6, 12.6);
    usleep(100000);
  }


  std::cout << "End of program" << std::endl;

  piTouch.calibrate();
  piTouch.reset();

  return 0;
}
