/*
 * DA5_TASK2_STEPPER.c
 *
 * Created: 4/18/2016 7:33:21 PM
 *  Author: Rodriguez
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRD = 0x00;
	DDRC = 0xFF;
	while (1)
	{
	while (PIND == 0x02)	//PD1 to pot, if on do following
	{
		PORTC = 0x6;		//fast speed
		_delay_ms(10);
		PORTC = 0xC;
		_delay_ms(10);
		PORTC = 0x9;
		_delay_ms(10);
		PORTC = 0x3;
		_delay_ms(10);
	}
	//if PD1 to pot registers 0
	//slower speed
	PORTC = 0x6;
	_delay_ms(100);
	PORTC = 0xC;
	_delay_ms(100);
	PORTC = 0x9;
	_delay_ms(100);
	PORTC = 0x3;
	_delay_ms(100);
	}
    return 0;
}