//WARNING: A EXREMELY BAD EXAMPLE OF MIDI OF MIDI SUPPORT BY SPARKSAMMY/SAMUEL LORD.
//Note: "n" stands for note.
float midi[127]; //127 is size in this case
int tune = 440; //440hz frequency
int round = 0;
int roundResetable = 0;
int freqOf(n) {
	char currentNote = "";
	char currentNoteNumStr = "";
	char midiNote[127]; //127 is size in this case
	for (int x = 0; x < 127; ++x)
	{
		round++;
		if (roundResetable > 7) {
			roundResetable = 0;
		}
		roundResetable++;
		midi[x] = (tune / 32) * (2 ^ ((x - 9) / 12));
		if (roundResetable == 1) {
			currentNoteNumStr = ((round / 7) - 1);
			currentNote = "A" + currentNoteNumStr;
		} else if (roundResetable == 2) {
			currentNoteNumStr = ((round / 7) - 1);
			currentNote = "B" + currentNoteNumStr;
		} else if (roundResetable == 3) {
			currentNoteNumStr = ((round / 7));;
			currentNote = "C" + currentNoteNumStr;
		} else if (roundResetable == 4) {
			currentNoteNumStr = ((round / 7));;
			currentNote = "D" + currentNoteNumStr;
		} else if (roundResetable == 5) {
			currentNoteNumStr = ((round / 7));;
			currentNote = "E" + currentNoteNumStr;
		} else if (roundResetable == 6) {
			currentNoteNumStr = ((round / 7));;
			currentNote = "F" + currentNoteNumStr;
		} else if (roundResetable == 7) {
			currentNoteNumStr = ((round / 7));;
			currentNote = "G" + currentNoteNumStr;
		} else {
			//dammit my code crashed
		}
		midiNote[n] = currentNote;  //n is is the current size of what we get/post
	}
	for (int i = 0; i < round; i++) {
		if (midiNote[n] == midiNote[i]) {
			return midi[i]; //n is is the current size of what we get/post. Also: there HAS to be a better way! :'(
		}
	}
}

int freqOfAsStr(n) {
	char freqStr;
	freqStr = freqOf(n);
	return freqStr;
}

