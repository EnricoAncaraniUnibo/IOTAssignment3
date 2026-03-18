#include "src/kernel/SchedulerESP.h"
#include "src/tasks/CheckingWaterLevelTask.h"
#include "src/model/Platform.h"
#include "src/model/ESP32.h"
Scheduler sched;
CheckingWaterLevelTask* checkingWaterTask;
Platform* p;
Esp32* esp;

void setup() {
  sched.init(50);
  p=new Platform();
  esp = new Esp32();
  checkingWaterTask = new CheckingWaterLevelTask(p->getSonar());
  sched.addTask(checkingWaterTask);
  p->getRedLed()->switchOn();
}

void loop() {
  sched.schedule();

}
