#include <ThingSpeak.h>
#include <WiFi.h>
WiFiClient client;
const char* ssid = "Lucky";//Enter the ssid of your router
const char* password = "viniluckyram@123";//Enter the password of your router
const char* host = "api.thingspeak.com";
const char* privateKey = "I2J0GRQWZG7IRD0B";//read key
const char* privateKey1 = "83HAOPE4L4L6UTF0";//write key
void setup() {
Serial.begin(115200);
pinMode(4, OUTPUT);//setting led as output
//pinMode(fan, OUTPUT);//setting led as output
//dht.begin();
ThingSpeak.begin(client);
delay(10);
// We start by connecting to a WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED){
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
}
void loop() {
//float h= ThingSpeak.readFloatField( 626040,2);
int d= ThingSpeak.readIntField( 1315709,1);
Serial.print(d);
if(d==1)
{
digitalWrite(4,HIGH);
Serial.print("LED ON");
Serial.println("");
}
if(d==0)
{digitalWrite(4,LOW);
Serial.print("LED OFF");
Serial.println("");
}
delay(5000);
}
