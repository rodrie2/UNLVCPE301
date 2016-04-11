/*
 * AssemblerApplication1.asm
 *
 *  Created: 3/10/2016 10:04:08 AM
 *   Author: RODRIE2
 */ 

 .org 0x00
	JMP MAIN
 .org 0x1C
	JMP COMP_INT

MAIN:
 SBI	DDRC, 5
 SBI	DDRC, 6
 SBI	DDRB, 1
 SBI	DDRB,0
 SBI	DDRB, 2
 SBI	DDRB, 3
 SBI	DDRB, 4
 SBI	DDRB, 5
 SBI	DDRB, 6
 SBI	DDRB, 7
 LDI	R21, 0
 LDI	R18, 0
 LDI	R19, 0

BEGIN:
 LDI	R20, HIGH(RAMEND)
 OUT	SPH, R20
 LDI	R20, LOW(RAMEND)
 OUT	SPH, R20

 LDI	R20, 0x07		;1/2 SECOND
 STS	OCR1AH, R20		;OCR1A = 07A1 
 LDI	R20, 0xA1
 STS	OCR1AL, R20

 LDI	R20, 0x00
 STS	TCCR1A, R20
 LDI	R20, 0x0d
 STS	TCCR1B, R20

 LDI	R20, (1<<OCIE1A)
 sts	TIMSK1, R20
 SEI

LOOP:
 JMP	LOOP



COMP_INT:
	;CLEAR FLAG?
	;LDI		R20, 1<<OCF1A
	;OUT		TIFR1, R20
	
 	INC R18
	INC R19
	CPI	R18, 5
	BRNE	CHK10
	LDI	R20, 0x20
	OUT	PORTC, R20
	LDI	R18, 0
CHK10:
	CPI	R19, 10
	BRNE	NORM
	LDI	R20, 0x40
	OUT	PORTC, R20
	LDI	R19, 0

NORM:
	INC	R21
	Out	PORTB, R21

;RESETTING CLOCK
	LDI	R20, 0x0F
	STS	OCR1AH, R20
	LDI	R20, 0x45
	STS	OCR1AL, R20
	LDI	R20, 0x00
	STS	TCCR1A, R20
	LDI	R20, 0x0D
	STS	TCCR1B, R20

	RETI