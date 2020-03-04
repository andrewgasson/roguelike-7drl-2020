#ifndef WORLD_H
#define WORLD_H

#include "world/being.h"
#include "world/compass.h"
#include "world/glyph.h"
#include "world/map.h"
#include "world/position.h"

struct world {
	struct being player;
	struct map map;
};

struct world *world_create(void);

void world_destroy(struct world *world);

void world_init(struct world *world);

/* Returns 1 if the file could be loaded, and 0 otherwise. */
int world_load(struct world *world, const char *filepath);

/* Returns 1 if the file could be saved, and 0 otherwise. */
int world_save(struct world *world, const char *filepath);

#endif
