#include <ESP8266WiFi.h>

const char *ssid = "EngrEDU IoT"; 
const char *password = "";

const char* host = "192.168.4.2";
const uint16_t port = 3000;

// TCP socket
WiFiClient client;

int counter = 0;

void setup() {
  Serial.begin(115200);
  // Create an Access Point
  WiFi.softAP(ssid, password); // Start the access point
}

void loop() {

  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    Serial.println("wait 2 sec...");
    delay(2000);
    return;
  }

  // Send TCP packet
  client.println(counter++);
  // Close connection
  client.stop();

  // Wait 1 sec
  delay(1000);
}

