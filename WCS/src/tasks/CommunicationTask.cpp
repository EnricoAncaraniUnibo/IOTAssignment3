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
        String content = msg->getContent();

        if (content == "cmd:OPEN") {
            system->setOpening(100);
            system->setState(AUTOMATIC);
        } else if (content == "cmd:HALF") {
            system->setOpening(50);
            system->setState(AUTOMATIC);
        } else if (content == "cmd:CLOSE") {
            system->setOpening(0);
            system->setState(AUTOMATIC);
        } else if (content == "st:UNCONNECTED") {
            system->setState(UNCONNECTED);
        }
        

        delete msg;
    }
}