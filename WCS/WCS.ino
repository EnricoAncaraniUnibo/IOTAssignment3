#include "src/kernel/Scheduler.h"
#include "src/model/Platform.h"

Scheduler sched;
Platform* p;

void setup() {
  Serial.begin(9600);
  sched.init(50);
  p = new Platform();
}

void loop() {
  sched.schedule();
  
}
