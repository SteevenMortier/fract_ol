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

#include <math.h>

# define WIDTH 800
# define HIGHT 600

# define Mandelbrot 1

# define Julia 2

# define ZOOM_MOUSE 4
# define DEZOOM_MOUSE 5
# define PLUS 24
# define LESS 27

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
	float	zoom_y;
	float	zoom_x;
	float	image_x;
	float	image_y;
	float 	h;
	int		iter;
}						t_mand;


typedef struct			s_params
{
	void				*mlx_ptr;
	void				*win_ptr;
	int 				fractal;
	int					x;
	int					y;
	float					zoom;
	t_mand				mand;
	t_img				img;
}						t_params;

int		key_holder(int key, t_params *params);

int		mouse_holder(int key, int x, int y, t_params *params);

void	init_drawing(t_params *params);

void	print_fractal(t_params *params);

void	ft_mandelbrot(t_params *params);

void    init_params(t_params *params);

//Thread mand
void	*thread_mand_1(void *parameter);
void	*thread_mand_2(void *parameter);
void	*thread_mand_3(void *parameter);
void	*thread_mand_4(void *parameter);

int	get_color(int red, int green, int blue);
void	*calc_mandel(t_params *params, int y, int x);

#endif
