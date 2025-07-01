section .data
newline db 0xA

section .text
global _start

_start:
    mov ecx, 1
loop:
    mov eax, 4
    mov ebx, 1
    mov edx, 1
    mov esi, ecx
    mov [num], cl
    mov ecx, num
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    inc ecx
    cmp ecx, 11
    jl loop

    mov eax, 1
    xor ebx, ebx
    int 0x80

section .bss
num resb 1
