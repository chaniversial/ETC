#include <stdio.h>
#include <softPwm.h>
#include <wiringPi.h>

static unsigned char PushSW[] = {0, 7};
static unsigned char LED[] = {27, 28};

int main(void)
{
	int i;
	int OldPushedSW = -1;
	int PushedSW = 0;

	if(wiringPiSetup() == -1)
	{
		printf("Setup Failed !!!\n");
		return -1;
	}

	for(i = 0; i < sizeof(LED); i++)
	{
		pinMode(PushSW[i], INPUT);
		pinMode(LED[i], OUTPUT);
		digitalWrite(LED[i], LOW);
	}

	while(1)
	{
		PushedSW = -1;

		for(i = 0; i < sizeof(PushSW); i++)
			if(digitalRead(PushSW[i]) == LOW)
				PushedSW = i;

		delay(10);

		if(PushedSW != -1 && digitalRead(PushSW[PushedSW]) == HIGH)
			PushedSW = -1;

		if(PushedSW != -1)
		{
			if(PushedSW != OldPushedSW)
			{
				printf("Switch %2d press !!!\n", PushedSW + 1);
				digitalWrite(LED[OldPushedSW], LOW);
				digitalWrite(LED[PushedSW], HIGH);
				OldPushedSW = PushedSW;
			}
		}
		else
		{
			if(OldPushedSW != -1)
			{
				printf("Switch %2d release !!!\n", OldPushedSW + 1);
				digitalWrite(LED[OldPushedSW], LOW);
				OldPushedSW = -1;
			}
		}
		delay(100);
	}
}
