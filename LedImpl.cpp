#include "Arduino.h"
#include "LedImpl.h"

#define MAX_CYCLES 3

LedImpl::LedImpl(int pin){
  this->pin = pin;
}

void LedImpl::on(){
  digitalWrite(this->pin, HIGH);
}

void LedImpl::off(){
  digitalWrite(this->pin, LOW);
}
