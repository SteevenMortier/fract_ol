/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_holder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:38:50 by smortier          #+#    #+#             */
/*   Updated: 2018/08/01 13:38:50 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_mand_params_key(t_params *params)
{
	long double tmp;
	long double h = 1 / params->zoom;

	params->mand.c_r = 0;
	params->mand.c_i = 0;
	params->mand.z_r = 0;
	params->mand.z_i = 0;
	params->mand.i = 0;
	tmp = params->mand.x1;
	printf("\e[32mH = [%Lf]\e[0m\n", h);
	printf("\e[32mx1 = [%Lf], x2 = [%Lf]\e[0m\n", params->mand.x1, params->mand.x2);
	tmp = params->mand.y1;
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

int		mand_case(int key, t_params *params)
{
	ft_printf("Key = [%d]\n", key);
	if (key == 53)
		exit(0);
	else if (key == PLUS)
	{
		params->mand.iter += 10;
		params->x = 0;
		params->y = 0;
		change_mand_params_key(params);
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
	else if (key == LESS)
	{
		params->mand.iter -= 10;
		params->x = 0;
		params->y = 0;
		change_mand_params_key(params);
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
	return (0);
}

int		julia_case(int key, t_params *params)
{
	long double		ladder;

	ladder = 0.001;
	ft_printf("Key = [%d]\n", key);
	if (key == 53)
		exit(0);
	if (key == PLUS)
	{
		params->julia.c_r += ladder;
		params->julia.c_i += ladder;
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
	if (key == LESS)
	{
		params->julia.c_r -= ladder;
		params->julia.c_i -= ladder;
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
	return (0);
}

int		key_holder(int key, t_params *params)
{
	if (params->fractal == 1)
		mand_case(key, params);
	else if (params->fractal == 2)
		julia_case(key, params);
	return (0);
}
