#include "game/player_action/player_action.h"

void player_action_move(struct world *world, enum compass direction)
{
	struct position destination;

	destination = position_add(world->player.position, compass_to_positon(direction));

	if (map_out_of_bounds(destination.x, destination.y))
		return;
	
	if (map_is_wall(&world->map, destination.x, destination.y))
		return;

	world->player.position = destination;
}
