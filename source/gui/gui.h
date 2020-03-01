#ifndef GUI_H
#define GUI_H

#include "gui/gui_main_menu.h"

struct gui {
	struct gui_main_menu main_menu;
};

struct gui *gui_create(void);

void gui_destroy(struct gui *gui);

void gui_init(struct gui *gui);

#endif
