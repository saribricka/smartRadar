#include "BlinkTask.h"

BlinkTask::BlinkTask(bool* blinkState, Led* led){
  this->blinkState = blinkState;
  this->led = led;
  this->on = false;
}

void BlinkTask::init(int period){
  Task::init(period);
}

void BlinkTask::tick(){
  if(this->on && *(this->blinkState) == false){
    this->led->off();
    this->on = false;
  } else {
    if(*(this->blinkState)){
      this->led->on();
      this->on = true;
      *(this->blinkState) = 0;
    }
  }
}
