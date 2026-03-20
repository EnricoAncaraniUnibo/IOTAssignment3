#ifndef __PLATFORM__
#define __PLATFORM__

#include "../config.h"
#include "../devices/ServoTimer2.h"
#include <LiquidCrystal_I2C.h>
#include "../devices/Pot.h"

class Platform {

  public:
  Platform();
  ServoTimer2* getServo();
  Potentiometer* getPot();
  LiquidCrystal_I2C* getLCD();
  
  private:
  ServoTimer2* servo;
  Potentiometer* pot;
  LiquidCrystal_I2C* lcd;
};

#endif