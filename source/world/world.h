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

#endif
