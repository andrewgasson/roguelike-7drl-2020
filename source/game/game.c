#include "game/game.h"

#include <stdlib.h>

struct game *game_create(void)
{
	struct game *game;

	game = malloc(sizeof(*game));

	return game;
}

void game_destroy(struct game *game)
{
	free(game);
}

void game_init(struct game *game, struct world *world)
{
	game->world = world;
}

void game_update(struct game *game)
{
	switch (game->world->game_input) {
	case TK_W:
		game->world->player.y--;
		break;
	case TK_A:
		game->world->player.x--;
		break;
	case TK_S:
		game->world->player.y++;
		break;
	case TK_D:
		game->world->player.x++;
		break;
	default:
		break;
	}
}
