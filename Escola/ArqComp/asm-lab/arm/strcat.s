.global strcat
strcat:
    mov r2, r0
find_end:
    ldrb r3, [r0]
    cmp r3, #0
    addne r0, r0, #1
    bne find_end
copy:
    ldrb r3, [r1], #1
    strb r3, [r0], #1
    cmp r3, #0
    bne copy
    mov r0, r2
    bx lr
