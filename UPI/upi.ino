#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 2
#define RST_PIN 20
MFRC522 mfrc522(SS_PIN, RST_PIN);  

const char *ssid = "Sandeep's Vivo";
const char *password = "qwerty123";
 
const char *host = "192.168.43.194";

void setup() {
  delay(1000);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
 

void loop() {




  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  Serial.print("Please scan sender's id :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  Serial.println(content.substring(1));
  delay(1000);
  String rfid = content.substring(1);


Serial.print("Please scan reciever's id :");
  String content1= "";
  byte letter1;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content1.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content1.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  Serial.println(content1.substring(1));
  delay(1000);
  String rfid2 = content1.substring(1);


  if(rfid == rfid2){
    Serial.print("Sender and reciever cant be same");
    }
  else{
    if (Serial.available() > 0) {
                String Amount = Serial.readString();
                Serial.print("Amount : ");
                Serial.println(Amount);
                delay(1000);
                Serial.print("Do you want to confirm ( 1 - Yes / 0 - No) : ");
                String Cnfrm = Serial.readString();
                Cnfrm.toUpperCase();
                if (Cnfrm == "1"){
                  Serial.println("Please enter sender's 4 digit pin :");
                  String pin = Serial.readString();
                  Serial.print(" Please wait while we verify and tranfer your amount");
                  String finalstring = rfid + " ; " + rfid2 + " ; " + Amount + " ; " + pin;
                  HTTPClient http;
                  http.begin("http://192.168.43.194/codechef/final.php");
                  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
                  String postData = "final"+finalstring ;
                  int httpCode = http.POST(postData);
                  String payload = http.getString();
                  Serial.println(payload);
                  http.end();
                  
                  }
                else{
                  exit();
                  }
                
        }
    
    }
  
  

}
