#include "engine/engine.h"
#include "game/game.h"
#include "input/input.h"
#include "render/render.h"
#include "world/world.h"
#include "BearLibTerminal.h"

int main(void)
{
	struct engine *engine;
	struct game *game;
	struct input *input;
	struct render *render;
	struct world *world;

	engine = engine_create();
	game = game_create();
	input = input_create();
	render = render_create();
	world = world_create();

	engine_init(engine, game, input, render, world);
	game_init(game, world);
	input_init(input, world);
	render_init(render, world);
	world_init(world);

	terminal_open();
	terminal_refresh();

	engine_start(engine);

	terminal_close();

	return 0;
}
