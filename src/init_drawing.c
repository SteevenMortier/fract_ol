/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 15:26:30 by smortier          #+#    #+#             */
/*   Updated: 2018/08/01 15:26:32 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_fractal(t_params *params)
{
	if (params->fractal == 1)
		ft_mandelbrot(params);
	else if (params->fractal == 2)
		ft_julia(params);
	else
		exit(0);
}

void	init_drawing(t_params *params)
{
	params->mlx_ptr = mlx_init();
	params->win_ptr = mlx_new_window(params->mlx_ptr,
			WIDTH, HIGHT, "smortier_fractol");
	init_params(params);
	print_fractal(params);
	mlx_hook(params->win_ptr, 2, 0, key_holder, params);
	mlx_mouse_hook(params->win_ptr, mouse_holder, params);
	//ici on peut mettre les hook souris
	mlx_loop(params->mlx_ptr);
}
