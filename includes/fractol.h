/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:22:15 by smortier          #+#    #+#             */
/*   Updated: 2018/08/01 13:22:19 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

#define FRACTOL_H

#include "../minilibx/mlx.h"

#include "../libft/libft.h"

#include <pthread.h>

# define WIDTH 1400
# define HIGHT 1200

# define Mandelbrot 1

# define Julia 2

typedef struct			s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}						t_img;

typedef struct			s_mand
{
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int 	i;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	zoom_x;
	float	zoom_y;
	float	image_x;
	float	image_y;
	int		iterations;
}						t_mand;


typedef struct			s_params
{
	void				*mlx_ptr;
	void				*win_ptr;
	int 				fractal;
	int					x;
	int					y;
	t_mand				mand;
	t_img				img;
}						t_params;

int		key_holder(int key, t_params *params);

void	init_drawing(t_params *params);

void	print_fractal(t_params *params);

void	ft_mandelbrot(t_params *params);

void    init_params(t_params *params);

#endif
