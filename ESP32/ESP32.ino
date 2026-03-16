#include "src/kernel/Scheduler.h"
Scheduler sched;

void setup() {
  sched.init(50);

}

void loop() {
  sched.schedule();

}
