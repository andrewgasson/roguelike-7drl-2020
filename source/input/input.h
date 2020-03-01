#ifndef INPUT_H
#define INPUT_H

#include "config/config.h"
#include "input/input_action.h"

struct input {
	struct config *config;
	enum input_game_action game_action;
	enum input_ui_action ui_action;
	enum input_system_action system_action;
};

struct input *input_create(void);

void input_destroy(struct input *input);

void input_init(struct input *input, struct config *config);

void input_update(struct input *input);

#endif
