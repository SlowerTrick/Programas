strcmp:
    mov esi, [esp + 4]
    mov edi, [esp + 8]
loop:
    mov al, [esi]
    mov bl, [edi]
    cmp al, bl
    jne diff
    cmp al, 0
    je equal
    inc esi
    inc edi
    jmp loop
diff:
    movzx eax, al
    movzx ebx, bl
    sub eax, ebx
    ret
equal:
    xor eax, eax
    ret
