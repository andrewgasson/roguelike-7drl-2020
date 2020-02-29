#include "world.h"

#include "game/map_generate/map_generate.h" /* TODO: TEMP */

#include "BearLibTerminal.h"
#include <stdlib.h>

struct world *world_create(void)
{
	struct world *world;

	world = malloc(sizeof(*world));

	return world;
}

void world_destroy(struct world *world)
{
	free(world);
}

void world_init(struct world *world)
{
	world->input_game_action = INPUT_GAME_ACTION_NONE;
	world->input_ui_action = INPUT_UI_ACTION_NONE;
	world->input_system_action = INPUT_SYSTEM_ACTION_NONE;

	world->player.position.x = MAP_WIDTH / 2;
	world->player.position.y = MAP_HEIGHT / 2;
	world->player.glyph.background = color_from_argb(255, 0, 128, 128);
	world->player.glyph.foreground = color_from_argb(255, 255, 0, 0);
	world->player.glyph.symbol = '@';

	/* map_clear(&world->map); */
	/* TODO: TEMP */
	map_generate_demo_box(&world->map);
}
