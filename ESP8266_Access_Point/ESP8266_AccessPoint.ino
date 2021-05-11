#include <ESP8266WiFi.h>

const char *ssid = "EngrEDU IoT";
const char *password = "";

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password); // Start the access point
}

void loop() {
}



