#ifndef __PLATFORM__
#define __PLATFORM__

#include "../config.h"
#include "../devices/ServoTimer2.h"
#include <LiquidCrystal_I2C.h>

class Platform {

  public:
  Platform();
  ServoTimer2* getServo();
  
  private:
  ServoTimer2* servo;
};

#endif