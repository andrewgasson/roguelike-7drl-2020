#include "gui/gui_prompt_bool.h"

void gui_prompt_bool_reset(struct gui_prompt_bool *prompt)
{
	prompt->enabled = 0;
	prompt->question_text = GUI_PROMPT_BOOL_DEFAULT_QUESTION_TEXT;
	prompt->yes_text = GUI_PROMPT_BOOL_DEFAULT_YES_TEXT;
	prompt->no_text = GUI_PROMPT_BOOL_DEFAULT_NO_TEXT;
	prompt->choice = 0;
}
