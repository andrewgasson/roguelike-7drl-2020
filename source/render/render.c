#include "render/render.h"

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

void render_init(struct render *render, struct world *world)
{
	render->world = world;
}

void render_update(struct render *render)
{
	/* Reset */
	terminal_bkcolor(BLACK_COLOR);
	terminal_color(WHITE_COLOR);
	terminal_clear();

	/* Draw */
	render_layer_player(render);

	/* Output */
	terminal_refresh();
}
