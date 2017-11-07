#include "ThumperControl.h"
#include "restclient-cpp/restclient.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

ThumperControl::ThumperControl(std::string address){
  this->address = address;
  voltage = 0.0;
}

void ThumperControl::driveForw(){
  std::string payload = "{\"left_speed\":200,\"right_speed\":200}";
  sendDrivePayload(payload);
}

void ThumperControl::driveBack(){
  std::string payload = "{\"left_speed\":-200,\"right_speed\":-200}";
  sendDrivePayload(payload);
}

void ThumperControl::driveLeft(){
  std::string payload = "{\"left_speed\":-150,\"right_speed\":150}";
  sendDrivePayload(payload);
}

void ThumperControl::driveRight(){
  std::string payload = "{\"left_speed\":150,\"right_speed\":-150}";
  sendDrivePayload(payload);
}

void ThumperControl::sendDrivePayload(std::string payload){
  RestClient::Response r = RestClient::post("http://" + address + "/speed", "application/json", payload);
  std::string response = r.body;
  voltage = std::stof( response.substr(20,4) );
}

float ThumperControl::getVoltage(){
  return voltage;
}

void ThumperControl::turnHornOn(){
  std::string payload = "{\"action\":\"on\"}";
  RestClient::Response r = RestClient::post("http://" + address + "/alarm", "application/json", payload);
}

void ThumperControl::turnHornOff(){
  std::string payload = "{\"action\":\"off\"}";
  RestClient::Response r = RestClient::post("http://" + address + "/alarm", "application/json", payload);
}

void ThumperControl::setLed(int red, int green, int blue){
  std::string payload = "{\"red\":" + std::to_string(red) + ",\"green\":" + std::to_string(red) + ",\"blue\":" + std::to_string(blue) + "}";
  RestClient::Response r = RestClient::post("http://" + address + "/neopixels/strings/0", "application/json", payload);
  std::string response = r.body;
}

void ThumperControl::setRandomLed(){
  srand(time(NULL));
  setLed((rand()%255),(rand()%255),(rand()%255));
}
