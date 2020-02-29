#ifndef INPUT_H
#define INPUT_H

#include "world/world.h"

struct input {
	struct world *world;
};

struct input *input_create(void);

void input_destroy(struct input *input);

void input_init(struct input *input, struct world *world);

void input_update(struct input *input);

#endif
