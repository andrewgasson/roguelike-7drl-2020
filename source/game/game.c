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
	struct config *config,
	struct engine *engine,
	struct gui *gui,
	struct input *input,
	struct world *world)
{
	int i;

	game->config = config;
	game->engine = engine;
	game->gui = gui;
	game->input = input;
	game->world = world;
	game->top_state_index = 0;

	for (i = 0; i < GAME_MAX_STATE_COUNT; i++)
		game->state[i] = NULL;
}

/* Clears all state layers before setting the bottom state. Each state layer 
 * will have their stop function called (if not NULL).
 */
void game_set_state(struct game *game, const struct game_state *state)
{
	int i;

	/* Remove all states, including the base state. */
	for (i = GAME_MAX_STATE_COUNT - 1; i >= 0; i--) {
		if (game->state[i]) {
			if (game->state[i]->stop)
				game->state[i]->stop(game);

			game->state[i] = NULL;
		}
	}

	game->top_state_index = 0;

	/* If the new state is NULL, we don't need to do anything. */
	if (state == NULL)
		return;

	game->state[0] = state;

	if (game->state[0]->start)
		game->state[0]->start(game);
}

/* Pushes the state onto the stack. Returns 0 if the stack as full, and 1 
 * otherwise.
 */
int game_push_state(struct game *game, const struct game_state *state)
{
	/* Stack is full, do nothing. */
	if (game->top_state_index >= GAME_MAX_STATE_COUNT - 1)
		return 0;
	
	game->top_state_index++;
	game->state[game->top_state_index] = state;

	if (game->state[game->top_state_index]->start)
		game->state[game->top_state_index]->start(game);

	return 1;
}

/* Removes a state from the stack. If there is a remaining state on the stack 
 * (the base state does not count), returns 1, otherwise, returns 0. If you 
 * want to pop all states, and set the base, you should just use 
 * game_set_state(). 
 */
int game_pop_state(struct game *game)
{
	if (game->top_state_index > 0) {
		if (game->state[game->top_state_index]->stop)
			game->state[game->top_state_index]->stop(game);

		game->state[game->top_state_index] = NULL;
		game->top_state_index--;

		return 1;
	}

	return 0;
}

/* Returns the next highest state on the stack (not the current stack, but the 
 * next one if popped), or NULL if the next state is the base state.
 */
const struct game_state *game_peek_state(struct game *game)
{
	if (game->top_state_index > 0)
		return game->state[game->top_state_index - 1];

	return NULL;
}

const struct game_state *game_current_state(struct game *game)
{
	return game->state[game->top_state_index];
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

	/* Update top game state. */
	if (game->state[game->top_state_index]->update)
		game->state[game->top_state_index]->update(game);
}
