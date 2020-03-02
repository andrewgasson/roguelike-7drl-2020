#include "game/game_state/game_state.h"

#include <stddef.h>

static void on_start(struct game *game)
{
	game->gui->main_menu.enabled = 1;
	game->gui->main_menu.cursor_state = GUI_MAIN_MENU_CURSOR_STATE_DEFAULT;
}

static void on_update(struct game *game)
{
	switch (game->input->ui_action) {
	case INPUT_UI_ACTION_UP:
		gui_main_menu_cursor_back(&game->gui->main_menu);
		break;
	case INPUT_UI_ACTION_DOWN:
		gui_main_menu_cursor_next(&game->gui->main_menu);
		break;
	case INPUT_UI_ACTION_SUBMIT:
		switch (game->gui->main_menu.cursor_state) {
		case GUI_MAIN_MENU_CURSOR_STATE_NEW_GAME:
			game_set_state(game, &GAME_STATE_NEW_GAME);
			break;
		case GUI_MAIN_MENU_CURSOR_STATE_QUIT:
			engine_stop(game->engine);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

static void on_stop(struct game *game)
{
	game->gui->main_menu.enabled = 0;
}

const struct game_state GAME_STATE_MAIN_MENU = { on_start, on_update, on_stop };
