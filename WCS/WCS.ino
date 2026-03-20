#include "src/kernel/Scheduler.h"
#include "src/model/Platform.h"
#include "src/tasks/CommunicationTask.h"
#include "src/tasks/SweepingTask.h"
#include "src/tasks/CheckingPotentiometerTask.h"

Scheduler sched;
Platform* p;
SystemState* sy;
CommunicationTask* com;
SweepingTask* swTask;
CheckingPotentiometerTask* cp;

void setup() {
  Serial.begin(9600);
  sched.init(50);
  p = new Platform();
  sy = new SystemState();
  com=new CommunicationTask(sy);
  swTask = new SweepingTask(p->getServo(),sy);
  cp = new CheckingPotentiometerTask(p->getPot(),sy);
  sched.addTask(com);
  sched.addTask(swTask);
  sched.addTask(cp);
  com->init();
  swTask->init();
}

void loop() {
  sched.schedule();
}
