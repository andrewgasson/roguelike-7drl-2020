#ifndef CONFIG_H
#define CONFIG_H

#include "config/keybind.h"

#define CONFIG_DEFAULT_FILEPATH "config.txt"

#define CONFIG_GAME_AUTHOR_UPPERCASE "ANDREW GASSON"
#define CONFIG_GAME_JAM "7DRL 2020"
#define CONFIG_GAME_NAME_UPPERCASE "THE GOLDBAND PROJECT"
#define CONFIG_GAME_VERSION "0.4"

struct config {
	struct {
		struct keybind game_move_north;
		struct keybind game_move_east;
		struct keybind game_move_south;
		struct keybind game_move_west;
		struct keybind game_rest;
		struct keybind ui_up;
		struct keybind ui_right;
		struct keybind ui_down;
		struct keybind ui_left;
		struct keybind ui_submit;
		struct keybind ui_toggle_pause_menu;
	} keybind;
};

const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_NORTH;
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_EAST;
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_SOUTH;
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_WEST;
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_REST;
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_UP;
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_RIGHT;
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_DOWN;
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_LEFT;
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_SUBMIT;
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_TOGGLE_PAUSE_MENU;

struct config *config_create(void);

void config_destroy(struct config *config);

void config_init(struct config *config);

void config_load(struct config *config, const char *filepath);

void config_save(struct config *config, const char *filepath);

#endif
