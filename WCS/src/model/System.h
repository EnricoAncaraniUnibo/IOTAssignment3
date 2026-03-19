#ifndef __SYSTEM__
#define __SYSTEM__

class System {

public:
  System();

  HangarState getState();
  void setState(HangarState s);
  void setBackUp(HangarState s);
  HangarState getBackUp();

private:
  char* currentState;
};

#endif
