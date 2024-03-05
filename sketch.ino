#define led D5
#define touch1 D0
#define touch2 D1
#define touch3 D2

void setup(){
  pinMode(led, OUTPUT);
  pinMode(touch1, INPUT);
  pinMode(touch2, INPUT);
  pinMode(touch3, INPUT);
}

void loop(){
  if ((digitalRead(touch1) == HIGH) || (digitalRead(touch2) == HIGH) || (digitalRead(touch3) == HIGH)) {
    digitalWrite(led, !digitalRead(led));
    delay(500);
  }
}
