/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formate_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:45:52 by smortier          #+#    #+#             */
/*   Updated: 2017/12/06 12:45:53 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_lenght_min(t_conv *conv)
{
	int		i;
	int		y;
	size_t	condition;

	i = -1;
	condition = 0;
	while (conv->first_arg[++i] && conv->first_arg[i] != '.')
	{
		y = 0;
		if (ft_isdigit((int)conv->first_arg[i]) && !condition)
		{
			while (conv->first_arg[i + y] && ft_isdigit(conv->first_arg[i + y]))
			{
				y++;
			}
			condition = ft_atoi(ft_strsub(conv->first_arg, i, y));
		}
	}
	if (condition)
		conv->lenght_min = condition;
}

void	ft_precision(t_conv *conv)
{
	int		i;
	int		y;
	size_t	condition;

	i = -1;
	y = 0;
	while (conv->first_arg[++i] && conv->first_arg[i] != '.')
		;
	i = (conv->first_arg[i] == '.' && conv->first_arg[i + 1]) ? i + 1 : i;
	if (!ft_isdigit(conv->first_arg[i]))
		return ;
	else
	{
		while (conv->first_arg[i + y] && ft_isdigit(conv->first_arg[i + y]))
			y++;
		condition = ft_atoi(ft_strsub(conv->first_arg, i, y));
		if (condition)
			conv->precision = condition;
	}
}

void	ft_formate_str(t_conv *conv)
{
	while (conv)
	{
		if (conv->type_letter)
		{
			ft_lenght_min(conv);
			ft_precision(conv);
		}
		conv = conv->next;
	}
}
