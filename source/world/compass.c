#include "world/compass.h"

struct position compass_to_positon(enum compass compass)
{
	struct position result;

	/* Position are relative to the screen: 0,0 is top-left. */
	switch (compass) {
	case COMPASS_NORTH:
		result.x = 0;
		result.y = -1;
		break;
	case COMPASS_EAST:
		result.x = 1;
		result.y = 0;
		break;
	case COMPASS_SOUTH:
		result.x = 0;
		result.y = 1;
		break;
	case COMPASS_WEST:
		result.x = -1;
		result.y = 0;
		break;
	default:
		result.x = 0;
		result.y = 0;
		break;
	}

	return result;
}
