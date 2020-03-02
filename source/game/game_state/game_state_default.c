#include "game/game_state/game_state.h"

#include "game/player_action/player_action.h"
#include <stddef.h>

static void on_update(struct game *game)
{
	if (game->input->ui_action == INPUT_UI_ACTION_TOGGLE_PAUSE_MENU) {
		game_set_state(game, &GAME_STATE_PAUSE_MENU);
		return;
	}

	switch (game->input->game_action) {
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

const struct game_state GAME_STATE_DEFAULT = { NULL, on_update, NULL };
