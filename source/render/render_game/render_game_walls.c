#include "render/render_game/render_game.h"

#include "BearLibTerminal.h"

void render_game_walls(struct render *render)
{
	int x;
	int y;

	terminal_bkcolor(color_from_argb(255, 0, 0, 0));
	terminal_color(color_from_argb(255, 64, 64, 64));

	for (y = 0; y < MAP_HEIGHT; y++) {
		for (x = 0; x < MAP_WIDTH; x++) {
			if (render->world->map.wall[map_index(x, y)])
				terminal_put(x, y, '#');
			else
				terminal_put(x, y, '.');
		}
	}
}
