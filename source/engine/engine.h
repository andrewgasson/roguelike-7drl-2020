#ifndef ENGINE_H
#define ENGINE_H

#include "game/game.h"
#include "input/input.h"
#include "render/render.h"
#include "world/world.h"

struct engine {
	int running;
	struct game *game;
	struct input *input;
	struct render *render;
	struct world *world;
};

struct engine *engine_create(void);

void engine_destroy(struct engine *engine);

void engine_init(
	struct engine *engine,
	struct game *game,
	struct input *input,
	struct render *render,
	struct world *world);

void engine_start(struct engine *engine);

void engine_stop(struct engine *engine);

#endif
