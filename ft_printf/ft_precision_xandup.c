/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_xandup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:33:02 by smortier          #+#    #+#             */
/*   Updated: 2018/01/10 21:44:06 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_push_str_end2(t_conv *conv, int size)
{
	int		i;
	int		y;

	i = size - 1;
	while (i != -1)
	{
		y = i;
		while (!conv->final_arg[y] && y != 0)
			y--;
		conv->final_arg[i] = conv->final_arg[y];
		conv->final_arg[y] = '\0';
		i--;
	}
	while (++i < size)
		if (!conv->final_arg[i])
			conv->final_arg[i] = ' ';
}

void		ft_hold_precision2(t_conv *conv)
{
	int		index;

	conv->final_arg[0] = '0';
	conv->final_arg[1] = conv->type_letter;
	index = 2;
	if (conv->final_arg[index] == '0' ||
			conv->final_arg[index] == conv->type_letter ||
			conv->final_arg[index] == ' ')
	{
		while (conv->final_arg[index] && (conv->final_arg[index] != 'x' &&
										conv->final_arg[index] != 'X'))
		{
			conv->final_arg[index] = '0';
			index++;
		}
		conv->final_arg[index] = '0';
	}
}

void		ft_jsp(t_conv *conv)
{
	int		i;

	if (conv->lenght_min > ft_strlen(conv->final_arg) &&
		conv->lenght_min > conv->precision)
	{
		conv->final_arg = ft_realloc((void **)&conv->final_arg,
								ft_strlen(conv->final_arg), conv->lenght_min);
		ft_push_str_end2(conv, (int)conv->lenght_min);
	}
	i = -1;
	if (conv->precision)
	{
		while (conv->final_arg[++i])
		{
			conv->precision += (ft_strchr("xX", conv->final_arg[i])) ? 2 : 0;
		}
		if (conv->precision >= ft_strlen(conv->final_arg))
		{
			conv->final_arg = ft_realloc((void **)&conv->final_arg,
								ft_strlen(conv->final_arg), conv->precision);
			if (conv->lenght_min < conv->precision)
				ft_push_str_end2(conv, conv->precision);
		}
		ft_hold_precision2(conv);
	}
}

void		ft_precision_xandup(t_conv *conv)
{
	ft_jsp(conv);
}
