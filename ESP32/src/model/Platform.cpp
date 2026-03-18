#include "Platform.h"
#include "../config.h"

Platform::Platform(){
  s = new Sonar(SONAR_TRIG_PIN,SONAR_ECHO_PIN,20);
  greenLed = new Led(GREEN_LED_PIN);
  redLed = new Led(RED_LED_PIN);
}

Sonar* Platform::getSonar(){
  return this->s;
}

Led* Platform::getGreenLed(){
return this->greenLed;
}

Led* Platform::getRedLed(){
return this->redLed;
}