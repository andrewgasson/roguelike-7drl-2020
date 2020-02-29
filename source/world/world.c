#include "world.h"

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
	world->game_input = TK_INPUT_NONE;

	world->player.x = 0;
	world->player.y = 0;
	world->player.glyph.background = color_from_argb(255, 0, 128, 128);
	world->player.glyph.foreground = color_from_argb(255, 255, 0, 0);
	world->player.glyph.symbol = '@';
}
