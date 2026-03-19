#ifndef __SWEEPING_TASK__
#define __SWEEPING_TASK__

#include "../kernel/Task.h"
#include <Arduino.h>
#include "../devices/ServoTimer2.h"

class SweepingTask: public Task{

  enum SweepingState {CLOSED,HALF,OPEN,CUSTOM};

  public:
    SweepingTask(ServoTimer2* servo);
    void tick();

  private:
    SweepingState state;
    ServoTimer2* servo;
};

#endif