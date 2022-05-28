Ideal 
P386N 
Model Small 
Dataseg 
X DW 1, -2, 3, -4, 5, -6, 7, -8
Y DW ? 
N EQU 8 
Codeseg 
proc myproc 
mov AX, 0
A: cmp [BX], 0 
             Jge B 
             add AX, [BX] 
B: inc BX 
               inc BX 
               loop A
ret 
ENDP 
Start: 
mov AX, @Data 
mov DS, AX
mov CX, N
Lea bx, [x] 
Call MyProc 
mov [Y], AX
mov AX, 4C00h 
int 21h 
STACK 100 
END start 
