# How to build (and run) GEMS in WSL.

If you decided to switch to Windows like me and you want to develop GEMS then here is a tutorial on how to do so:

How to build:

Setup WSL 2.x (Select Ubuntu or Debian)

Install all of the packages

run ./build.sh

How to test:

Download QEMU for windows.

Copy the GEMS ISO to the QEMU folder

Then run "./qemu-system-x86_64.exe -soundhw pcspk -cdrom builds/gems.iso -m 1000"

There are probably other, better ways of running GEMS in windows.

Try VirtualBox but give it a lot of Memory.

Maybe change the PATH variable to the QEMU Folder.

and then just run the command in Powershell (Without ./ at the beginning)
