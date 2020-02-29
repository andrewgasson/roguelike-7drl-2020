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

void input_init(
	struct input *input,
	struct config *config,
	struct world *world)
{
	input->config = config;
	input->world = world;
}

void input_update(struct input *input)
{
	enum input_game_action game_action;
	enum input_ui_action ui_action;
	enum input_system_action system_action;
	struct input_key_state key_state;

	game_action = INPUT_GAME_ACTION_NONE;
	ui_action = INPUT_UI_ACTION_NONE;
	system_action = INPUT_SYSTEM_ACTION_NONE;

	key_state.key_press = terminal_read();
	key_state.control_held = terminal_state(TK_CONTROL);
	key_state.shift_held = terminal_state(TK_SHIFT);

	/* Window close pressed. */
	if (key_state.key_press == TK_CLOSE) {
		system_action = INPUT_SYSTEM_ACTION_QUIT;
		goto finalize_input;
	}

	/* Set game actions. */
	if (input_keybind_pressed(&input->config->keybind.game_move_north, &key_state))
		game_action = INPUT_GAME_ACTION_MOVE_NORTH;
	else if (input_keybind_pressed(&input->config->keybind.game_move_east, &key_state))
		game_action = INPUT_GAME_ACTION_MOVE_EAST;
	else if (input_keybind_pressed(&input->config->keybind.game_move_south, &key_state))
		game_action = INPUT_GAME_ACTION_MOVE_SOUTH;
	else if (input_keybind_pressed(&input->config->keybind.game_move_west, &key_state))
		game_action = INPUT_GAME_ACTION_MOVE_WEST;
	else if (input_keybind_pressed(&input->config->keybind.game_rest, &key_state))
		game_action = INPUT_GAME_ACTION_REST;

	/* Set UI actions. */
	if (input_keybind_pressed(&input->config->keybind.ui_up, &key_state))
		ui_action = INPUT_UI_ACTION_UP;
	else if (input_keybind_pressed(&input->config->keybind.ui_left, &key_state))
		ui_action = INPUT_UI_ACTION_LEFT;
	else if (input_keybind_pressed(&input->config->keybind.ui_down, &key_state))
		ui_action = INPUT_UI_ACTION_DOWN;
	else if (input_keybind_pressed(&input->config->keybind.ui_right, &key_state))
		ui_action = INPUT_UI_ACTION_RIGHT;
	else if (input_keybind_pressed(&input->config->keybind.ui_submit, &key_state))
		ui_action = INPUT_UI_ACTION_SUBMIT;

finalize_input:
	input->world->input_game_action = game_action;
	input->world->input_ui_action = ui_action;
	input->world->input_system_action = system_action;
}
