#ifndef __SYSTEMSTATE__
#define __SYSTEMSTATE__

enum SystemActualState {
  AUTOMATIC,
  MANUAL
};

class SystemState {

public:
  SystemState();

  int getOpening();
  void setOpening(int n);
  SystemActualState getState();
  void setState(SystemActualState s);

private:
  int opening;
  SystemActualState state;
};

#endif
