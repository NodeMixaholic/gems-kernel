echo "Setting target as 32bit ELF"
export TARGET=i386-elf
echo "Making directories"
mkdir builds
mkdir builds/blocks
mkdir builds/iso
mkdir builds/iso/boot
mkdir builds/iso/boot/grub
echo "Building bootloader"
i686-elf-gcc -std=gnu99 -ffreestanding -g -c start.s -o builds/blocks/bl.o
echo "Building basic keyboard support"
nasm -f elf32 detect-kbinput.asm -o builds/blocks/detectkeys.o
echo "Building OS"
set disassembly-flavor intel
i686-elf-gcc builds/blocks/bl.o builds/blocks/detectkeys.o os.c -g -ffreestanding -m32 -o builds/iso/gems.elf -I"/usr/include" -nostdlib
echo "Creating GRUB config"
echo "set default=0" > builds/iso/boot/grub/grub.cfg
echo "set timeout=60" >> builds/iso/boot/grub/grub.cfg
echo 'menuentry "GEMS" {' >> builds/iso/boot/grub/grub.cfg
echo "  multiboot /gems.elf" >> builds/iso/boot/grub/grub.cfg
echo "  boot" >> builds/iso/boot/grub/grub.cfg
echo "}" >> builds/iso/boot/grub/grub.cfg
echo "Note: NOT CREATING ISO. USE CREATE-ISO.SH TO DO THIS."
