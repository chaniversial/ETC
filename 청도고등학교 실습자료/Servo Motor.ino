#include<Servo.h> //Servo 라이브러리를 추가
Servo servo;      //Servo 클래스로 servo객체 생성
int value = 0;    // 각도를 조절할 변수 value

void setup() {
  servo.attach(7);     //servo 서보모터 7번 핀에 연결
                       // 이때 ~ 표시가 있는 PWM을 지원하는 디지털 핀에 연결
}

void loop() {
    value = 90;
    servo.write(value); //value값의 각도로 회전. ex) value가 90이라면 90도 회전

}
