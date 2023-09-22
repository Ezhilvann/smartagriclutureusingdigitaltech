#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
// WiFi network info.
char ssid[] ="project";
char wifiPassword[] ="123456789";
char red1;
// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "ef2d1a20-59b0-11ed-baf6-35fab7fd0ac8";
char password[] = "5635daaddd6724075dcecc8ae925918c2d13c163";
char clientID[] = "3deeb150-59b1-11ed-baf6-35fab7fd0ac8";

#define level A0
#define motion D7
#define m1 D6



int a=0,b=0,c=0,d=0,e=0,A=0,B=0,C=0,D=0,E=0,F=0;
void smart() 
{
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  digitalWrite(m1,0);
  
 
  
  pinMode(m1,OUTPUT);
  
  Serial.begin(9600);
  delay(200);
}
void loop() 
{
  Cayenne.loop();
 

 a=analogRead(level);
 c=digitalRead(motion);

delay(200);

Serial.println(a);
delay(300);
Cayenne.virtualWrite(1,a);
delay(1000);
Serial.println(c);
delay(300);
Cayenne.virtualWrite(4,c);
delay(1000);


if(A==1)                      
{
 digitalWrite(m1,HIGH);
 delay(1000);
}
if(B==1)                      
{
 digitalWrite(m1,LOW);
 delay(1000);
}
}
CAYENNE_IN(2)
{
A=getValue.asInt();
}
CAYENNE_IN(3)
{
B=getValue.asInt();
}
