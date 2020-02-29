#include "game/game.h"

#include "game/player_action/player_action.h"
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
	/* TODO: Change to state machine. */
	
	switch (game->world->input_game_action) {
	case INPUT_GAME_ACTION_MOVE_NORTH:
		player_action_move(game->world, COMPASS_NORTH);
		break;
	case INPUT_GAME_ACTION_MOVE_EAST:
		player_action_move(game->world, COMPASS_EAST);
		break;
	case INPUT_GAME_ACTION_MOVE_SOUTH:
		player_action_move(game->world, COMPASS_SOUTH);
		break;
	case INPUT_GAME_ACTION_MOVE_WEST:
		player_action_move(game->world, COMPASS_WEST);
		break;
	case INPUT_GAME_ACTION_REST:
		player_action_rest(game->world);
		break;
	default:
		break;
	}
}
