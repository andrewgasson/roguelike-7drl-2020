#ifndef GAME_H
#define GAME_H

#include "engine/engine.h"
#include "game/game_state/game_state.h"
#include "gui/gui.h"
#include "input/input.h"
#include "world/world.h"

#define GAME_MAX_STATE_COUNT 4

struct game {
	struct engine *engine;
	struct gui *gui;
	struct input *input;
	struct world *world;
	int top_state_index;
	const struct game_state *state[GAME_MAX_STATE_COUNT];
};

struct game *game_create(void);

void game_destroy(struct game *game);

void game_init(
	struct game *game,
	struct engine *engine,
	struct gui *gui,
	struct input *input,
	struct world *world);

/* Clears all state layers before setting the bottom state. Each state layer 
 * will have their stop function called (if not NULL).
 */
void game_set_state(struct game *game, const struct game_state *state);

/* Pushes the state onto the stack. Returns 0 if the stack as full, and 1 
 * otherwise.
 */
int game_push_state(struct game *game, const struct game_state *state);

/* Removes a state from the stack. If there is a remaining state on the stack 
 * (the base state does not count), returns 1, otherwise, returns 0. If you 
 * want to pop all states, and set the base, you should just use 
 * game_set_state(). 
 */
int game_pop_state(struct game *game);

/* Returns the next highest state on the stack (not the current stack, but the 
 * next one if popped), or NULL if the next state is the base state.
 */
const struct game_state *game_peek_state(struct game *game);

/* Returns the currently active state (the highest available on the stack).
 */
const struct game_state *game_current_state(struct game *game);

void game_update(struct game *game);

#endif
