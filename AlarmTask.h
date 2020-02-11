#ifndef __ALARMTASK__
#define __ALARMTASK__

#include "AutoTask.h"
#include "ServoMotorImpl.h"
#include "PotImpl.h"
#include "SonarImpl.h"

class AlarmTask: public AutoTask{
  private:
    bool detected;
    bool* blinkState;
    void checkDetected();

  public:
    AlarmTask(State* state, bool* blinkState, ServoMotor* servo, Pot* pot, Sonar* sonar);
    void init(int period);
    void tick();
};

#endif
