#include "world/map.h"

int map_index(int x, int y)
{
	return y * MAP_WIDTH + x;
}

int map_is_wall(struct map *map, int x, int y)
{
	return map->wall[map_index(x, y)];
}

int map_out_of_bounds(int x, int y)
{
	return x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT;
}

void map_clear(struct map *map)
{
	int i;

	for (i = 0; i < MAP_AREA; i++) {
		map->wall[i] = 0;
	}
}
