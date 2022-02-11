SECTIONS
{
  .text.start (_KERNEL_BASE_) : {
/* link multiboot struct */
. = ALIGN(8);
KEEP(*(.multiboot))
/* keep this */
    startup.o( .text )
  }

  .text : ALIGN(0x1000) {
/* link multiboot struct */
. = ALIGN(8);
KEEP(*(.multiboot))
/* keep this */
_TEXT_START_ = .;
    *(.text)
_TEXT_END_ = .;
  }

  .data : ALIGN(0x1000) {
/* link multiboot struct */
. = ALIGN(8);
KEEP(*(.multiboot))
/* keep this */
_DATA_START_ = .;
    *(.data)
_DATA_END_ = .;
  }

  .bss : ALIGN(0x1000) {
/* link multiboot struct */
. = ALIGN(8);
KEEP(*(.multiboot))
/* keep this */
_BSS_START_ = .;
    *(.bss)
_BSS_END_ = .;
  }
}

