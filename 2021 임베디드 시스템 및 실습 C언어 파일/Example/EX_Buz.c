// related library
#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

// define the pin number
#define BUZ_A_PIN	30 // wiringPi 

// create the buzzer function
int main(void)
{
	// initializing the wiringPiSetup
	if(wiringPiSetup() == -1)
	{
		printf("Setup Failed !!! \n");
		return -1;
	}

	// initializing the sensor
	pinMode(BUZ_A_PIN, OUTPUT);

	while(1)
	{
		digitalWrite(BUZ_A_PIN, HIGH);
		printf("BUZ_A_PIN 30 is HIGH !!!\n");
		delay(1000);

		digitalWrite(BUZ_A_PIN, LOW);
		printf("BUZ_A_PIN 30 is LOW !!!\n");
		delay(1000);

	}
}
