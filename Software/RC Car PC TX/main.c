/******************************************
*	
* 	main.c for RC-CAR PC TX
* 
* 	Version:	1.0
* 	Date:		2022-05-22
* 	Author:		Hamish T
* 
*	Enable GPIO on pins
*	GP0, GP1, GP2, GP3
*	Output, Default set high
*	
*	REVERSE	SW2		GPIO2
* 	FORWARD	SW3		GPIO3
* 	LEFT	SW4		GPIO20
* 	RIGHT	SW5		GPIO21
*
*
*******************************************/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
//Full relative address /../pico-sdk/src/common/pico_stdlib/include/pico/stdlib.h

const uint LED_PIN = 25;
const uint REVERSE = 20;
const uint FORWARD = 21;
const uint LEFT = 2;
const uint RIGHT = 3;

void test_drive(void)
{
	/*Cycle through each direction*/
	//FORWARD
	puts("FORWARD\n");
	gpio_put(FORWARD, 0);
	sleep_ms(250);
	gpio_put(FORWARD, 1);
	sleep_ms(1000);

	//REVERSE
	puts("REVERSE\n");
	gpio_put(REVERSE, 0);
	sleep_ms(250);
	gpio_put(REVERSE, 1);
	sleep_ms(1000);

	//LEFT
	puts("LEFT\n");
	gpio_put(LEFT, 0);
	sleep_ms(250);
	gpio_put(LEFT, 1);
	sleep_ms(1000);

	//RIGHT
	puts("RIGHT\n");
	gpio_put(RIGHT, 0);
	sleep_ms(250);
	gpio_put(RIGHT, 1);
	sleep_ms(1000);
}

void gpio_init_all(void)
{
	stdio_init_all();

	gpio_init (LED_PIN);
	gpio_init (FORWARD);
	gpio_init (REVERSE);
	gpio_init (LEFT);
	gpio_init (RIGHT);

	//set outputs
  	gpio_set_dir(LED_PIN, GPIO_OUT);
	gpio_set_dir(FORWARD, GPIO_OUT);
	gpio_set_dir(REVERSE, GPIO_OUT);
	gpio_set_dir(RIGHT, GPIO_OUT);
	gpio_set_dir(LEFT, GPIO_OUT);

	//Set starting output direction
	gpio_put(FORWARD, 1);
	gpio_put(REVERSE, 1);
	gpio_put(LEFT, 1);
	gpio_put(RIGHT, 1);
	gpio_put(LED_PIN, 1);

}



int main()
{
   bi_decl(bi_program_description("This is a RC Car test binary."));
   bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

   gpio_init_all();  



   while (true)
   {
   		gpio_put(LED_PIN, 1);
		sleep_ms(250);
		gpio_put(LED_PIN, 0);
		sleep_ms(250);
		puts("Blink Blink\n");
		gpio_put(LED_PIN, 1);
		sleep_ms(250);
		gpio_put(LED_PIN, 0);
		sleep_ms(250);

		test_drive();
		sleep_ms(1000);

	}
}