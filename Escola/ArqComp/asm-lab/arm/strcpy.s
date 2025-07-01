.global strcpy
strcpy:
    mov r2, r0      @ salva o ponteiro destino
loop:
    ldrb r3, [r1], #1
    strb r3, [r0], #1
    cmp r3, #0
    bne loop
    mov r0, r2
    bx lr
