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

int		key_holder(int key, t_params *params)
{
	(void)params;
	ft_printf("Key = [%d]\n", key);
	if (key == 53)
		exit(0);
	else
	{
		mlx_destroy_image(params->mlx_ptr, params->img.img_ptr);
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		print_fractal(params);
	}
	return (0);
}
