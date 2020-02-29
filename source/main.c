#include <stdio.h>
#include "BearLibTerminal.h"

int main(void)
{
	printf("Hello world!");

	terminal_open();
	terminal_print(0, 0, "Hello BearLibTerminal!");
	terminal_refresh();

	while (terminal_read() != TK_CLOSE);

	terminal_close();

	return 0;
}
