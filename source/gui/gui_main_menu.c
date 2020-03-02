#include "gui/gui_main_menu.h"

void gui_main_menu_cursor_back(struct gui_main_menu *main_menu)
{
	switch (main_menu->cursor_state) {
	case GUI_MAIN_MENU_CURSOR_STATE_LOAD_GAME:
		main_menu->cursor_state = GUI_MAIN_MENU_CURSOR_STATE_NEW_GAME;
		break;
	case GUI_MAIN_MENU_CURSOR_STATE_SETTINGS:
		main_menu->cursor_state = GUI_MAIN_MENU_CURSOR_STATE_LOAD_GAME;
		break;
	case GUI_MAIN_MENU_CURSOR_STATE_QUIT:
		main_menu->cursor_state = GUI_MAIN_MENU_CURSOR_STATE_SETTINGS;
		break;
	default:
		break;
	}
}

void gui_main_menu_cursor_next(struct gui_main_menu *main_menu)
{
	switch (main_menu->cursor_state) {
	case GUI_MAIN_MENU_CURSOR_STATE_NEW_GAME:
		main_menu->cursor_state = GUI_MAIN_MENU_CURSOR_STATE_LOAD_GAME;
		break;
	case GUI_MAIN_MENU_CURSOR_STATE_LOAD_GAME:
		main_menu->cursor_state = GUI_MAIN_MENU_CURSOR_STATE_SETTINGS;
		break;
	case GUI_MAIN_MENU_CURSOR_STATE_SETTINGS:
		main_menu->cursor_state = GUI_MAIN_MENU_CURSOR_STATE_QUIT;
		break;
	default:
		break;
	}
}
