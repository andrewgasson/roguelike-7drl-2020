#include "config/config.h"
#include "engine/engine.h"
#include "game/game.h"
#include "gui/gui.h"
#include "input/input.h"
#include "render/render.h"
#include "world/world.h"
#include "BearLibTerminal.h"

#include <stdio.h>

int main(void)
{
	static struct config *config;
	static struct engine *engine;
	static struct game *game;
	static struct gui *gui;
	static struct input *input;
	static struct render *render;
	static struct world *world;

	config = config_create();
	engine = engine_create();
	game = game_create();
	gui = gui_create();
	input = input_create();
	render = render_create();
	world = world_create();

	config_init(config);
	engine_init(engine, game, input, render);
	game_init(game, config, engine, gui, input, world);
	gui_init(gui);
	input_init(input, config);
	render_init(render, gui, world);
	world_init(world);

	config_load(config, CONFIG_DEFAULT_FILEPATH);
	game_set_state(game, &GAME_STATE_MAIN_MENU);

	terminal_open();
	terminal_refresh();

	engine_start(engine);

	terminal_close();

	return 0;
}
