#include <WiFi.h>
#include <WiFiUdp.h>
int read_command;
const char * udpAddress = "10.30.0.191"; // your pc ip
const int udpPort = 8080; //port server
IPAddress local_IP(10,30,0,31);
IPAddress gateway(10, 30, 0, 1);
IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8); //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional
WiFiUDP udp;
void setup() {
 Serial.begin(115200);
   WiFi.begin(ssid, pwd);
    if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  udp.begin(udpPort);
}

void loop() {
  uint8_t buffer[50];
  udp.beginPacket(udpAddress, udpPort);
  udp.print(veri.dataMessage);
  udp.write(buffer, 11);
  udp.endPacket();
  memset(buffer, 0, 50);
    udp.parsePacket();
   if(udp.read(buffer, 50) > 0){
    Serial.print("Server to client: ");
    Serial.println((char *)buffer);
    buffer[50];
  read_command=atoi((char *)buffer);// read command and put your code
  if(read_command==0){
      // put your code for receive command
  }

}
