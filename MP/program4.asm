; STRING OPERATIONS

.MODEL SMALL

.DATA
ARRAY1 DB "MICROPROCESSOR"
ARRAY2 DB 15 DUP(0)   ; LENGTH OF MICROPROCESSOR IS 14 + 1 FOR NULL = 15
LEN DW 14

.CODE
MOV AX,@DATA
MOV DS,AX     ; INITIALIZE DATA SEGMENT
MOV ES,AX     ; INITIALIZE EXTRA SEGMENT ALSO FOR STRING OPERATIONS

MOV CX, LEN   ; ALWAYS THE COUNT WILL BE IN 'CX' SO THAT IT IS AUTO INC OR DEC

LEA SI, ARRAY1
LEA DI, ARRAY2

CLD           ; CLEAR DIRECTION FOR POSITIVE DIRECTION
REP MOVSB     ; COPY FROM [SI] TO [DI] AND INC TILL CX(14 TIMES HERE)

MOV AH,4CH
INT 21H

END
