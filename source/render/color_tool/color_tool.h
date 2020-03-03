#ifndef COLOR_TOOL_H
#define COLOR_TOOL_H

#include "BearLibTerminal.h"

color_t color_tool_get_a(color_t c);

color_t color_tool_get_r(color_t c);

color_t color_tool_get_g(color_t c);

color_t color_tool_get_b(color_t c);

color_t color_tool_add(color_t lhs, color_t rhs);

color_t color_tool_subtract(color_t lhs, color_t rhs);

#endif
