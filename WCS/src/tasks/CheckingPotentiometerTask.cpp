#include "../tasks/CheckingPotentiometerTask.h"

CheckingPotentiometerTask::CheckingPotentiometerTask(Potentiometer* pot, SystemState* sy){
  potentiometer = pot;
  system = sy;
  setActive(false);
}

void CheckingPotentiometerTask::tick(){
  potentiometer->sync();
  system->setOpening(potentiometer->getValue()*100);
}