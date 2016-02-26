/*
 * Assembler2.asm
 *
 *  Created: 2/3/2015 10:19:10 AM
 *   Author: venkim
 */ 


.DEF ANS1 = R0               ;Two Byte Answer
.DEF ANS2 = R1               ;
.DEF ZERO = R10              ;To hold Zero
.DEF   AL = R16              ;To hold multiplicand
.DEF   AH = R17              ;
.DEF   BL = R18              ;To hold multiplier
.DEF   BH = R19              ;
.DEF WRK1 = R20              ;Workspace
.DEF WRK2 = R21              ;
.DEF WRK3 = R22              ;
.DEF WRK4 = R23              ;

        LDI AL,LOW(1000)     ;Load Original Value into AH:AL
        LDI AH,HIGH(1000)    ;
        LDI BL,LOW(5567)     ;Load multiplier into BH:BL
        LDI BH,HIGH(5567)    ;
MUL16x16:
        CLR ZERO             ;Set Zero
        MUL AH,BH            ;Multiply AH:AL by 5567
        MOVW WRK4:WRK3,R1:R0 ;
        MUL AL,BL            ;
        MOVW WRK2:WRK1,R1:R0 ;
        MUL AH,BL            ;
        ADD WRK2,R0          ;
        ADC WRK3,R1          ;
        ADC WRK4,ZERO        ;
        MUL BH,AL            ;
        ADD WRK2,R0          ;
        ADC WRK3,R1          ;
        ADC WRK4,ZERO        ;
        LSR WRK4             ;Ignore lower two bytes is division
        ROR WRK3             ;by 1024 and a shift makes it 2048
        MOV ANS2,WRK4        ;Store Answer
        MOV ANS1,WRK3        ;By ignoring the lower two bytes we
                             ;get a division by 65536
start:
    rjmp start