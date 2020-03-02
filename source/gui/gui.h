#ifndef GUI_H
#define GUI_H

#include "gui/gui_main_menu.h"
#include "gui/gui_pause_menu.h"
#include "gui/gui_prompt_bool.h"

struct gui {
	struct gui_main_menu main_menu;
	struct gui_pause_menu pause_menu;
	struct gui_prompt_bool prompt_bool;
};

struct gui *gui_create(void);

void gui_destroy(struct gui *gui);

void gui_init(struct gui *gui);

int gui_game_render_disabled(struct gui *gui);

#endif
