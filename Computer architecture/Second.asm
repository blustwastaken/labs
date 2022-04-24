Ideal
P386
Model Small
Dataseg
N EQU 8
X DW 1,-2,3,-4,5,-6,7,-8
Y DW ?
Codeseg
start:
mov AX,@Data
mov DS,AX
sub AX,AX
lea BX,[X]
mov CX,N
M:
 mov DX,[BX]
 cmp DX,0
 jl M1
M2:
 INC BX
 INC BX
 DEC CX
 JNZ M
 JMP EXIT
M1:
 add AX,[BX]
 JMP M2
EXIT:
mov [Y],AX
mov AX,4c00h
int 21h
stack 10
end start