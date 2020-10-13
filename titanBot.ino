#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = "Auth token";
char ssid[] = "hello_world";
char pass[] = "hello_world";
int PWMA=5;//Right side
int PWMB=4;//Left side
int DA=0;//Right reverse
int DB=2;//Left reverse
int da=15;
int db=16;
void setup(){
Blynk.begin(auth, ssid, pass);
pinMode(PWMA, OUTPUT);
pinMode(PWMB, OUTPUT);
pinMode(DA, OUTPUT);
pinMode(DB, OUTPUT);
Serial.begin(115200);
delay(10);
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, pass);
int wifi_ctr = 0;
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("WiFi connected");
Blynk.begin(auth, ssid, pass);
}
void loop(){
Blynk.run();
}

BLYNK_WRITE(V1){
int x = param[0].asInt();
int y = param[1].asInt();
if(x==-1 && y==-1){ //Backward and Left
digitalWrite(PWMA, LOW);
digitalWrite(DA, LOW);
digitalWrite(da, HIGH);
digitalWrite(PWMB, HIGH);
digitalWrite(DB, HIGH);
digitalWrite(db, LOW);
}else if(x==-1 && y==0){ //Left Turn
digitalWrite(PWMA, 450);
digitalWrite(DA, HIGH);
digitalWrite(da, LOW);
digitalWrite(PWMB, 450);
digitalWrite(DB, LOW);
digitalWrite(db, HIGH);
}else if(x==-1 && y==1){ //Forward and Left
digitalWrite(PWMA, LOW);
digitalWrite(DA, LOW);
digitalWrite(da, HIGH);
digitalWrite(PWMB, HIGH);
digitalWrite(DB, LOW);
digitalWrite(db, HIGH);
}else if(x==0 && y==-1){ //Backward
digitalWrite(PWMA, HIGH);
digitalWrite(DA, HIGH);
digitalWrite(da, LOW);
digitalWrite(PWMB, HIGH);
digitalWrite(DB, HIGH);
digitalWrite(db, LOW);
}else if(x==0 && y==0){ //Stay
digitalWrite(PWMA, LOW);
digitalWrite(DA, LOW);
digitalWrite(da, HIGH);
digitalWrite(PWMB, LOW);
digitalWrite(DB, LOW);
digitalWrite(db, HIGH);
}else if(x==0 && y==1){ //Forward
digitalWrite(PWMA, HIGH);
digitalWrite(DA, LOW);
digitalWrite(da, HIGH);
digitalWrite(PWMB, HIGH);
digitalWrite(DB, LOW);
digitalWrite(db, HIGH);
}else if(x==1 && y==-1){ //Backward and Right
digitalWrite(PWMA, HIGH);
digitalWrite(DA, HIGH);
digitalWrite(da, LOW);
digitalWrite(PWMB, LOW);
digitalWrite(DB, LOW);
digitalWrite(db, HIGH);
}else if(x==1 && y==0){ //Right turn
digitalWrite(PWMA, 450);
digitalWrite(DA, LOW);
digitalWrite(da, HIGH);
digitalWrite(PWMB, 450);
digitalWrite(DB, HIGH);
digitalWrite(db, LOW);
}else if(x==1 && y==1){ //Forward and Right
digitalWrite(PWMA, HIGH);
digitalWrite(DA, LOW);
digitalWrite(da, HIGH);
digitalWrite(PWMB, LOW);
digitalWrite(DB, LOW);
digitalWrite(db, HIGH);
}
}
