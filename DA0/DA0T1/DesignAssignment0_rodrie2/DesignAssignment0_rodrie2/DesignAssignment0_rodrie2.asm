/*
 * DesignAssignment0_rodrie2.asm
 *
 *  Created: 2/14/2016 12:14:22 PM
 *   Author: erl25_000
 */ 

	LDI R16, 255	;to compare the overflow
					;if number ends up negative, an overflow happend
					;if number ends up positve, no overflow happend
	LDI R17, 59		;number 1
	LDI R27, 59		;number 2
	add r17, r27	;adding number 1 + 2
	sub r16, r17	;subtracting from overflow number
	ldi r27, 59		;number 3
	add r17, r27	;adding of number 3
	sub r16, r27	
	ldi r27, 50		;number 4
	add r17, r27	
	sub r16, r27
	ldi r27, 59		;number 5
	add r17, r27
	sub r16, r27	;final check of overflow number

	cpi r16, 0		
	brlt overflow	;if overflow number is less than 0, an overflow occured, else not.
	;brvs overflow
	ldi r28, 0		;no overflow so PORTB - PIN 2 is low
	out PORTB, r28
	jmp done
 overflow:
	ldi r28, 4		;overflow happened so PORTB - PIN 2 is high
	out PORTB, r28
 done:
	sbi DDRB,2		;makes PORTB - PIN 2 an output
	jmp done