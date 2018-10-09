/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:49:46 by smortier          #+#    #+#             */
/*   Updated: 2018/10/09 15:49:49 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*thread_julia_1(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_julia(params, 0, 0);
	return (0);
}

void	*thread_julia_2(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_julia(params, 150, 0);
	return (0);
}

void	*thread_julia_3(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_julia(params, 300, 0);
	return (0);
}

void	*thread_julia_4(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_julia(params, 450, 0);
	return (0);
}
