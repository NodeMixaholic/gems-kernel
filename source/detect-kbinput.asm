_start:
    push ax

    xor bp, bp    ;clear out bp
    mov ah, 1     ;Function 1, check key status.
    int 16h       ;Is a key ready? 
    jz NO_KEY     ;If zf cleared, then no.
    xor ah, ah    ;Otherwise, a key is waiting.
    int 16h       ;ah -> scancode
    xor al, al    
    xchg al, ah   ;ax -> scancode
    mov bp, ax    ;bp -> scancode, accessible globally


NO_KEY:
    pop ax
    ret
