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

void game_init(struct game *game, struct engine *engine, struct world *world)
{
	game->engine = engine;
	game->world = world;
	game->state = game_state_default;
}

void game_update(struct game *game)
{
	if (game->state == NULL)
		game->state = game_state_default;

	/* TODO: If the player cannot take an action, handle all turns until
	 * they can.
	 */
	
	/* TODO: Update camera position. */

	/* Update game state. */
	game->state(game);
}
