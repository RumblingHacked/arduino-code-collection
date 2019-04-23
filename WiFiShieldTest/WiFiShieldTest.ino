#include <SPI.h>
#include <WiFi.h>

int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);
  while(!Serial);

}

void loop() {
  delay(10000);
  printNetworks();

}

void printNetworks(){
  Serial.println("Scanning Networks");
  byte num = WiFi.scanNetworks();

  for (int network = 0; network < num; network++){
    Serial.print(network);
    Serial.print(")");
    Serial.print(WiFi.SSID(network));
    Serial.print("  Strength: ");
    Serial.print(WiFi.RSSI(network));
    Serial.print("dBm  Security: ");
    Serial.println(WiFi.encryptionType(network));
    }
  }

 void connectOpenNetwork(char ssid){
  Serial.print("Connecting To ");
  Serial.println(ssid);
  status = WiFi.begin(ssid);
  while(status!=WL_CONNECTED);
    Serial.print("Connected to: ");
    Serial.print(WiFi.localIP());
  }
