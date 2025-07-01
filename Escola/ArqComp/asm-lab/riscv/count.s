.section .data
newline: .asciz "\n"

.section .text
.globl _start

_start:
    li t0, 1
loop:
    li a7, 1
    li a0, 1
    mv a1, t0
    li a2, 1
    ecall

    li a7, 64
    li a0, 1
    la a1, newline
    li a2, 1
    ecall

    addi t0, t0, 1
    li t1, 11
    blt t0, t1, loop

    li a7, 93
    li a0, 0
    ecall