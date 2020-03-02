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

	gui->prompt_bool.enabled = 0;
	gui->prompt_bool.question_text = GUI_PROMPT_BOOL_DEFAULT_QUESTION_TEXT;
	gui->prompt_bool.yes_text = GUI_PROMPT_BOOL_DEFAULT_YES_TEXT;
	gui->prompt_bool.no_text = GUI_PROMPT_BOOL_DEFAULT_NO_TEXT;
	gui->prompt_bool.choice = 0;
}

int gui_game_render_disabled(struct gui *gui)
{
	return gui->main_menu.enabled;
}
