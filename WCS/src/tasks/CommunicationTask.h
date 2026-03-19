#ifndef COMMUNICATION_TASK_H
#define COMMUNICATION_TASK_H

#include "../kernel/Task.h"
#include "../model/Platform.h"
#include "MsgService.h"
#include "System.h"

class CommunicationTask : public Task {
public:
    CommunicationTask(System* sy);
    void init();
    void tick();

private:
    System* system;
};

#endif