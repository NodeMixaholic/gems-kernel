//Made to create time at 100000000 TPS
//by Sparksammy
int time = 1;

void countOld() {
	static long long int i; 
	static int state = 0; 
		switch (state) 
		{ 
		case 0: /* start of function */
		while (1 == 1) {
			time++;
		}
		/* Returns control */
		case 1:; /* resume control straight 
		after the return */
		}
		state = 0; 
		return 0; 
	
}

void waitSecs(int end) {
	int start = 0;
	end = end * 100000000;
	while (start < end) {
		start++;
	}
}

void wait(int end) {
	int start = 0;
	while (start < end) {
		start++;
	}
	
}

bool countstate = false;
int time2 = 0;

// New count feature cuz why not?
// They are all counted in seconds
void Count() {
	while (countstate == true) {
		waitSecs(1);
		time2++;
	}
}

// get time from the new count feature
int getTime() {
	return time2;
}

// Sets time in seconds
int setTime(int sec) {
	time2 = sec;
}


void disableCount() {
	countstate = false;
}

void enableCount() {
	countstate = true;
}
