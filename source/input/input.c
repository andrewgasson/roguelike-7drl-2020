#include "input/input.h"

#include "BearLibTerminal.h"
#include <stdlib.h>

struct input *input_create(void)
{
	struct input *input;

	input = malloc(sizeof(*input));

	return input;
}

void input_destroy(struct input *input)
{
	free(input);
}

void input_init(struct input *input, struct world *world)
{
	input->world = world;
}

void input_update(struct input *input)
{
	input->world->game_input = terminal_read();
}
