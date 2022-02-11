echo "Setting target as 32bit ELF"
export TARGET=i386-elf
echo "Making directories"
mkdir builds
mkdir builds/blocks
mkdir builds/iso
mkdir builds/iso/boot
mkdir builds/iso/boot/grub
echo "Building bootloader"
opt/cross/bin/i686-elf-gcc -std=gnu99 -ffreestanding -g -c start.s -o builds/blocks/bl.o
echo "Building basic keyboard support"
nasm -f elf32 keyboardbasic.asm -o builds/blocks/keys.o
echo "Building OS"
set disassembly-flavor intel
opt/cross/bin/i686-elf-gcc builds/blocks/bl.o os.c -g -ffreestanding -m32 -o builds/iso/gems.elf -I"lua-precomp/" -I"/usr/include" -nostdlib
echo "Creating GRUB config"
echo "set default=0" > builds/iso/boot/grub/grub.cfg
echo "set timeout=60" >> builds/iso/boot/grub/grub.cfg
echo 'menuentry "GEMS" {' >> builds/iso/boot/grub/grub.cfg
echo "  multiboot /gems.elf" >> builds/iso/boot/grub/grub.cfg
echo "  boot" >> builds/iso/boot/grub/grub.cfg
echo "}" >> builds/iso/boot/grub/grub.cfg
echo "Creating ISO"
grub-mkrescue -d /usr/lib/grub/i386-pc -o builds/gems.iso builds/iso
