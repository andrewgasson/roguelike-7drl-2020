#ifndef GAME_H
#define GAME_H

#include "engine/engine.h"
#include "world/world.h"

struct game {
	struct engine *engine;
	struct world *world;
	void (*state)(struct game *game);
};

struct game *game_create(void);

void game_destroy(struct game *game);

void game_init(struct game *game, struct engine *engine, struct world *world);

void game_update(struct game *game);

#endif
