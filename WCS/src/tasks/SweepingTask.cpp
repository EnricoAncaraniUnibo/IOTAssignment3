#include "SweepingTask.h"

SweepingTask::SweepingTask(ServoTimer2* servo,SystemState* sy): servo(servo),system(sy){
  max=90;
}

void SweepingTask::init() {
    setActive(true);
}

void SweepingTask::tick(){
  float coeff = (2250.0-750.0)/180.0;
  float angle = (max/100)*system->getOpening();
  servo->write(750+angle*coeff);
}