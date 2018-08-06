/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mandel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:52:34 by smortier          #+#    #+#             */
/*   Updated: 2018/08/05 15:52:35 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*thread_mand_1(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_mandel(params, 0, 0);
	return (0);
}

void	*thread_mand_2(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_mandel(params, 150, 0);
	return (0);
}

void	*thread_mand_3(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_mandel(params, 300, 0);
	return (0);
}

void	*thread_mand_4(void *parameter)
{
	t_params *params;

	params = (t_params *)parameter;
	calc_mandel(params, 450, 0);
	return (0);
}
