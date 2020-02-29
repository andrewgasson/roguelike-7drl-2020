#ifndef WORLD_H
#define WORLD_H

#include "world/being.h"
#include "world/compass.h"
#include "world/glyph.h"
#include "world/input_action.h"

struct world {
	enum input_game_action input_game_action;
	enum input_ui_action input_ui_action;
	enum input_system_action input_system_action;
	struct being player;
};

struct world *world_create(void);

void world_destroy(struct world *world);

void world_init(struct world *world);

#endif
