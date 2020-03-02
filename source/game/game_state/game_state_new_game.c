#include "game/game_state/game_state.h"

#include <stddef.h>

static void on_start(struct game *game)
{
	/* Clear the world. Beware, world_init() may or may not allocate in the 
	 * future. In which case, we'd probably call some sort of world_reset()
	 * function instead.
	 */
	world_init(game->world);

	/* For now, just move on to the default game state. In the future, we'd
	 * also probably call the map_draw_hub_town() function, and/or have a 
	 * sub state system for character creation.
	 */ 
	game_set_state(game, &GAME_STATE_DEFAULT);
}

const struct game_state GAME_STATE_NEW_GAME = { on_start, NULL, NULL };
