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
	DDRB = 0xFF;
	PORTB = 0;
	int i = 1;
    while(1)
    {
		_delay_us(250000);
		if (i == 1)
		{
			PORTB++;
			i = 0;
		}
		else
		{
			i = 1;
		}
	}
return 0;
}
