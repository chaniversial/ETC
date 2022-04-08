#include <stdio.h>
#include <wiringPi.h>

#define PIR_PIN	1
#define R_LED_PIN 27


// 센서 핀 선언
int main(void)
{
	// wiringPi 초기화
	if(wiringPiSetup() == -1)
	{
		printf("Setup Failed !!!! \n");
		return -1;
	}

	// PIR, LED 동작 모드 및 초기값 설정
	pinMode(PIR_PIN, INPUT);
	pinMode(R_LED_PIN, OUTPUT);

	digitalWrite(PIR_PIN, HIGH);
	digitalWrite(PIR_PIN, LOW);
	digitalWrite(R_LED_PIN, LOW);
	delay(10);
	int cnt = 0;
	// PIR 센서 감지에 따른 LED 제어
	while(1)
	{
		printf("%5d - ", cnt++);
		if(digitalRead(PIR_PIN) == HIGH)
		{
			digitalWrite(R_LED_PIN, HIGH);
			printf(" PIR SENSOR ON !!!\n");
		}
		else
		{
			digitalWrite(R_LED_PIN, LOW);
			printf(" PIR SENSOR OFF !!\n");
		}
		delay(100);
	}
	return 0;
}
