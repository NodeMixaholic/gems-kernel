//create ram filesystem for while system is in use
char ramFileNames[9999999] = {"init"};
char ramFileContents[9999999] = {"init"};
int ramFileSizeInChars[99999999] = {"init"};

int makeFile(char name) {
	int i = 0;
	while (ramFileNames[i]) {
		i++;
	}
	ramFileNames[i] = name;
	ramFileContents[i] = 0;
	ramFileSizeInChars[i] = 0;
	return i;
}

char fileContents(char name) {
	int i = 0;
	while (ramFileNames[i] != name) {
		i++;
	}
	return ramFileContents[i];
}

addToFile(char name, char data) {
	int i = 0;
	while (ramFileNames[i] != name) {
		i++;
	}
	ramFileContents[i] = data;
}
