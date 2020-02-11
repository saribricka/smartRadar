#ifndef __TRACKINGALARMTASK__
#define __TRACKINGALARMTASK__

#include "Task.h"
#include "SonarImpl.h"

class TrackingAlarmTask : public Task{
  private:
    State* state;
    Sonar* sonar;

  public:
    TrackingAlarmTask(State* state, Sonar* sonar);
    void init(int period);
    void tick();

};

#endif
