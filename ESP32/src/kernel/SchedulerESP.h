#ifndef __SCHEDULER_ESP__
#define __SCHEDULER_ESP__

#include <Ticker.h>
#include "Task.h"

#define MAX_TASKS 50

class Scheduler {
  
  int basePeriod;
  int nTasks;
  Task* taskList[MAX_TASKS];  
  Ticker timer;

public:
  void init(int basePeriod);  
  virtual bool addTask(Task* task);  
  virtual void schedule();
};

#endif
