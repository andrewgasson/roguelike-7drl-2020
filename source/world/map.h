#ifndef MAP_H
#define MAP_H

#define MAP_WIDTH 80
#define MAP_HEIGHT 25
#define MAP_AREA (MAP_WIDTH * MAP_HEIGHT)

struct map {
	int wall[MAP_AREA];
};

int map_index(int x, int y);

int map_is_wall(struct map *map, int x, int y);

int map_out_of_bounds(int x, int y);

void map_clear(struct map *map);

#endif
