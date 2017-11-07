#pragma once

#include <string>

class ThumperControl{

private:
  std::string address;
  float voltage;


public:
  ThumperControl(std::string address);
  void driveForw();
  void driveBack();
  void driveLeft();
  void driveRight();
  void setLed(int red, int green, int blue);
  void setRandomLed();
  void turnHornOn();
  void turnHornOff();

  float getVoltage();

private:
  void sendDrivePayload(std::string payload);
};
