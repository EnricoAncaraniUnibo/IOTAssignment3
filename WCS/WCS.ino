#include "src/kernel/Scheduler.h"
#include "src/model/Platform.h"
#include "src/tasks/CommunicationTask.h"
#include "src/tasks/SweepingTask.h"
#include "src/tasks/CheckingPotTask.h"
#include <EnableInterrupt.h>

#define DEBOUNCE_MS 200
unsigned long lastPress = 0;

Scheduler sched;
Platform* p;
SystemState* sy;
CommunicationTask* com;
SweepingTask* swTask;
CheckingPotTask* cp;

void setup() {
  MsgService.init();
  sched.init(50);
  p = new Platform();
  sy = new SystemState();
  enableInterrupt(BUTTON_PIN,changeState,RISING);
  com=new CommunicationTask(sy);
  swTask = new SweepingTask(p->getServo(),sy);
  cp = new CheckingPotTask(p->getPot(),sy);
  sched.addTask(com);
  sched.addTask(swTask);
  sched.addTask(cp);
  com->init();
  swTask->init();
  p->getLCD()->init();
  p->getLCD()->backlight();
}

void loop() {
  sched.schedule();
}

void changeState(){
  unsigned long now = millis();
  if (now - lastPress < DEBOUNCE_MS) return;
  lastPress = now;
  if(sy->getState()==AUTOMATIC){
    sy->setState(MANUAL);
    cp->setActive(true);
    MsgService.sendMsg("MANUAL");
  }else{
    sy->setState(AUTOMATIC);
    cp->setActive(false);
    MsgService.sendMsg("AUTOMATIC");
  }
}
