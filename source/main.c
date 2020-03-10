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

	printf("call: config_init()\n");
	config_init(config);
	printf("call: engine_init()\n");
	engine_init(engine, game, input, render);
	printf("call: game_init()\n");
	game_init(game, config, engine, gui, input, world);
	printf("call: gui_init()\n");
	gui_init(gui);
	printf("call: input_init()\n");
	input_init(input, config);
	printf("call: render_init()\n");
	render_init(render, gui, world);
	printf("call: world_init()\n");
	world_init(world);

	printf("call: config_load(%s)\n", CONFIG_DEFAULT_FILEPATH);
	config_load(config, CONFIG_DEFAULT_FILEPATH);
	printf("call: game_set_state(GAME_STATE_MAIN_MENU)\n");
	game_set_state(game, &GAME_STATE_MAIN_MENU);

	printf("call: terminal_open()\n");
	terminal_open();
	printf("call: terminal_refresh()\n");
	terminal_refresh();

	printf("call: engine_start()\n");
	engine_start(engine);
	
	printf("call: terminal_has_input()\n");
	
	if (terminal_has_input()) {
		printf("call: terminal_read(): FOUND THE BUG!\n");
		terminal_read();
	}


	printf("call: terminal_close()\n");
	terminal_close();

	printf("fin.\n");

	return 0;
}
