/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot->c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42->fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:08:00 by smortier          #+#    #+#             */
/*   Updated: 2018/08/01 16:08:02 by smortier         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_mand	*init_mand(void)
{
	t_mand *tmp;

	if (!(tmp = (t_mand *)ft_memalloc(sizeof(t_mand))))
		exit(0);
	tmp->c_r = 0;
	tmp->c_i = 0;
	tmp->z_r = 0;
	tmp->z_i = 0;
	tmp->i = 0;
	tmp->x1 = -2.1;
	tmp->x2 = 0.6;
	tmp->y1 = -1.2;
	tmp->y2 = 1.2;
	tmp->image_x = WIDTH;
	tmp->image_y = HIGHT;
	tmp->zoom_x = tmp->image_x / (tmp->x2 - tmp->x1);
	tmp->zoom_y = tmp->image_y / (tmp->y2 - tmp->y1);
	return (tmp);
}

void	ft_mandelbrot(t_params *params)
{
	int		x;
	int		y;
	t_mand *mand;
	float	tmp;

	x = 0;
	y = 0;
	tmp = 0;
	mand = init_mand();
	params->img.img_ptr = mlx_new_image(params->mlx_ptr, WIDTH, HIGHT);
	params->img.data = (int *)mlx_get_data_addr(params->img.img_ptr,
										&params->img.bpp, &params->img.size_l,
										&params->img.endian);
	// printf("image_x = [%f] && image_y = [%f]\n", mand->image_x, mand->image_y);
	while (y < mand->image_y)
	{
		x = 0;
		while (x < mand->image_x)
		{
			mand->c_r = x / mand->zoom_x + mand->x1;
            mand->c_i = y / mand->zoom_y + mand->y1;
            mand->z_r = 0;
            mand->z_i = 0;
            mand->i = 0;
            while (mand->z_r * mand->z_r + mand->z_i * mand->z_i < 4 && mand->i < 100)
			{
                tmp = mand->z_r;
                mand->z_r = mand->z_r * mand->z_r - mand->z_i * mand->z_i + mand->c_r;
                mand->z_i = 2 * mand->z_i * tmp + mand->c_i;
                mand->i = mand->i + 1;
			}
			// ft_printf("mand->i = [%d]\n", mand->i);
			if (mand->i == 100)
			{
				params->img.data[y * WIDTH + x] = 0xFF0000;
				// mlx_pixel_put(params->mlx_ptr, params->win_ptr, x, y, 0xF0F000);
				// ft_printf("on affiche [%d,%d]\n", x, y);
			}
			else
				params->img.data[y * WIDTH + x] = mand->i*255/100;
			// ft_printf("y = [%d]\n", y);
			x++;
			(void)params;
		}
		// ft_printf("x = [%d]\n", x);
		y++;
	}
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img.img_ptr,
							0, 0);
	// free(&mand);
	ft_printf("On printf un mandelbrot =O\n");
}
