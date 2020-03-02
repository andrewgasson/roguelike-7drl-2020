#include "gui/gui.h"

#include <stdlib.h>

struct gui *gui_create(void)
{
	struct gui *gui;

	gui = malloc(sizeof(*gui));

	return gui;
}

void gui_destroy(struct gui *gui)
{
	free(gui);
}

void gui_init(struct gui *gui)
{
	gui->main_menu.enabled = 0;
	gui->main_menu.cursor_state = GUI_MAIN_MENU_CURSOR_STATE_DEFAULT;
	gui->pause_menu.enabled = 0;
	gui->pause_menu.cursor_state = GUI_PAUSE_MENU_CURSOR_STATE_DEFAULT;
}

int gui_game_render_disabled(struct gui *gui)
{
	return (gui->main_menu.enabled && GUI_MAIN_MENU_DISABLE_GAME_RENDER)
	|| (gui->pause_menu.enabled && GUI_PAUSE_MENU_DISABLE_GAME_RENDER);
}
