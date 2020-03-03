#include "render/render_gui/render_gui.h"

#include "config/config.h"
#include "BearLibTerminal.h"

void render_gui_pause_menu(struct render *render)
{
	int padding_left;
	int y;

	/* Draw menu background. */
	terminal_bkcolor(color_from_argb(255, 0, 0, 0));
	terminal_clear_area(3, 0, 22, terminal_state(TK_HEIGHT));

	/* Draw menu text. */
	padding_left = 4;
	y = 2;

	terminal_color(color_from_name("amber"));
	terminal_print(padding_left, y, CONFIG_GAME_NAME_UPPERCASE);
	terminal_color(color_from_argb(255, 255, 255, 255));

	y += 2;

	if (render->gui->pause_menu.cursor_state == GUI_PAUSE_MENU_CURSOR_STATE_RESUME)
		terminal_print(padding_left, y, "> Resume");
	else
		terminal_print(padding_left, y, "  Resume");

	y++;

	if (render->gui->pause_menu.cursor_state == GUI_PAUSE_MENU_CURSOR_STATE_SAVE_GAME)
		terminal_print(padding_left, y, "> Save Game");
	else
		terminal_print(padding_left, y, "  Save Game");

	y++;

	if (render->gui->pause_menu.cursor_state == GUI_PAUSE_MENU_CURSOR_STATE_LOAD_GAME)
		terminal_print(padding_left, y, "> Load Game");
	else
		terminal_print(padding_left, y, "  Load Game");

	y++;

	if (render->gui->pause_menu.cursor_state == GUI_PAUSE_MENU_CURSOR_STATE_SETTINGS)
		terminal_print(padding_left, y, "> Settings");
	else
		terminal_print(padding_left, y, "  Settings");
	
	y += 2;

	if (render->gui->pause_menu.cursor_state == GUI_PAUSE_MENU_CURSOR_STATE_QUIT_TO_MAIN_MENU)
		terminal_print(padding_left, y, "> Quit to Main Menu");
	else
		terminal_print(padding_left, y, "  Quit to Main Menu");
}
