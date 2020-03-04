#include "config/config.h"

#include "BearLibTerminal.h"
#include "iniparser/iniparser.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_TO_BOOLSTRING(i) (i ? "true" : "false")
#define TK_STRING_TABLE_LENGTH 95

struct tk_string_pair {
	int key;
	const char *string;
};

const struct tk_string_pair tk_string_table[] = {
	{ TK_A, "TK_A" },
	{ TK_B, "TK_B" },
	{ TK_C, "TK_C" },
	{ TK_D, "TK_D" },
	{ TK_E, "TK_E" },
	{ TK_F, "TK_F" },
	{ TK_G, "TK_G" },
	{ TK_H, "TK_H" },
	{ TK_I, "TK_I" },
	{ TK_J, "TK_J" },
	{ TK_K, "TK_K" },
	{ TK_L, "TK_L" },
	{ TK_M, "TK_M" },
	{ TK_N, "TK_N" },
	{ TK_O, "TK_O" },
	{ TK_P, "TK_P" },
	{ TK_Q, "TK_Q" },
	{ TK_R, "TK_R" },
	{ TK_S, "TK_S" },
	{ TK_T, "TK_T" },
	{ TK_U, "TK_U" },
	{ TK_V, "TK_V" },
	{ TK_W, "TK_W" },
	{ TK_X, "TK_X" },
	{ TK_Y, "TK_Y" },
	{ TK_Z, "TK_Z" },
	{ TK_1, "TK_1" },
	{ TK_2, "TK_2" },
	{ TK_3, "TK_3" },
	{ TK_4, "TK_4" },
	{ TK_5, "TK_5" },
	{ TK_6, "TK_6" },
	{ TK_7, "TK_7" },
	{ TK_8, "TK_8" },
	{ TK_9, "TK_9" },
	{ TK_0, "TK_0" },
	{ TK_ENTER, "TK_ENTER" },
	{ TK_RETURN, "TK_RETURN" },
	{ TK_ESCAPE, "TK_ESCAPE" },
	{ TK_BACKSPACE, "TK_BACKSPACE" },
	{ TK_TAB, "TK_TAB" },
	{ TK_SPACE, "TK_SPACE" },
	{ TK_MINUS, "TK_MINUS" },
	{ TK_EQUALS, "TK_EQUALS" },
	{ TK_LBRACKET, "TK_LBRACKET" },
	{ TK_RBRACKET, "TK_RBRACKET" },
	{ TK_BACKSLASH, "TK_BACKSLASH" },
	{ TK_SEMICOLON, "TK_SEMICOLON" },
	{ TK_APOSTROPHE, "TK_APOSTROPHE" },
	{ TK_GRAVE, "TK_GRAVE" },
	{ TK_COMMA, "TK_COMMA" },
	{ TK_PERIOD, "TK_PERIOD" },
	{ TK_SLASH, "TK_SLASH" },
	{ TK_F1, "TK_F1" },
	{ TK_F2, "TK_F2" },
	{ TK_F3, "TK_F3" },
	{ TK_F4, "TK_F4" },
	{ TK_F5, "TK_F5" },
	{ TK_F6, "TK_F6" },
	{ TK_F7, "TK_F7" },
	{ TK_F8, "TK_F8" },
	{ TK_F9, "TK_F9" },
	{ TK_F10, "TK_F10" },
	{ TK_F11, "TK_F11" },
	{ TK_F12, "TK_F12" },
	{ TK_PAUSE, "TK_PAUSE" },
	{ TK_INSERT, "TK_INSERT" },
	{ TK_HOME, "TK_HOME" },
	{ TK_PAGEUP, "TK_PAGE_UP" },
	{ TK_DELETE, "TK_DELETE" },
	{ TK_END, "TK_END" },
	{ TK_PAGEDOWN, "TK_PAGEDOWN" },
	{ TK_RIGHT, "TK_RIGHT" },
	{ TK_LEFT, "TK_LEFT" },
	{ TK_DOWN, "TK_DOWN" },
	{ TK_UP, "TK_UP" },
	{ TK_KP_DIVIDE, "TK_KP_DIVIDE" },
	{ TK_KP_MULTIPLY, "TK_KP_MULTIPLY" },
	{ TK_KP_MINUS, "TK_KP_MINUS" },
	{ TK_KP_PLUS, "TK_KP_PLUS" },
	{ TK_KP_ENTER, "TK_KP_ENTER" },
	{ TK_KP_1, "TK_KP_1" },
	{ TK_KP_2, "TK_KP_2" },
	{ TK_KP_3, "TK_KP_3" },
	{ TK_KP_4, "TK_KP_4" },
	{ TK_KP_5, "TK_KP_5" },
	{ TK_KP_6, "TK_KP_6" },
	{ TK_KP_7, "TK_KP_7" },
	{ TK_KP_8, "TK_KP_8" },
	{ TK_KP_9, "TK_KP_9" },
	{ TK_KP_0, "TK_KP_0" },
	{ TK_KP_PERIOD, "TK_KP_PERIOD" },
	{ TK_SHIFT, "TK_SHIFT" },
	{ TK_CONTROL, "TK_CONTROL" },
	{ TK_ALT, "TK_ALT" }
};

const char * const CONFIG_DEFAULT_DIRECTORY_SAVE_FOLDER = "test.txt"; /* TODO: folders don't work... */

const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_NORTH = { TK_UP, TK_KP_8, 0, 0, 0 };
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_EAST = { TK_RIGHT, TK_KP_6, 0, 0, 0 };
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_SOUTH = { TK_DOWN, TK_KP_2, 0, 0, 0 };
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_MOVE_WEST = { TK_LEFT, TK_KP_4, 0, 0, 0 };
const struct keybind CONFIG_DEFAULT_KEYBIND_GAME_REST = { TK_SPACE, TK_KP_5, 0, 0, 0 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_UP = { TK_UP, TK_KP_8, 0, 0, 0 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_RIGHT = { TK_RIGHT, TK_KP_6, 0, 0, 0 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_DOWN = { TK_DOWN, TK_KP_2, 0, 0, 0 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_LEFT = { TK_LEFT, TK_KP_4, 0, 0, 0 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_SUBMIT = { TK_ENTER, TK_KP_ENTER, 0, 0, 0 };
const struct keybind CONFIG_DEFAULT_KEYBIND_UI_TOGGLE_PAUSE_MENU = { TK_ESCAPE, TK_KP_MINUS, 0, 0, 0 };

/* Note, this only really deals with ASCII symbols. Fine for our usecase here, 
 * but if there are locale errors down the line, coming from config, it's 
 * probably this.
 */
static void config_normalize_string(char *destination, const char *source)
{
	int i;

	for (i = 0; source[i]; i++) {
		destination[i] = toupper(source[i]);
	}

	destination[i] = '\0';
}

/* If the key is found, return the key as a string, otherwise returns NULL. */
static const char *config_tk_to_string(int tk_key)
{
	int i;

	for (i = 0; i < TK_STRING_TABLE_LENGTH; i++) {
		if (tk_string_table[i].key == tk_key)
			return tk_string_table[i].string;
	}

	return NULL;
}

/* If the string is found, returns the TK key id, otherwise returns -1. */
static int config_string_to_tk(const char *tk_string)
{
	int i;
	char *normalised_string;

	if (!tk_string)
		return -1;

	normalised_string = malloc(strlen(tk_string) * sizeof(*normalised_string));
	config_normalize_string(normalised_string, tk_string);

	for (i = 0; i < TK_STRING_TABLE_LENGTH; i++) {
		if (strcmp(normalised_string, tk_string_table[i].string) == 0)
			return tk_string_table[i].key;
	}

	free(normalised_string);

	return -1;
}

static void config_load_directory(dictionary *ini_dictionary, const char *ini_key, char *directory)
{
	const char *parsed_directory;
	
	parsed_directory = iniparser_getstring(ini_dictionary, "directory:save_folder", NULL);
	
	if (parsed_directory)
		strcpy(directory, parsed_directory);
}

static void config_load_keybind(dictionary *ini_dictionary, const char *ini_key, struct keybind *keybind)
{
	int key;
	int key_alternative;
	int hold_alt;
	int hold_control;
	int hold_shift;
	char *key_full_string;

	/* The 24 is additional space for appending the dot struct value, for 
	 * example: ".hold_shift" is 11 characters, and would fit within this 
	 * additional 24 character space.
	 */
	key_full_string = malloc(strlen(ini_key) + 24 * sizeof(*key_full_string));

	strcpy(key_full_string, ini_key);
	strcat(key_full_string, ".key");
	key = config_string_to_tk(iniparser_getstring(ini_dictionary, key_full_string, NULL));

	strcpy(key_full_string, ini_key);
	strcat(key_full_string, ".key_alternative");
	key_alternative = config_string_to_tk(iniparser_getstring(ini_dictionary, key_full_string, NULL));

	strcpy(key_full_string, ini_key);
	strcat(key_full_string, ".hold_alt");
	hold_alt = iniparser_getboolean(ini_dictionary, key_full_string, -1);
	
	strcpy(key_full_string, ini_key);
	strcat(key_full_string, ".hold_control");
	hold_control = iniparser_getboolean(ini_dictionary, key_full_string, -1);

	strcpy(key_full_string, ini_key);
	strcat(key_full_string, ".hold_shift");
	hold_shift = iniparser_getboolean(ini_dictionary, key_full_string, -1);

	if (key != -1)
		keybind->key = key;
	
	if (key_alternative != -1)
		keybind->key_alternative = key_alternative;
	
	if (hold_alt != -1)
		keybind->hold_alt = hold_alt;

	if (hold_control != -1)
		keybind->hold_control = hold_control;

	if (hold_shift != -1)
		keybind->hold_shift = hold_shift;
	
	free(key_full_string);
}

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
	strcpy(config->directory.save_folder, CONFIG_DEFAULT_DIRECTORY_SAVE_FOLDER);

	config->keybind.game_move_north = CONFIG_DEFAULT_KEYBIND_GAME_MOVE_NORTH;
	config->keybind.game_move_east = CONFIG_DEFAULT_KEYBIND_GAME_MOVE_EAST;
	config->keybind.game_move_south = CONFIG_DEFAULT_KEYBIND_GAME_MOVE_SOUTH;
	config->keybind.game_move_west = CONFIG_DEFAULT_KEYBIND_GAME_MOVE_WEST;
	config->keybind.game_rest = CONFIG_DEFAULT_KEYBIND_GAME_REST;
	config->keybind.ui_up = CONFIG_DEFAULT_KEYBIND_UI_UP;
	config->keybind.ui_right = CONFIG_DEFAULT_KEYBIND_UI_RIGHT;
	config->keybind.ui_down = CONFIG_DEFAULT_KEYBIND_UI_DOWN;
	config->keybind.ui_left = CONFIG_DEFAULT_KEYBIND_UI_LEFT;
	config->keybind.ui_submit = CONFIG_DEFAULT_KEYBIND_UI_SUBMIT;
	config->keybind.ui_toggle_pause_menu = CONFIG_DEFAULT_KEYBIND_UI_TOGGLE_PAUSE_MENU;
}

void config_load(struct config *config, const char *filepath)
{
	dictionary *ini_dictionary;

	/* All functions rely on have the default state as a base. */
	config_init(config);

	ini_dictionary = iniparser_load(filepath);

	if (!ini_dictionary) {
		config_save(config, filepath);
		return;
	}

	config_load_directory(ini_dictionary, "directory:save_folder", config->directory.save_folder);

	config_load_keybind(ini_dictionary, "keybind:game_move_north", &config->keybind.game_move_north);
	config_load_keybind(ini_dictionary, "keybind:game_move_east", &config->keybind.game_move_east);
	config_load_keybind(ini_dictionary, "keybind:game_move_south", &config->keybind.game_move_south);
	config_load_keybind(ini_dictionary, "keybind:game_move_west", &config->keybind.game_move_west);
	config_load_keybind(ini_dictionary, "keybind:game_rest", &config->keybind.game_rest);
	config_load_keybind(ini_dictionary, "keybind:ui_up", &config->keybind.ui_up);
	config_load_keybind(ini_dictionary, "keybind:ui_right", &config->keybind.ui_right);
	config_load_keybind(ini_dictionary, "keybind:ui_down", &config->keybind.ui_down);
	config_load_keybind(ini_dictionary, "keybind:ui_left", &config->keybind.ui_left);
	config_load_keybind(ini_dictionary, "keybind:ui_submit", &config->keybind.ui_submit);
	config_load_keybind(ini_dictionary, "keybind:ui_toggle_pause_menu", &config->keybind.ui_toggle_pause_menu);

	iniparser_freedict(ini_dictionary);
}

void config_save(struct config *config, const char *filepath)
{
	FILE *ini_file;

	ini_file = fopen(filepath, "w");

	if (!ini_file)
		return;

	fprintf(ini_file, "[directory]\n");
	fprintf(ini_file, "save_folder = %s\n\n", config->directory.save_folder);

	fprintf(ini_file, "[keybind]\n");
	fprintf(ini_file, "game_move_north.key = %s\n", config_tk_to_string(config->keybind.game_move_north.key));
	fprintf(ini_file, "game_move_north.key_alternative = %s\n", config_tk_to_string(config->keybind.game_move_north.key_alternative));
	fprintf(ini_file, "game_move_north.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.game_move_north.hold_alt));
	fprintf(ini_file, "game_move_north.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.game_move_north.hold_shift));
	fprintf(ini_file, "game_move_north.hold_control = %s\n\n", INT_TO_BOOLSTRING(config->keybind.game_move_north.hold_control));

	fprintf(ini_file, "game_move_east.key = %s\n", config_tk_to_string(config->keybind.game_move_east.key));
	fprintf(ini_file, "game_move_east.key_alternative = %s\n", config_tk_to_string(config->keybind.game_move_east.key_alternative));
	fprintf(ini_file, "game_move_east.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.game_move_east.hold_alt));
	fprintf(ini_file, "game_move_east.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.game_move_east.hold_shift));
	fprintf(ini_file, "game_move_east.hold_control = %s\n\n", INT_TO_BOOLSTRING(config->keybind.game_move_east.hold_control));

	fprintf(ini_file, "game_move_south.key = %s\n", config_tk_to_string(config->keybind.game_move_south.key));
	fprintf(ini_file, "game_move_south.key_alternative = %s\n", config_tk_to_string(config->keybind.game_move_south.key_alternative));
	fprintf(ini_file, "game_move_south.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.game_move_south.hold_alt));
	fprintf(ini_file, "game_move_south.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.game_move_south.hold_shift));
	fprintf(ini_file, "game_move_south.hold_control = %s\n\n", INT_TO_BOOLSTRING(config->keybind.game_move_south.hold_control));

	fprintf(ini_file, "game_move_west.key = %s\n", config_tk_to_string(config->keybind.game_move_west.key));
	fprintf(ini_file, "game_move_west.key_alternative = %s\n", config_tk_to_string(config->keybind.game_move_west.key_alternative));
	fprintf(ini_file, "game_move_west.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.game_move_west.hold_alt));
	fprintf(ini_file, "game_move_west.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.game_move_west.hold_shift));
	fprintf(ini_file, "game_move_west.hold_control = %s\n\n", INT_TO_BOOLSTRING(config->keybind.game_move_west.hold_control));

	fprintf(ini_file, "game_rest.key = %s\n", config_tk_to_string(config->keybind.game_rest.key));
	fprintf(ini_file, "game_rest.key_alternative = %s\n", config_tk_to_string(config->keybind.game_rest.key_alternative));
	fprintf(ini_file, "game_rest.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.game_rest.hold_alt));
	fprintf(ini_file, "game_rest.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.game_rest.hold_shift));
	fprintf(ini_file, "game_rest.hold_control = %s\n\n", INT_TO_BOOLSTRING(config->keybind.game_rest.hold_control));

	fprintf(ini_file, "ui_up.key = %s\n", config_tk_to_string(config->keybind.ui_up.key));
	fprintf(ini_file, "ui_up.key_alternative = %s\n", config_tk_to_string(config->keybind.ui_up.key_alternative));
	fprintf(ini_file, "ui_up.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_up.hold_alt));
	fprintf(ini_file, "ui_up.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_up.hold_shift));
	fprintf(ini_file, "ui_up.hold_control = %s\n\n", INT_TO_BOOLSTRING(config->keybind.ui_up.hold_control));

	fprintf(ini_file, "ui_right.key = %s\n", config_tk_to_string(config->keybind.ui_right.key));
	fprintf(ini_file, "ui_right.key_alternative = %s\n", config_tk_to_string(config->keybind.ui_right.key_alternative));
	fprintf(ini_file, "ui_right.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_right.hold_alt));
	fprintf(ini_file, "ui_right.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_right.hold_shift));
	fprintf(ini_file, "ui_right.hold_control = %s\n\n", INT_TO_BOOLSTRING(config->keybind.ui_right.hold_control));

	fprintf(ini_file, "ui_down.key = %s\n", config_tk_to_string(config->keybind.ui_down.key));
	fprintf(ini_file, "ui_down.key_alternative = %s\n", config_tk_to_string(config->keybind.ui_down.key_alternative));
	fprintf(ini_file, "ui_down.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_down.hold_alt));
	fprintf(ini_file, "ui_down.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_down.hold_shift));
	fprintf(ini_file, "ui_down.hold_control = %s\n\n", INT_TO_BOOLSTRING(config->keybind.ui_down.hold_control));

	fprintf(ini_file, "ui_left.key = %s\n", config_tk_to_string(config->keybind.ui_left.key));
	fprintf(ini_file, "ui_left.key_alternative = %s\n", config_tk_to_string(config->keybind.ui_left.key_alternative));
	fprintf(ini_file, "ui_left.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_left.hold_alt));
	fprintf(ini_file, "ui_left.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_left.hold_shift));
	fprintf(ini_file, "ui_left.hold_control = %s\n\n", INT_TO_BOOLSTRING(config->keybind.ui_left.hold_control));

	fprintf(ini_file, "ui_submit.key = %s\n", config_tk_to_string(config->keybind.ui_submit.key));
	fprintf(ini_file, "ui_submit.key_alternative = %s\n", config_tk_to_string(config->keybind.ui_submit.key_alternative));
	fprintf(ini_file, "ui_submit.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_submit.hold_alt));
	fprintf(ini_file, "ui_submit.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_submit.hold_shift));
	fprintf(ini_file, "ui_submit.hold_control = %s\n\n", INT_TO_BOOLSTRING(config->keybind.ui_submit.hold_control));

	fprintf(ini_file, "ui_toggle_pause_menu.key = %s\n", config_tk_to_string(config->keybind.ui_toggle_pause_menu.key));
	fprintf(ini_file, "ui_toggle_pause_menu.key_alternative = %s\n", config_tk_to_string(config->keybind.ui_toggle_pause_menu.key_alternative));
	fprintf(ini_file, "ui_toggle_pause_menu.hold_alt = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_toggle_pause_menu.hold_alt));
	fprintf(ini_file, "ui_toggle_pause_menu.hold_shift = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_toggle_pause_menu.hold_shift));
	fprintf(ini_file, "ui_toggle_pause_menu.hold_control = %s\n", INT_TO_BOOLSTRING(config->keybind.ui_toggle_pause_menu.hold_control));

	fclose(ini_file);
}
