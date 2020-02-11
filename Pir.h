#ifndef __PIR__
#define __PIR__

class Pir {
  public:
    virtual int getPin() = 0;

  protected:
    virtual void init() = 0;
};

#endif
