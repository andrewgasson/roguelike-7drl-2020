#ifndef RENDER_H
#define RENDER_H

#include "gui/gui.h"
#include "world/world.h"

struct render {
	struct gui *gui;
	struct world *world;
};

struct render *render_create(void);

void render_destroy(struct render *render);

void render_init(
	struct render *render,
	struct gui *gui,
	struct world *world);

void render_update(struct render *render);

#endif
