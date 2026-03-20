#include "CommunicationTask.h"

CommunicationTask::CommunicationTask(SystemState* sy) {
    system = sy;
}

void CommunicationTask::init() {
    system->setOpening(0);
    setActive(true);
}

void CommunicationTask::tick() {
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        float coeff = (2250.0-750.0)/180.0;
        String content = msg->getContent();

        if (content == "cmd:OPEN") {
            system->setOpening(100);
        } else if (content == "cmd:HALF") {
            system->setOpening(50);
        } else if (content == "cmd:CLOSE") {
            system->setOpening(0);
        }

        delete msg;
    }
}