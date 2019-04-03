#define TRIGGER D1
#define ECHO D2
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

long duration,distance;

char ssid[] = "Sneha";    //  your network SSID (name) 
char pass[] = "Sneha15@figa";   // your network password
int status=WL_IDLE_STATUS;
unsigned long DistanceStationChannelNumber = 499334;
const char* myWriteAIPKey="CU65HU99W80KIS3B";
WiFiClient  client;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);  
WiFi.begin(ssid, pass); 
ThingSpeak.begin(client); 
pinMode(TRIGGER,OUTPUT);
pinMode(ECHO,INPUT);
Serial.println("connected to:");
Serial.println(ssid);
ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,distance;
  digitalWrite(TRIGGER,LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIGGER,HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIGGER,LOW);
  duration=pulseIn(ECHO,HIGH);
  distance=(duration/2) /29.1;
  ThingSpeak.writeFields(DistanceStationChannelNumber,myWriteAIPKey);

  Serial.print("Distance:");
  Serial.print(distance);
  Serial.print("cm");
  ThingSpeak.setField(1, distance); //float distanceInF
 
  delay(2000);
  
  

}
