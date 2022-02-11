int sticker = 0;

void stick() {
	static long long int i; 
	static int state = 0; 
	switch (state) 
	{ 
		case 0: /* start of function */
		sticker = 1;
		while(sticker > 0) {
			/* Returns control */
			case 1:; /* resume control straight 
			after the return */
		}
	}
	state = 0; 
	return 0; 
	
}

void unstick() {
	static long long int i; 
	static int state = 0; 
	switch (state) 
	{ 
		case 0: /* start of function */
		sticker = 0;
	/* Returns control */
	case 1:; /* resume control straight 
	after the return */
	}
	state = 0; 
	return 0; 
}

void halt() {
	stick(); //do nothing... :)
}

void unhalt() {
	unstick(); //resume... :)
}

void doubleBeep() {
	beep();
	beep();
}

void showColors() {
    setTermColor(0x19);
    print("Blue ");
    setTermColor(0x2A);
    print("Green ");
    setTermColor(0x3B);
    print("Lightblue ");
    setTermColor(0x4C);
    print("Red ");
    setTermColor(0x5D);
    print("Pink ");
    setTermColor(0x6E);
    print("Orange ");
    setTermColor(0x7F);
    print("White ");
    setTermColor(0x0F);
}

void panic(char deets[128]) {
    clear();
    print("\nGEMS Kernel has somehow been borked.\n Error code: ");
    print(deets);
    print("\n");
    print("For now, try restarting your computer or file a bug report.\n");
    print("When filing a bug report, please give us information about your computer.\n");
    print("tell us about your computer's architecture.\n");
    print("does it support VGA?\n");
    print("does it support GRUB?\n");
    print("Is it scared of Microsoft? (jk)\n");
    print("Debugging details:\n");
    print("\nIf you hear a beep then PC Speakers are working fine.");
    doubleBeep();
    print("\nAre colors working? (Order: Blue,Green,Lightblue,Red,Pink,Orange,White.)\n");
    showColors();
    print("Regular\n");
    halt();
}
