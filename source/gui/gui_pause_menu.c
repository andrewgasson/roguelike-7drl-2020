#include "gui/gui_pause_menu.h"

void gui_pause_menu_cursor_back(struct gui_pause_menu *pause_menu)
{
	switch (pause_menu->cursor_state) {
	case GUI_PAUSE_MENU_CURSOR_STATE_SAVE_GAME:
		pause_menu->cursor_state = GUI_PAUSE_MENU_CURSOR_STATE_RESUME;
		break;
	case GUI_PAUSE_MENU_CURSOR_STATE_LOAD_GAME:
		pause_menu->cursor_state = GUI_PAUSE_MENU_CURSOR_STATE_SAVE_GAME;
		break;
	case GUI_PAUSE_MENU_CURSOR_STATE_SETTINGS:
		pause_menu->cursor_state = GUI_PAUSE_MENU_CURSOR_STATE_LOAD_GAME;
		break;
	case GUI_PAUSE_MENU_CURSOR_STATE_QUIT_TO_MAIN_MENU:
		pause_menu->cursor_state = GUI_PAUSE_MENU_CURSOR_STATE_SETTINGS;
		break;
	default:
		break;
	}
}

void gui_pause_menu_cursor_next(struct gui_pause_menu *pause_menu)
{
	switch (pause_menu->cursor_state) {
	case GUI_PAUSE_MENU_CURSOR_STATE_RESUME:
		pause_menu->cursor_state = GUI_PAUSE_MENU_CURSOR_STATE_SAVE_GAME;
		break;
	case GUI_PAUSE_MENU_CURSOR_STATE_SAVE_GAME:
		pause_menu->cursor_state = GUI_PAUSE_MENU_CURSOR_STATE_LOAD_GAME;
		break;
	case GUI_PAUSE_MENU_CURSOR_STATE_LOAD_GAME:
		pause_menu->cursor_state = GUI_PAUSE_MENU_CURSOR_STATE_SETTINGS;
		break;
	case GUI_PAUSE_MENU_CURSOR_STATE_SETTINGS:
		pause_menu->cursor_state = GUI_PAUSE_MENU_CURSOR_STATE_QUIT_TO_MAIN_MENU;
		break;
	default:
		break;
	}
}
