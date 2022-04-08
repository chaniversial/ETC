#include <stdio.h>
#include <wiringPi.h>

#define ULTRASONIC_TRIG 4
#define ULTRASONIC_ECHO 5

int main(void)
{
	int start_time = 0;
	int end_time = 0;
	float distance = 0;
	float duration = 0;

	if(wiringPiSetup() == -1)
	{
		printf("Setup Failed !!! \n");
		return -1;
	}

	// 초음파 센서 핀 동작모드
	pinMode(ULTRASONIC_TRIG, OUTPUT);
	pinMode(ULTRASONIC_ECHO, INPUT);
	while(1)
	{
		//초음파 센서에 동작 커맨드 신호 보내기
		digitalWrite(ULTRASONIC_TRIG, LOW);
		delay(500);
		digitalWrite(ULTRASONIC_TRIG, HIGH);
		delay(10);
		digitalWrite(ULTRASONIC_TRIG, LOW);

		// 초음파 발사 시작 시간 측정
		while(digitalRead(ULTRASONIC_ECHO) == LOW)
		{
			start_time = micros();
		}

		// 초음파 발사 되어 돌아온 시간 측정
		while(digitalRead(ULTRASONIC_ECHO) == HIGH)
		{
			end_time = micros();
		}

		duration = (float)(end_time - start_time);
		duration = duration / 1000000/2;
		distance = (340 * duration) * 100;

		printf("Distance : %3.0f cm\n", distance);
	}
	return 0;
}
