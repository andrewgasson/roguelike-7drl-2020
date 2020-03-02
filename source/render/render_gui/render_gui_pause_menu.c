#include "render/render_gui/render_gui.h"

#include "BearLibTerminal.h"

void render_gui_pause_menu(struct render *render)
{
	/* Reset colours */
	terminal_color(color_from_argb(255, 255, 255, 255));

	/* Draw menu background. */
	terminal_layer(0);
	terminal_bkcolor(color_from_argb(255, 0, 0, 0));
	terminal_clear_area(3, 0, 22, terminal_state(TK_HEIGHT));
	terminal_layer(1);

	/* Draw menu text. */
	terminal_print(4, 2, "PAUSE MENU");

	if (render->gui->pause_menu.cursor_state == GUI_PAUSE_MENU_CURSOR_STATE_RESUME)
		terminal_print(4, 4, "> Resume");
	else
		terminal_print(4, 4, "  Resume");

	if (render->gui->pause_menu.cursor_state == GUI_PAUSE_MENU_CURSOR_STATE_SAVE_GAME)
		terminal_print(4, 5, "> Save Game");
	else
		terminal_print(4, 5, "  Save Game");

	if (render->gui->pause_menu.cursor_state == GUI_PAUSE_MENU_CURSOR_STATE_LOAD_GAME)
		terminal_print(4, 6, "> Load Game");
	else
		terminal_print(4, 6, "  Load Game");

	if (render->gui->pause_menu.cursor_state == GUI_PAUSE_MENU_CURSOR_STATE_SETTINGS)
		terminal_print(4, 7, "> Settings");
	else
		terminal_print(4, 7, "  Settings");
	
	if (render->gui->pause_menu.cursor_state == GUI_PAUSE_MENU_CURSOR_STATE_QUIT_TO_MAIN_MENU)
		terminal_print(4, 9, "> Quit to Main Menu");
	else
		terminal_print(4, 9, "  Quit to Main Menu");
}
