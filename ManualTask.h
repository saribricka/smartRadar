#ifndef __MANUALTASK__
#define __MANUALTASK__

#include "Task.h"

class ManualTask: public Task{
  private:

  public:
    ManualTask();
    void init(int period);
    void tick();
};

#endif
