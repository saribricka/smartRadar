#ifndef __SCANNINGTASK__
#define __SCANNINGTASK__

#include "Task.h"
#include "ServoMotorImpl.h"
#include "PotImpl.h"
#include "SonarImpl.h"

class ScanningTask: public Task{
  private:
    State* state;
    ServoMotor* servo;
    Pot* pot;
    Sonar* sonar;
    int currentPosition;
    bool* blinkState;
    void setInitialPosition();

  public:
    ScanningTask(State* state, bool* blinkState, ServoMotor* servo, Pot* pot, Sonar* sonar);
    void init(int period);
    void tick();
};

#endif
