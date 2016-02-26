/*
 * AssemblerApplication1.asm
 *
 *  Created: 2/22/2016 7:58:41 PM
 *   Author: erl25_000
 */ 

	LDI		ZH,	0x00		;only way to get value besides ff
	LDI		ZL,	0x00		;LOW(RAMEND)/2 didnt work, instead starting at 0x0000 of memory
	
BEGIN:
	CPI		R22, 0x19		;to only traverse 25 numbers
	BREQ	END				;jump to finish
	LPM		XL, Z+			;load value in memory to xl
	LDI		R16,	7		
	LDI		R18,	3
	LDI		YH, 0			;FOR 7 LIMIT
	LDI		XH, 0			;FOR 3 LIMIT
	CPI		XL, 0			;make sure number is not 0,
	BREQ	NXT				;if it is, get next number
SEVENLOOP:
	CPI		YH, 36			;checking every number that is below 255 and divisible by 7. ONlY 36 options
	BREQ	THREELOOP
	CP		XL, R16			;compare XL to x*7
	BREQ	ADDSEV			;if XL is a number divisible by 7
	SUBI	R16, -7			;next number divisible by 7
	INC		YH				
	JMP SEVENLOOP
ADDSEV:
	ADD	R21, XL				;add if divisible by 7
	ADC	R20, R17
THREELOOP:
	CPI		XH, 85			;checking every number that is below 255 and divisible by 3. 85 options
	BREQ	NXT		
	CP		XL, R18			;compare XL to x*3
	BREQ	ADDTHR			;if XL is divisible by 3
	SUBI	R18, -3			; next number divisible by 3 to compare to XL
	INC		XH
	JMP THREELOOP
ADDTHR:
	ADD	R24, XL				;add if divisible by 3
	ADC	R23, R17
NXT:
	INC R22					;increase upto 25
	JMP BEGIN
END:
	JMP END