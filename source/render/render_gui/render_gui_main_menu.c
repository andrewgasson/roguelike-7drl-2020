#include "render/render_gui/render_gui.h"

void render_gui_main_menu(struct render *render)
{
	terminal_print(0, 0, "<Main Menu>");

	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_PLAY)
		terminal_print(0, 2, "> Play");
	else
		terminal_print(0, 2, "  Play");
	
	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_SETTINGS)
		terminal_print(0, 3, "> Settings");
	else
		terminal_print(0, 3, "  Settings");
	
	if (render->gui->main_menu.cursor_state == GUI_MAIN_MENU_CURSOR_STATE_QUIT)
		terminal_print(0, 4, "> Quit");
	else
		terminal_print(0, 4, "  Quit");
}
