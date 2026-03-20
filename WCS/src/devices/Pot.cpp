#include "Pot.h"
#include "Arduino.h"

Potentiometer::Potentiometer(int pin){
  this->pin = pin;
} 
  
void Potentiometer::sync(){
  value = analogRead(pin);  
}

float Potentiometer::getValue(){
  return value / 1023.0;
}
