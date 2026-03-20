#ifndef __COMMUNICATION_TASK__
#define __COMMUNICATION_TASK__

#include "../kernel/Task.h"
#include "../model/Platform.h"
#include "../kernel/MsgService.h"
#include "../model/SystemState.h"
#include "../devices/ServoTimer2.h"

class CommunicationTask : public Task {
public:
    CommunicationTask(SystemState* sy);
    void init();
    void tick();

private:
    SystemState* system;
};

#endif