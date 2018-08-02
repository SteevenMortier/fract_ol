//HEADER
//HEADER
//HEADER
//HEADER
//HEADER
//HEADER

#include "fractol.h"

t_mand	init_mand(void)
{
	t_mand tmp;

	tmp.c_r = 0;
	tmp.c_i = 0;
	tmp.z_r = 0;
	tmp.z_i = 0;
	tmp.i = 0;
	tmp.x1 = -2.1;
	tmp.x2 = 0.6;
	tmp.y1 = -1.2;
	tmp.y2 = 1.2;
	tmp.image_x = WIDTH;
	tmp.image_y = HIGHT;
	tmp.zoom_x = tmp.image_x / (tmp.x2 - tmp.x1);
	tmp.zoom_y = tmp.image_y / (tmp.y2 - tmp.y1);
	tmp.iterations = 50;
	return (tmp);
}

void    init_params(t_params *params)
{
    params->mand = init_mand();
    params->x = 0;
    params->y = 0;
}
