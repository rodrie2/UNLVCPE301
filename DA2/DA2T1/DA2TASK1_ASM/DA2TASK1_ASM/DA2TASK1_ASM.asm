/*
 * DA2Task1_ASM.asm
 *
 *  Created: 3/3/2016 10:30:17 PM
 *   Author: erl25_000
 */ 

 SBI	DDRC, 0
BEGIN:
 LDI	R20, 0x07
 STS	OCR1AH, R20
 LDI	R20, 0xA1
 STS	OCR1AL, R20

 LDI	R20, 0x00
 STS	TCCR1A, R20
 LDI	R20, 0x0D
 STS	TCCR1B, R20
 LDI	R20, 1
 out	PORTC, R20
L1:
 IN		R20, TIFR1
 SBRS	R20, OCF1A
 RJMP	L1
 LDI	R20, 0
 STS	TCCR1B, R20
 LDI	R20, 1<<OCF1A
 OUT	TIFR1, R20
 LDI	R20, 0
 OUT	PORTC, R20
 LDI	R20, 0x07
 STS	OCR1AH, R20
 LDI	R20, 0xA1
 STS	OCR1AL, R20
 LDI	R20, 0x00
 STS	TCCR1A, R20
 LDI	R20, 0x0D
 STS	TCCR1B, R20
L2:
 IN		R20, TIFR1
 SBRS	R20, OCF1A
 RJMP	L2
 LDI	R20, 0
 STS	TCCR1B, R20
 LDI	R20, 1<<OCF1A
 OUT	TIFR1, R20
 JMP	BEGIN
