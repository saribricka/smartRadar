#include "TrackingAlarmTask.h"
#include "Arduino.h"

TrackingAlarmTask::TrackingAlarmTask(State* state, Sonar* sonar){
  this->state = state;
  this->sonar = sonar;
}

void TrackingAlarmTask::init(int period){
  Task::init(period);
}

void TrackingAlarmTask::tick(){
  float distance = this->sonar->scan();
  Serial.println("TRACKING ALARM " + String(distance));
  if(distance >= DFAR){
    *(this->state) = State::AUTO;
  }
}
