/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_holder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 16:51:05 by smortier          #+#    #+#             */
/*   Updated: 2018/08/05 16:51:05 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_mand_params(t_params *params, int x, int y)
{
	float tmp;

	float h = 1 / params->zoom;
	params->mand.c_r = 0;
	params->mand.c_i = 0;
	params->mand.z_r = 0;
	params->mand.z_i = 0;
	params->mand.i = 0;
	tmp = params->mand.x1;
	ft_printf("\e[31mIterations = [%d]\e[0m\n", params->mand.iter);
	printf("\e[32mH = [%f]\e[0m\n", h);
	params->mand.x1 = ((x / params->mand.zoom_x) + params->mand.x1) - h;
	params->mand.x2 = ((x / params->mand.zoom_x) + tmp) + h;
	printf("\e[32mx1 = [%f], x2 = [%f]\e[0m\n", params->mand.x1, params->mand.x2);
	tmp = params->mand.y1;
	params->mand.y1 = ((y / params->mand.zoom_y) + params->mand.y1) - h;
	params->mand.y2 = ((y / params->mand.zoom_y) + tmp) + h;
	printf("\e[32my1 = [%f], y2 = [%f]\e[0m\n", params->mand.y1, params->mand.y2);
	params->mand.image_x = WIDTH;
	params->mand.image_y = HIGHT;
	params->mand.zoom_x = params->mand.image_x / (params->mand.x2 -
		params->mand.x1);
	params->mand.zoom_y = params->mand.image_y / (params->mand.y2 -
		params->mand.y1);
	printf("zoom_x = [%f], zoom_y = [%f]\n", params->mand.zoom_x, params->mand.zoom_y);
	// params->mand.iter = 50 + (int)params->zoom / 2;
}

int		mouse_holder(int key, int x, int y, t_params *params)
{
	if (key == ZOOM_MOUSE)
	{
		ft_printf("Mouse--> x = [%d], y = [%d]\n", x, y);
		params->zoom *= 1.1;
		params->mand.iter += 1;
		ft_printf("Mouse--> ZOOM (%d)\n", params->zoom);
		params->x = 0;
		params->y = 0;
		change_mand_params(params, x, y);
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
	else if (key == DEZOOM_MOUSE)
	{
		// params->mand.iter += 50;
		ft_printf("Mouse--> x = [%d], y = [%d]\n", x, y);
		params->zoom /= 1.1;
		params->mand.iter -= 1;
		// params->mand.iter -= 1;
		// ft_printf("Mouse--> DEZOOM (%d)\n", params->zoom);
		params->x = 0;
		params->y = 0;
		change_mand_params(params, x, y);
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
	return (0);
}
