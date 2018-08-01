/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_holder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 22:37:15 by smortier          #+#    #+#             */
/*   Updated: 2017/12/11 22:37:16 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_replace_points_by_space(t_conv *conv)
{
	int		i;

	i = -1;
	while (conv->final_arg[++i])
		if (conv->final_arg[i] == '.')
			conv->final_arg[i] = ' ';
}

void		ft_push_str_end(t_conv *conv, int size)
{
	int		i;
	int		y;

	i = size - 1;
	while (i != -1)
	{
		y = i;
		while (!conv->final_arg[y] && y != 0)
			y--;
		if (conv->final_arg[y] == 'x' || conv->final_arg[y] == 'X')
			i -= 1;
		conv->final_arg[i] = conv->final_arg[y];
		conv->final_arg[y] = '\0';
		i--;
	}
	while (++i < size)
		if (!conv->final_arg[i])
			conv->final_arg[i] = '.';
}

void		ft_hold_precision(t_conv *conv)
{
	int		i;
	int		y;

	if (conv->lenght_min > conv->precision)
		i = conv->lenght_min - conv->precision;
	else
		i = 0;
	y = i;
	while (conv->final_arg[++y])
	{
		if (ft_strchr(" -+", conv->final_arg[y]))
			conv->final_arg[i] = conv->final_arg[y];
	}
	if (conv->lenght_min > conv->precision)
		i = conv->lenght_min - conv->precision;
	else
		i = 0;
	if (ft_strchr(" -+", conv->final_arg[i]))
		i += 1;
	while (conv->final_arg[i] != '\0' && ft_strchr(" .-+", conv->final_arg[i]))
	{
		conv->final_arg[i] = '0';
		i++;
	}
}

void		ft_existprec(t_conv *conv)
{
	int		i;

	if (conv->lenght_min > ft_strlen(conv->final_arg) &&
			conv->lenght_min >= conv->precision && conv->lenght_min)
	{
		conv->final_arg = ft_realloc((void **)&conv->final_arg,
								ft_strlen(conv->final_arg), conv->lenght_min);
		ft_push_str_end(conv, (int)conv->lenght_min);
	}
	i = -1;
	if (conv->precision)
	{
		while (conv->final_arg[++i])
			conv->precision += (ft_strchr(" -+", conv->final_arg[i])) ? 1 : 0;
		if (conv->precision > ft_strlen(conv->final_arg))
		{
			conv->final_arg = ft_realloc((void **)&conv->final_arg,
								ft_strlen(conv->final_arg), conv->precision);
			if (conv->lenght_min < conv->precision)
				ft_push_str_end(conv, conv->precision);
		}
		ft_hold_precision(conv);
	}
	if (conv->lenght_min || conv->precision)
		ft_replace_points_by_space(conv);
}

void		ft_precision_holder(t_conv *conv)
{
	if (conv->type_letter == '%')
		ft_precision_pourcent(conv);
	else if (conv->type_letter == 's' && conv->typing)
		ft_precision_s(conv);
	else if (ft_strchr(conv->final_arg, 'X') || ft_strchr(conv->final_arg, 'x'))
		ft_precision_xandup(conv);
	else if (conv->type_letter != 'S' && conv->type_letter != 'C' &&
			conv->type_letter != 's')
		ft_existprec(conv);
}
