#ifndef PLAYER_ACTION_H
#define PLAYER_ACTION_H

#include "world/compass.h"
#include "world/world.h"

void player_action_move(struct world *world, enum compass direction);

void player_action_rest(struct world *world);

#endif
