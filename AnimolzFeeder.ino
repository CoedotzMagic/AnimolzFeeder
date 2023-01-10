#include <Servo.h>
#define echoPin 6 //Echo Pin
#define trigPin 7 //Trigger Pin

Servo myservo;
long duration, distance;
const int servoPin = 9;

void setup() {
  Serial.begin (9600);
  myservo.attach(servoPin);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  myservo.write(180);
  delay(1000);
  myservo.detach();
}

void loop() {
  digitalWrite(trigPin, LOW);delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration/58.2;
  if(distance <= 15) {
    myservo.attach(servoPin);
    myservo.write(30);
    delay(575);
    myservo.write(180);
    delay(1500);
    myservo.detach();
    delay(2000);
  }
  delay(13);
}
