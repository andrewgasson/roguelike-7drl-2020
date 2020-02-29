#include "BearLibTerminal.h"

struct glyph {
	color_t background;
	color_t foreground;
	char symbol;
};

struct being {
	int x;
	int y;
	struct glyph glyph;
};

struct being player;

int main(void)
{
	int terminal_input;
	int engine_running;

	player.x = 0;
	player.y = 0;
	player.glyph.background = color_from_argb(255, 0, 128, 128);
	player.glyph.foreground = color_from_argb(255, 255, 0, 0);
	player.glyph.symbol = '@';

	terminal_open();
	terminal_refresh();

	engine_running = 1;

	/* Engine loop */
	while (engine_running) {
		/* Render */
		terminal_bkcolor(0xFF000000);
		terminal_color(0xFFFFFFFF);
		terminal_clear();

		terminal_bkcolor(player.glyph.background);
		terminal_color(player.glyph.foreground);
		terminal_put(player.x, player.y, player.glyph.symbol);

		terminal_refresh();

		/* Input */
		terminal_input = terminal_read();

		/* Gameplay */
		switch (terminal_input) {
		case TK_W:
			player.y--;
			break;
		case TK_A:
			player.x--;
			break;
		case TK_S:
			player.y++;
			break;
		case TK_D:
			player.x++;
			break;
		default:
			break;
		}

		/* Check engine running */
		if (terminal_input == TK_CLOSE)
			engine_running = 0;
	}

	terminal_close();

	return 0;
}
