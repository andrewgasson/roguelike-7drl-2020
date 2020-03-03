#include "render/color_tool/color_tool.h"

#define GET_ALPHA(color) (color >> 24) & 255
#define GET_RED(color) (color >> 16) & 255
#define GET_GREEN(color) (color >> 8) & 255
#define GET_BLUE(color) color & 255
#define GET_COLOR(a, r, g, b) (a << 24) | (r << 16) | (g << 8) | (b)

color_t color_tool_get_a(color_t c)
{
	return GET_ALPHA(c);
}

color_t color_tool_get_r(color_t c)
{
	return GET_RED(c);
}

color_t color_tool_get_g(color_t c)
{
	return GET_GREEN(c);
}

color_t color_tool_get_b(color_t c)
{
	return GET_BLUE(c);
}

color_t color_tool_add(color_t lhs, color_t rhs)
{
	signed int a;
	signed int r;
	signed int g;
	signed int b;

	a = ((signed) GET_ALPHA(lhs)) + ((signed) GET_ALPHA(rhs));
	r = ((signed) GET_RED(lhs))   + ((signed) GET_RED(rhs));
	g = ((signed) GET_GREEN(lhs)) + ((signed) GET_GREEN(rhs));
	b = ((signed) GET_BLUE(lhs))  + ((signed) GET_BLUE(rhs));

	if (a > 255) a = 255;
	if (r > 255) r = 255;
	if (g > 255) g = 255;
	if (b > 255) b = 255;

	return GET_COLOR((unsigned) a, (unsigned) r, (unsigned) g, (unsigned) b);
}


color_t color_tool_subtract(color_t lhs, color_t rhs)
{
	signed int a;
	signed int r;
	signed int g;
	signed int b;

	a = ((signed) GET_ALPHA(lhs)) - ((signed) GET_ALPHA(rhs));
	r = ((signed) GET_RED(lhs))   - ((signed) GET_RED(rhs));
	g = ((signed) GET_GREEN(lhs)) - ((signed) GET_GREEN(rhs));
	b = ((signed) GET_BLUE(lhs))  - ((signed) GET_BLUE(rhs));

	if (a < 0) a = 0;
	if (r < 0) r = 0;
	if (g < 0) g = 0;
	if (b < 0) b = 0;

	return GET_COLOR((unsigned) a, (unsigned) r, (unsigned) g, (unsigned) b);
}
