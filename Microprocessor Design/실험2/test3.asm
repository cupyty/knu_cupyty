; STANDARD HEADER FILE
	PROCESSOR	16F876
;
; BANK 0
INDF	EQU	00H
TMR0	EQU	01H
PCL		EQU	02H
STATUS	EQU	03H
FSR		EQU	04H
PORTA	EQU	05H
PORTB	EQU	06H
PORTC	EQU	07H
EEDATA	EQU	08H
EEADR	EQU	09H
PCLATH	EQU	0AH
INTCON	EQU	0BH
; BANK 1
OPTINOR	EQU	81H
TRISA	EQU	85H
TRISB	EQU	86H
TRISC	EQU	87H
EECON1	EQU	88H
EECON2	EQU	89H
ADCON1	EQU	9FH
;
IRP		EQU	7
RP1		EQU	6
RP0		EQU	5
NOT_TO	EQU	4
NOT_PD	EQU	3
ZF		EQU	2
DC		EQU	1
CF		EQU	0
;
;

W		EQU	B'0'
F		EQU	.1
DBUF1	EQU	24H
DBUF2	EQU	25H
; MAIN PROGRAM
	ORG 0000
	BSF		STATUS,RP0
	MOVLW	B'00000000'
	MOVWF	TRISA
	MOVLW	B'00001111'
	MOVWF	TRISB
	MOVLW	B'00000111'
	MOVWF	ADCON1
	BCF		STATUS,RP0
;
	MOVLW	00H
	MOVWF	PORTA
LOOP	INCF	PORTA,F
		CALL	DELAY
		GOTO LOOP

;Subroutine
DELAY	
		MOVLW	.125
		MOVWF	DBUF1
LP1		MOVLW	.200
		MOVWF	DBUF2
LP2		NOP		
		DECFSZ	DBUF2,F
		GOTO	LP2
		DECFSZ	DBUF1,F
		GOTO	LP1
		RETURN
END