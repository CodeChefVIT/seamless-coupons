#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  
String status ="";
const char* ssid = "Sandeep's Vivo";
const char* password = "qwerty123";
int fst,snd;
void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
Serial.println("COnnecting..");
WiFi.begin(ssid,password);
Serial.println(WiFi.localIP());
Serial.println("connected");
 SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}

String getvalue(String data,char Seperator, int index)
{
  int found =0;
  int strindex[] ={0,0};
  int maxindex = data.length()-1;
  for(int i;i<=maxindex && found <= index;i++){
    if(data.charAt(i)==Seperator || i==maxindex){
      found++;
      strindex[0]=strindex[1]+1;
      strindex[1]=(i==maxindex)?i+1:i;
      }
    }
  String finalstr=found>index?data.substring(strindex[0], strindex[1]):"";
  return finalstr;
 }

void loop() {
  // put your main code here, to run repeatedly:


if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
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
  String rfid = content.substring(1);



if (WiFi.status() == WL_CONNECTED){
  HTTPClient http;
  http.begin("http://192.168.43.194/codechef/final.php?rfid="+rfid);
  int httpcode = http.GET();
  if (httpcode>0){
    status = http.getString();
    //Serial.print(status);
    }
}
if (status == "Out of coupons"){
  Serial.print("No valid coupons");
  }
}
