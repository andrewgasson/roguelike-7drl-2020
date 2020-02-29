#ifndef POSITION_H
#define POSITION_H

struct position {
	int x;
	int y;
};

int position_are_equal(struct position lhs, struct position rhs);

struct position position_add(struct position lhs, struct position rhs);

struct position position_subtract(struct position lhs, struct position rhs);

#endif
