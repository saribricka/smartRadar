#include "ChooseStateTask.h"

ChooseStateTask::ChooseStateTask(int pin1, int pin2, int pin3, State *state){
  this->pin[0] = pin1;
  this->pin[1] = pin2;
  this->pin[2] = pin3;
  this->state = state;
}

void ChooseStateTask::init(int period){
  Task::init(period);
  this->buttons[0] = new ButtonImpl(pin[0]);
  this->buttons[1] = new ButtonImpl(pin[1]);
  this->buttons[2] = new ButtonImpl(pin[2]);
  this->state = state;
}

void ChooseStateTask::tick(){
  for(int i=0; i<3; i++){
    if(buttons[i]->isPressed()){
      buttons[i]->press(this->state);
    }
  }
}
