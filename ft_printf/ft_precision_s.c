/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:17:26 by smortier          #+#    #+#             */
/*   Updated: 2017/12/13 19:40:59 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define SIZE ft_strlen(conv->final_arg)

void		ft_special_case_s(t_conv *conv)
{
	int		i;

	i = -1;
	while (++i < (int)conv->lenght_min)
	{
		conv->final_arg[i] = ' ';
	}
	conv->final_arg[i] = 0;
}

void		ft_cut_end(t_conv *conv)
{
	int		i;
	int		y;

	if (conv->lenght_min && !conv->precision && ft_strchr(conv->first_arg, '.'))
	{
		ft_special_case_s(conv);
		return ;
	}
	if (conv->lenght_min < ft_strlen(conv->type))
		return ;
	if (conv->precision)
		conv->typing[conv->precision] = '\0';
	i = 0;
	if (conv->lenght_min > ft_strlen(conv->typing))
		conv->final_arg = ft_realloc((void **)&conv->final_arg,
							ft_strlen(conv->first_arg), conv->lenght_min);
	while (i < (int)(conv->lenght_min - ft_strlen(conv->typing)))
	{
		conv->final_arg[i] = ' ';
		i++;
	}
	y = -1;
	while (i + ++y != (int)conv->lenght_min)
		conv->final_arg[i + y] = conv->typing[y];
	conv->final_arg[i + y] = '\0';
}

void		ft_precision_s(t_conv *conv)
{
	size_t		i;

	if (conv->typing && conv->lenght_min > ft_strlen(conv->typing))
		ft_cut_end(conv);
	else if (!conv->lenght_min && conv->precision)
		conv->final_arg[conv->precision] = '\0';
	else if (conv->lenght_min <= ft_strlen(conv->typing) &&
			conv->precision < conv->lenght_min)
		ft_cut_end(conv);
	else if (conv->precision < ft_strlen(conv->typing) &&
			conv->precision >= conv->lenght_min && !conv->modified)
		conv->final_arg[conv->precision] = '\0';
	if (conv->lenght_min && !conv->precision &&
			!conv->modified && conv->lenght_min > ft_strlen(conv->typing) &&
			ft_strchr(conv->first_arg, '.'))
	{
		i = -1;
		ft_memdel((void **)&conv->final_arg);
		conv->final_arg = ft_strnew(conv->lenght_min);
		while (++i < conv->lenght_min)
			conv->final_arg[i] = ' ';
	}
}
