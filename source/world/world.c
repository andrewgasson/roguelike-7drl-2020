#include "world.h"

#include "BearLibTerminal.h"
#include <stdio.h>
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

	map_clear(&world->map);
}

void world_load(struct world *world, FILE *file)
{
	/* Reset the world to ensure no previous state leaks. */
	world_init(world);
	fread(world, sizeof(*world), 1, file);
}

void world_save(struct world *world, FILE *file)
{
	fwrite(world, sizeof(*world), 1, file);
}
