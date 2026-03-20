#ifndef __CHECKINGPOTENTIOMETER_TASK__
#define __CHECKINGPOTENTIOMETER_TASK__

#include "../kernel/Task.h"
#include "../model/Platform.h"
#include "../devices/Pot.h"
#include "../model/SystemState.h"

class CheckingPotentiometerTask : public Task {
public:
    CheckingPotentiometerTask(Potentiometer* pot, SystemState* sy);
    void tick();

private:
    SystemState* system;
    Potentiometer* potentiometer;
};

#endif