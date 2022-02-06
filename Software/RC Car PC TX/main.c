/******************************************
*	
* 	main.c for RC-CAR PC TX
* 
* 	Version:	1.0
* 	Date:		2021-12-20
* 	Author:		Hamish T
* 
*	Enable GPIO on pins
*	GP0, GP1, GP2, GP3
*	Output, Default set high
*	
*	REVERSE	SW2
* 	FORWARD	SW3
* 	LEFT	SW4
* 	RIGHT	SW5
*
*
*******************************************/

#include <stdio.h>
#include "pico/stdlib.h"
//Full relative address /../pico-sdk/src/common/pico_stdlib/include/pico/stdlib.h

int main()
{
	const uint LED_PIN = 25;
	gpio_init (LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	while (true)
	{
		gpio_put(LED_PIN, 1);
		sleep_ms(250);
		gpio_put(LED_PIN, 0);
		sleep_ms(250);
	}
}