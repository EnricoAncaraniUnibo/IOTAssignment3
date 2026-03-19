#ifndef __ESP32__
#define __ESP32__

enum NetworkState {
  ON,
  OFF
};

class Esp32 {

public:
  Esp32();

  NetworkState getState();
  void setState(NetworkState s);

private:
  NetworkState currentState;
};

#endif
