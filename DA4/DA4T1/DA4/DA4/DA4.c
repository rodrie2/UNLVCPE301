/*
 * DA4.c
 *
 * Created: 4/5/2016 8:28:35 PM
 *  Author: Rodriguez
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    //3 timers
	//3 loops in 3 loops that increase all frequencies to 90%
	//Then 3 loops to decrease all to 10%
	//one more loop to exentuate green
	//go through one period, and all the intensities
	
	DDRB =  0xFF;
	DDRD = 0xFF;
	//TIMER 1	BLUE
	TCCR1A |= (1<<COM1B1)|(1<<WGM11)|(1<<WGM10);	//Outputs in OC1B (pb2)
	TCCR1B |= (1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10);
	OCR1A = 25;//top, thus changing is changing frequency
	OCR1B = 5;//n, thus changing is changing the DC
	
	//TIMER 0	GREEN
	TCCR0A |= (1<<COM0B1)|(1<<WGM01)|(1<<WGM00);	//OUTS in pd5
	TCCR0B |= (1<<WGM02)|(1<<CS01)|(1<<CS00);
	OCR0A = 25;
	OCR0B = 5;
	
	//TIMER 2	RED
	TCCR2A |= (1<<COM2B1)|(1<<WGM21)|(1<<WGM20);
	TCCR2B |= (1<<WGM22)|(1<<CS21)|(1<<CS20);
	OCR2A = 25;
	OCR2B = 5;
	
	while(1)
		{
		//BLUE+
		while (OCR1A<230)
			{
				OCR1A += 15;
				_delay_us(500);
				while (OCR1B<OCR1A)
				{
					OCR1B += 5;
				//	_delay_us(500);
				}
				OCR1B = 5;
			}
			
		//GREEN+
		while (OCR0A<230)
			{
				OCR0A += 15;
				_delay_us(500);
				while (OCR0B<OCR0A)
				{
					OCR0B += 5;
				//	_delay_us(500);
				}
				OCR0B = 5;
			}
			
		//RED+
		while (OCR2A<230)
			{
				OCR2A += 15;
				_delay_us(500);
				while (OCR2B<OCR2A)
				{
					OCR2B += 1;
				//	_delay_us(500);
				}
				OCR2B = 5;
			}					
			
		//all max
		//BLUE -
		while (OCR1A>30)
			{
				OCR1A -= 15;
				_delay_us(500000);
				while (OCR1B>25)
				{
					OCR1B -= 1;
				//	_delay_ms(500);
				}
				OCR1B = 5;
			}
			
		//GREEN-
		while (OCR0A>30)
			{
				OCR0A -= 15;
				_delay_us(500000);
				while (OCR0B>25)
				{
					OCR0B -= 1;
				//	_delay_us(500);
				}
				OCR0B = 5;
			}
			
		//RED-
		while (OCR2A>30)
			{
				OCR2A -= 15;
				_delay_us(500000);
				while (OCR2B>25)
				{
					OCR2B -= 1;
				//	_delay_us(500);
				}
				OCR2B = 5;
			}
			
		//GREEN+
		while (OCR0A<230)
			{
				OCR0A += 15;
				_delay_us(500000);
				while (OCR0B<OCR0A)
				{
					OCR0B += 1;
					//	_delay_us(500);
				}
				OCR0B = 5;
			}
		}
		return 0;
}