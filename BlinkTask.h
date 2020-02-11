#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"
#include "LedImpl.h"

class BlinkTask : public Task{
  private:
    Led* led;
    bool* blinkState;
    bool on;

  public:
    BlinkTask(bool* blinkState, Led* led);
    void init(int period);
    void tick();
};

#endif
