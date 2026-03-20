#ifndef __POT__
#define __POT__

class Potentiometer {
 
public: 
  Potentiometer(int pin);
  
  float getValue();

  virtual void sync();

private:
  int pin;
  float value;
};

#endif
