#include "src/tasks/CheckingWaterLevelTask.h"
#include "src/model/Platform.h"
#include "src/model/ESP32.h"

TaskHandle_t CheckingWaterTask;
CheckingWaterLevelTask* CheckingWater;
Platform* p;
Esp32* esp;

void setup() {
  p = new Platform();
  esp=new Esp32();
  p->getRedLed()->switchOn();
  p->getGreenLed()->switchOff();
  CheckingWater = new CheckingWaterLevelTask(p->getSonar());
  xTaskCreatePinnedToCore(waterTaskWrapper,"CheckingWaterLevelTask",10000,NULL,1,&CheckingWaterTask,0);
}

void loop() {

}

void waterTaskWrapper(void* param) {
  while(true) {
    if(esp->getState()==ON){
      CheckingWater->tick();
    }
    vTaskDelay(1000);
  }
}
