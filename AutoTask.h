#ifndef __AUTOTASK__
#define __AUTOTASK__

#include "Task.h"
#include "ServoMotorImpl.h"
#include "PotImpl.h"
#include "SonarImpl.h"

class AutoTask: public Task{
  protected:
    State* state;
    ServoMotor* servo;
    Pot* pot;
    Sonar* sonar;
    int currentPosition;
    void setInitialPosition();
    int delta = 180/N;

  public:
    AutoTask(State* state, ServoMotor* servo, Pot* pot, Sonar* sonar);
    void init(int period);
    void tick();
};

#endif
