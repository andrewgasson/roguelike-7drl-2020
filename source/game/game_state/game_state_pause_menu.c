#include "game/game_state/game_state.h"

#include <stddef.h>

static void on_start(struct game *game)
{
	game->gui->pause_menu.enabled = 1;
	game->gui->pause_menu.cursor_state = GUI_PAUSE_MENU_CURSOR_STATE_DEFAULT;
}

static void on_update(struct game *game)
{
	switch (game->input->ui_action) {
	case INPUT_UI_ACTION_UP:
		gui_pause_menu_cursor_back(&game->gui->pause_menu);
		break;
	case INPUT_UI_ACTION_DOWN:
		gui_pause_menu_cursor_next(&game->gui->pause_menu);
		break;
	case INPUT_UI_ACTION_SUBMIT:
		switch (game->gui->pause_menu.cursor_state) {
		case GUI_PAUSE_MENU_CURSOR_STATE_RESUME:
			game_pop_state(game);
			break;
		case GUI_PAUSE_MENU_CURSOR_STATE_QUIT_TO_MAIN_MENU:
			game_push_state(game, &GAME_STATE_PAUSE_MENU_QUIT);
			break;
		default:
			break;
		}
		break;
	case INPUT_UI_ACTION_TOGGLE_PAUSE_MENU:
		game_pop_state(game);
		break;
	default:
		break;
	}
}

static void on_stop(struct game *game)
{
	game->gui->pause_menu.enabled = 0;
}

const struct game_state GAME_STATE_PAUSE_MENU = { on_start, on_update, on_stop };
