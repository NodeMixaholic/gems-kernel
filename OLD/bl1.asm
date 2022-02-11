;BL.asm files are deprecated, please use booloader.asm
mov ax, 9ch
mov ss, ax ;cannot be written directly
mov sp, 4094d
mov ax, 7c0h
mov ds, ax ;cannot be written directly
