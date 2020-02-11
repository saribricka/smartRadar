#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

#include "Arduino.h"
#include "ServoTimer2.h"

class ServoMotor{
  public:
    virtual void on() = 0;
    virtual void setPosition(int angle) = 0;
    virtual void off() = 0;
};

#endif
