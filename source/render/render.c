#include "render/render.h"

#include "render/render_game/render_game.h"
#include "render/render_gui/render_gui.h"
#include <stdlib.h>

struct render *render_create(void)
{
	struct render *render;

	render = malloc(sizeof(*render));

	return render;
}

void render_destroy(struct render *render)
{
	free(render);
}

void render_init(
	struct render *render,
	struct gui *gui,
	struct world *world)
{
	render->gui = gui;
	render->world = world;
}

void render_update(struct render *render)
{
	/* Reset draw area. */
	terminal_bkcolor(color_from_argb(255, 0, 0, 0));
	terminal_color(color_from_argb(255, 255,255, 255));
	terminal_clear();

	/* Only render game layer if the enabled GUI(s) are non-blocking. */
	if (!gui_game_render_disabled(render->gui)) {
		/* Setup draw layer */
		terminal_layer(0);

		/* Draw game */
		render_game_walls(render);
		render_game_player(render);
	}

	/* Setup GUI layer */
	terminal_layer(1);

	/* Draw GUI */
	if (render->gui->main_menu.enabled)
		render_gui_main_menu(render);
	
	if (render->gui->pause_menu.enabled)
		render_gui_pause_menu(render);

	/* Output */
	terminal_refresh();
}
