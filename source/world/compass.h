#ifndef COMPASS_H
#define COMPASS_H

#include "world/position.h"

enum compass {
	COMPASS_NORTH,
	COMPASS_EAST,
	COMPASS_SOUTH,
	COMPASS_WEST
};

struct position compass_to_positon(enum compass compass);

#endif
