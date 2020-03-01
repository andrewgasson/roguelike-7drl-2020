#include "config/config.h"
#include "engine/engine.h"
#include "game/game.h"
#include "gui/gui.h"
#include "input/input.h"
#include "render/render.h"
#include "world/world.h"
#include "BearLibTerminal.h"

int main(void)
{
	struct config *config;
	struct engine *engine;
	struct game *game;
	struct gui *gui;
	struct input *input;
	struct render *render;
	struct world *world;

	config = config_create();
	engine = engine_create();
	game = game_create();
	gui = gui_create();
	input = input_create();
	render = render_create();
	world = world_create();

	config_init(config);
	engine_init(engine, game, input, render);
	game_init(game, engine, gui, input, world);
	gui_init(gui);
	input_init(input, config);
	render_init(render, gui, world);
	world_init(world);

	game_set_state(game, &GAME_STATE_MAIN_MENU);

	terminal_open();
	terminal_refresh();

	engine_start(engine);

	terminal_close();

	return 0;
}
