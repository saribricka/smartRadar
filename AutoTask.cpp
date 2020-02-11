#include "AutoTask.h"
#include "Arduino.h"

AutoTask::AutoTask(State* state, ServoMotor* servo, Pot* pot, Sonar* sonar){
  this->state = state;
  this->servo = servo;
  this->sonar = sonar;
  this->pot = pot;
  this->currentPosition = 0;
}

void AutoTask::init(int period){
  Task::init(period);
  this->servo->on();
  this->setInitialPosition();
}

void AutoTask::setInitialPosition(){
  this->currentPosition = 0;
  this->servo->setPosition(this->currentPosition);
}

void AutoTask::tick(){
  Task::setMyPeriod(analogRead(this->pot->getPin()) * 8 + 125);
  if(this->currentPosition + delta >= 180){
    delta = - 180/N; 
  }
  if(this->currentPosition + delta < 0){
    delta = 180/N;
  }
  float distance = this->sonar->scan();
  if(distance > DNEAR && distance < DFAR){
    *(this->state) = State::ALARM;
  } else if(distance <= DNEAR){
    *(this->state) = State::TRACKING_ALARM;
  }
  currentPosition += delta;
  Serial.println(this->currentPosition);
  this->servo->setPosition(this->currentPosition * 8 + 750);
}
