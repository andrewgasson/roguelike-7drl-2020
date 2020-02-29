#include "game/game_state/game_state.h"

#include "game/player_action/player_action.h"

void game_state_default(struct game *game)
{
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
