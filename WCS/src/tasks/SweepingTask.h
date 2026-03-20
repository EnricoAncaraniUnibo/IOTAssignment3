#ifndef __SWEEPING_TASK__
#define __SWEEPING_TASK__

#include "../kernel/Task.h"
#include <Arduino.h>
#include "../devices/ServoTimer2.h"
#include "../model/SystemState.h"

class SweepingTask: public Task{

  public:
    SweepingTask(ServoTimer2* servo, SystemState* sy);
    void tick();
    void init();

  private:
    ServoTimer2* servo;
    SystemState* system;
    int max;
};

#endif