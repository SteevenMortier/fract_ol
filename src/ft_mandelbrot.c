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

void 	*calc_mandel(t_params *params, int y)
{
	t_mand mand;
	float	tmp;
	int		limit;
	int		x;

	limit = y + 300;
	mand = params->mand;
	tmp = 0;
	while (y < limit)
	{
		x = 0;
		while (x < mand.image_x)
		{
			mand.c_r = x / mand.zoom_x + mand.x1;
            mand.c_i = y / mand.zoom_y + mand.y1;
            mand.z_r = 0;
            mand.z_i = 0;
            mand.i = 0;
            while (mand.z_r * mand.z_r + mand.z_i * mand.z_i < 4 &&
				mand.i < mand.iterations)
			{
                tmp = mand.z_r;
                mand.z_r = mand.z_r * mand.z_r - mand.z_i * mand.z_i + mand.c_r;
                mand.z_i = 2 * mand.z_i * tmp + mand.c_i;
                mand.i = mand.i + 1;
			}
			if (mand.i == mand.iterations)
				params->img.data[y * WIDTH + x] = 0xFF0000;
			else
				params->img.data[y * WIDTH + x] = mand.i * 255/ mand.iterations;
			x++;
			(void)params;
		}
		y++;
	}
	ft_printf("y = [%d]\n", y);
	return 0;
}

void 	*thread_1(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_mandel(params, 0);
	return(0);
}

void 	*thread_2(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_mandel(params, 300);
	return(0);
}

void 	*thread_3(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_mandel(params, 600);
	return(0);
}

void 	*thread_4(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_mandel(params, 900);
	return(0);
}

void	ft_mandelbrot(t_params *params)
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;

	params->img.img_ptr = mlx_new_image(params->mlx_ptr, WIDTH, HIGHT);
	params->img.data = (int *)mlx_get_data_addr(params->img.img_ptr,
										&params->img.bpp, &params->img.size_l,
										&params->img.endian);
	// printf("image_x = [%f] && image_y = [%f]\n", mand->image_x, mand->image_y);
	if (pthread_create(&thread1, 0, thread_1, (void *)params))
	{
		ft_printf("pthread_create\n");
		exit(0);
    }
	if (pthread_create(&thread2, 0, thread_2, (void *)params))
	{
		ft_printf("pthread_create\n");
		exit(0);
    }
	if (pthread_create(&thread3, 0, thread_3, (void *)params))
	{
		ft_printf("pthread_create\n");
		exit(0);
    }
	if (pthread_create(&thread4, 0, thread_4, (void *)params))
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
