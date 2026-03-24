#include "CheckingPotTask.h"

extern bool updateOpening;

CheckingPotTask::CheckingPotTask(Potentiometer* pot, SystemState* sy){
  potentiometer = pot;
  system = sy;
  setActive(false);
}

void CheckingPotTask::tick(){
  potentiometer->sync();
  int currentPotPos = (int)(potentiometer->getValue() * 100);
  if(updateOpening==true){
    system->setOpening(currentPotPos);
  }else{
    if(abs(currentPotPos - system->getLastOpening()) > 10) {
      updateOpening = true;
      system->setOpening(currentPotPos);
      system->setLastOpening(-1);
    }
  }
  
}