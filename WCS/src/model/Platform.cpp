#include "Platform.h"

Platform::Platform(){
  servo = new ServoTimer2();
  servo->attach(MOTOR_PIN);
  pot = new Potentiometer(POTENZIOMETER_PIN);
  lcd = new LiquidCrystal_I2C(0x27, 20, 4);
}

ServoTimer2* Platform::getServo(){
  return this->servo;
}

Potentiometer* Platform::getPot(){
  return this->pot;
}

LiquidCrystal_I2C* Platform::getLCD(){
  return this->lcd;
}