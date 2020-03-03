#include "render/render_game/render_game.h"

void render_game_player(struct render *render)
{
	terminal_bkcolor(render->world->player.glyph.background);
	terminal_color(render->world->player.glyph.foreground);
	terminal_put(
		render->world->player.position.x,
		render->world->player.position.y,
		render->world->player.glyph.symbol);
}
