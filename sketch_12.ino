#include <NanitLib.h>
byte const trigPin = P5_1;
byte const echoPin = P5_4;
byte const ledPin = P3_4;
byte const buzPin = P3_2;

int const buzTone = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Nanit_Base_Start();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, 1);
  delayMicroseconds(10);
  digitalWrite(trigPin, 0);

  int cm = pulseIn(echoPin, 1) / 58;
  Serial.println(cm);
  if (cm > 5) {
    park(cm);
  } else {
    digitalWrite(ledPin, 1);
     tone(buzPin, buzTone);
  }
  
  delay(50);
}

void park(int cm) {
  digitalWrite(ledPin, 1);
  tone(buzPin, buzTone);
  delay(cm * 10);
  digitalWrite(ledPin, 0);
  noTone(buzPin);
}