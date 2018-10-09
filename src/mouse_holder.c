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
	long double tmp;

	long double h = 1 / params->zoom;
	params->mand.c_r = 0;
	params->mand.c_i = 0;
	params->mand.z_r = 0;
	params->mand.z_i = 0;
	params->mand.i = 0;
	tmp = params->mand.x1;
	ft_printf("\e[31mIterations = [%d]\e[0m\n", params->mand.iter);
	printf("\e[32mH = [%Lf]\e[0m\n", h);
	params->mand.x1 = ((x / params->mand.zoom_x) + params->mand.x1) - h;
	params->mand.x2 = ((x / params->mand.zoom_x) + tmp) + h;
	printf("\e[32mx1 = [%Lf], x2 = [%Lf]\e[0m\n", params->mand.x1, params->mand.x2);
	tmp = params->mand.y1;
	params->mand.y1 = ((y / params->mand.zoom_y) + params->mand.y1) - h;
	params->mand.y2 = ((y / params->mand.zoom_y) + tmp) + h;
	printf("\e[32my1 = [%Lf], y2 = [%Lf]\e[0m\n", params->mand.y1, params->mand.y2);
	params->mand.image_x = WIDTH;
	params->mand.image_y = HIGHT;
	params->mand.zoom_x = params->mand.image_x / (params->mand.x2 -
		params->mand.x1);
		params->mand.zoom_y = params->mand.image_y / (params->mand.y2 -
		params->mand.y1);
	printf("zoom_x = [%Lf], zoom_y = [%Lf]\n", params->mand.zoom_x, params->mand.zoom_y);
	// params->mand.iter = 50 + (int)params->zoom / 2;
}

void	mouse_mandel(int key, int x, int y, t_params *params)
{
	printf("MOUSE ENTERED = %d\n", key);
	if (key == 1)//ZOOM_MOUSE)
	{
		ft_printf("Mouse--> x = [%d], y = [%d]\n", x, y);
		params->zoom *= 1.5;
		params->mand.iter += 10;
		ft_printf("Mouse--> ZOOM (%d)\n", params->zoom);
		params->x = 0;
		params->y = 0;
		change_mand_params(params, x, y);
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
	else if (key == 2)//DEZOOM_MOUSE)
	{
		// params->mand.iter += 50;
		ft_printf("Mouse--> x = [%d], y = [%d]\n", x, y);
		params->zoom /= 1.5;
		params->mand.iter -= 10;
		// params->mand.iter -= 1;
		// ft_printf("Mouse--> DEZOOM (%d)\n", params->zoom);
		params->x = 0;
		params->y = 0;
		change_mand_params(params, x, y);
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
}

void	change_julia_params(t_params *params, int x, int y)
{
	long double tmp;

	long double h = 1 / params->zoom;
	params->julia.z_r = 0;
	params->julia.z_i = 0;
	params->julia.i = 0;
	tmp = params->julia.x1;
	ft_printf("\e[31mIterations = [%d]\e[0m\n", params->julia.iter);
	printf("\e[32mH = [%Lf]\e[0m\n", h);
	params->julia.x1 = ((x / params->julia.zoom_x) + params->julia.x1) - h;
	params->julia.x2 = ((x / params->julia.zoom_x) + tmp) + h;
	printf("\e[32mx1 = [%Lf], x2 = [%Lf]\e[0m\n", params->julia.x1, params->julia.x2);
	tmp = params->julia.y1;
	params->julia.y1 = ((y / params->julia.zoom_y) + params->julia.y1) - h;
	params->julia.y2 = ((y / params->julia.zoom_y) + tmp) + h;
	printf("\e[32my1 = [%Lf], y2 = [%Lf]\e[0m\n", params->julia.y1, params->julia.y2);
	params->julia.image_x = WIDTH;
	params->julia.image_y = HIGHT;
	params->julia.zoom_x = params->julia.image_x / (params->julia.x2 -
		params->julia.x1);
		params->julia.zoom_y = params->julia.image_y / (params->julia.y2 -
		params->julia.y1);
	printf("zoom_x = [%Lf], zoom_y = [%Lf]\n", params->julia.zoom_x, params->julia.zoom_y);
	// params->mand.iter = 50 + (int)params->zoom / 2;
}

void	mouse_julia(int key, int x, int y, t_params *params)
{
	if (key == 1)//ZOOM_MOUSE)
	{
		ft_printf("Mouse--> x = [%d], y = [%d]\n", x, y);
		params->zoom *= 1.5;
		params->julia.iter += 10;
		ft_printf("Mouse--> ZOOM (%d)\n", params->zoom);
		params->x = 0;
		params->y = 0;
		change_julia_params(params, x, y);
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
	else if (key == 2)//DEZOOM_MOUSE)
	{
		// params->mand.iter += 50;
		ft_printf("Mouse--> x = [%d], y = [%d]\n", x, y);
		params->zoom /= 1.5;
		params->julia.iter -= 10;
		// params->mand.iter -= 1;
		// ft_printf("Mouse--> DEZOOM (%d)\n", params->zoom);
		params->x = 0;
		params->y = 0;
		change_julia_params(params, x, y);
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
}

int		mouse_holder(int key, int x, int y, t_params *params)
{
	if (params->fractal == 1)
		mouse_mandel(key, x, y, params);
	else if (params->fractal == 2)
		mouse_julia(key, x, y, params);
	return (0);
}
