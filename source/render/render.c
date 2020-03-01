#include "render/render.h"

#include "render/render_gui/render_gui.h"
#include "render/render_layer/render_layer.h"
#include <stdlib.h>

#define BLACK_COLOR 0xFF000000
#define WHITE_COLOR 0xFFFFFFFF

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
	/* Reset colors and layers */
	terminal_bkcolor(BLACK_COLOR);
	terminal_color(WHITE_COLOR);
	terminal_layer(1);
	terminal_clear();
	terminal_layer(0);
	terminal_clear();

	/* Setup GUI layer */
	terminal_layer(1);

	/* Draw GUI */
	if (render->gui->main_menu.enabled)
		render_gui_main_menu(render);

	/* Only render game layer if enabled GUI is non-blocking. */
	if (!gui_game_render_disabled(render->gui)) {
		/* Setup game layer */
		terminal_layer(0);
		terminal_bkcolor(BLACK_COLOR);
		terminal_color(WHITE_COLOR);

		/* Draw game */
		render_layer_walls(render);
		render_layer_player(render);
	}

	/* Output */
	terminal_refresh();
}
