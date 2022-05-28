Ideal
P386N
Model Small
Dataseg
N EQU 14
A DW N
B DW N-16
C DW N+7
Y DW ?
Codeseg
main:
mov AX,@data
mov DS,AX
lea BX,[B]
mov CX,[BX+2]
mov AX,[BX-2]
add CX,5
add AX,BX
sub AX,CX
mov [y],AX
mov AX,4c00h
int 21h
STACK 10
END main