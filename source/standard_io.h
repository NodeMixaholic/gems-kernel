int x = 0;
int y = 0;
int lc = 0;
int VGA_WIDTH = 24;
char *line = 0x00;

void clear() {
	char *mem = (char*)0xb8000;
	int i = 0;
	while (i < 4096) {
		mem[i++] = 0;
	}
}

/* We will use this later on for reading from the I/O ports to get data
*  from devices such as the keyboard. We are using what is called
*  'inline assembly' in these routines to actually do the work */
unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

/* We will use this to write to I/O ports to send bytes to devices. This
*  will be used in the next tutorial for changing the textmode cursor
*  position. Again, we use some inline assembly for the stuff that simply
*  cannot be done in C */
void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

// This is the x86's VGA textmode buffer. To display text, we write data to this memory location
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
// By default, the VGA textmode buffer has a size of 80x25 characters
const int VGA_COLS = 80;
const int VGA_ROWS = 25;
 
// We start displaying text in the top-left of the screen (column = 0, row = 0)
int term_col = 0;
int term_row = 0;
uint8_t term_color = 0x0F; // Black background, White foreground
 
// This function initiates the terminal by clearing it
void term_init()
{
	// Clear the textmode buffer
	for (int col = 0; col < VGA_COLS; col ++)
	{
		for (int row = 0; row < VGA_ROWS; row ++)
		{
			// The VGA textmode buffer has size (VGA_COLS * VGA_ROWS).
			// Given this, we find an index into the buffer for our character
			const size_t index = (VGA_COLS * row) + col;
			// Entries in the VGA buffer take the binary form BBBBFFFFCCCCCCCC, where:
			// - B is the background color
			// - F is the foreground color
			// - C is the ASCII character
			vga_buffer[index] = ((uint16_t)term_color << 8) | ' '; // Set the character to blank (a space character)
		}
	}
}
 
// This function places a single character onto the screen
void printc(char c)
{
	// Remember - we don't want to display ALL characters!
	switch (c)
	{
	case '\n': // Newline characters should return the column to 0, and increment the row
		{
			term_col = 0;
			term_row ++;
			break;
		}
 
	default: // Normal characters just get displayed and then increment the column
		{
			const size_t index = (VGA_COLS * term_row) + term_col; // Like before, calculate the buffer index
			vga_buffer[index] = ((uint16_t)term_color << 8) | c;
			term_col ++;
			break;
		}
	}
 
	// What happens if we get past the last column? We need to reset the column to 0, and increment the row to get to a new line
	if (term_col >= VGA_COLS)
	{
		term_col = 0;
		term_row ++;
	}
 
	// What happens if we get past the last row? We need to reset both column and row to 0 in order to loop back to the top of the screen
	if (term_row >= VGA_ROWS)
	{
		term_col = 0;
		term_row = 0;
	}
}
 
// This function prints an entire string onto the screen
void print(const char* str)
{
	for (size_t i = 0; str[i] != '\0'; i ++) // Keep placing characters until we hit the null-terminating character ('\0')
		printc(str[i]);
}


char int2str(int num) {
    //convert int to string without common libraries
	char str[10];
	int i = 0;
	while (num > 0) {
		str[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	str[i] = '\0';
	char *p = str;
	while (*p != '\0') {
		p++;
	}
	p--;
	char c = *p;
	*p = '\0';
	return c;
}


void printint(int num)
{
	char str = int2str(num); //Make number a string. 
	print(str); //print it.
}

//DO NOT USE
void vgaprint(char *text, int color) {
	lc = color;
	char *mem = (char*)0xb8000;
	if (y == 23) {
		clear(lc);
		y = 0;
	}
	while (*text != 0) {
		if (x > 78) {
			int i = 0;
			while (i < x){
				mem[i++] = 0;
			}
			x = 0;
			y = y + 1;
		}
		x = x + 1;
		if (*text == "\n") {
			int i = 0;
			while (i < x) {
				mem[i++] = 0;
			}
			x = 0;
			y = y + 1;
		} else {
			*mem++ = *text++;
			*mem++ = color;
		}
		int i = 0;
		while (i < x) {
			mem[i++] = 0;
		}
		x = 0;
		y = y + 1;
	}
	
}

int lastVGATextColor() {
	return lc;
}

void setTermColor(uint8_t color) {
	term_color = color;
}

uint8_t termColor() {
	return term_color;
}

//create malloc function without standard libs
char malloc(int size) {
	char *mem = (char*)0xb8000;
	int i = 0;
	while (i < size) {
		mem[i++] = 0;
	}
	return (char)mem;
}

//create free function without standard libs
void free(char *mem) {
	int i = 0;
	while (mem[i] != 0) {
		mem[i++] = 0;
	}
}

void basickeys() {
	register char *ptr asm("ax");; //pointer var
	//do something
	while(*ptr != '\0') {
		*line = *ptr;
		print(ptr); //try to print what's in memory
		ptr++; //add 1 to ptr
	}
}
