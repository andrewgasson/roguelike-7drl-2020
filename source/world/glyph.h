#ifndef GLYPH_H
#define GLYPH_H

#include "BearLibTerminal.h"

struct glyph {
	color_t background;
	color_t foreground;
	char symbol;
};

#endif
