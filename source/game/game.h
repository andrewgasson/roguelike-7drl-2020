#ifndef GAME_H
#define GAME_H

#include "engine/engine.h"
#include "game/game_state/game_state.h"
#include "gui/gui.h"
#include "input/input.h"
#include "world/world.h"

struct game {
	struct engine *engine;
	struct gui *gui;
	struct input *input;
	struct world *world;
	const struct game_state *state;
};

struct game *game_create(void);

void game_destroy(struct game *game);

void game_init(
	struct game *game,
	struct engine *engine,
	struct gui *gui,
	struct input *input,
	struct world *world);

void game_set_state(struct game *game, const struct game_state *state);

void game_update(struct game *game);

#endif
