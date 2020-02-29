#ifndef BEING_H
#define BEING_H

#include "world/glyph.h"

struct being {
	int x;
	int y;
	struct glyph glyph;
};

#endif
