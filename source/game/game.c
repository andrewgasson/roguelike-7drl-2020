#include "game/game.h"

#include "game/game_state/game_state.h"
#include <stddef.h>
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

void game_init(
	struct game *game, 
	struct engine *engine,
	struct input *input,
	struct world *world)
{
	game->engine = engine;
	game->input = input;
	game->world = world;
	game->state = NULL;
}

void game_set_state(struct game *game, const struct game_state *state)
{
	if (game->state && game->state->stop)
		game->state->stop(game);

	game->state = state;

	if (game->state->start)
		game->state->start(game);
}

void game_update(struct game *game)
{
	/* Stop the engine if the user decided to quit. */
	if (game->input->system_action == INPUT_SYSTEM_ACTION_QUIT) {
		engine_stop(game->engine);
		return;
	}

	/* TODO: If the player cannot take an action, handle all turns until
	 * they can.
	 */
	
	/* TODO: Update camera position. */

	/* Update game state. */
	if (game->state->update)
		game->state->update(game);
}
