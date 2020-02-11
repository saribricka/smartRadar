#ifndef __CHOOSESTATETASK__
#define __CHOOSESTATETASK__

#include "Task.h"

class ChooseStateTask: public Task{
  private:
    int pin[3];
    Button* buttons[3];
    State* state;

  public:
    ChooseStateTask(int pin1, int pin2, int pin3, State* state);
    void init(int period);
    void tick();
};

#endif
