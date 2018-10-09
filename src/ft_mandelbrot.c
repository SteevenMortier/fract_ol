/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 14:42:48 by smortier          #+#    #+#             */
/*   Updated: 2018/08/05 14:42:52 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	change_mand(t_mand *mand, int x, int y)
{
	mand->c_r = x / mand->zoom_x + mand->x1;
	mand->c_i = y / mand->zoom_y + mand->y1;
	mand->z_r = 0;
	mand->z_i = 0;
	mand->i = 0;
}

void	change_mand2(t_mand *mand, float tmp)
{
	mand->z_r = mand->z_r * mand->z_r - mand->z_i * mand->z_i + mand->c_r;
	mand->z_i = 2 * mand->z_i * tmp + mand->c_i;
	mand->i = mand->i + 1;
}

void	store_img(t_params *params, int x, int y, t_mand mand)
{
	int	iterations;

	iterations = mand.i % 256;
	/*if (mand.i >= mand.iter)
	// (void)mand;
		params->img.data[y * WIDTH + x] = get_color(iterations * 5, 255, 255);
	else */
		params->img.data[y * WIDTH + x] = get_color(iterations * 10, iterations * 5, 0);
	//params->img.data[y * WIDTH + x] = get_color(0, 255, 0); // a enlever
}

void	*calc_mandel(t_params *params, int y, int x)
{
	t_mand	mand;
	long double	tmp;
	int		limit;

	limit = y + HIGHT / 4;
	mand = params->mand;
	tmp = 0;
	printf("mand.iter = %d\n", mand.iter);
	while (y < limit)
	{
		x = 0;
		while (x < mand.image_x)
		{
			change_mand(&mand, x, y);
			while (mand.z_r * mand.z_r + mand.z_i * mand.z_i < 4 &&
				mand.i < mand.iter)
			{
				tmp = mand.z_r;
				change_mand2(&mand, tmp);
			}
			store_img(params, x, y, mand);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_mandelbrot(t_params *params)
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;

	params->img.img_ptr = mlx_new_image(params->mlx_ptr, WIDTH, HIGHT);
	params->img.data = (int *)mlx_get_data_addr(params->img.img_ptr,
		&params->img.bpp, &params->img.size_l, &params->img.endian);
	if (pthread_create(&thread1, 0, thread_mand_1, (void *)params) ||
		pthread_create(&thread2, 0, thread_mand_2, (void *)params) ||
		pthread_create(&thread3, 0, thread_mand_3, (void *)params) ||
		pthread_create(&thread4, 0, thread_mand_4, (void *)params))
	{
		ft_printf("pthread_create\n");
		exit(0);
	}
	if (pthread_join(thread1, NULL) || pthread_join(thread2, NULL) ||
		pthread_join(thread3, NULL) || pthread_join(thread4, NULL))
	{
		perror("pthread_join");
		exit(0);
	}
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr,
		params->img.img_ptr, 0, 0);
	ft_printf("On printf un mandelbrot =O\n");
}
