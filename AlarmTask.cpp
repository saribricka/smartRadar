#include "AlarmTask.h"

AlarmTask::AlarmTask(State* state, bool* blinkState, ServoMotor* servo, Pot* pot, Sonar* sonar) : AutoTask(state, servo, pot, sonar){
  this->blinkState = blinkState;
  this->detected = false;
}

void AlarmTask::checkDetected(){
  if(!this->detected){
    *(this->state) = State::AUTO;
  }
  this->detected = false;
}

void AlarmTask::init(int period){
  AutoTask::init(period);
  this->detected = false;
}

void AlarmTask::tick(){
  Task::setMyPeriod(analogRead(this->pot->getPin()) * 8 + 125);
  if(this->currentPosition + delta >= 180){
    delta = - 180/N;
    this->checkDetected();
  }
  if(this->currentPosition + delta <= 0){
    delta = 180/N;
    this->checkDetected();
  }
  float distance = this->sonar->scan();
  if(distance < DFAR){
    this->detected = true;
  }
  currentPosition += delta;
  Serial.println(this->currentPosition);
  this->servo->setPosition(this->currentPosition * 8 + 750);
  *(this->blinkState) = true;
  Serial.println("ALARM");
}
