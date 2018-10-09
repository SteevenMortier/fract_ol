/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:56:57 by smortier          #+#    #+#             */
/*   Updated: 2018/08/05 15:57:00 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	tmp.iter = 50;
	return (tmp);
}

t_julia	init_julia(void)
{
	/*définir x1 = -1
	définir x2 = 1
	définir y1 = -1.2
	définir y2 = 1.2
	définir zoom = 100
	définir iteration_max = 150

	définir image_x = (x2 - x1) * zoom
	définir image_y = (y2 - y1) * zoom*/
 	t_julia tmp;

	tmp.c_r = 0.285;
	tmp.c_i = 0.01;
	tmp.z_r = 0;
	tmp.z_i = 0;
	tmp.i = 0;
	tmp.x1 = -1;
	tmp.x2 = 1;
	tmp.y1 = -1.2;
	tmp.y2 = 1.2;
	tmp.image_x = WIDTH;
	tmp.image_y = HIGHT;
	tmp.zoom_x = tmp.image_x / (tmp.x2 - tmp.x1);
	tmp.zoom_y = tmp.image_y / (tmp.y2 - tmp.y1);
	tmp.iter = 50;
	return (tmp);
}

void	init_params(t_params *params)
{
	if (params->fractal == 1)
	{
		params->mand = init_mand();
		params->x = 0;
		params->y = 0;
		params->zoom = 1;
	}
	else if (params->fractal == 2)
	{
		params->julia = init_julia();
		params->x = 0;
		params->y = 0;
		params->zoom = 1;
	}
	else
		exit(0);
}
