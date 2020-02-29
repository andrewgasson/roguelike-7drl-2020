#ifndef INPUT_H
#define INPUT_H

#include "config/config.h"
#include "world/world.h"

struct input {
	struct config *config;
	struct world *world;
};

struct input *input_create(void);

void input_destroy(struct input *input);

void input_init(
	struct input *input,
	struct config *config,
	struct world *world);

void input_update(struct input *input);

#endif
