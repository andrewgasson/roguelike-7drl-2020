#include "engine/engine.h"

#include <stdlib.h>

struct engine *engine_create(void)
{
	struct engine *engine;

	engine = malloc(sizeof(*engine));

	return engine;
}

void engine_destroy(struct engine *engine)
{
	free(engine);
}

void engine_init(
	struct engine *engine,
	struct game *game,
	struct input *input,
	struct render *render)
{
	engine->game = game;
	engine->input = input;
	engine->render = render;
	engine->running = 0;
}

void engine_start(struct engine *engine)
{
	/* Avoid any possibility of accidental recursion. */
	if (engine->running)
		return;

	engine->running = 1;

	while (engine->running) {
		render_update(engine->render);
		input_update(engine->input);
		game_update(engine->game);
	}
}

void engine_stop(struct engine *engine)
{
	engine->running = 0;
}
