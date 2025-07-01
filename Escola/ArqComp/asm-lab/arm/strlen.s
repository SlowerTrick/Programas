.global strlen
strlen:
    mov r1, r0      @ r1 = ponteiro para a string
    mov r2, #0      @ r2 = contador
loop:
    ldrb r3, [r1], #1
    cmp r3, #0
    beq done
    add r2, r2, #1
    b loop
done:
    mov r0, r2
    bx lr
