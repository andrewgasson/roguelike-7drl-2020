#ifndef WORLD_H
#define WORLD_H

#include "world/being.h"
#include "world/glyph.h"

struct world {
	int game_input;
	struct being player;
};

struct world *world_create(void);

void world_destroy(struct world *world);

void world_init(struct world *world);

#endif
