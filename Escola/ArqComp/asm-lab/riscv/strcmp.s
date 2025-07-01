.global strcmp
strcmp:
loop:
    lbu t0, 0(a0)
    lbu t1, 0(a1)
    bne t0, t1, notequal
    beq t0, zero, equal
    addi a0, a0, 1
    addi a1, a1, 1
    j loop
notequal:
    sub a0, t0, t1
    ret
equal:
    li a0, 0
    ret
