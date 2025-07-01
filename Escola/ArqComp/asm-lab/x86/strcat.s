strcat:
    mov edi, [esp + 4]
    mov esi, [esp + 8]
find_end:
    cmp byte [edi], 0
    je copy
    inc edi
    jmp find_end
copy:
    mov al, [esi]
    mov [edi], al
    inc esi
    inc edi
    cmp al, 0
    jne copy
    mov eax, [esp + 4]
    ret
