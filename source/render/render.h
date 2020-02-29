#ifndef RENDER_H
#define RENDER_H

#include "world/world.h"

struct render {
	struct world *world;
};

struct render *render_create(void);

void render_destroy(struct render *render);

void render_init(struct render *render, struct world *world);

void render_update(struct render *render);

#endif
