int brk = 0;
int ghzepoch = 0; //nanoseconds
void unstick() {
	brk = 0;
}

void delay(unsigned int s) {
	int g = s + ghzepoch;
	while (g > ghzepoch); {
		//do nothing
	}
}

void stick() {
	brk = 1;
	while (brk < 0) {
		//do nothing
	}
}
