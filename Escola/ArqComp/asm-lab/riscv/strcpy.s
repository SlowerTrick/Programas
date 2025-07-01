.global strcpy
strcpy:
    mv t0, a0          # destino
    mv t1, a1          # origem
    mv t2, a0          # retorno
loop:
    lbu t3, 0(t1)
    sb t3, 0(t0)
    beq t3, zero, done
    addi t0, t0, 1
    addi t1, t1, 1
    j loop
done:
    mv a0, t2
    ret
