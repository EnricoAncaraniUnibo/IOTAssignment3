#include "CheckingPotTask.h"

CheckingPotTask::CheckingPotTask(Potentiometer* pot, SystemState* sy){
  potentiometer = pot;
  system = sy;
  setActive(false);
}

void CheckingPotTask::tick(){
  potentiometer->sync();
  system->setOpening(potentiometer->getValue()*100);
}