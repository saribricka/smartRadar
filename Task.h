#ifndef __TASK__
#define __TASK__

#include "ButtonImpl.h"

class Task {
  int myPeriod;
  int timeElapsed;

  protected:
    void setMyPeriod(int period){
      this->myPeriod = period;
    }

  public:
    virtual void init(int period){
      this->myPeriod = period;
      timeElapsed = 0;
    }
    virtual void tick() = 0;
    bool updateAndCheckTime(int basePeriod){
      this->timeElapsed += basePeriod;
      if(this->timeElapsed >= this->myPeriod){
        this->timeElapsed = 0;
        return true;
      } else {
        return false;
      }
    }
};

#endif
