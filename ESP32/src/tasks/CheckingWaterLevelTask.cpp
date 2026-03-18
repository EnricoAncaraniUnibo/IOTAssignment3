#include "CheckingWaterLevelTask.h"
#include "../config.h"

CheckingWaterLevelTask::CheckingWaterLevelTask(Sonar* sonar): sonar(sonar){
  setActive(false);
}

void CheckingWaterLevelTask::init(){
  setActive(true);
}

void CheckingWaterLevelTask::tick(){
  float d = sonar->getDistance();
  lastDistance = d;
}