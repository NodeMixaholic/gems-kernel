;BL.asm files are deprecated, please use booloader.asm
quit:
hlt
jmp quit
jmp $
times 510-($-$$) db 0
dw 0xAA55

