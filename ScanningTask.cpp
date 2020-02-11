#include "ScanningTask.h"
#include "Arduino.h"

#define DELTA (180/N)

ScanningTask::ScanningTask(State* state, bool* blinkState, ServoMotor* servo, Pot* pot, Sonar* sonar){
  this->state = state;
  this->servo = servo;
  this->pot = pot;
  this->sonar = sonar;
  this->blinkState = blinkState;
  this->currentPosition = 0;
}

void ScanningTask::init(int period){
  Task::init(period);
  this->servo->on();
  this->setInitialPosition();
}

void ScanningTask::setInitialPosition(){
  this->currentPosition = 0;
  this->servo->setPosition(this->currentPosition);
}

void ScanningTask::tick(){
  Task::setMyPeriod(analogRead(this->pot->getPin()) * 8 + 125);
  if(this->currentPosition + DELTA >= 180){
    *(this->state) = State::MANUAL;
    this->setInitialPosition();
  }
  float distance = this->sonar->scan();
  if(distance < 1.0){
    *(this->blinkState) = true;
    Serial.println("Rilevato Oggetto");
  }
  currentPosition += DELTA;
  Serial.println(this->currentPosition);
  this->servo->setPosition(this->currentPosition * 8 + 750);
}
