#include "render/render_gui/render_gui.h"

#include "BearLibTerminal.h"
#include "render/color_tool/color_tool.h"
#include <string.h>

#define PADDING_TOP 1
#define PADDING_RIGHT 2
#define PADDING_BOTTOM 1
#define PADDING_LEFT 2
#define MODAL_WIDTH 30
#define MODAL_HEIGHT 8
#define BLEND_BKCOLOR_BLEND_ARGB 0x00050505
#define BLEND_COLOR_ARGB 0x00222222

void render_gui_prompt_bool(struct render *render)
{
	int x;
	int y;
	int choice_button_length;

	/* Darken background, to make the prompt stand out. */
	for (y = 0; y < terminal_state(TK_HEIGHT); y++) {
		for (x = 0; x < terminal_state(TK_WIDTH); x++) {
			color_t background;
			color_t foreground;

			background = terminal_pick_bkcolor(x, y);
			foreground = terminal_pick_color(x, y, 0);
			terminal_bkcolor(color_tool_add(background, BLEND_BKCOLOR_BLEND_ARGB));
			terminal_color(color_tool_subtract(foreground, BLEND_COLOR_ARGB));
			terminal_put(x, y, terminal_pick(x, y, 0));
		}
	}

	/* Get x and y start positions to center the modal. */
	x = (terminal_state(TK_WIDTH) / 2) - (MODAL_WIDTH / 2);
	y = (terminal_state(TK_HEIGHT) / 2) - (MODAL_HEIGHT / 2);

	/* Clear background box. */
	terminal_bkcolor(color_from_argb(255, 0, 0, 0));
	terminal_clear_area(x, y, MODAL_WIDTH, MODAL_HEIGHT);

	/* Print the message text. */
	terminal_color(color_from_argb(255, 255, 255, 255));

	terminal_print_ext(
		x + PADDING_LEFT,
		y + PADDING_TOP,
		MODAL_WIDTH - PADDING_RIGHT,
		MODAL_HEIGHT - PADDING_BOTTOM - 3,
		TK_ALIGN_LEFT,
		render->gui->prompt_bool.question_text);
	
	/* Print choice buttons. */
	choice_button_length = (
		strlen(render->gui->prompt_bool.yes_text)
		+ strlen(render->gui->prompt_bool.no_text)
		+ 3);

	if (render->gui->prompt_bool.choice) {
		terminal_printf(
			x + MODAL_WIDTH - PADDING_RIGHT - choice_button_length - 3,
			y + MODAL_HEIGHT - PADDING_BOTTOM - 1, 
			"> %s    %s", 
			render->gui->prompt_bool.yes_text, 
			render->gui->prompt_bool.no_text);
	} else {
		terminal_printf(
			x + MODAL_WIDTH - PADDING_RIGHT - choice_button_length - 3,
			y + MODAL_HEIGHT - PADDING_BOTTOM - 1, 
			"  %s  > %s ", 
			render->gui->prompt_bool.yes_text, 
			render->gui->prompt_bool.no_text);
	}
}
