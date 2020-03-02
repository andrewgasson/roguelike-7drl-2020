#ifndef GUI_PAUSE_MENU_H
#define GUI_PAUSE_MENU_H

#define GUI_PAUSE_MENU_DISABLE_GAME_RENDER 0

enum gui_pause_menu_cursor_state {
	GUI_PAUSE_MENU_CURSOR_STATE_RESUME,
	GUI_PAUSE_MENU_CURSOR_STATE_SAVE_GAME,
	GUI_PAUSE_MENU_CURSOR_STATE_LOAD_GAME,
	GUI_PAUSE_MENU_CURSOR_STATE_SETTINGS,
	GUI_PAUSE_MENU_CURSOR_STATE_QUIT_TO_MAIN_MENU,

	/* Size */
	GUI_PAUSE_MENU_CURSOR_STATE__LENGTH,

	/* Default */
	GUI_PAUSE_MENU_CURSOR_STATE_DEFAULT = GUI_PAUSE_MENU_CURSOR_STATE_RESUME
};


struct gui_pause_menu {
	int enabled;
	enum gui_pause_menu_cursor_state cursor_state;
};

void gui_pause_menu_cursor_back(struct gui_pause_menu *pause_menu);

void gui_pause_menu_cursor_next(struct gui_pause_menu *pause_menu);

#endif
