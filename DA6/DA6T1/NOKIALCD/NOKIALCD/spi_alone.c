/*
 * spi.c
 *
 * Created: 4/29/2016 9:41:27 PM
 * Author : Rodriguez
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#define DDR_SPI DDRB
#define DD_MOSI PB3
#define DD_SCK PB5
#define LCD_SCE PB2
#define LCD_DE PB6
#define LCD_RST PB1


int main(void)
{
	char data;
	DDRB = 0xFF;
	
	PORTB &= ~(1<<LCD_RST);
	PORTB |= (1<<LCD_SCE);
	SPI_MasterInit();
	PORTB |= (1<<LCD_RST);
	PORTB &= ~(1<<LCD_SCE);
	PORTB &= ~(1<<LCD_DE);	
	
	SPI_MasterTransmit(0x21);
	_delay_ms(1000);
	SPI_MasterTransmit(0x13);
	_delay_ms(1000);
	SPI_MasterTransmit(0x06);
	_delay_ms(1000);
		SPI_MasterTransmit(0xC2);
		_delay_ms(1000);
			SPI_MasterTransmit(0x20);
			_delay_ms(1000);
				SPI_MasterTransmit(0x09);
				_delay_ms(1000);
					SPI_MasterTransmit(0x80);
					_delay_ms(1000);
						SPI_MasterTransmit(0x40);
						_delay_ms(1000);
						PORTB |= (1<<LCD_DE);
						for (int i = 0; i < 504; i++)
						{
							SPI_MasterTransmit(0x00);
						}
							PORTB &= ~(1<<LCD_DE);
							SPI_MasterTransmit(0x08);
							_delay_ms(1000);
	//start writing PH but in code, need table for ass
	SPI_MasterTransmit(0x0C);
	_delay_ms(1000);
	PORTB |= (1<<LCD_DE);
	SPI_MasterTransmit(0x1F);
	_delay_ms(1000);
	SPI_MasterTransmit(0x05);
	_delay_ms(1000);
	SPI_MasterTransmit(0x07);
	_delay_ms(1000);
	SPI_MasterTransmit(0x00);
	_delay_ms(1000);
		SPI_MasterTransmit(0x1f);
		_delay_ms(1000);
			SPI_MasterTransmit(0x04);
			_delay_ms(1000);
				SPI_MasterTransmit(0x1f);
				_delay_ms(1000);
				SPI_MasterTransmit(0x00);
	//PORTB &= ~(1<<LCD_DE);
	//SPI_MasterTransmit(0x00);			
	while(1){}
	return 0;
	}

void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	//DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void SPI_MasterTransmit(char cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
}
