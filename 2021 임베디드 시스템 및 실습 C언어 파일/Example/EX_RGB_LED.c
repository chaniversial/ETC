//-ㅅㅔㄴㅅㅓㄹㅏㅇㅣㅂㅡㄹㅓㄹㅣ--------
#include <stdio.h>
#include <wiringPi.h>

//--SENSOR CONNECTING PIN NUMBER --//
#define R_LED_PIN	27
#define G_LED_PIN	28
#define B_LED_PIN	29

// -- MAIN LOOP -- //
int main(void)
{
	// Initializing the wiringPi
	if(wiringPiSetup() == -1)
	{
		printf("Setup is Failed!!!\n");
		return -1;
	}

	// Initializing the Sensor Value
	pinMode(R_LED_PIN, OUTPUT);
	pinMode(G_LED_PIN, OUTPUT);
	pinMode(B_LED_PIN, OUTPUT);

	// Control the Three Color LED
	while(1)
	{
		digitalWrite(R_LED_PIN, HIGH);
		digitalWrite(B_LED_PIN, LOW);
		printf("RED LED ON ~\n");
		delay(1000);

		digitalWrite(R_LED_PIN, LOW);
		digitalWrite(G_LED_PIN, HIGH);
		printf("GREEN LED ON ~\n");
		delay(1000);

		digitalWrite(G_LED_PIN, LOW);
		digitalWrite(B_LED_PIN, HIGH);
		printf("BLUE LED ON ~\n");
		delay(1000);

		digitalWrite(R_LED_PIN, LOW);
		digitalWrite(G_LED_PIN, LOW);
		digitalWrite(B_LED_PIN, LOW);
		printf("RGB LED OFF ~\n");
		delay(2000);
	}
	return 0;
}
