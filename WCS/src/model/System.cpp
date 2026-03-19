#include "System.h"

System::System(){
  opening=0;
}

int System::getOpening(){
  return opening;
}

void System::setOpening(int n){
  opening = n;
}