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

int world_load(struct world *world, const char *filepath)
{
	FILE *file;

	printf("Attempting to load filepath \"%s\"\n", filepath);

	/* Allocate file based on path. If the file doesn't exist at the path, 
	 * return with error.
	 */
	file = fopen(filepath, "r");

	if (!file)
		return 0;
	
	/* Reset the world to ensure no previous state leaks. */
	world_init(world);

	/* Read the contents of world. */
	fread(world, sizeof(*world), 1, file);

	/* Deallocate */
	fclose(file);

	return 1;
}

int world_save(struct world *world, const char *filepath)
{
	FILE *file;

	printf("Attempting to save to filepath \"%s\"\n", filepath);

	/* Create or override the file at the filepath. If the file could not 
	 * be created or overriden, return with error.
	 */
	file = fopen(filepath, "w");

	if (!file)
		return 0;

	/* Save the contents of world. */
	fwrite(world, sizeof(*world), 1, file);

	/* Deallocate */
	fclose(file);

	return 1;
}
