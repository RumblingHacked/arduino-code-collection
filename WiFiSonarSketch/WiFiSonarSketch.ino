#include <SPI.h>
#include <WiFi.h>
#include<NewPing.h>
int status = WL_IDLE_STATUS;
WiFiServer server(23);
boolean clientConnected = false;
NewPing sonar (6, 6, 200);


void setup() {
  Serial.begin(9600);
  while(!Serial);
  connectOpenNetwork("UTPB");
  server.begin();

}

void loop() {
  WiFiClient client = server.available();
  if(client){
    if(!clientConnected){
      client.flush();
      Serial.println("New Client");
      client.println("Hi!");
      clientConnected = true;
    }
    if(client.available()>0){
      char temp = client.read();
      if(temp == 'u'){
        unsigned int uS = sonar.ping();
        server.write(uS/US_ROUNDTRIP_CM);
        }
      }
      } 
    }
    
      void connectOpenNetwork(char ssid[]){
        Serial.print("Connecting To ");
        Serial.println(ssid);
        status = WiFi.begin(ssid);
        while (status != WL_CONNECTED);
          Serial.print("CONNECTED!");
            Serial.print(WiFi.localIP());
        }

        void connectClosedNetwork(char ssid[], char password[]){
          Serial.print("Connecting To ");
          Serial.println(ssid);
          status = WiFi.begin(ssid);
          while(status != WL_CONNECTED);
            Serial.print("CONNECTED!");
              Serial.print(WiFi.localIP());
          }

          void printNetworks(){
            Serial.println("Scanning Networks");
            byte num = WiFi.scanNetworks();

            for (int network = 0; network<num; network++){
              Serial.print(network);
              Serial.print(")");
              Serial.print(WiFi.SSID(network));
              Serial.print(" Strength: ");
              Serial.print(WiFi.RSSI(network));
              Serial.print(" dBm Security: ");
              Serial.println(WiFi.encryptionType(network));
            }

}
