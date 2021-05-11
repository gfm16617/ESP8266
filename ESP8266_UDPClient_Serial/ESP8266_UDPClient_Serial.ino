#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "EngrEDU IoT"; 
const char *password = "";

WiFiUDP Udp;
#define remoteUdpIP "192.168.4.2"
#define remoteUdpPort 3001

#define BUFF_SIZE 10
char udpBuff[BUFF_SIZE];
char incomingChar = 0; // for incoming serial data
int iBuff;

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password); // Start the access point
}

void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    delay(2); // allow the serial buffer to get data
    // read start of message:
    incomingChar = Serial.read();
    if(incomingChar == '#')
    {
      iBuff = 0; // set udpBuff Index to zero
      // read the rest of the characters until BUFF_SIZE or '13'
      incomingChar = Serial.read();
      while((incomingChar != 10)){
        udpBuff[iBuff] = incomingChar;
        iBuff++;
        if(iBuff == BUFF_SIZE)
          break;
        incomingChar = Serial.read();
      }

      // UDP Client structure  
      Udp.beginPacket(remoteUdpIP, remoteUdpPort);
      Udp.write(udpBuff, BUFF_SIZE);
      Udp.endPacket();
    }
  }

  // Clear udpBuff
  for(int i = 0; i<BUFF_SIZE; i++)
    udpBuff[i] = 0;
}

