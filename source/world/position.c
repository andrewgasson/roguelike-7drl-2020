#include "world/position.h"

int position_are_equal(struct position lhs, struct position rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

struct position position_add(struct position lhs, struct position rhs)
{
	struct position result;

	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;

	return result;
}

struct position position_subtract(struct position lhs, struct position rhs)
{
	struct position result;

	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;

	return result;
}
