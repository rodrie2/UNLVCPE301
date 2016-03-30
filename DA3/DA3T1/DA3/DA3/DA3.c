/*
 * DA3.c
 *
 * Created: 3/20/2016 9:24:46 PM
 *  Author: Rodriguez
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

#define FOSC 8000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1		//52

volatile int RECH;
char outs[5];						//space for 3 digits and decimal

void usart_init(void)
{
	UBRR0H = (MYUBRR >> 8);			//0
	UBRR0L = MYUBRR;
	
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);//|(1<<RXCIE0);
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
}
/*
void adc_init(void)
{
	ADMUX |= (1<<REFS0)|(1<<ADLAR)|(1<<MUX1);
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS0);
}
*/
void usart_rx(void)
{
	while(!(UCSR0A & (1<<RXC0)))
	{
		RECH = UDR0;
	}
	
}

int main(void)
{
	usart_init();
	//adc_init();
	TCCR1A = 0x00;
	TCCR1B = 0x0D;
	OCR1A = 0x1E85;
	TIMSK1 |= (1<<OCIE1A);
	sei();
	while(1)
	{
		usart_rx();
	}
}

ISR(TIMER1_COMPA_vect)
{
	int i = 0;
	printf(outs, sizeof(outs), "%3d\r\n", RECH);	//PRINT
	while (!(UCSR0A & (1<<UDRE0)) & i<6)
	{
		UDR0 = outs[i++];
	}
	TCCR1A = 0x00;
	TCCR1B = 0x0D;
	OCR1A = 0x1E85;
}