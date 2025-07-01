strcpy:
    mov edi, [esp + 4]
    mov esi, [esp + 8]
loop:
    mov al, [esi]
    mov [edi], al
    inc esi
    inc edi
    cmp al, 0
    jne loop
    mov eax, [esp + 4]
    ret
