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
	/* TODO: Create config and rely on keybinds. */
	int terminal_input;

	input->world->input_game_action = INPUT_GAME_ACTION_NONE;
	input->world->input_ui_action = INPUT_UI_ACTION_NONE;
	input->world->input_system_action = INPUT_SYSTEM_ACTION_NONE;
	
	terminal_input = terminal_read();

	switch (terminal_input) {
	case TK_W:
		input->world->input_game_action = INPUT_GAME_ACTION_MOVE_NORTH;
		input->world->input_ui_action = INPUT_UI_ACTION_UP;
		break;
	case TK_A:
		input->world->input_game_action = INPUT_GAME_ACTION_MOVE_WEST;
		input->world->input_ui_action = INPUT_UI_ACTION_LEFT;
		break;
	case TK_S:
		input->world->input_game_action = INPUT_GAME_ACTION_MOVE_SOUTH;
		input->world->input_ui_action = INPUT_UI_ACTION_DOWN;
		break;
	case TK_D:
		input->world->input_game_action = INPUT_GAME_ACTION_MOVE_EAST;
		input->world->input_ui_action = INPUT_UI_ACTION_RIGHT;
		break;
	case TK_SPACE:
		input->world->input_game_action = INPUT_GAME_ACTION_REST;
		break;
	case TK_ENTER:
		input->world->input_ui_action = INPUT_UI_ACTION_SUBMIT;
		break;
	case TK_CLOSE:
		input->world->input_system_action = INPUT_SYSTEM_ACTION_QUIT;
		break;
	default:
		break;
	}
}
