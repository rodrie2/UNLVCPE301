/*
 * DA6NOKIA.c
 *
 * Created: 4/28/2016 8:58:41 AM
 *  Author: rodrie2
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#include "nokia5110.c"

//from .h
/*#define LCD_SCE PB2
#define LCD_RST PB1
#define LCD_DC PB6
#define LCD_DIN PB3
#define LCD_CLK PB5*/
#define ACD_0 PC0

int main(void)
{
	int adc_temp;
	char temp[8];
	DDRB = 0xFF;
	
	SPI_MasterInit();
	
//from nokia5110.c
//inserted transmit function in file.	
 nokia_lcd_init();
 nokia_lcd_write_string("The current", 1);
 nokia_lcd_set_cursor(0,10);
 nokia_lcd_write_string("temperature is", 1);
 ADC_init();
 
 while(1)
 {
	 adc_temp = adc_read();
	 adc_temp = (adc_temp)/3;
	 sprintf(temp, "%d", adc_temp);
	 nokia_lcd_set_cursor(0, 20);
	 nokia_lcd_write_string(temp, 1);
	 nokia_lcd_write_string(" degrees", 1);
	 nokia_lcd_set_cursor(0, 30);
	 nokia_lcd_write_string("Fahrenheit", 1);
	 nokia_lcd_render();
	 //ADCSRA |= (1<<ADIF);
	 _delay_ms(1000);
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
//ADOPTED FROM ATMEGA328P DATASHEET
void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	//ALREADY DONE OUTSIDE FUNCTION
	//DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
/*
//PLACED IN OTHER FUNCTION
void SPI_MasterTransmit(char cData)
{
	/* Start transmission //
	SPDR = cData;
	/* Wait for transmission complete /
	while(!(SPSR & (1<<SPIF)))
	;
}*/