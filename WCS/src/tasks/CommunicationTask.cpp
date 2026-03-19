// CommunicationTask.cpp
#include "CommunicationTask.h"

CommunicationTask::CommunicationTask(System* sy) {
    system = sy;
}

void CommunicationTask::init() {
    setActive(true);
}

void CommunicationTask::tick() {
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
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