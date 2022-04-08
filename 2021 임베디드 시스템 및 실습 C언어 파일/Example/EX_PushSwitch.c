// include library
#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>


// define the global variable
static unsigned char PushSW[] = {0, 7};
static unsigned char LED[] = {24, 25};

// Control the Led by pushing
int main(void)
{
	int i;
	int OldPushedSW = -1, PushedSW = 0;

	// initializing the wiringPi
	if(wiringPiSetup() == -1)
	{
		printf("Setup Failed !!!\n");
		return -1;
	}

	// Change the Setup to CONTROL THE LED and SWITCH
	for(i = 0; i < sizeof(LED); i++)
	{
		pinMode(PushSW[i], INPUT);
		pinMode(LED[i], OUTPUT);
		digitalWrite(LED[i], LOW);
	}

	// Push Switch입력에 따라 LED 제어하기
	while(1)
	{
		PushedSW = -1;

		// Push된 switch 검색
		for(i = 0; i<sizeof(PushSW); i++)
		{
			if(digitalRead(PushSW[i]) == LOW)
			{
				PushedSW = i;
			}
		}
		delay(10);

		// SwitchUp 여부 체크
		if(PushedSW != -1 && digitalRead(PushSW[PushedSW]) == HIGH)
		{
			PushedSW = -1;
		}
		// SwitchDowns 여부 체크
		if(PushedSW != -1)
		{
			// 처음 눌려진 경우
			if(PushedSW != OldPushedSW)
			{
				printf("Switch %d press !!!\n", PushedSW + 1);
				digitalWrite(LED[OldPushedSW], LOW);
				digitalWrite(LED[PushedSW], HIGH);
				OldPushedSW = PushedSW;
			}
		}
		else
		{
			// Switch를 Up 했을 경우
			if(OldPushedSW != -1)
			{
				printf("Switch %d release !!!\n", OldPushedSW + 1);
				digitalWrite(LED[OldPushedSW], LOW);
				OldPushedSW = -1;
				//OldPushedSW++;
				//OldPushedSW = OldPushedSW % 3;
			}
		}
		delay(100);
	}
}
