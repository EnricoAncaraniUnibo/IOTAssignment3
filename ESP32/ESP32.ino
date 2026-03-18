#include "src/tasks/CheckingWaterLevelTask.h"
#include "src/model/Platform.h"
#include "src/model/ESP32.h"
#include "WiFi.h"
#include "PubSubClient.h"
#define MSG_BUFFER_SIZE  50

WiFiClient espClient;
PubSubClient client(espClient);
const char* ssid = "Ancarani_WIFI";
const char* password = "Ancarani98";
const char* mqtt_server = "broker.mqtt-dashboard.com";
const char* topic = "MSG";
TaskHandle_t CheckingWaterTask;
CheckingWaterLevelTask* CheckingWater;
Platform* p;
Esp32* esp;

void setup() {
  Serial.begin(115200);
  p = new Platform();
  esp=new Esp32();
  p->getRedLed()->switchOn();
  p->getGreenLed()->switchOff();
  CheckingWater = new CheckingWaterLevelTask(p->getSonar());
  xTaskCreatePinnedToCore(waterTaskWrapper,"CheckingWaterLevelTask",10000,NULL,1,&CheckingWaterTask,0);
  SetupConnection();
}

void loop() {
  if (!client.connected()) {
    esp->setState(OFF);
    p->getRedLed()->switchOn();
    p->getGreenLed()->switchOff();
    reconnect();
  }
  char msg[MSG_BUFFER_SIZE];
  snprintf (msg, MSG_BUFFER_SIZE, "#%f", CheckingWater->getLastDistance());
  client.publish(topic, msg);  
  Serial.println(String(msg));
  delay(1000);
}

void reconnect() {
  
  while (!client.connected()) {
    
    String clientId = String("assignment3-client-")+String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("Connected");
      esp->setState(ON);
      p->getRedLed()->switchOff();
      p->getGreenLed()->switchOn();
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
      Serial.println("Riprovo");
    }
  }
}

void waterTaskWrapper(void* param) {
  while(true) {
    if(esp->getState()==ON){
      CheckingWater->tick();
    }
    vTaskDelay(1000);
  }
}

void SetupConnection() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqtt_server, 1883);
  esp->setState(ON);
  p->getRedLed()->switchOff();
  p->getGreenLed()->switchOn();
}

