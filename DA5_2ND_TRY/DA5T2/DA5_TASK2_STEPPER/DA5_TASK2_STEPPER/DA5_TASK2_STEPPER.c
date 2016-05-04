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
	DDRD = 0x0F;
	int ADC1 = 0;
	ADC_init();
	while(1)
	{
		ADC1 = adc_read();
		if ((ADC1 >= 901) && (ADC1 < 1024))
		{
			PORTD = 0x6;		//fast speed
			_delay_ms(10);
			PORTD = 0xC;
			_delay_ms(10);
			PORTD = 0x9;
			_delay_ms(10);
			PORTD = 0x3;
			_delay_ms(10);
		}
		if ((ADC1 >= 700) && (ADC1 < 901))
		{
			PORTD = 0x6;		
			_delay_ms(15);
			PORTD = 0xC;
			_delay_ms(15);
			PORTD = 0x9;
			_delay_ms(15);
			PORTD = 0x3;
			_delay_ms(15);
		}
		if ((ADC1 < 700)&&(ADC1>=500))
		{
			PORTD = 0x6;		
			_delay_ms(20);
			PORTD = 0xC;
			_delay_ms(20);
			PORTD = 0x9;
			_delay_ms(20);
			PORTD = 0x3;
			_delay_ms(20);
		}
		if ((ADC1 < 500)&&(ADC1>=300))
		{
			PORTD = 0x6;		
			_delay_ms(25);
			PORTD = 0xC;
			_delay_ms(25);
			PORTD = 0x9;
			_delay_ms(25);
			PORTD = 0x3;
			_delay_ms(25);
		}
		if ((ADC1 < 300)&&(ADC1>=150))
		{
			PORTD = 0x6;		
			_delay_ms(30);
			PORTD = 0xC;
			_delay_ms(30);
			PORTD = 0x9;
			_delay_ms(30);
			PORTD = 0x3;
			_delay_ms(30);
		}
		if ((ADC1 < 150)&&(ADC1>=0))
		{
			PORTD = 0x6;
			_delay_ms(40);
			PORTD = 0xC;
			_delay_ms(40);
			PORTD = 0x9;
			_delay_ms(40);
			PORTD = 0x3;
			_delay_ms(40);
		}
	}
	return 0;
}

int adc_read()
{
	ADMUX &= 0x00;
	ADCSRA |= (1<<ADSC);
	while((ADCSRA & (1<<ADSC)));
	return ADC;
}
void ADC_init(void)
{
	ADCSRA = (1<<ADEN);//|(1<<ADSC);//|(1<<ADIF);
}