/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:50:27 by smortier          #+#    #+#             */
/*   Updated: 2018/08/01 12:53:16 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_fractale(char **av, t_params *params)
{
	if (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1], "mandelbrot"))
		params->fractal = Mandelbrot;
	else
	{
		ft_printf("Usage: ./fractol [arg]\n");
		ft_printf("- Mandelbrot\n- Julia\n- ...\n");
		exit(0);
	}
}

int		main(int ac, char **av)
{
	t_params params;

	if (ac == 1)
	{
		ft_printf("Usage: %s", "Put some options\n");
		exit (0);
	}
	choose_fractale(av, &params);
	ft_printf("choosed fractal = [%d]\n", params.fractal);
	init_drawing(&params);
	return (0);
}
