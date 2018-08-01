/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_pourcent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 20:04:53 by smortier          #+#    #+#             */
/*   Updated: 2018/01/21 00:51:45 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define SIZE ft_strlen(conv->final_arg)
#define CHAR conv->final_arg[i] ==
#define CHARY conv->final_arg[y] ==
#define CHARI2 conv->final_arg[i + 1] ==

void		ft_precision_pourcent(t_conv *conv)
{
	int		i;
	int		y;

	i = -1;
	conv->final_arg = ft_strnew(ft_strlen(conv->first_arg) + conv->lenght_min);
	while (++i < (int)ft_strlen(conv->first_arg) + (int)conv->lenght_min - 2)
		conv->final_arg[i] = '.';
	i = -1;
	while (++i < (int)conv->lenght_min - 1)
		conv->final_arg[i] = ' ';
	y = 0;
}
