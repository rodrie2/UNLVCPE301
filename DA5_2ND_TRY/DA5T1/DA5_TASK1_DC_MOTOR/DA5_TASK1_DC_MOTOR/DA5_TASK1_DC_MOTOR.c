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
	DDRC = 0x20;
	int ADC1 = 0;
	ADC_init();
	while(1)
	{
		ADC1 = adc_read();
	if ((ADC1 >= 901) && (ADC1 < 1024))
	{
		PORTC = 0x20;	//pc5
		_delay_ms(10);
		PORTC = 0x00;
		_delay_ms(500);
	}
	if ((ADC1 >= 700) && (ADC1 < 901))
	{
		PORTC = 0x20;	//pc5
		_delay_ms(75);
		PORTC = 0x00;
		_delay_ms(500);
	}
	if ((ADC1 < 700)&&(ADC1>=500))
	{
		PORTC = 0x20;	//pc5
		_delay_ms(150);
		PORTC = 0x00;
		_delay_ms(500);
	}
	if ((ADC1 < 500)&&(ADC1>=300))
	{
		PORTC = 0x20;	//pc5
		_delay_ms(300);
		PORTC = 0x00;
		_delay_ms(500);
	}
	if ((ADC1 < 300)&&(ADC1>=150))
	{
		PORTC = 0x20;	//pc5
		_delay_ms(500);
		PORTC = 0x00;
		_delay_ms(600);
	}
	if ((ADC1 < 150)&&(ADC1>=0))
	{
		PORTC = 0x20;	//pc5
		_delay_ms(600);
		PORTC = 0x00;
		_delay_ms(700);
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