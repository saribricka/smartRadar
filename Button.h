#ifndef __BUTTON__
#define __BUTTON__

#include "Utils.h"

class Button {
  public:
    virtual bool isPressed() = 0;
    virtual void press(State *state) = 0;
};

#endif
