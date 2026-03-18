#ifndef __PLATFORM__
#define __PLATFORM__

#include "../devices/Sonar.h"
#include "../devices/Led.h"

class Platform {

  public:
  Platform();
  Sonar* getSonar();
  Led* getGreenLed();
  Led* getRedLed();

  private:
  Sonar* s;
  Led* greenLed;
  Led* redLed;
};

#endif