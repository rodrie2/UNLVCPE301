/*
 * DA5_TASK3_SERVO.c
 *
 * Created: 4/19/2016 10:08:22 PM
 *  Author: Rodriguez
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
   DDRB = 0xFF;
   ICR1 = 20000;
   
   TCCR1A |= (1<<COM1A1)|(1<<WGM11);
   TCCR1B |= (1<<WGM12)|(1<<WGM13)|(1<<CS11);
   int ADC1 = 0;
   ADC_init();
   while(1)
   {
	   ADC1 = adc_read();
	   _delay_ms(20);
	   OCR1A = 600 + (2*ADC1);
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
	   ADCSRA = (1<<ADEN);
   }
  