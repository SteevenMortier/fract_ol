#include "fractol.h"

int	get_color(int red, int green, int blue)
{
	if (red > 255)
		red = 255;
	if (green)
		green = 255;
	if (blue > 255)
		blue = 255;
	return (red * 256 * 256 + green * 256 + blue);
}
