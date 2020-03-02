#include "render/render_gui/render_gui.h"

#include "BearLibTerminal.h"

void render_gui_main_menu(struct render *render)
{
	/* Reset colours. */
	terminal_color(color_from_argb(255, 255, 255, 255));

	/* Draw menu text. */
	terminal_print(2, 1, "MAIN MENU");

	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_NEW_GAME)
		terminal_print(2, 3, "> New Game");
	else
		terminal_print(2, 3, "  New Game");
	
	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_LOAD_GAME)
		terminal_print(2, 4, "> Load Game");
	else
		terminal_print(2, 4, "  Load Game");
	
	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_SETTINGS)
		terminal_print(2, 5, "> Settings");
	else
		terminal_print(2, 5, "  Settings");
	
	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_QUIT)
		terminal_print(2, 7, "> Quit to Desktop");
	else
		terminal_print(2, 7, "  Quit to Desktop");
}
