#ifndef GAME_STATE_H
#define GAME_STATE_H

struct game;

#include "game/game.h"

struct game_state {
	void (*start)(struct game *game);
	void (*update)(struct game *game);
	void (*stop)(struct game *game);
};

const struct game_state GAME_STATE_DEFAULT;
const struct game_state GAME_STATE_MAIN_MENU;
const struct game_state GAME_STATE_NEW_GAME;
const struct game_state GAME_STATE_PAUSE_MENU;

#endif
