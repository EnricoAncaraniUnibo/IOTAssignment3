#include "ESP32.h"

Esp32::Esp32(){
  currentState = OFF;
}

NetworkState Esp32::getState(){
  return this->currentState;
}

void Esp32::setState(NetworkState s){
  currentState = s;
}