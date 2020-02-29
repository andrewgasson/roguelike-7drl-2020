#include "game/player_action/player_action.h"

void player_action_move(struct world *world, enum compass direction)
{
	int destination_x;
	int destination_y;

	destination_x = world->player.x;
	destination_y = world->player.y;

	/* TODO: Replace with "business logic" so that we're not guessing the 
	 * directions.
	 */
	switch (direction) {
	case COMPASS_NORTH:
		destination_y--;
		break;
	case COMPASS_EAST:
		destination_x++;
		break;
	case COMPASS_SOUTH:
		destination_y++;
		break;
	case COMPASS_WEST:
		destination_x--;
		break;
	default:
		break;
	}

	world->player.x = destination_x;
	world->player.y = destination_y;
}
