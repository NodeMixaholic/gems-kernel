Here are all the notes so far:


http://www.troubleshooters.com/codecorn/lua/lua_c_calls_lua.htm  
this link is useful since it teaches you how to call lua from a running C program by using lua libraries  
(PS: Do not use GNU Linker if you run lua in c, however for technical reasons most OSDev Kernels/OSes (including ours) require ld, so we can no longer use LUA..)

You can't make LUA in C bootable. :-(

Seeking outside the file? Try changing linker.ld and changing your bootloader to start.s! Modify accordingly.

*You really do need a i686 cross-compiler, get one here: https://drive.google.com/file/d/0Bw6lG3Ej2746STJaM2dNbC05elE/view?usp=sharing*
