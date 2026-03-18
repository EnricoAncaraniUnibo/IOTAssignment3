#include "src/tasks/CheckingWaterLevelTask.h"
#include "src/model/Platform.h"
#include "src/model/ESP32.h"



void setup() {
  Serial.begin(115200);
  Serial.println(xPortGetCoreID());
}

void loop() {

}
