#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 2
#define RST_PIN 20
MFRC522 mfrc522(SS_PIN, RST_PIN);  

const char *ssid = "Sandeep's Vivo";  //ENTER YOUR WIFI SETTINGS
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
  Serial.print("UID tag :");
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
  
  HTTPClient http;
  http.begin("http://192.168.43.194/codechef/coupons/deduct.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String postData = "rfid="+rfid;
  int httpCode = http.POST(postData);
  String payload = http.getString();
 
  //Serial.println(httpCode);
  Serial.println(payload);
  http.end();

}
