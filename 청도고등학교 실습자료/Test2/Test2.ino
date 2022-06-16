/* 이 소스는 에듀이노(Eduino)에 의해서 번역, 수정, 작성되었고 소유권 또한 에듀이노의 것입니다.
    소유권자의 허락을 받지 않고 무단으로 수정, 삭제하여 배포할 시 법적인 처벌을 받을 수도 있습니다.

    에듀이노 SmartCar 예제
    - 스마트 자동차 검정색 라인을 따라 스스로 움직이는 예제 -
*/

int RightMotor_E_pin = 5;      // 오른쪽 모터의 Enable & PWM
int LeftMotor_E_pin = 6;       // 왼쪽 모터의 Enable & PWM
int RightMotor_1_pin = 8;      // 오른쪽 모터 제어선 IN1
int RightMotor_2_pin = 9;      // 오른쪽 모터 제어선 IN2
int LeftMotor_3_pin = 10;      // 왼쪽 모터 제어선 IN3
int LeftMotor_4_pin = 11;      // 왼쪽 모터 제어선 IN4

int L_Line = A5; // 왼쪽 라인트레이서 센서는 A5 핀에 연결
int C_Line = A4; // 가운데 라인트레이서 센서는 A4 핀에 연결
int R_Line = A3; // 오른쪽 라인트레이서 센서는 A3 핀에 연결

//좌우 모터 속도 조절, 설정 가능 최대 속도 : 255
int L_MotorSpeed = 255; // 왼쪽 모터 속도
int R_MotorSpeed = L_MotorSpeed - 10; // 오른쪽 모터 속도

int SL = 1;
int SC = 1;
int SR = 1;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(RightMotor_E_pin, OUTPUT);
  pinMode(LeftMotor_E_pin, OUTPUT);
  pinMode(RightMotor_1_pin, OUTPUT);
  pinMode(RightMotor_2_pin, OUTPUT);
  pinMode(LeftMotor_3_pin, OUTPUT);
  pinMode(LeftMotor_4_pin, OUTPUT);

  Serial.begin(9600);    // PC와의 시리얼 통신 9600bps로 설정
  Serial.println("Welcome Eduino!");
}

void loop() {
  int L = digitalRead(L_Line);
  int C = digitalRead(C_Line);
  int R = digitalRead(R_Line);

  Serial.print("digital : "); 
  Serial.print(L); 
  Serial.print(", "); 
  Serial.print(C); 
  Serial.print(", "); 
  Serial.print(R); 
  Serial.print("   ");

  if ( L == LOW && C == LOW && R == LOW ) {           // 0 0 0
    L = SL; C = SC; R = SR;
  }

  if ( L == LOW && C == HIGH && R == LOW ) {          // 0 1 0
    motor_role(HIGH, HIGH, 0);
    Serial.println("직진");
  }
  
  else if (L == LOW && R == HIGH ){                   // 0 0 1, 0 1 1
    motor_role(LOW, HIGH, 1);
    Serial.println("우회전");
  }
 
  else if (L == HIGH && R == LOW ) {                  // 1 0 0, 1 1 0
    motor_role(HIGH, LOW, 2);
    Serial.println("좌회전");

  }
  else if ( L == HIGH && R == HIGH ) {                // 1 1 1, 1 0 1
    //analogWrite(RightMotor_E_pin, 0);
    //analogWrite(LeftMotor_E_pin, 0);
    //Serial.println("정지");
    SmartCar_Left_Turn();
  }
  SL = L; SC = C; SR = R;
}

void motor_role(int R_motor, int L_motor, int role) {
  digitalWrite(RightMotor_1_pin, R_motor);
  digitalWrite(RightMotor_2_pin, !R_motor);
  digitalWrite(LeftMotor_3_pin, L_motor);
  digitalWrite(LeftMotor_4_pin, !L_motor);

  if(role == 0)
  {
    analogWrite(RightMotor_E_pin, 245);  // 우측 모터 속도값
    analogWrite(LeftMotor_E_pin, 255);   // 좌측 모터 속도값
  }
  else if(role == 1)
  {
    analogWrite(RightMotor_E_pin, 250);  // 우측 모터 속도값
    analogWrite(LeftMotor_E_pin, 153);   // 좌측 모터 속도값
  }
  else if(role == 2)
  {
    analogWrite(RightMotor_E_pin, 143);  // 우측 모터 속도값
    analogWrite(LeftMotor_E_pin, 250);   // 좌측 모터 속도값
  }
}


void SmartCar_Right_Turn() {       // 전진
  Serial.println("Forward");
  digitalWrite(RightMotor_1_pin, HIGH);
  digitalWrite(RightMotor_2_pin, LOW);
  digitalWrite(LeftMotor_3_pin, LOW);
  digitalWrite(LeftMotor_4_pin, HIGH);
  analogWrite(RightMotor_E_pin, 250);
  analogWrite(LeftMotor_E_pin, 250);
}


void SmartCar_Left_Turn() {       // 후진
  Serial.println("Backward");
  digitalWrite(RightMotor_1_pin, LOW);
  digitalWrite(RightMotor_2_pin, HIGH);
  digitalWrite(LeftMotor_3_pin, HIGH);
  digitalWrite(LeftMotor_4_pin, LOW);
  analogWrite(RightMotor_E_pin, L_MotorSpeed);
  analogWrite(LeftMotor_E_pin, R_MotorSpeed);
}
