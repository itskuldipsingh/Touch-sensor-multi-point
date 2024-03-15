#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define bulb D5
#define touch1_1 D0
#define touch2_1 D1
#define touch3_1 D2

bool bulbState = LOW; // Initialize bulb state

void setup() {
  pinMode(bulb, OUTPUT);
  digitalWrite(bulb, bulbState);

  pinMode(touch1_1, INPUT);
  pinMode(touch2_1, INPUT);
  pinMode(touch3_1, INPUT);

  Serial.begin(9600);

  WiFi.begin("iitk");
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  Serial.println("NodeMCU is Connected!");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  client = server.available();  

  if (client) {
    String request = client.readStringUntil('\r');
    Serial.println(request);
    request.trim();
    
    if (request.indexOf("/bulb/on") != -1) {
      bulbState = HIGH;
    } 
    else if (request.indexOf("/bulb/off") != -1) {
      bulbState = LOW;
    }

    digitalWrite(bulb, bulbState);

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head><title>ESP8266 Bulb Control</title></head>");
    client.println("<body>");
    client.println("<h1>ESP8266 Bulb Control</h1>");
    client.println("<p>Bulb is currently: " + String(bulbState ? "ON" : "OFF") + "</p>");
    client.println("<form action=\"/bulb/on\" method=\"POST\"><button>Turn Bulb ON</button></form>");
    client.println("<form action=\"/bulb/off\" method=\"POST\"><button>Turn Bulb OFF</button></form>");
    client.println("</body>");
    client.println("</html>");

    client.stop();
    Serial.println("Client disconnected");
  }

  // Check for touch sensor activation
  if ((digitalRead(touch1_1) == HIGH) || (digitalRead(touch2_1) == HIGH) || (digitalRead(touch3_1) == HIGH)) {
    bulbState = !bulbState;
    digitalWrite(bulb, bulbState);
    delay(500); // Debounce delay
  }
}
