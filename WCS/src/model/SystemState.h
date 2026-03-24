#ifndef __SYSTEMSTATE__
#define __SYSTEMSTATE__

enum SystemActualState {
  AUTOMATIC,
  MANUAL,
  UNCONNECTED
};

class SystemState {

public:
  SystemState();

  int getOpening();
  void setOpening(int n);
  int getLastOpening();
  void setLastOpening(int n);
  SystemActualState getState();
  void setState(SystemActualState s);

private:
  int opening;
  SystemActualState state;
  int lastOpening;
};

#endif
