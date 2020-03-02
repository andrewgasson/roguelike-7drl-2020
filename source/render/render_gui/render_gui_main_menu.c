#include "render/render_gui/render_gui.h"

#include "BearLibTerminal.h"
#include "config/config.h"
#include <string.h>

#define GOLDBAND_TITLE_HEIGHT 16
#define GOLDBAND_TITLE_WIDTH 40
#define GOLDBAND_SUBTITLE_PADDING_TOP (GOLDBAND_TITLE_HEIGHT + (GOLDBAND_TITLE_PADDING_TOP * 2))

static const char *const GOLDBAND_TITLE[] = {
	"  /$$$$$$   /$$$$$$  /$$       /$$$$$$$ ",
	" /$$__  $$ /$$__  $$| $$      | $$__  $$",
	"| $$  \\__/| $$  \\ $$| $$      | $$  \\ $$",
	"| $$ /$$$$| $$  | $$| $$      | $$  | $$",
	"| $$|_  $$| $$  | $$| $$      | $$  | $$",
	"| $$  \\ $$| $$  | $$| $$      | $$  | $$",
	"|  $$$$$$/|  $$$$$$/| $$$$$$$$| $$$$$$$/",
	" \\______/  \\______/ |________/|_______/ ",
	" /$$$$$$$   /$$$$$$  /$$   /$$ /$$$$$$$ ",
	"| $$__  $$ /$$__  $$| $$$ | $$| $$__  $$",
	"| $$  \\ $$| $$  \\ $$| $$$$| $$| $$  \\ $$",
	"| $$$$$$$ | $$$$$$$$| $$ $$ $$| $$  | $$",
	"| $$__  $$| $$__  $$| $$  $$$$| $$  | $$",
	"| $$  \\ $$| $$  | $$| $$\\  $$$| $$  | $$",
	"| $$$$$$$/| $$  | $$| $$ \\  $$| $$$$$$$/",
	"|_______/ |__/  |__/|__/  \\__/|_______/ "
};

void render_gui_main_menu(struct render *render)
{
	int y;
	int screen_width;
	int screen_height;
	int padding_left;
	int padding_top;

	screen_width = terminal_state(TK_WIDTH);
	screen_height = terminal_state(TK_HEIGHT);

	/* Draw title placard. */
	padding_left = screen_width - GOLDBAND_TITLE_WIDTH - 2;
	padding_top = 1;

	terminal_layer(0);
	terminal_bkcolor(color_from_name("amber"));
	terminal_color(color_from_argb(255, 0, 0, 0));
	terminal_clear_area(padding_left - 2, 0, screen_width, screen_height);
	terminal_layer(1);

	terminal_print(padding_left, padding_top, "THE");
	padding_top++;

	for (y = 0; y < GOLDBAND_TITLE_HEIGHT; y++) {
		terminal_print(padding_left, y + padding_top, GOLDBAND_TITLE[y]);
	}

	terminal_print(screen_width - 9, padding_top + GOLDBAND_TITLE_HEIGHT, "PROJECT");

	/* Draw game jam info. */
	padding_left = screen_width - 2 - strlen(CONFIG_GAME_JAM);
	terminal_print(padding_left, screen_height - 4, CONFIG_GAME_JAM);

	/* Draw version info. */
	padding_left = screen_width - 10 - strlen(CONFIG_GAME_VERSION);
	terminal_print(padding_left, screen_height - 3, "VERSION " CONFIG_GAME_VERSION);

	/* Draw author info. */
	padding_left = screen_width - 13 - strlen(CONFIG_GAME_AUTHOR_UPPERCASE);
	terminal_print(padding_left, screen_height - 2, "CREATED BY " CONFIG_GAME_AUTHOR_UPPERCASE);

	/* Draw menu text. */
	padding_left = 4;
	y = 2;

	terminal_color(color_from_name("amber"));
	terminal_print(padding_left, y, CONFIG_GAME_NAME_UPPERCASE);
	terminal_color(color_from_argb(255, 255, 255, 255));

	y += 2;

	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_NEW_GAME)
		terminal_print(padding_left, y, "> New Game");
	else
		terminal_print(padding_left, y, "  New Game");
	
	y++;

	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_LOAD_GAME)
		terminal_print(padding_left, y, "> Load Game");
	else
		terminal_print(padding_left, y, "  Load Game");
	
	y++;

	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_SETTINGS)
		terminal_print(padding_left, y, "> Settings");
	else
		terminal_print(padding_left, y, "  Settings");
	
	y += 2;

	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_QUIT)
		terminal_print(padding_left, y, "> Quit to Desktop");
	else
		terminal_print(padding_left, y, "  Quit to Desktop");
}
