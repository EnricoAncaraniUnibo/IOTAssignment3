#include "SystemState.h"
#include "../kernel/MsgService.h"

SystemState::SystemState(){
  state = AUTOMATIC;
  opening=0;
}

int SystemState::getOpening(){
  return opening;
}

void SystemState::setOpening(int n){
  if(n!=opening){
    MsgService.sendMsg(String(n));
  }
  opening = n;
}

SystemActualState SystemState::getState(){
  return state;
}

void SystemState::setState(SystemActualState s){
  state = s;
}