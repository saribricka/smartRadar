#include "PirImpl.h"
#include "Arduino.h"

#define CALIBRATION_TIME_SEC 10

PirImpl::PirImpl(int pin){
  this->pin = pin;
  pinMode(this->pin, INPUT);
  this->init();
}

int PirImpl::getPin(){
  return this->pin;
}

void PirImpl::init(){
  Serial.println("PLEASE WAIT WHILE CALIBRATING PIR SENSOR");
  for(int i = 0; i < CALIBRATION_TIME_SEC; i++){
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" done");
  Serial.println("PIR SENSOR READY.");
}
