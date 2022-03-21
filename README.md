# <img src="gems.png" alt="Logo" width="5%"/> GEMS KERNEL

GEMS - GEMS is ESSENTIALLY MAYBE SPINEL
*Note: This is not Spinel, we are just trying to be better. ;)*
Note: GEMS is in *really early development*, and will probably be that way for ***quite a while.*** Note: This is highly based off of https://wiki.osdev.org/ and user Zesterer's Bare_Bones, however it is modified quite a bit to work for me.

Seriously... You can only boot to a small splash screen, you can't even type anything...

but it has Colors, Sounds, A panic system so it is definitely improving.

However, here are the dependencies (in ubuntu) in case you *want* to compile this

~~sudo apt install -y libc6-dev-i386 grub-common nasm gcc liblua5.1-0-dev liblua50:i386 liblua50-dev:i386 libc-dev:i386 linux-libc-dev:i386 libc6-dev:i386 qemu-system-i386 grub-pc-bin lua-socket xorriso gcc-9-multilib libc6-dev-i386 libc6-x32 gcc-multilib libc6-dev-x32 libc6-dev linux-libc-dev~~

Update: You might want to install these:
sudo apt install -y build-essential grub-common nasm gcc git qemu-system-x86 grub-pc-bin lua-socket xorriso gcc-8-multilib gcc-arm-none-eabi git

Oh and also: You really need an *i686 cross compiler,* I reccomend this one here for GNU/Linux: https://drive.google.com/file/d/0Bw6lG3Ej2746STJaM2dNbC05elE/view?usp=sharing


Or for macOS, run this brew command (requires homebrew)

```
brew install i686-elf-gcc
```

And then setup GRUB on macOS, as explained here:
https://wiki.osdev.org/GRUB_2#HDD_Image_Instructions_for_OS_X_users

~~(Hint, download LUA 5.0 source here: https://www.lua.org/ftp/lua-5.0.tar.gz)~~ Update: We are switching to mostly custom C/ASM

Oh and a quick warning: *Test.sh / Qemu's PC SPEAKER is VERY LOUD. You will want to turn down your volume.*

# Other files
COC.md is the *old* Code of Conduct. *(Read the new one linked at GEMS NT page.)*

BUGS.md is for listing all the different bugs and their origins/source and status.

NOTES.md is for listing everything we have learned so far.

WSLHOWTO.MD is a tutorial on how to build and run GEMS in Windows.
