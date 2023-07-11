#include "WiFi.h"
#include <esp_now.h>

typedef struct struct_message {
  char a[32];
  float b;
  float c;
} struct_message;

struct_message myData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len){
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Data received: ");
  Serial.println(len);
  Serial.println(myData.a);
  Serial.print("Celsius Temperature: ");
  Serial.println(myData.b);
  Serial.print("Fahrenheit Temperature: ");
  Serial.println(myData.c);

}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  if(esp_now_init() != ESP_OK){
    Serial.println("Error initiating ESP-NOW");
    return;
  }
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  // put your main code here, to run repeatedly:

}
