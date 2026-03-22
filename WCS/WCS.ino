#include "src/kernel/Scheduler.h"
#include "src/model/Platform.h"
#include "src/tasks/CommunicationTask.h"
#include "src/tasks/SweepingTask.h"
#include "src/tasks/CheckingPotTask.h"
#include <EnableInterrupt.h>

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
  if(sy->getState()==AUTOMATIC){
    sy->setState(MANUAL);
    cp->setActive(true);
  }else{
    sy->setState(AUTOMATIC);
    cp->setActive(false);
  }
}
