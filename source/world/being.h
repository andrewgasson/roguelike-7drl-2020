#ifndef BEING_H
#define BEING_H

#include "world/glyph.h"
#include "world/position.h"

struct being {
	struct position position;
	struct glyph glyph;
};

#endif
