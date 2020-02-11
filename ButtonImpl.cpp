#include "ButtonImpl.h"
#include "Arduino.h"

ButtonImpl::ButtonImpl(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);
}

bool ButtonImpl::isPressed(){
  return digitalRead(pin) == HIGH;
}

void ButtonImpl::press(State *state){
  switch(this->pin){
    case(SINGLE_BUTTON):
      *state = State::SINGLE;
      break;
    case(MANUAL_BUTTON):
      *state = State::MANUAL;
      break;
    case(AUTO_BUTTON):
      *state = State::AUTO;
      break;
  }
}
