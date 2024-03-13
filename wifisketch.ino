#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);
#define fan D5
#define touch1_1 D0
#define touch2_1 D1
#define touch3_1 D2

void setup() {
  pinMode(fan, OUTPUT);
  digitalWrite(fan, LOW);
  pinMode(touch1_1, INPUT);
  pinMode(touch2_1, INPUT);
  pinMode(touch3_1, INPUT);
  Serial.begin(9600);
  WiFi.begin("iitk");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("..");
    delay(1000);
  }
  Serial.println();
  Serial.println("NodeMCU is Connected!");
  Serial.println(WiFi.localIP());
}

void loop() {
  client = server.available();  //Gets a client that is connected to the server and has data available for reading.    
  if (client == 1)
  {  
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
  if ((digitalRead(touch1_1) == HIGH) || (digitalRead(touch2_1) == HIGH) || (digitalRead(touch3_1) == HIGH)) {
    digitalWrite(fan, !digitalRead(fan));
    delay(500);
  }
}
