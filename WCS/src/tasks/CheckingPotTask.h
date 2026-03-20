#ifndef __CHECKINGPOT_TASK__
#define __CHECKINGPOT_TASK__

#include "../kernel/Task.h"
#include <Arduino.h>
#include "../devices/Pot.h"
#include "../model/SystemState.h"

class CheckingPotTask: public Task{

  public:
    CheckingPotTask(Potentiometer* pot, SystemState* sy);
    void tick();

  private:
    Potentiometer* potentiometer;
    SystemState* system;
};

#endif