#include "src/tasks/CheckingWaterLevelTask.h"
#include "src/model/Platform.h"
#include "src/model/ESP32.h"

TaskHandle_t CheckingWaterTask;
CheckingWaterLevelTask* CheckingWater;
Platform* p;

void setup() {
  Serial.begin(115200);
  p = new Platform();
  p->getRedLed()->switchOn();
  p->getGreenLed()->switchOff();
  CheckingWater = new CheckingWaterLevelTask(p->getSonar());
  xTaskCreatePinnedToCore(CheckingWater,"CheckingWaterLevelTask",10000,NULL,1,&CheckingWaterTask,0);
}

void loop() {

}

void waterTaskWrapper(void* param) {
  while(true) {
    CheckingWater->tick();
    Serial.println(CheckingWater->getLastDistance());
    vTaskDelay(1000);
  }
}
