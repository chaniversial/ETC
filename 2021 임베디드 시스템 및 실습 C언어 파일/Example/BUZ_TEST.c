#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <wiringPi.h>
#include <softTone.h>

#define PIN 30
 
int scale [] = {440, 440, 494, 440, 880, 880, 784, 749, 659, 659, 659, 749, 784, 749, 784, 749, 749, 659, 587, 554, 587, 587, 659, 749, 880, 784, 494, 784, 749, 659, 587, 749, 659, 659, 587 } ;
 
int main (void)
{
	int i ;
	wiringPiSetup () ;
	softToneCreate (PIN) ;
	for (i = 0 ; i < sizeof(scale) ; i++)
   	{
      		softToneWrite (PIN, scale [i]) ;
      		delay (500) ;
    	}
}
