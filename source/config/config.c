#include "config/config.h"

#include "BearLibTerminal.h"
#include <stdlib.h>

const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_NORTH = { 0, 0, TK_UP, TK_KP_8 };
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_EAST = { 0, 0, TK_RIGHT, TK_KP_6 };
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_SOUTH = { 0, 0, TK_DOWN, TK_KP_2 };
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_WEST = { 0, 0, TK_LEFT, TK_KP_4 };
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_REST = { 0, 0, TK_SPACE, TK_KP_5 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_UP = { 0, 0, TK_UP, TK_KP_8 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_LEFT = { 0, 0, TK_LEFT, TK_KP_4 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_DOWN = { 0, 0, TK_DOWN, TK_KP_2 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_RIGHT = { 0, 0, TK_RIGHT, TK_KP_6 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_SUBMIT = { 0, 0, TK_ENTER, TK_KP_0 };

struct config *config_create(void)
{
	struct config *config;

	config = malloc(sizeof(*config));

	return config;
}

void config_destroy(struct config *config)
{
	free(config);
}

void config_init(struct config *config)
{
	config->keybind.game_move_north = CONFIG_DEFAULT_KEYBIND_GAME_MOVE_NORTH;
	config->keybind.game_move_east = CONFIG_DEFAULT_KEYBIND_GAME_MOVE_EAST;
	config->keybind.game_move_south = CONFIG_DEFAULT_KEYBIND_GAME_MOVE_SOUTH;
	config->keybind.game_move_west = CONFIG_DEFAULT_KEYBIND_GAME_MOVE_WEST;
	config->keybind.ui_up = CONFIG_DEFAULT_KEYBIND_UI_UP;
	config->keybind.ui_left = CONFIG_DEFAULT_KEYBIND_UI_LEFT;
	config->keybind.ui_down = CONFIG_DEFAULT_KEYBIND_UI_DOWN;
	config->keybind.ui_right = CONFIG_DEFAULT_KEYBIND_UI_RIGHT;
	config->keybind.ui_submit = CONFIG_DEFAULT_KEYBIND_UI_SUBMIT;
}

void config_load(struct config *config, const char *filepath)
{
	/* TODO: Implement. */
}

void config_save(struct config *config, const char *filepath)
{
	/* TODO: Implement. */
}
