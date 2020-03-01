#ifndef GAME_STATE_H
#define GAME_STATE_H

struct game;

#include "game/game.h"

struct game_state {
	void (*start)(struct game *game);
	void (*update)(struct game *game);
	void (*stop)(struct game *game);
};

const struct game_state game_state_default;

#endif
