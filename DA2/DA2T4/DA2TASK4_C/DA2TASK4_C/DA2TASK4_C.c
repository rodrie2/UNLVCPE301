/*
 * DA2TASK4_C.c
 *
 * Created: 3/13/2016 7:20:38 PM
 *  Author: Rodriguez
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int i = 1, five, ten;

int main(void)
{
   DDRB = 0xFF;
   DDRC = 0x60;
   PORTC = 0;
   PORTB = 0;
   
   TCCR1A = 0x00;
   TCCR1B = 0x0D;
   
   OCR1A = 0x07A1;
   
   TIMSK1 |= (1<<OCIE1A);
   sei();
   
   while(1)
   {
	   
   }
}

ISR(TIMER1_COMPA_vect)
{
	if (i==1)
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
	else if (i == 0)
	{
		i=1;
	}
	TCCR1A = 0x00;
	TCCR1B = 0x0D;
	
	OCR1A = 0x07A1;
	
}