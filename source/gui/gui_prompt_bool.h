#ifndef GUI_PROMPT_BOOL
#define GUI_PROMPT_BOOL

#include <stddef.h>

/* Positive */
#define GUI_PROMPT_BOOL_TEXT_ACCEPT "Accept"
#define GUI_PROMPT_BOOL_TEXT_TRUE "True"
#define GUI_PROMPT_BOOL_TEXT_YES "Yes"

/* Negative */
#define GUI_PROMPT_BOOL_TEXT_CANCEL "Cancel"
#define GUI_PROMPT_BOOL_TEXT_DECLINE "Decline"
#define GUI_PROMPT_BOOL_TEXT_NO "No"

/* Default */
#define GUI_PROMPT_BOOL_DEFAULT_QUESTION_TEXT NULL
#define GUI_PROMPT_BOOL_DEFAULT_YES_TEXT GUI_PROMPT_BOOL_TEXT_YES
#define GUI_PROMPT_BOOL_DEFAULT_NO_TEXT GUI_PROMPT_BOOL_TEXT_NO

#define GUI_PROMPT_BOOL_INPUT_YES INPUT_UI_ACTION_LEFT
#define GUI_PROMPT_BOOL_INPUT_NO INPUT_UI_ACTION_RIGHT

struct gui_prompt_bool {
	int enabled;
	const char *question_text;
	const char *yes_text;
	const char *no_text;
	int choice;
};

void gui_prompt_bool_reset(struct gui_prompt_bool *prompt);

#endif
