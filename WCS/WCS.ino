#include "src/kernel/Scheduler.h"
#include "src/model/Platform.h"

Scheduler sched;
Platform* p;
System* sy;
CommunicationTask* com;

void setup() {
  Serial.begin(9600);
  sched.init(50);
  p = new Platform();
  sy = new System();
  com=new CommunicationTask(sy);
  sched.addTask(com);
  com->init();
}

void loop() {
  sched.schedule();
  
}
