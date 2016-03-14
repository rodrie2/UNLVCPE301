/*
 * GccApplication1.c
 *
 * Created: 3/4/2016 1:33:49 PM
 *  Author: RODRIE2
 */ 

#define F_CPU 8000000UL	//setting frequency
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC |= (1<<PORTC0);
	PORTC= 1;
    while(1)
    {
		_delay_us(250000);
		// 	PORTC ^= 1; INSTEAD OF THIS CRAP BELOW
		if (PORTC == 1)
		{
			PORTC = 0;
		}
		else
		{
			PORTC = 1;
		}
	}
return 0;
}
