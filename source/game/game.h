#ifndef GAME_H
#define GAME_H

#include "world/world.h"

struct game {
	struct world *world;
};

struct game *game_create(void);

void game_destroy(struct game *game);

void game_init(struct game *game, struct world *world);

void game_update(struct game *game);

#endif
