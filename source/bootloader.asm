/* Deprecated */
/* New one is start.s */
SECTION .multiboot
ALIGN 4
mboot:
    MULTIBOOT_PAGE_ALIGN   equ 1<<0
    MULTIBOOT_MEMORY_INFO   equ 1<<1
    MULTIBOOT_AOUT_KLUDGE   equ 1<<16
    MULTIBOOT_HEADER_MAGIC   equ 0x1BADB002
    MULTIBOOT_HEADER_FLAGS   equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE
    MULTIBOOT_CHECKSUM   equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
    EXTERN code, bss, end
 
    dd MULTIBOOT_HEADER_MAGIC
    dd MULTIBOOT_HEADER_FLAGS
    dd MULTIBOOT_CHECKSUM
	
global exit
extern _start
mov ax, 9ch
mov ss, ax ;cannot be written directly
mov sp, 4094d
mov ax, 7c0h
mov ds, ax ;cannot be written directly
MODULEALIGN       equ     1<<0
MEMINFO           equ     1<<1


loader:
	call _start
	call exit ;crash, forgot to add

exit:
	hlt
	jmp exit
times 510-($-$$) db 0
dw 0xAA55
call loader ;darn i forgot to add this. probably whats causing the boot loop.
