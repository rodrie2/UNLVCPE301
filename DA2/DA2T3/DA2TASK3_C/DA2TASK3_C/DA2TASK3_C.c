/*
 * DA2TASK3_C.c
 *
 * Created: 3/13/2016 5:55:59 PM
 *  Author: Rodriguez
 */ 


#define F_CPU 8000000UL	//setting frequency
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0x60;
	PORTB = 0;
	//PORTC = 0;
	int i = 1;
	int five = 0;
	int ten = 0;
	while(1)
	{
		_delay_us(250000);
		if (i == 1)
		{
			PORTB++;
 			five++;
			ten++;
			i = 0;
			if (ten == 10)
			{
				PORTC = 0x40;
				ten = 0;
				five = 0;
			}
			if (five==5)
			{
				PORTC = 0x20;
				five = 0;
			}
		}
		else
		{
			i = 1;
		}
	}
	return 0;
}
