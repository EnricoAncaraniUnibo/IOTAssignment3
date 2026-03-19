#ifndef __CHECKINGWATERLEVEL_TASK__
#define __CHECKINGWATERLEVEL_TASK__

#include "../kernel/Task.h"
#include <Arduino.h>
#include "../devices/Sonar.h"

class CheckingWaterLevelTask : public Task {

public:
  CheckingWaterLevelTask(Sonar* sonar);
  void tick();
  void init();
  float getLastDistance();

private:
  Sonar* sonar;
  float lastDistance;
};

#endif