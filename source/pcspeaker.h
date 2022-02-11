//Play sound using built in speaker
 static void play_sound(uint32_t nFrequence) {
 	uint32_t Div;
 	uint8_t tmp;
 
        //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outportb(0x43, 0xb6);
 	outportb(0x42, (uint8_t) (Div) );
 	outportb(0x42, (uint8_t) (Div >> 8));
 
        //And play the sound using the PC speaker
 	tmp = inportb(0x61);
  	if (tmp != (tmp | 3)) {
 		outportb(0x61, tmp | 3);
 	}
 }
 
 //make it shutup
 static void nosound() {
 	uint8_t tmp = inportb(0x61) & 0xFC;
 
 	outportb(0x61, tmp);
 }
 
 //Make a beep
 void beep() {
 	 play_sound(1000);
 	 wait(10000000);
 	 nosound();
 }
 
  //Make a beep
 void beepToneShort(int frequency) {
 	 play_sound(1000);
 	 wait(frequency);
 	 nosound();
 }
 
 void beepTone(int frequency, int secs) {
 	 play_sound(frequency);
 	 waitSecs(secs);
 	 nosound();
 }
