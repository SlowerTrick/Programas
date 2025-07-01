strlen:
    mov ecx, 0
    mov edi, [esp + 4]
loop:
    cmp byte [edi + ecx], 0
    je end
    inc ecx
    jmp loop
end:
    mov eax, ecx
    ret
