#include "world.h"

#include "game/map_draw/map_draw.h" /* TODO: TEMP */

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
	world->player.position.x = MAP_WIDTH / 2;
	world->player.position.y = MAP_HEIGHT / 2;
	world->player.glyph.background = color_from_argb(255, 0, 128, 128);
	world->player.glyph.foreground = color_from_argb(255, 255, 0, 0);
	world->player.glyph.symbol = '@';

	/* map_clear(&world->map); */
	map_draw_demo_box(&world->map); /* TODO: TEMP */
}
