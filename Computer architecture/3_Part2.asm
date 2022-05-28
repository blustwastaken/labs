Ideal 
P386N 
Model Small 
Dataseg 
X DW 1,-2,3,-4,5,-6,7,-8
Y DW ? 
N EQU 8 
Codeseg 
proc myproc 
push BP 
mov BP, SP 
mov CX, [BP+4] 
mov BX, [BP+6] 
mov AX, 0 
A: cmp [BX], 0
             Jge B
             add AX, [BX] 
B: inc BX 
               inc BX 
               loop A 
pop BP
ret 
ENDP 
Start: 
mov AX, @Data 
mov DS, AX
Lea AX, [X] 
push AX 
push N 
Call MyProc 
add SP, 4 
mov [Y], AX 
mov AX, 4C00h 
int 21h 
STACK 100 
END start
