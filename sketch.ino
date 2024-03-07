#define fan D6
#define led D7

#define touch1_1 D0
#define touch1_2 D1
#define touch2_1 D2
#define touch2_2 D3
#define touch3_1 D4
#define touch3_2 D5

void setup() {
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);

  digitalWrite(fan, LOW);
  digitalWrite(led, LOW);
  
  pinMode(touch1_1, INPUT);
  pinMode(touch1_2, INPUT);
  pinMode(touch2_1, INPUT);
  pinMode(touch2_2, INPUT);
  pinMode(touch3_1, INPUT);
  pinMode(touch3_2, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  if ((digitalRead(touch1_1) == HIGH) || (digitalRead(touch2_1) == HIGH) || (digitalRead(touch3_1) == HIGH)) {
    digitalWrite(fan, !digitalRead(fan));
    delay(500);
  }
  if ((digitalRead(touch1_2) == HIGH) || (digitalRead(touch2_2) == HIGH) || (digitalRead(touch3_2) == HIGH)) {
    digitalWrite(led, !digitalRead(led));
    delay(500);
  }
}
