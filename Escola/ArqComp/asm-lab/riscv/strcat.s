.global strcat
strcat:
    mv t0, a0      # destino
    mv t1, a1      # origem
    mv t2, a0      # retorno
find_end:
    lbu t3, 0(t0)
    beq t3, zero, copy
    addi t0, t0, 1
    j find_end
copy:
    lbu t3, 0(t1)
    sb t3, 0(t0)
    addi t0, t0, 1
    addi t1, t1, 1
    bne t3, zero, copy
    mv a0, t2
    ret
