#include "game/player_action/player_action.h"

void player_action_move(struct world *world, enum compass direction)
{
	struct position destination;

	destination = position_add(world->player.position, compass_to_positon(direction));

	world->player.position = destination;
}
