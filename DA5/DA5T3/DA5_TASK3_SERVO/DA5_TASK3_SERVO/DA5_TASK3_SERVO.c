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
   DDRD = 0x00;
  // PORTD = 0xFF;
   DDRB = 0xFF;
   ICR1 = 20000;
   
   TCCR1A |= (1<<COM1A1)|(1<<WGM11);
   TCCR1B |= (1<<WGM12)|(1<<WGM13)|(1<<CS11);
   while (1)
   {
  while (PIND == 0x02)
   {
	   _delay_ms(20);
	   OCR1A = 2900;
   }
   _delay_ms(20);
   OCR1A = 400;
   }
}