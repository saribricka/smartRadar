#ifndef __LEDIMPL__
#define __LEDIMPL__

#include "Led.h"

class LedImpl : public Led{
  public:
    LedImpl(int pin);
    void on();
    void off();

  protected:
    int pin;
};

#endif
