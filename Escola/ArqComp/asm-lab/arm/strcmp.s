.global strcmp
strcmp:
loop:
    ldrb r2, [r0], #1
    ldrb r3, [r1], #1
    cmp r2, r3
    bne notequal
    cmp r2, #0
    beq equal
    b loop
notequal:
    sub r0, r2, r3
    bx lr
equal:
    mov r0, #0
    bx lr
