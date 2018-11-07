#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

 ESP8266WebServer server(80);
void setup() {
 // put your setup code here, to run once:
 WiFi.mode(WIFI_AP_STA);
 WiFi.softAP("name" ,"password");
 Serial.begin(115200);
 delay(500);
 Serial.println("Starting ESooriAccess");

 server.begin();
 server.on("/", handleRoot);
 server.onNotFound(handleNotFound);
}
void handleRoot() {
 String s = "Welcome to ESP8266"; 
 server.send(200, "text/plain", s); //Send web page
}

void loop() {

}
