#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "EngrEDU IoT"; 
const char *password = "";

WiFiUDP Udp;
#define remoteUdpIP "192.168.4.2"
#define remoteUdpPort 3001

#define BUFF_SIZE 10
char udpBuff[BUFF_SIZE];
int counter = 0;

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password); // Start the access point
}

void loop() {
  // UDP Client structure  
  Udp.beginPacket(remoteUdpIP, remoteUdpPort);
  sprintf(udpBuff, "%i", counter++);
  Udp.write(udpBuff, BUFF_SIZE);
  Udp.endPacket();
  
  delay(1000);
}

