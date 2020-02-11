#include "PotImpl.h"
#include "Arduino.h"

PotImpl::PotImpl(int pin){
  this->pin = pin;
}

int PotImpl::getPin(){
  return this->pin;
}

int PotImpl::getValue(){
  return analogRead(this->getPin());
}
