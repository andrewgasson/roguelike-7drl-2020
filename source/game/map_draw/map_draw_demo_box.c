#include "game/map_draw/map_draw.h"

void map_draw_demo_box(struct map *map)
{
	int x;
	int y;

	for (y = 0; y < MAP_HEIGHT; y++) {
		for (x = 0; x < MAP_WIDTH; x++) {
			if (x == 0 || y == 0 || x == MAP_WIDTH - 1 || y == MAP_HEIGHT - 1)
				map->wall[map_index(x, y)] = 1;
			else
				map->wall[map_index(x, y)] = 0;
		}
	}
}
