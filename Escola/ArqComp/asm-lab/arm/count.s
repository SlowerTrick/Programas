.section .data
newline: .asciz "\n"

.section .text
.global _start

_start:
    mov r0, #1
loop:
    mov r7, #4
    mov r1, r0
    mov r2, #1
    mov r0, #1
    svc #0

    ldr r1, =newline
    mov r2, #1
    mov r7, #4
    svc #0

    add r0, r0, #1
    cmp r0, #11
    blt loop

    mov r7, #1
    mov r0, #0
    svc #0