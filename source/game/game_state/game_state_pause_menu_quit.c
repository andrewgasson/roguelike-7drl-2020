#include "game/game_state/game_state.h"

static void on_start(struct game *game)
{
	game->gui->pause_menu.enabled = 0;

	gui_prompt_bool_reset(&game->gui->prompt_bool);

	game->gui->prompt_bool.enabled = 1;
	game->gui->prompt_bool.question_text = "Are you sure you want to quit?";
	game->gui->prompt_bool.yes_text = GUI_PROMPT_BOOL_TEXT_YES;
	game->gui->prompt_bool.no_text = GUI_PROMPT_BOOL_TEXT_NO;
	game->gui->prompt_bool.choice = 0;
}

static void on_update(struct game *game)
{
	switch (game->input->ui_action) {
	case GUI_PROMPT_BOOL_INPUT_YES:
		game->gui->prompt_bool.choice = 1;
		break;
	case GUI_PROMPT_BOOL_INPUT_NO:
		game->gui->prompt_bool.choice = 0;
		break;
	case INPUT_UI_ACTION_SUBMIT:
		if (game->gui->prompt_bool.choice)
			game_set_state(game, &GAME_STATE_MAIN_MENU);
		else
			game_pop_state(game);
		break;
	default:
		break;
	}
}

static void on_stop(struct game *game)
{
	game->gui->pause_menu.enabled = 1;
	game->gui->prompt_bool.enabled = 0;
}

const struct game_state GAME_STATE_PAUSE_MENU_QUIT = { on_start, on_update, on_stop };
