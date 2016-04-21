/*
 * DA5_TASK1_DC_MOTOR.c
 *
 * Created: 4/16/2016 5:19:07 PM
 *  Author: Rodriguez
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF;
	while (1)
	{
		PORTC = 0x20;	//pc5
		_delay_ms(100);
		PORTC = 0x00;
		_delay_ms(100);
	}
	return 0;
}