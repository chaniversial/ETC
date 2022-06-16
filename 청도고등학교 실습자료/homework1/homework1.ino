#include <Servo.h>

int servoPin = 13;
int trigPin = 9;
int echoPin = 8;
int second1000 = 1000;
int second3000 = 3000;

int angle = 0;
Servo servo;
void setup()
{
  servo.attach(servoPin);
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop()
{
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;
  Serial.print(" distnace : ");
  Serial.print(distance);
  Serial.print(" cm\n");
  delay(250);
  if((distance > 20) && (distance <= 30))
  {
    servo.write(30);
    delay(second3000);
    servo.write(150);
    delay(second3000);
  }
  else if ((distance > 0) && (distance <= 20))
  {
    servo.write(30);
    delay(second1000);
    servo.write(150);
    delay(second1000);
  }
}
