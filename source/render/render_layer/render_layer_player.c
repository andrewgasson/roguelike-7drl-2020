#include "render/render_layer/render_layer.h"

void render_layer_player(struct render *render)
{
	terminal_bkcolor(render->world->player.glyph.background);
	terminal_color(render->world->player.glyph.foreground);
	terminal_put(
		render->world->player.x,
		render->world->player.y,
		render->world->player.glyph.symbol);
}
