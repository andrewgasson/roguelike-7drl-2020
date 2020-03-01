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
}
