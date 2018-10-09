/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:46:54 by smortier          #+#    #+#             */
/*   Updated: 2018/10/09 15:46:56 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_julia(t_julia *julia, int x, int y)
{
	//julia->c_r = 0.285;
	//julia->c_i = 0.01;
	julia->z_r = x / julia->zoom_x + julia->x1;
	julia->z_i = y / julia->zoom_y + julia->y1;
	julia->i = 0;
}

void	change_julia2(t_julia *julia, float tmp)
{
	julia->z_r = julia->z_r * julia->z_r - julia->z_i * julia->z_i + julia->c_r;
	julia->z_i = 2 * julia->z_i * tmp + julia->c_i;
	julia->i = julia->i + 1;
}

void	store_img_julia(t_params *params, int x, int y, t_julia julia)
{
	int	iterations;

	iterations = julia.i % 256;
	params->img.data[y * WIDTH + x] = get_color(iterations * 10, iterations * 5, 0);
}

void	*calc_julia(t_params *params, int y, int x)
{
	t_julia	julia;
	long double	tmp;
	int		limit;

	limit = y + HIGHT / 4;
	julia = params->julia;
	tmp = 0;
	printf("julia.iter = %d\n", julia.iter);

	while (y < limit)
	{
		x = 0;
		while (x < julia.image_x)
		{
			change_julia(&julia, x, y);
			while (julia.z_r * julia.z_r + julia.z_i * julia.z_i < 4 &&
				julia.i < julia.iter)
			{
				tmp = julia.z_r;
				change_julia2(&julia, tmp);
			}
			store_img_julia(params, x, y, julia);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_julia(t_params *params)
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;

	params->img.img_ptr = mlx_new_image(params->mlx_ptr, WIDTH, HIGHT);
	params->img.data = (int *)mlx_get_data_addr(params->img.img_ptr,
		&params->img.bpp, &params->img.size_l, &params->img.endian);
	if (pthread_create(&thread1, 0, thread_julia_1, (void *)params) ||
		pthread_create(&thread2, 0, thread_julia_2, (void *)params) ||
		pthread_create(&thread3, 0, thread_julia_3, (void *)params) ||
		pthread_create(&thread4, 0, thread_julia_4, (void *)params))
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
	ft_printf("On printf un Julia =O\n");
}
