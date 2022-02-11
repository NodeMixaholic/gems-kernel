#include "diamondfs.h" //BORKED - USE AT YOUR OWN RISK
void rloadstring(cmd, var1, var2) {
	if (cmd == "welcomescreen") {
		setTermColor(0xA0);
		print("Welcome!\n");
		setTermColor(0x0F);
		print("I had to start over on ");
		setTermColor(0x4F);
		print("GEMS");
		setTermColor(0x0F);
		print(" development \n");
		print(" because Windows sucks.\n");
	} else if (cmd == "helpscreen") {
		setTermColor(0x2A);
		print("It just depends on how we feel...\n");
		print("--The GEMS Team");
		setTermColor(0x0F);
	} else if (cmd == "debugRainbow") {
		setTermColor(0x2F);
		print("\n----------------------------------------------\n");
		print("`Why are there so many songs about rainbows\n");
		print("and what's on the other side`\n");
		setTermColor(0x08);
		print("~");
		setTermColor(0x19);
		print("~");
		setTermColor(0x2A);
		print("K");
		setTermColor(0x3B);
		print("E");
		setTermColor(0x4C);
		print("R");
		setTermColor(0x5D);
		print("M");
		setTermColor(0x6E);
		print("I");
		setTermColor(0x7F);
		print("T");
		beepTone(700,1);
		beepTone(894,1);
		beepTone(990,2);
		waitSecs(.4);
		beepTone(950,1);
		beepTone(900,1);
		beepTone(1000,1);
		waitSecs(.6);
		beepTone(666,3);
		waitSecs(.3);
		beepTone(700,1);
		waitSecs(.6);
		beepTone(861,1);
		waitSecs(.7);
		beepTone(925,1);
		waitSecs(.5);
		beepTone(950,1);
		beepTone(975,1);
		waitSecs(.5);
		beepTone(942,1);
		beepTone(875,1);
		beepTone(800,1);
		waitSecs(.75);
		beepTone(942,2);
		beepTone(990,1);
		waitSecs(.03);
		beepTone(800,2);
		setTermColor(0x0F);
	} else if (cmd == "getkey") {
		basickeys();
	} else if (cmd == "cli") {
		
	}
}
