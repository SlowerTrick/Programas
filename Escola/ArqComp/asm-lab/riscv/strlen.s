.global strlen
strlen:
    mv t0, a0          # t0 = ponteiro para string
    li t1, 0           # t1 = contador
loop:
    lbu t2, 0(t0)
    beq t2, zero, done
    addi t1, t1, 1
    addi t0, t0, 1
    j loop
done:
    mv a0, t1
    ret
