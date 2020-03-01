#include "input/input.h"

#include "config/keybind.h"
#include "BearLibTerminal.h"
#include <stdlib.h>
#include <stdio.h>

struct input_key_state {
	int key_press;
	int control_held;
	int shift_held;
};

static int input_keybind_pressed(
	const struct keybind *keybind,
	const struct input_key_state *key_state)
{
	if (keybind->hold_control != key_state->control_held)
		return 0;
	
	if (keybind->hold_shift != key_state->shift_held)
		return 0;
	
	if (keybind->terminal_key_1 != key_state->key_press
	&& keybind->terminal_key_2 != key_state->key_press)
		return 0;

	return 1;
}

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

void input_init(struct input *input, struct config *config)
{
	input->config = config;
	input->game_action = INPUT_GAME_ACTION_NONE;
	input->ui_action = INPUT_UI_ACTION_NONE;
	input->system_action = INPUT_SYSTEM_ACTION_NONE;
}

void input_update(struct input *input)
{
	struct input_key_state key_state;

	/* Clear actions. */
	input->game_action = INPUT_GAME_ACTION_NONE;
	input->ui_action = INPUT_UI_ACTION_NONE;
	input->system_action = INPUT_SYSTEM_ACTION_NONE;

	/* Store input state. */
	key_state.key_press = terminal_read();
	key_state.control_held = terminal_state(TK_CONTROL);
	key_state.shift_held = terminal_state(TK_SHIFT);

	/* Window close button pressed. */
	if (key_state.key_press == TK_CLOSE) {
		input->system_action = INPUT_SYSTEM_ACTION_QUIT;
		return;
	}

	/* Set game actions. */
	if (input_keybind_pressed(&input->config->keybind.game_move_north, &key_state))
		input->game_action = INPUT_GAME_ACTION_MOVE_NORTH;
	else if (input_keybind_pressed(&input->config->keybind.game_move_east, &key_state))
		input->game_action = INPUT_GAME_ACTION_MOVE_EAST;
	else if (input_keybind_pressed(&input->config->keybind.game_move_south, &key_state))
		input->game_action = INPUT_GAME_ACTION_MOVE_SOUTH;
	else if (input_keybind_pressed(&input->config->keybind.game_move_west, &key_state))
		input->game_action = INPUT_GAME_ACTION_MOVE_WEST;
	else if (input_keybind_pressed(&input->config->keybind.game_rest, &key_state))
		input->game_action = INPUT_GAME_ACTION_REST;

	/* Set UI actions. */
	if (input_keybind_pressed(&input->config->keybind.ui_up, &key_state))
		input->ui_action = INPUT_UI_ACTION_UP;
	else if (input_keybind_pressed(&input->config->keybind.ui_left, &key_state))
		input->ui_action = INPUT_UI_ACTION_LEFT;
	else if (input_keybind_pressed(&input->config->keybind.ui_down, &key_state))
		input->ui_action = INPUT_UI_ACTION_DOWN;
	else if (input_keybind_pressed(&input->config->keybind.ui_right, &key_state))
		input->ui_action = INPUT_UI_ACTION_RIGHT;
	else if (input_keybind_pressed(&input->config->keybind.ui_submit, &key_state))
		input->ui_action = INPUT_UI_ACTION_SUBMIT;
	else if (input_keybind_pressed(&input->config->keybind.ui_open_pause_menu, &key_state))
		input->ui_action = INPUT_UI_ACTION_OPEN_PAUSE_MENU;
}
