#ifndef __SINGLETASK__
#define __SINGLETASK__

#include "Task.h"
#include "PirImpl.h"

class SingleTask: public Task{
  private:
    Pir* pir;
    State* state;
  public:
    SingleTask(State *state);
    void init(int period);
    void tick();
};

#endif
