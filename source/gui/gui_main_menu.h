#ifndef GUI_MAIN_MENU_H
#define GUI_MAIN_MENU_H

#define GUI_MAIN_MENU_DISABLE_GAME_RENDER 1

enum gui_main_menu_cursor_state {
	GUI_MAIN_MENU_CURSOR_STATE_NEW_GAME,
	GUI_MAIN_MENU_CURSOR_STATE_LOAD_GAME,
	GUI_MAIN_MENU_CURSOR_STATE_SETTINGS,
	GUI_MAIN_MENU_CURSOR_STATE_QUIT,

	/* Size */
	GUI_MAIN_MENU_CURSOR_STATE__LENGTH,

	/* Default */
	GUI_MAIN_MENU_CURSOR_STATE_DEFAULT = GUI_MAIN_MENU_CURSOR_STATE_NEW_GAME
};


struct gui_main_menu {
	int enabled;
	enum gui_main_menu_cursor_state cursor_state;
};

void gui_main_menu_cursor_back(struct gui_main_menu *main_menu);

void gui_main_menu_cursor_next(struct gui_main_menu *main_menu);

#endif
